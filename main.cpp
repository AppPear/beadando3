#include "Application.h"

using namespace std;
extern const int windowWidth = 800;
extern const int windowHeight = 600;


int main()
{
    Application *app = new Application();
    app->fuss();
    return 0;
}
