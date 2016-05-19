#include "Application.h"
#include <fstream>
#include "dot.h"
using namespace std;
using namespace genv;

extern const int windowWidth;
extern const int windowHeight;
extern const color backround = color(61,189,148);
extern const color playerOne = color(253,186,2);
extern const color playerTwo = color(239,36,14);
extern const color emptyColor = color(255,255,255);
const int rows = 6;
const int columns = 7;

Application::Application()
{
    for(unsigned int i = 0; i < columns;i++)
}

void Application::fuss(){
    gout.open(windowWidth,windowHeight);
    gin.timer(16);

    event ev;
    while (gin >> ev) {
            if (ev.type == ev_timer){
                gout << backround << move_to(0,0)<<box(windowWidth,windowHeight);
                for(unsigned int i = 0; i < widgets.size(); i++){
                    widgets[i]->handle(ev);
                    widgets[i]->draw();
                }
                gout<<refresh;

            }
    }
}
