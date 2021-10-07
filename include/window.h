#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Graphics { 

    class Window  {
        public:
            Window(
                int width = 640,
                int height = 480,
                const std::string& title = "Window"
                    );

            virtual ~Window();

            void run();

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
    };

}

#endif
