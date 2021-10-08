#ifndef ENTITY_H
#define ENTITY_H

#include <string>

namespace Graphics {
    class Shader;

    class Mesh {
        public:
            Mesh(const std::string& texture_path = "") {}
            virtual void draw() = 0;

            virtual bool load_texture(const std::string& texture_path);

            unsigned int VAO;
            unsigned int VBO;
            unsigned int texture_id;

    };

    class Entity {
        public:
            Entity(Shader* shader, Mesh* mesh);;

            virtual void draw() = 0;

        protected:
            Shader* m_shader;
            Mesh* m_mesh;

    };
}

#endif
