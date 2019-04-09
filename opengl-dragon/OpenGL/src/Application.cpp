#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

// Shader sources
const GLchar* vertexSource = R"glsl(
    #version 150 core
    in vec2 position;
    in vec3 color;
    out vec3 Color;
    void main()
    {
        Color = color;
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";
const GLchar* fragmentSource = R"glsl(
    #version 150 core
    in vec3 Color;
    out vec4 outColor;
    void main()
    {
        outColor = vec4(Color, 1.0);
    }
)glsl";

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "NAGA", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;
	std::cout << "Status: Using OpenGL " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;

	// Create Vertex Array Object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create a Vertex Buffer Object and copy the vertex data to it
	GLuint vbo;
	glGenBuffers(1, &vbo);

	GLfloat vertices[] = {
		0.16f, -0.62f, 1.0f, 0.0f, 0.0f,
		0.19f, -0.58f, 1.0f, 0.0f, 0.0f,
		0.19f, -0.66f, 1.0f, 0.0f, 0.0f,

		0.19f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.19f, -0.71f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.74f, 1.0f, 0.0f, 0.0f,

		0.19f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.74f, 1.0f, 0.0f, 0.0f,

		0.22f, -0.74f, 1.0f, 0.0f, 0.0f,
		0.27f, -0.73f, 1.0f, 0.0f, 0.0f,
		0.25f, -0.71f, 1.0f, 0.0f, 0.0f,

		0.25f, -0.71f, 1.0f, 0.0f, 0.0f,
		0.27f, -0.73f, 1.0f, 0.0f, 0.0f,
		0.29f, -0.71f, 1.0f, 0.0f, 0.0f,

		0.25f, -0.71f, 1.0f, 0.0f, 0.0f,
		0.29f, -0.71f, 1.0f, 0.0f, 0.0f,
		0.27f, -0.69f, 1.0f, 0.0f, 0.0f,

		0.22f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.74f, 1.0f, 0.0f, 0.0f,
		0.25f, -0.71f, 1.0f, 0.0f, 0.0f,

		0.22f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.25f, -0.71f, 1.0f, 0.0f, 0.0f,
		0.27f, -0.69f, 1.0f, 0.0f, 0.0f,

		0.22f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.27f, -0.69f, 1.0f, 0.0f, 0.0f,
		0.25f, -0.63f, 1.0f, 0.0f, 0.0f,

		0.19f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.63f, 1.0f, 0.0f, 0.0f,

		0.22f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.63f, 1.0f, 0.0f, 0.0f,
		0.25f, -0.63f, 1.0f, 0.0f, 0.0f,

		0.22f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.25f, -0.63f, 1.0f, 0.0f, 0.0f,
		0.27f, -0.69f, 1.0f, 0.0f, 0.0f,

		0.27f, -0.69f, 1.0f, 1.0f, 0.0f,
		0.29f, -0.71f, 1.0f, 1.0f, 0.0f,
		0.29f, -0.56f, 1.0f, 1.0f, 0.0f,

		0.16f, -0.62f, 1.0f, 0.0f, 0.0f,
		0.19f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.63f, 1.0f, 0.0f, 0.0f,

		0.19f, -0.58f, 1.0f, 0.0f, 0.0f,
		0.16f, -0.62f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.63f, 1.0f, 0.0f, 0.0f,

		0.19f, -0.58f, 1.0f, 0.0f, 0.0f,
		0.25f, -0.63f, 1.0f, 0.0f, 0.0f,
		0.29f, -0.56f, 1.0f, 0.0f, 0.0f,

		0.19f, -0.58f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.56f, 1.0f, 0.0f, 0.0f,
		0.29f, -0.56f, 1.0f, 0.0f, 0.0f,

		0.19f, -0.58f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.56f, 1.0f, 0.0f, 0.0f,
		0.20f, -0.53f, 1.0f, 0.0f, 0.0f,

		0.27f, -0.69f, 1.0f, 0.0f, 0.0f,
		0.25f, -0.63f, 1.0f, 0.0f, 0.0f,
		0.29f, -0.56f, 1.0f, 0.0f, 0.0f,

		0.20f, -0.53f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.56f, 1.0f, 0.0f, 0.0f,
		0.29f, -0.56f, 1.0f, 0.0f, 0.0f,

		0.20f, -0.53f, 1.0f, 0.0f, 0.0f,
		0.29f, -0.56f, 1.0f, 0.0f, 0.0f,
		0.27f, -0.46f, 1.0f, 0.0f, 0.0f,

		0.29f, -0.56f, 1.0f, 1.0f, 0.0f,
		0.27f, -0.46f, 1.0f, 1.0f, 0.0f,
		0.37f, -0.55f, 1.0f, 1.0f, 0.0f,

		0.27f, -0.46f, 1.0f, 0.0f, 0.0f,
		0.37f, -0.55f, 1.0f, 0.0f, 0.0f,
		0.35f, -0.43f, 1.0f, 0.0f, 0.0f,

		0.37f, -0.55f, 1.0f, 1.0f, 0.0f,
		0.35f, -0.43f, 1.0f, 1.0f, 0.0f,
		0.41f, -0.43f, 1.0f, 1.0f, 0.0f,

		0.37f, -0.55f, 1.0f, 0.0f, 0.0f,
		0.41f, -0.43f, 1.0f, 0.0f, 0.0f,
		0.41f, -0.57f, 1.0f, 0.0f, 0.0f,

		0.41f, -0.43f, 1.0f, 1.0f, 0.0f,
		0.41f, -0.57f, 1.0f, 1.0f, 0.0f,
		0.45f, -0.43f, 1.0f, 1.0f, 0.0f,

		0.19f, -0.58f, 1.0f, 0.0f, 0.0f,
		0.22f, -0.66f, 1.0f, 0.0f, 0.0f,
		0.29f, -0.56f, 1.0f, 0.0f, 0.0f,

		0.41f, -0.57f, 1.0f, 1.0f, 0.0f,
		0.45f, -0.43f, 1.0f, 1.0f, 0.0f,
		0.50f, -0.45f, 1.0f, 1.0f, 0.0f,

		0.50f, -0.45f, 1.0f, 0.0f, 0.0f,
		0.41f, -0.57f, 1.0f, 0.0f, 0.0f,
		0.53f, -0.48f, 1.0f, 0.0f, 0.0f,

		0.53f, -0.48f, 1.0f, 1.0f, 0.0f,
		0.41f, -0.57f, 1.0f, 1.0f, 0.0f,
		0.65f, -0.72f, 1.0f, 1.0f, 0.0f,

		0.53f, -0.48f, 1.0f, 0.0f, 0.0f,
		0.65f, -0.72f, 1.0f, 0.0f, 0.0f,
		0.73f, -0.60f, 1.0f, 0.0f, 0.0f,

		0.73f, -0.60f, 1.0f, 1.0f, 0.0f,
		0.65f, -0.72f, 1.0f, 1.0f, 0.0f,
		0.76f, -0.70f, 1.0f, 1.0f, 0.0f,

		0.73f, -0.60f, 1.0f, 0.0f, 0.0f,
		0.76f, -0.70f, 1.0f, 0.0f, 0.0f,
		0.93f, -0.69f, 1.0f, 0.0f, 0.0f,

		0.73f, -0.60f, 1.0f, 1.0f, 0.0f,
		0.93f, -0.69f, 1.0f, 1.0f, 0.0f,
		0.91f, -0.61f, 1.0f, 1.0f, 0.0f,

		0.93f, -0.69f, 1.0f, 0.0f, 0.0f,
		0.91f, -0.61f, 1.0f, 0.0f, 0.0f,
		1.10f, -0.64f, 1.0f, 0.0f, 0.0f,
		
		0.50f, -0.45f, 1.0f, 0.0f, 0.0f,
		0.53f, -0.21f, 1.0f, 1.0f, 0.0f,
		0.58f, -0.39f, 1.0f, 0.0f, 0.0f,

		0.53f, -0.21f, 1.0f, 1.0f, 0.0f,
		0.58f, -0.39f, 1.0f, 0.0f, 0.0f,
		0.86f, -0.05f, 1.0f, 1.0f, 0.0f,

		0.53f, -0.21f, 1.0f, 1.0f, 0.0f,
		0.58f, -0.39f, 1.0f, 0.0f, 0.0f,
		0.99f, -0.32f, 1.0f, 1.0f, 0.0f,

		0.53f, -0.21f, 1.0f, 1.0f, 0.0f,
		0.58f, -0.39f, 1.0f, 0.0f, 0.0f,
		0.83f, -0.48f, 1.0f, 0.0f, 0.0f,

		0.50f, -0.45f, 1.0f, 0.0f, 0.0f,
		0.33f, -0.21f, 1.0f, 1.0f, 0.0f,
		0.16f, -0.14f, 1.0f, 0.0f, 0.0f,

		0.31f, -0.26f, 1.0f, 1.0f, 0.0f,
		0.16f, -0.14f, 1.0f, 0.0f, 0.0f,
		0.52f, -0.2f, 1.0f, 1.0f, 0.0f,

		0.31f, -0.26f, 1.0f, 1.0f, 0.0f,
		0.16f, -0.14f, 1.0f, 0.0f, 0.0f,
		0.51f, -0.28f, 1.0f, 1.0f, 0.0f,

		0.41f, -0.57f, 1.0f, 0.0f, 0.0f,
		0.41f, -0.72f, 1.0f, 0.0f, 0.0f,
		0.76f, -0.70f, 1.0f, 0.0f, 0.0f,

		0.46f, -0.65f, 1.0f, 0.0f, 0.0f,
		0.47f, -0.80f, 1.0f, 0.0f, 0.0f,
		0.53f, -0.65f, 1.0f, 0.0f, 0.0f,

		0.47f, -0.80f, 1.0f, 0.0f, 0.0f,
		0.53f, -0.65f, 1.0f, 0.0f, 0.0f,
		0.54f, -0.77f, 1.0f, 0.0f, 0.0f,

		0.47f, -0.80f, 1.0f, 0.0f, 0.0f,
		0.54f, -0.77f, 1.0f, 0.0f, 0.0f,
		0.56f, -0.82f, 1.0f, 0.0f, 0.0f,

		0.54f, -0.77f, 1.0f, 0.0f, 0.0f,
		0.56f, -0.82f, 1.0f, 0.0f, 0.0f,
		0.60f, -0.80f, 1.0f, 0.0f, 0.0f,

		0.68f, -0.69f, 1.0f, 0.0f, 0.0f,
		0.74f, -0.68f, 1.0f, 0.0f, 0.0f,
		0.76f, -0.74f, 1.0f, 0.0f, 0.0f,

		0.68f, -0.69f, 1.0f, 0.0f, 0.0f,
		0.76f, -0.74f, 1.0f, 0.0f, 0.0f,
		0.70f, -0.76f, 1.0f, 0.0f, 0.0f,

		0.76f, -0.74f, 1.0f, 0.0f, 0.0f,
		0.70f, -0.76f, 1.0f, 0.0f, 0.0f,
		0.75f, -0.78f, 1.0f, 0.0f, 0.0f,

		0.76f, -0.74f, 1.0f, 0.0f, 0.0f,
		0.75f, -0.78f, 1.0f, 0.0f, 0.0f,
		0.80f, -0.75f, 1.0f, 0.0f, 0.0f
	};

	for (int i = 0; i < 153; i++) {
		for (int j = 0; j < 5; j++) {
			if (j == 0) {
				vertices[i * 5 + j] -= 0.6f;
			}
			else if (j == 1) {
				vertices[i * 5 + j] += 0.5f;
			}
			else if (j == 2) {
				vertices[i * 5 + j] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			}
			else if (j == 3) {
				vertices[i * 5 + j] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			}
			else if (j == 4) {
				vertices[i * 5 + j] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			}
		}
	}

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Create and compile the vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// Link the vertex and fragment shader into a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	//GLint posAttrib = 0;
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	// GLint colAttrib = 1;
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// draw points 0-3 from the currently bound VAO with current in-use shader
		glDrawArrays(GL_TRIANGLES, 0, 51*3);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}