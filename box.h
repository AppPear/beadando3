
#include "graphics.hpp"
#include "functional"
///CGSize

#ifndef CGSIZE_H
#define CGSIZE_H

class CGSize
{
    public:
        CGSize(float s_width, float s_height);
        float width;
        float height;
    protected:

    private:
};

#endif // CGSIZE_H

///CGPoint

#ifndef CGPOINT_H
#define CGPOINT_H


class CGPoint
{
    public:
        CGPoint(float p_x, float p_y);
        float x,y;

    protected:
    private:
};

#endif // CGPOINT_H

///CGRect

#ifndef CGRECT_H
#define CGRECT_H

class CGRect
{
    public:
        CGRect(float x, float y, float width, float height);
        CGSize r_size;
        CGPoint position;
    protected:


    private:
};

#endif // CGRECT_H

/// Color

#ifndef COLOR_H
#define COLOR_H


class colour
{
    public:
        colour(int r, int g, int b);
        int r()const {return pr;};
        int g()const {return pg;};
        int b ()const {return pb;};
    protected:
        int pr,pg,pb;
    private:
};

#endif // COLOR_H

///BOXY

#ifndef BOX_H
#define BOX_H

using namespace genv;

class boxy
{
     protected:
        CGRect frame;
        colour boxColour;
        std::function<void()> callback;

    public:
        boxy(CGRect box_frame);
        virtual void draw();
        virtual void drawContour(bool isSelected);
        virtual bool selected(int mouse_x, int mouse_y) const;
        virtual void handle(event ev);
        void handleSelection(event ev);
        CGRect getFrame(){return frame;};
        virtual void setColor(colour _color);
        template <typename lambdaFn>
        void setCallBack(lambdaFn&& _fn){
            callback = _fn;
        }
        int tag;




    private:
};

#endif // BOX_H


