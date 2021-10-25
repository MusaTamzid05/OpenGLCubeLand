#ifndef MESH_FACTORY_H
#define MESH_FACTORY_H


#include <map>
#include "factory_type.h"

namespace Graphics {
    class Mesh;
};

namespace Factory {

    class MeshFactory {
        public:


            static MeshFactory* GetInstance();
            Graphics::Mesh* get_mesh(const MeshType& type) ;

        private:
            MeshFactory();
            static MeshFactory* m_instance;

            std::map<MeshType, Graphics::Mesh*> mesh_list;
    };
}

#endif
