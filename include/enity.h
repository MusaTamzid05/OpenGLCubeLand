#ifndef ENTITY_H
#define ENTITY_H

namespace Graphics {
    class Shader;

    class Mesh {
        public:
            Mesh() {}
            virtual void draw() = 0;

            unsigned int VAO;
            unsigned int VBO;

    };

    class Enity {
        public:
            Enity(Shader* shader, Mesh* mesh);;

            virtual void draw() = 0;

        protected:
            Shader* m_shader;
            Mesh* m_mesh;

    };
}

#endif
