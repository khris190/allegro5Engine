#pragma once    

#include "button.h"
#include <stdexcept>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <list>
#include <iterator>

class gui
{
private:
    std::list<button> buttons;
    ALLEGRO_FONT *font;
public:
    gui(/* args */);

    void init();
    void addButton(button BTN);
    bool checkPessed(double x, double y, int mouseBtn);
    void drawButtons();

    button * getBtn(std::string name);

    
    ~gui();
};


gui::gui(/* args */)
{
    
}
void gui::init(){
    font = al_load_ttf_font("arial.ttf", 20, ALLEGRO_TTF_NO_AUTOHINT);
    if (!font)
    {
        throw std::runtime_error("unable to load font");
    }
}

void gui::addButton(button BTN)
{
    buttons.push_front(BTN);

}

bool gui::checkPessed(double x, double y, int mouseBtn)
{
    std::list<button>::iterator it;
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        it->press(x, y, mouseBtn);
    }
    return false;
}

void gui::drawButtons()
{
    std::list<button>::iterator it;
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        al_draw_text(font, al_map_rgb(255,255,255), it->getCenterX() , it->getCenterY() - ((it->getCenterY() - it->y1) /2), ALLEGRO_ALIGN_CENTRE, it->getText().c_str());
        al_draw_rectangle(it->x1, it->y1, it->x2, it->y2, al_map_rgb(255,255,255), 1);
    }
}

button * gui::getBtn(std::string name)
{
    std::list<button>::iterator it;
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        if (it->btnName == name)
        {
            return &(*it);
        }
        
    }
    return nullptr;
}

gui::~gui()
{
     std::list<button>::iterator it;
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        it->~button();
    }

}