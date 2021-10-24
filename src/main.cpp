#include <iostream>
#include "window.h"
#include "const.h"
#include "mesh_factory.h"

int main(int argc, char** argv) {
    /*
    std::string map_path;

    if(argc > 1) 
        map_path = argv[1];
    else
        map_path = "../maps/data.txt";

    std::cout << "loading map : " << map_path << "\n";

    Graphics::Window window(map_path, Const::WIDTH, Const::HEIGHT);
    window.run();
    */

    Factory::MeshFactory::GetInstance();
    return 0;
}
