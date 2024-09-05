#include <iostream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std; 

// some vertex and fragment shit idk
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";


int main()
{
    // initializing glfw
    glfwInit();


    // some essential information about software used(like the version ext.)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
	};

    // creating the window
    GLFWwindow* window = glfwCreateWindow(800, 800, "Hello", NULL, NULL);
    if(window == NULL) {
        cout << "Failed to create a window!" << endl;
        glfwTerminate();
        return -1;
    }

    // context?
    glfwMakeContextCurrent(window);


    // using glad to do some visual stuff
    gladLoadGL();

    glViewport(0,0,800,800);

    glClearColor(0.07f, 0.16f, 0.12f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);


    // keeping the window open
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    // closing the window and terminating the program
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}