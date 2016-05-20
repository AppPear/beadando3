#include "dot.h"
#include <cmath>

using namespace genv;

extern const int windowWidth;
extern const int windowHeight;
extern const color backround;
extern const color playerOne;
extern const color playerTwo;
extern const color emptyColor;
extern const int boxSize;


Dott::Dott():boxy(CGRect(0,0,0,0)){

}
Dott::Dott(CGRect _frame):boxy(_frame){
    //radius = frame.r_size.width/2;
    radius = (boxSize-15);
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
    // 200 �tm�r�j�, 200,200 k�z�ppont� k�rt akarunk rajzolni
    // ez 100,100-n�l kezd�d� 200x200-as n�gyzetbe esik, ez�rt ennek a
    // n�gyzetnek a pontjain megy�nk v�gig
    /*for (int i = frame.position.x; i<frame.position.x+2*radius; i++) {
        for (int j = frame.position.y; j<frame.position.y+2*radius; j++) {
            // i,j t�vols�ga 200,200-t�l
            double d = sqrt((i-frame.position.x+radius)*(i-frame.position.x+radius) + (j-frame.position.y+radius)*(j-frame.position.y+radius));
            if (d < radius) {
                gout << move_to(i, j) << dot;
            }
        }
    }*/
    gout<<move_to(frame.position.x,frame.position.y) << box(radius,radius);
}
void Dott::setCoulmnIndex(int c, int i){
    column = c;
    index = i;
}

void Dott::setState(dotState _dotState){
    state = _dotState;
}
