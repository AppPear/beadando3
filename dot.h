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
        Dott();
        Dott(CGRect _frame);
        virtual void handle(event ev);
        virtual void draw();
        dotState getState(){return state;};
        void setState(dotState _dotState);
        void setCoulmnIndex(int c, int i);
        int getIndex(){return index;};
        int getColumn(){return column;};

    protected:

    private:
        dotState state;
        int radius;
        int column;
        int index;
};

#endif // DOT_H
