#ifndef CUBE_H
#define CUBE_H

#include "entity.h"
#include <string>

namespace Cube {
    class Mesh : Graphics::Mesh {
        public:
            Mesh(const std::string& texture_path);
            void draw();
    };

};

#endif
