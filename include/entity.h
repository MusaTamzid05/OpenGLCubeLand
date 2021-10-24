#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <glm/glm.hpp>

namespace Graphics {
    class Shader;
    class Camera;

    class Mesh {
        public:
            Mesh();
            virtual void draw(unsigned int texture_id) = 0;


            unsigned int VAO;
            unsigned int VBO;

    };

    class Entity {
        public:
            Entity(Shader* shader = nullptr, Mesh* mesh = nullptr,
                    const glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f)
                    );
            virtual void load_shader_defaults(const glm::vec3 pos);

            virtual void draw() = 0;
            virtual void update(Camera* camera);

            Shader* m_shader;
            Mesh* m_mesh;

            void update_camera_view(Camera* camera);

    };
}

#endif
