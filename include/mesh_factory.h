#ifndef MESH_FACTORY_H
#define MESH_FACTORY_H

namespace Factory {

    class MeshFactory {
        public:
            static MeshFactory* GetInstance();

        private:
            MeshFactory() {}
            static MeshFactory* m_instance;
    };
}

#endif
