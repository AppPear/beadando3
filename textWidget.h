#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H
#include "box.h"
#include "graphics.hpp"

class textWidget: public boxy
{
    public:
        textWidget(CGRect _frame, std::string text, genv::color tColor);
        virtual void handle(event ev);
        virtual void draw();
    protected:

    private:
        std::string textToDisp;
        genv::color textColor;
};

#endif // TEXTWIDGET_H
