#include <stdio.h>
#include <dlfcn.h>
#include "tests.hpp"
#include <iostream>
#include <sstream>
#include <experimental/filesystem>

#ifdef WINDOWS
std::string libExtension = ".dll";
#else
std::string libExtension = ".so";
#endif

namespace fs = std::experimental::filesystem;
using function_ptr = void (*)(void);

int main( int argc, char * argv[] ) {
   
    std::stringstream currpath;
    currpath << fs::current_path().string() << "/libtests" << libExtension;


    function_ptr fptr;
    void* lib = dlopen( currpath.str().c_str(), RTLD_LAZY);
    if (!lib) {
        puts (dlerror());
        return 1;
    }
    puts("opened file");

    fptr = reinterpret_cast<function_ptr>(dlsym(lib, "foo"));

    char *error;
    if ((error = dlerror()) != NULL) {
        puts (error);
        delete error;
        return 1;
    }
    puts("found function");


    (*fptr)();

delete error;
    dlclose(lib);
  return 0;
}
