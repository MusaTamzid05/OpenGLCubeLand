#include "window.h"
#include "cube.h"
#include "const.h"
#include "camera.h"
#include "file_world_loader.h"
#include "perlin_world_loader.h"


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Graphics {

    bool Window::first_mouse = true;
    float Window::last_x = Const::WIDTH / 2;
    float Window::last_y = Const::HEIGHT / 2;
    Camera* Window::m_camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));

    Window::Window(
        int x_axis,
        int z_axis,
        int width,
        int height,
        const std::string& title 
        ):width(width), height(height), window_loaded(false), 
    delta_time(0.0f), last_frame(0.0) {

        init_lib();

        if(!init_window(title)) {
            std::cerr << "Could not load window.\n";
            return;
        }

        window_loaded = true;
        glEnable(GL_DEPTH_TEST);

        load_world(x_axis, z_axis);


        for(CubeData data : cube_data)
            m_entities.push_back(new Cube::Cube(
                        glm::vec3(
                            data.x_axis,
                            data.y_axis,
                            data.z_axis),
                        Factory::TextureFactory::Type::Container
                        ));

        std::cout << "Total entities : " << m_entities.size() << "\n";


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
        glfwSetCursorPosCallback(m_window, mouse_callback);
        glfwSetScrollCallback(m_window, scroll_callback);

        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
            return false;
		}

        return true;

    }

    void Window::load_world(int x_axis, int z_axis) {
        WorldLoader* m_world_loader = new PerlinWorldLoader(x_axis, z_axis);
        cube_data = m_world_loader->run();
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

        if(glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
            m_camera->ProcessKeyboard(FORWARD, delta_time);

        if(glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
            m_camera->ProcessKeyboard(BACKWARD, delta_time);

        if(glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
            m_camera->ProcessKeyboard(LEFT, delta_time);

        if(glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
            m_camera->ProcessKeyboard(RIGHT, delta_time);


    }

    void Window::update() {
        update_fps();

        for(Entity* entity : m_entities)
            entity->update(m_camera);

        glfwSwapBuffers(m_window);
        glfwPollEvents();

    }

    void Window::update_fps() {
        float current_frame = glfwGetTime();
        delta_time = current_frame - last_frame;
        last_frame = current_frame;
    }

    void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void Window::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
        if(first_mouse) {
            last_x = xpos;
            last_y = ypos;
            first_mouse = false;
        }

        float xoffset = xpos - last_x;
        float yoffset = last_y - ypos;

        last_x = xpos;
        last_y = ypos;

        m_camera->ProcessMouseMovement(xoffset, yoffset);
    }

    void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
        m_camera->ProcessMouseScroll(yoffset);
    }
}
