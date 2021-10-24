#ifndef CUBE_H
#define CUBE_H

#include "entity.h"
#include "texture_factory.h"

#include <string>

namespace Cube {
    class Mesh : public  Graphics::Mesh {
        public:
            Mesh(const std::string& texture_path);
            void draw(unsigned int texture_id);
    };


    class Cube : public Graphics::Entity {
        public:
            Cube(const glm::vec3& pos, const Factory::TextureFactory::Type& = Factory::TextureFactory::Container);
            void draw();

            Factory::TextureFactory::Type type;

            unsigned int texture_id;
    };


};

#endif
