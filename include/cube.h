#ifndef CUBE_H
#define CUBE_H

#include "entity.h"
#include <string>

namespace Cube {
    class Mesh : public  Graphics::Mesh {
        public:
            Mesh(const std::string& texture_path);
            void draw();
    };


    class Cube : public Graphics::Entity {
        public:
            Cube(const glm::vec3& pos, const std::string& texture_path = "../textures/container.jpg");
            void draw();
    };


};

#endif
