#include "shader_factory.h"
#include "shader.h"

namespace Factory {
    ShaderFactory* ShaderFactory::m_instance = nullptr;

    ShaderFactory::ShaderFactory() {
        load_shaders();
    }


    ShaderFactory* ShaderFactory::get_instance() {
        if(m_instance == nullptr)
            m_instance = new ShaderFactory();

        return m_instance;
    }

    void ShaderFactory::load_shaders() {

        shader_list.insert(std::pair<ShaderType, Graphics::Shader*>(CubeShader, new Graphics::Shader("../shaders/cube.vs", "../shaders/cube.fs")));

    }


    Graphics::Shader* ShaderFactory::get_shader(const ShaderType& type) {
        return shader_list[type];
    }
}


