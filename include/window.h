#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "world_loader.h"


namespace Graphics { 
    class Entity;
    class Camera;


    class Window  {
        public:
            Window(
                    int x_axis,
                    int z_axis,
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
            void load_world(int x_axis, int z_axis);

            void handle_input();
            void update();
            void update_fps();



            int width;
            int height;
            bool window_loaded;

            GLFWwindow* m_window;

            static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
            static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
            static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

            std::vector<Entity*> m_entities;
            static Camera* m_camera;


            static float last_x;
            static float last_y;
            static bool first_mouse;

            float delta_time;
            float last_frame;

            std::vector<CubeData> cube_data;


    };

}

#endif
