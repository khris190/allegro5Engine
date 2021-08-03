
#include <stdio.h>
#include <allegro5/allegro.h>

#include "engine/engine.h"
#include <dlfcn.h>


const int FPS = 60;

int main( int argc, char * argv[] ) {

  engine(FPS);
  return 0;
}
