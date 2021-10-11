#include <iostream>
#include "window.h"
#include "const.h"

int main(int argc, char** argv) {

    std::string map_path;

    if(argc > 1) 
        map_path = argv[1];
    else
        map_path = "../maps/data.txt";

    std::cout << "loading map : " << map_path << "\n";

    Graphics::Window window(map_path, Const::WIDTH, Const::HEIGHT);
    window.run();
    return 0;
}
