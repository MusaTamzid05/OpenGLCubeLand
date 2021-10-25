#include "entity.h"
#include "camera.h"


#include "shader.h"
#include "const.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

namespace Graphics {

    Mesh::Mesh() {

    }


    Entity::Entity(Shader* shader, Mesh* mesh, const  glm::vec3 pos):m_shader(shader), m_mesh(mesh), pos(pos) {}


    void Entity::load_shader_defaults(const glm::vec3 pos) {

        if(m_shader == nullptr) {
            std::cerr << "No shader loaded yet.";
            return;
        }



        m_shader->use();

        glm::mat4 view = glm::mat4(1.0f); 
        glm::mat4 projection    = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f), (float)Const::WIDTH/ (float)Const::HEIGHT, 0.1f, 100.0f);
        view       = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        
        m_shader->setMat4("projection", projection); 
        m_shader->setMat4("view", view);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, pos);

        m_shader->setMat4("model", model);


    }

    void Entity::update(Camera* camera) {
        update_camera_view(camera);
        update_pos();

    }

    void Entity::update_camera_view(Camera* camera) {
        glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom),
                (float)Const::WIDTH / (float)Const::HEIGHT,
                 0.1f,
                 100.0f);

        glm::mat4 view = camera->GetViewMatrix();

        m_shader->use();

        m_shader->setMat4("projection", projection);
        m_shader->setMat4("view", view);

    }

    void Entity::update_pos() {
        m_shader->use();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, pos);
        m_shader->setMat4("model", model);


    }


}
