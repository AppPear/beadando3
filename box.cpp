#include "box.h"

using namespace genv;
const int contourWidth = 2;

///CGSize

CGSize::CGSize(float s_width, float s_height):width(s_width),height(s_height)
{

}

///CGPoint

CGPoint::CGPoint(float p_x, float p_y):x(p_x),y(p_y)
{

}

///CGRect

CGRect::CGRect(float x, float y, float width, float height):r_size(width,height),position(x,y)
{

}

/// Color

colour::colour(int r, int g, int b)
{
    //ctor
    pr = r;
    pg = g;
    pb = b;
}

/// BOXY

boxy::boxy(CGRect box_frame):frame(box_frame),boxColour(colour(255,255,255))
{
}

bool boxy::selected(int mouse_x, int mouse_y) const{
    return mouse_x >= frame.position.x && mouse_x <= frame.position.x+frame.r_size.width && mouse_y >= frame.position.y && mouse_y <= frame.position.y+frame.r_size.height;
}
void boxy::handle(event ev){
    this->handleSelection(ev);
}
void boxy::handleSelection(event ev){
    this->drawContour(this->selected(ev.pos_x,ev.pos_y));
}

void boxy::drawContour(bool isSelected){
    if(isSelected){
        gout<< move_to(frame.position.x-contourWidth,frame.position.y-contourWidth) << color(255,255,255) << box(frame.r_size.width+2*contourWidth,frame.r_size.height+2*contourWidth);
    }else{
        gout<< move_to(frame.position.x-contourWidth,frame.position.y-contourWidth) << color(0,0,0) << box(frame.r_size.width+2*contourWidth,frame.r_size.height+2*contourWidth);

    }
}
void boxy::draw(){
    gout<< move_to(frame.position.x,frame.position.y) << color(boxColour.r(),boxColour.g(),boxColour.b()) << box(frame.r_size.width,frame.r_size.height);
}
void boxy::setColor(colour _color){
    boxColour = _color;
}

