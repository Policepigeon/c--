#include <GLFW/glfw3.h>
#include <iostream>

// Function to handle button clicks
void on_click(GLFWbutton* button, int action) {
    if (action == GLFW_PRESS) {
        std::cout << "Button clicked!" << std::endl;
    }
}

int main() {
    // Create a window
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(640, 480, "Button Demo", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        return -1;
    }

    // Create a button
    GLFWbutton* button = glfwCreateButton(GLFW_BUTTON_LEFT, 50, 50, 100, 20);
    if (!button) {
        std::cerr << "Failed to create button" << std::endl;
        return -1;
    }

    // Set the button's label and callback function
    glfwSetButtonLabel(button, "Click Me");
    glfwSetButtonCallback(button, on_click);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // Clean up
    glfwDestroyButton(button);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
