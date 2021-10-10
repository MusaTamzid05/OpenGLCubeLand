#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Graphics { 
    class Entity;

    class Window  {
        public:
            Window(
                int width = 640,
                int height = 480,
                const std::string& title = "Window"
                    );

            virtual ~Window();

            void run();
            void render();

        private:
            void init_lib() const;
            bool init_window(const std::string& title);

            void handle_input();
            void update();



            int width;
            int height;
            bool window_loaded;

            GLFWwindow* m_window;

            static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

            std::vector<Entity*> m_entities;
    };

}

#endif
