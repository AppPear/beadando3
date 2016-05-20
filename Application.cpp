#include "Application.h"
#include <fstream>
#include "dot.h"
#include <iostream>
using namespace std;
using namespace genv;

extern const int windowWidth = 800;
extern const int windowHeight = 620;
const int edge = 110;
extern const int boxSize = 85;
extern const color backround = color(61,189,148);
extern const color playerOne = color(253,186,2);
extern const color playerTwo = color(239,36,14);
extern const color emptyColor = color(255,255,255);
const int rows = 6;
const int columns = 7;

Application::Application()
{
    for(unsigned int i = 0; i < columns;i++){
        vector<boxy *> columnVector;
        for(unsigned int j = 0; j < rows; j++){
            Dott *potty = new Dott(CGRect(edge+i*boxSize,edge+j*boxSize,boxSize,boxSize));
            potty->setState(allWhite);
            columnVector.push_back(potty);
        }
        dotWidgets.push_back(columnVector);
        columnVector.clear();
    }
}

void Application::fuss(){
    gout.open(windowWidth,windowHeight);
    gin.timer(16);

    event ev;
    while (gin >> ev) {
            if (ev.type == ev_timer){
                gout << backround << move_to(0,0)<<box(windowWidth,windowHeight);

                for(unsigned int i = 0; i< dotWidgets.size(); i++){
                    vector<boxy*> temp = dotWidgets[i];
                    for(unsigned int j = 0; j < temp.size(); j++){
                        temp[j]->handle(ev);
                        temp[j]->draw();
                    }
                }
                for(unsigned int i = 0; i < widgets.size(); i++){
                    widgets[i]->handle(ev);
                    widgets[i]->draw();
                }
                gout<<refresh;

            }
    }
}
