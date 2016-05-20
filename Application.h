#ifndef APPLICATION_H
#define APPLICATION_H
#include <vector>
#include "box.h"
#include "graphics.hpp"

class Application
{
    public:
        Application();
        std::vector<std::vector<boxy *>> dotWidgets;
        std::vector<boxy *> widgets;
        void fuss();

    protected:

    private:
};

#endif // APPLICATION_H
