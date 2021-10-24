#include <iostream>
#include "window.h"
#include "const.h"
#include "mesh_factory.h"

int main(int argc, char** argv) {

    int x_axis;
    int z_axis;

    if(argc != 3)  {
        x_axis = 10;
        z_axis= 10;
    } else {
        x_axis = atoi(argv[1]);
        z_axis = atoi(argv[2]);
    }

    std::cout << "x_axis : " << x_axis << " z_axis : " << z_axis << "\n";

    Graphics::Window window(x_axis, z_axis, Const::WIDTH, Const::HEIGHT);
    window.run();

    return 0;
}
