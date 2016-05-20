#ifndef INDICATORARROW_H
#define INDICATORARROW_H

#include "box.h"
#include "graphics.hpp"
#include "dot.h"

typedef enum{
    ONE,TWO
}player;

class indicatorArrow: public boxy
{
    public:
        indicatorArrow(CGRect _frame);
        virtual void handle(event ev);
        virtual void draw();
        void setPlayer(player nextPlayer);
        player getPlayer(){return CurrentPlayer;};
    protected:

    private:
        player CurrentPlayer;
};

#endif // INDICATORARROW_H
