#ifndef BUTTON_H
#define BUTTON_H
#include "box.h"

class Button: public boxy
{
    public:
        Button(CGRect _frame);
        virtual void handle(event ev);
        virtual void draw();
    protected:

    private:
        bool isPressed;
};

#endif // BUTTON_H
