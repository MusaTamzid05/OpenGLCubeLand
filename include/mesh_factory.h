#ifndef MESH_FACTORY_H
#define MESH_FACTORY_H


#include <map>

namespace Graphics {
    class Mesh;
};

namespace Factory {

    class MeshFactory {
        public:

            enum Type {
                Cube
            };

            static MeshFactory* GetInstance();
            Graphics::Mesh* get_mesh(const Type& type) ;

        private:
            MeshFactory();
            static MeshFactory* m_instance;

            std::map<Type, Graphics::Mesh*> mesh_list;
    };
}

#endif
