#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window();
    Window(const Window&) = delete;
    ~Window();

    void Update();

    int ShouldClose() const { return glfwWindowShouldClose(window_); }
private:
    GLFWwindow* window_;
};
