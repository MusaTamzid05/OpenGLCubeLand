#include "mesh_factory.h"

namespace Factory {
    MeshFactory* MeshFactory::m_instance = nullptr;

    MeshFactory* MeshFactory::GetInstance() {
        if(m_instance == nullptr)
            m_instance = new MeshFactory();

        return m_instance;
    }
}
