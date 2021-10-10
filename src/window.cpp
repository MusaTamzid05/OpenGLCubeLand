#include "window.h"
#include "cube.h"


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Graphics {

    Window::Window(
        int width,
        int height,
        const std::string& title 
        ):width(width), height(height), window_loaded(false) {

        init_lib();

        if(!init_window(title)) {
            std::cerr << "Could not load window.\n";
            return;
        }
        window_loaded = true;
        glEnable(GL_DEPTH_TEST);

        m_entities.push_back(new Cube::Cube(glm::vec3(0.0, 0.0, 0.0)));
        m_entities.push_back(new Cube::Cube(glm::vec3(-1.0, 0.0, 0.0)));

    }

    Window::~Window() {
        glfwTerminate();
    }

    void Window::init_lib() const  {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    }

    bool Window::init_window(const std::string& title) {
        m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		if (m_window == nullptr) {
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
            return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
            return false;
		}

        return true;

    }

    void Window::run() {
        if(!window_loaded) {
            std::cerr << "Cannot run window without loading!!\n";
            return;
        }

        while(!glfwWindowShouldClose(m_window)) {
            handle_input();
            render();
            update();

        }
    }

    void Window::render() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for(Entity* enity : m_entities)
            enity->draw();

    }

    void Window::handle_input() {
		if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window, true);
    }

    void Window::update() {
        glfwSwapBuffers(m_window);
        glfwPollEvents();

    }

    void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }
}
