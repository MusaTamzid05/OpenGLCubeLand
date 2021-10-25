#include "texture_factory.h"



#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Factory {
    TextureFactory* TextureFactory::m_instance = nullptr;

    TextureFactory::TextureFactory() {
        load_textures();

    }

    void TextureFactory::load_textures() {
        texture_list.insert(std::pair<TextureType, unsigned int>(Container, load_texture("../textures/container.jpg")));
        texture_list.insert(std::pair<TextureType, unsigned int>(Container, load_texture("../textures/bricks2.jpg")));

    }


    unsigned int TextureFactory::load_texture(const std::string& texture_path) const {
        unsigned int texture_id;
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

		stbi_image_free(data);


        return true;


    }

    unsigned int TextureFactory::get_texture(const TextureType& type) {
        return texture_list[type];
    }

    TextureFactory* TextureFactory::get_instance() {
        if(m_instance == nullptr)
            m_instance = new TextureFactory();

        return m_instance;
    }
}
