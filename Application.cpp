#include "Application.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace genv;

extern const int windowWidth = 800;
extern const int windowHeight = 620;
extern const int edge = 110;
extern const int boxSize = 85;
extern const color backround = color(61,189,148);
extern const color playerOne = color(253,186,2);
extern const color playerTwo = color(239,36,14);
extern const color emptyColor = color(255,255,255);
const int rows = 6;
extern const int columns = 7;

Application::Application()
{
    for(unsigned int i = 0; i < columns;i++){
        vector<Dott *> columnVector;
        for(unsigned int j = 0; j < rows; j++){
            Dott *potty = new Dott(CGRect(edge+i*boxSize,edge+j*boxSize,boxSize,boxSize));
            potty->setState(allWhite);
            potty->setCoulmnIndex(i,j-rows);
            columnVector.push_back(potty);
        }
        dotWidgets.push_back(columnVector);
        columnVector.clear();
    }
    arrow = new indicatorArrow(CGRect(edge,edge-boxSize,boxSize-15, boxSize-15));
    widgets.push_back(arrow);
}
void placeDottInColumn(vector<vector<Dott*>>&dots, int column, dotState state){
    int minIndex = dots[column].size();
    for(unsigned int i = 0; i < dots[column].size();i++){
        if(dots[column][i]->getState() == allWhite && dots[column][i]->getIndex()< minIndex){
            minIndex = i;
        }
    }
    cout<<minIndex<<endl;
    dots[column][minIndex]->setState(state);
}
int witchColumn(int x){
    int column = (x-edge)/boxSize;
    if(column < 0){
        column = 0;
    }
    if(column > columns-1){
        column = columns-1;
    }
    return column;
}

void Application::fuss(){
    gout.open(windowWidth,windowHeight);
   // gin.timer(16);

    event ev;
    while (gin >> ev) {
                gout << backround << move_to(0,0)<<box(windowWidth,windowHeight);

                for(unsigned int i = 0; i< dotWidgets.size(); i++){
                    vector<Dott *> temp = dotWidgets[i];
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
                if(ev.type == ev_mouse){
                    if(ev.button == btn_left){
                        dotState dState = allWhite;
                        switch(arrow->getPlayer()){
                        case ONE:
                            dState = TWOgotit;
                            break;
                        case TWO:
                            dState = ONEgotit;
                            break;
                        }
                        placeDottInColumn(dotWidgets,witchColumn(ev.pos_x),dState);
                    }
                }

    }
}
