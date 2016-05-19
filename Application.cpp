#include "Application.h"
#include <fstream>

using namespace std;
using namespace genv;

extern const int windowWidth;
extern const int windowHeight;

Application::Application()
{

}

void Application::fuss(){
    gout.open(windowWidth600);

    event ev;
    while (gin >> ev) {
        for(unsigned int i = 0; i < widgets.size(); i++){
            widgets[i]->handle(ev);
            widgets[i]->draw();
            gout<<refresh;
        }
        if(ev.type == ev_key){
            if(ev.keycode == key_space){
                this->writeToFile();
            }
        }
    }
}
