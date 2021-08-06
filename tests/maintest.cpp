#include <stdio.h>
#include <dlfcn.h>
#include <chrono>
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
using add_function_ptr = void (*)(int*);


int main( int argc, char * argv[] ) {

    //TODO make path work u piece of shit


    //get path from args
    std::string path = argv[0];
    std::size_t found = path.find_last_of( '/');
    path = path.substr(0, found);
    puts(path.c_str());


    std::stringstream currpath;
    currpath << path << "/libtests" << libExtension;


    function_ptr fptr;
    void* lib = dlopen( currpath.str().c_str(), RTLD_LAZY);
    if (!lib) {
        puts (dlerror());
        return 1;
    }
    puts("opened file");



    add_function_ptr afptr;
    fptr = reinterpret_cast<function_ptr>(dlsym(lib, "foo"));
    afptr = reinterpret_cast<add_function_ptr>(dlsym(lib,"addition"));
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


