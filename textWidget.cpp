#include "textWidget.h"

using namespace genv;
textWidget::textWidget(CGRect _frame, std::string text,genv::color tColor):textColor(tColor),boxy(_frame)
{
    textToDisp = text;
}
void textWidget::handle(event ev){

}
void textWidget::draw(){
    gout<<move_to(frame.position.x,frame.position.y)<<color(textColor)<< font("MANIFESTO.ttf",38,true)<<text(textToDisp);
}

