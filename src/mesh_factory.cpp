#include "mesh_factory.h"
#include "entity.h"
#include "cube.h"
#include <iostream>

namespace Factory {
    MeshFactory* MeshFactory::m_instance = nullptr;

    MeshFactory::MeshFactory() {
        mesh_list.insert(std::pair<MeshType, Graphics::Mesh*>(MeshType::Cube, new Cube::Mesh("../textures/container.jpg")));

    }

    MeshFactory* MeshFactory::GetInstance() {
        if(m_instance == nullptr)
            m_instance = new MeshFactory();

        return m_instance;
    }


    Graphics::Mesh* MeshFactory::get_mesh(const MeshType& type) {
        return mesh_list[type];
    }
}
