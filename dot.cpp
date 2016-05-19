#include "dot.h"
#include <cmath>

using namespace genv;

extern const int windowWidth;
extern const int windowHeight;
extern const color backround;
extern const color playerOne;
extern const color playerTwo;
extern const color emptyColor;

Dott::Dott(CGRect _frame):boxy(_frame){

}
void Dott::handle(event ev){

}
void Dott::draw(){
    switch(state){
    case allWhite:
        gout <<emptyColor;
        break;
    case ONEgotit:
        gout <<playerOne;
        break;
    case TWOgotit:
        gout <<playerTwo;
        break;
    }

    for (int i = frame.position.x; i<frame.position.x+2*radius; i++) {
        for (int j = frame.position.y; j<frame.position.y+2*radius; j++) {
            // i,j távolsága 200,200-tól
            double d = sqrt((i-2*radius)*(i-2*radius) + (j-2*radius)*(j-2*radius));
            if (d < radius) {
                gout << move_to(i, j) << dot;
            }
        }
    }
}
void Dott::setState(dotState _dotState){
    state = _dotState;
}
