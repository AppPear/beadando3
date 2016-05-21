#include "Application.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include "textWidget.h"
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
    textWidget *one = new textWidget(CGRect(8,50,80,60),"ONE",playerOne);
    widgets.push_back(one);
    textWidget *two = new textWidget(CGRect(688,50,80,60),"TWO",playerTwo);
    widgets.push_back(two);

}
void placeDottInColumn(vector<vector<Dott*>>&dots, int column, dotState state){
    int minIndex = dots[column].size();
    for(unsigned int i = 0; i < dots[column].size();i++){
        if(dots[column][i]->getState() == allWhite && dots[column][i]->getIndex()< minIndex){
            minIndex = i;
        }
    }
    if(minIndex >= 0 &&minIndex < 7){
        dots[column][minIndex]->setState(state);
    }
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
dotState checkIfSomeBodyWon(vector<vector<Dott*>>&dots){
    ///check rows
    int counter = 0;
    dotState newDot;
    dotState oldDot;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns;j++){
            newDot = dots[j][i]->getState();
            if(newDot == oldDot && newDot != allWhite){
                counter++;
            }else{
                counter = 0;
            }
            if(counter > 2){
                return newDot;
            }
            oldDot = newDot;
        }
        counter = 0;
    }

    ///check columns
    newDot = allWhite;
    oldDot = allWhite;
    counter = 0;
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows;j++){
            newDot = dots[i][j]->getState();
            if(newDot == oldDot && newDot != allWhite){
                counter++;
            }else{
                counter = 0;
            }
            if(counter > 2){
                return newDot;
            }
            oldDot = newDot;

        }
        counter = 0;
    }
    ///check diagonals
    newDot = allWhite;
    oldDot = allWhite;
    counter = 0;
    for(int i = 3; i < 6; i++){
        for(int j = 0; j < i+1;j++){
            //cout<<"("<<j+1<<","<<i+1-j<<") ";
            newDot = dots[i-j][j]->getState();
            if(newDot == oldDot && newDot != allWhite){
            counter++;
            }else{
                counter = 0;
            }
            if(counter > 2){
                return newDot;
            }
                oldDot = newDot;
            }
            counter = 0;
    }

    newDot = allWhite;
    oldDot = allWhite;
    counter = 0;
    for(int i = 2; i >= 0; i--){
        for(int j = 6; j > i;j--){
            //cout<<"("<<j<<","<<i+1-j+7<<") ";
            newDot = dots[i-j+7][j-1]->getState();
            if(newDot == oldDot && newDot != allWhite){
            counter++;
            }else{
                counter = 0;
            }
            if(counter > 2){
                return newDot;
            }
                oldDot = newDot;
            }
            counter = 0;
    }
    ///check antidiagonals
    newDot = allWhite;
    oldDot = allWhite;
    counter = 0;
    for(int i = 3; i < 6; i++){
        for(int j = 0; j < i+1;j++){
            //cout<<"("<<j+1<<","<<j+6-i+1<<") ";
            newDot = dots[j+6-i][j]->getState();
            if(newDot == oldDot && newDot != allWhite){
            counter++;
            }else{
                counter = 0;
            }
            if(counter > 2){
                return newDot;
            }
                oldDot = newDot;
            }
            counter = 0;

    }

    newDot = allWhite;
    oldDot = allWhite;
    counter = 0;
    for(int i = 3; i < 6; i++){
        for(int j = 0; j < i+1;j++){
            //cout<<"("<<j+6-i<<","<<j+1<<") ";
            newDot = dots[j][j+5-i]->getState();
            if(newDot == oldDot && newDot != allWhite){
            counter++;
            }else{
                counter = 0;
            }
            if(counter > 2){
                return newDot;
            }
                oldDot = newDot;
            }
            counter = 0;
    }


    return allWhite;
}
void Application::fuss(){
    gout.open(windowWidth,windowHeight);
    gin.timer(100);

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
                if(ev.type == ev_timer){
                    if(checkIfSomeBodyWon(dotWidgets) != allWhite){
                        switch(checkIfSomeBodyWon(dotWidgets)){
                        case ONEgotit:
                            if(dotWidgets.size() > 0){
                                dotWidgets.clear();
                                textWidget *one = new textWidget(CGRect(200,380,160,60),"player ONE won",color(255,255,255));
                                widgets.push_back(one);
                            }
                        break;
                        case TWOgotit:
                            if(dotWidgets.size() > 0){
                                dotWidgets.clear();
                                textWidget *one = new textWidget(CGRect(200,320,160,60),"player TWO won",color(255,255,255));
                                widgets.push_back(one);
                            }
                        break;
                        }
                    }
                }

    }
}
