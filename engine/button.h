#pragma once

#include <allegro5/allegro.h>
#include <string>

class button
{
public:
    std::string btnName;
    void (*functionLMB)();
    void (*functionRMB)();
    double x1, y1, x2, y2;
    ALLEGRO_BITMAP * bitmap = nullptr;
    std::string btnText;

public:
    button(std::string name, double x1, double y1, double x2, double y2, std::string text, void (*functionLMB)() = nullptr, void (*functionRMB)() = nullptr);

    void setBitmap(ALLEGRO_BITMAP* bmp);
    void press(double x, double y, int mouseButton);
    bool isHovering(double x, double y);
    double getCenterX();
    double getCenterY();
    std::string getText();
    void setText(std::string btnText);

    ~button();
};

button::button(std::string name, double x1, double y1, double x2, double y2, std::string text, void (*functionLMB)(), void (*functionRMB)())
{
    this->btnName = name;
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->btnText = text;
    this->functionLMB = functionLMB;
    this->functionRMB = functionRMB;
    
}

bool button::isHovering(double x, double y)
{
    return (x > x1 && x < x2 && y > y1 && y < y2);
}

void button::press(double x, double y, int mouseButton)
{
    if (isHovering(x, y))
    {
        if (mouseButton == 1)
        {
            if (this->functionLMB != NULL)
            {
                functionLMB();
            }
        }
        else if (mouseButton == 2)
        {
            if (this->functionRMB != NULL)
            {
                functionRMB();
            }
        }
    }
}

double button::getCenterX()
{
    return ( x1 + x2 )/ 2;
}

double button::getCenterY()
{
    return ( y1 + y2 )/ 2;
}

std::string button::getText()
{
    return this->btnText;
}
void button::setText(std::string text)
{
    this->btnText = text;
}

button::~button()
{
    if (bitmap)
    {
        al_destroy_bitmap(bitmap);
    }
}