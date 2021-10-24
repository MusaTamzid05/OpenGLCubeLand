#include "mesh_factory.h"
#include "entity.h"
#include "cube.h"

namespace Factory {
    MeshFactory* MeshFactory::m_instance = nullptr;

    MeshFactory::MeshFactory() {
        mesh_list.insert(std::pair<Type, Graphics::Mesh*>(Type::Cube, new Cube::Mesh("../textures/container.jpg")));

    }

    MeshFactory* MeshFactory::GetInstance() {
        if(m_instance == nullptr)
            m_instance = new MeshFactory();

        return m_instance;
    }


    Graphics::Mesh* MeshFactory::get_mesh(const Type& type) {
        return mesh_list[type];
    }
}
