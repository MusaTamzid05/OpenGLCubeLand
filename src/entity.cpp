#include "entity.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "shader.h"
#include "const.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

namespace Graphics {

    Mesh::Mesh(const std::string& texture_path):texture_id(0) {

    }


    bool Mesh::load_texture(const std::string& texture_path) {
        std::cout << "Current texture id " << texture_id << "\n";
		glGenTextures(1, &texture_id);
		glBindTexture(GL_TEXTURE_2D, texture_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
		unsigned char *data = stbi_load(texture_path.c_str(), &width, &height, &nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "Failed to load texture" << std::endl;
            return false;
		}
        std::cout << "texture loaded.\n";

		stbi_image_free(data);


        std::cout << "After texture id " << texture_id << "\n";
        return true;

    }


    Entity::Entity(Shader* shader, Mesh* mesh, const  glm::vec3 pos):m_shader(shader), m_mesh(mesh) {}


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



}
