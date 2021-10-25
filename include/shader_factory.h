#ifndef SHADER_FACTORY_H
#define SHADER_FACTORY_H

#include <map>
#include "factory_type.h"

namespace Graphics {
    class Shader;
}

namespace Factory {

    class ShaderFactory {
        public:


            Graphics::Shader* get_shader(const ShaderType& type);

            static ShaderFactory* get_instance();


        private:
            ShaderFactory();
            static ShaderFactory* m_instance;

            void load_shaders();


            std::map<ShaderType, Graphics::Shader*> shader_list;


    };
};


#endif
