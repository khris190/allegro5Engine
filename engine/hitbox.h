
enum hitbox_type{
    rectangle,
    circle,
    elipse
};


class hitboxRect
{
private:
   hitbox_type hType;
   double x1,y1,x2,y2;
   double r1,r2;
public:
    hitboxRect(/* args */);

    bool CheckCollision(hitboxRect &obj);

    ~hitboxRect();
};

hitboxRect::hitboxRect(/* args */) 
{
    
}

bool hitboxRect::CheckCollision(hitboxRect &obj) 
{
    
}

hitboxRect::~hitboxRect()
{
}
