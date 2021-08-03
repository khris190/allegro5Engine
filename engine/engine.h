#ifndef __ALLEGRO_5_ENGINE_H__
#define __ALLEGRO_5_ENGINE_H__ 

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "gui.h"

#include <stdio.h>
#include <string.h>
#include <chrono>


#include <iostream>

using namespace std;

ALLEGRO_DISPLAY * display = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_TIMER *timer = nullptr;
bool redraw = true;
ALLEGRO_BITMAP * image = nullptr;



bool isPaused = true;

void pauseCalc();
void startCalc();
void DestroyEngine();

void addBallMass();
void subBallMass();
void addRodMass();
void subRodMass();

void resetSim();

int ballMass = 1;
int RodMass = 1;


gui mainGui;

void engine(int FPS)
{
    if( !al_init() ) {
            fprintf( stderr, "failed to initialize allegro!\n" );
            return;
        }
   
    display = al_create_display( 800, 600 );
    if( !display ) {
        fprintf( stderr, "failed to create display!\n" );
        return;
    }

    timer = al_create_timer(1.0/(double)FPS);
    if(!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return;
    }

    event_queue = al_create_event_queue();
    if(!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n"); 
        al_destroy_display(display);
        al_destroy_timer(timer);
        return;
    }
    //addons
    al_install_mouse();
    al_install_keyboard();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();



    mainGui.init();
    for (int i = 0; i < 1000; i++)
    {
        mainGui.addButton(button("test", i % 100, i / 100, (i % 100) + 400, (i / 100)  + 400, "", nullptr, nullptr));
    }
    

    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_start_timer(timer);


    
    while (true)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)  
        {
            if(ev.mouse.button & 1)
            {

            }
            if(ev.mouse.button & 2)
            {
            }
        }
        
        
        if(redraw && al_event_queue_is_empty(event_queue)) {
            al_hold_bitmap_drawing(false);

            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            redraw = false;
            al_clear_to_color(al_map_rgb(0,0,0));
            if (isPaused == false)
            {
                
            }
            mainGui.drawButtons();

            

            al_hold_bitmap_drawing(false);
            al_flip_display();
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
        }
    }
    DestroyEngine();
    return;
}


void pauseCalc()
{
    isPaused = true;
}

void startCalc()
{
    isPaused = false;
}


void DestroyEngine()
{
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
}

#endif // __ALLEGRO_5_ENGINE_H__