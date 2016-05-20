#ifndef APPLICATION_H
#define APPLICATION_H
#include <vector>
#include "box.h"
#include "graphics.hpp"
#include "dot.h"
#include "indicatorArrow.h"

class Application
{
    public:
        Application();
        indicatorArrow *arrow;
        std::vector<std::vector<Dott *>> dotWidgets;
        std::vector<boxy *> widgets;
        void fuss();
    protected:

    private:

};

#endif // APPLICATION_H
