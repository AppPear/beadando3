#ifndef DOT_H
#define DOT_H
#include "box.h"
#include "graphics.hpp"
typedef enum{
     allWhite,
     ONEgotit,
     TWOgotit
}dotState;

class Dott: public boxy
{
    public:
        Dott(CGRect _frame);
        virtual void handle(event ev);
        virtual void draw();
        dotState getState(){return state;};
        void setState(dotState _dotState);

    protected:

    private:
        dotState state;
        int radius;
};

#endif // DOT_H
