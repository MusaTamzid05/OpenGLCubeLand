#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <glm/glm.hpp>

namespace Graphics {
    class Shader;

    class Mesh {
        public:
            Mesh(const std::string& texture_path = "");
            virtual void draw() = 0;

            virtual bool load_texture(const std::string& texture_path);

            unsigned int VAO;
            unsigned int VBO;
            unsigned int texture_id;

    };

    class Entity {
        public:
            Entity(Shader* shader = nullptr, Mesh* mesh = nullptr,
                    const glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f)
                    );
            virtual void load_shader_defaults(const glm::vec3 pos);

            virtual void draw() = 0;

            Shader* m_shader;
            Mesh* m_mesh;

    };
}

#endif
