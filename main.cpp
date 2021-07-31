#ifndef __AALLEGRO_ENGINE__
#define __AALLEGRO_ENGINE__


//#include <stdio.h>
//#include <allegro5/allegro.h>
//
#include <dlfcn.h>
//void func()
//{
//    int x = 1;
//    x++;
//    x++;
//}
//const int FPS = 60;
int main( int argc, char * argv[] ) {
 void* handle = dlopen("hello.so", RTLD_LAZY);
  dlsym(handle, "hello");
    //button btn(1.f, 1, 1, 1, &func);

    //engine(FPS);
    return 0;
}



#endif // __AALLEGRO_ENGINE__