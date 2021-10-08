#include <iostream>
#include "window.h"
#include "const.h"

int main(int argc, char** argv) {
    Graphics::Window window(Const::WIDTH, Const::HEIGHT);
    window.run();
    return 0;
}
