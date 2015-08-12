#include "main.h"

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_Q && action == GLFW_PRESS)		//zoom in
		zoom += 0.1f;
	if (key == GLFW_KEY_Z && action == GLFW_PRESS)		//zoom out
		zoom -= 0.1f;

	if (key == GLFW_KEY_W && action == GLFW_PRESS)		//up
		ship->worldY += 0.1;
	if (key == GLFW_KEY_S && action == GLFW_PRESS)		//down
		ship->worldY -= 0.1;
	if (key == GLFW_KEY_A && action == GLFW_PRESS)		//left
		ship->worldX -= 0.1;
	if (key == GLFW_KEY_D && action == GLFW_PRESS)		//right
		ship->worldX += 0.1;
	

	if (key == GLFW_KEY_C && action == GLFW_PRESS)		//charge shields
		ship->shield.addCharge(0.5);
	if (key == GLFW_KEY_H && action == GLFW_PRESS)		//hit shields
		ship->shield.hit();
}

static void mouseButton_callback(GLFWwindow* window, int button, int action, int mods) {
    //if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
        //popup_menu();
}

void drawGrid() {
	glLoadIdentity();
	glBegin(GL_LINES);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(-1.f, 0.f);		glVertex2f(1.f, 0.f);
	glVertex2f(0.f, -1.f);		glVertex2f(0.f, 1.f);
	glEnd();
}

double lastRenderTime;
void draw(GLFWwindow *window) {
	double timeNow = glfwGetTime();

	drawGrid();
	ship->draw(timeNow);

	char title[30];
	sprintf(title, "fps: %2.1f", 1/(timeNow-lastRenderTime));
	glfwSetWindowTitle(window, title);

	lastRenderTime = timeNow;
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
	window = glfwCreateWindow(640, 480, "Simple example", NULL /*glfwGetPrimaryMonitor()*/, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
	printf("GL_VERSION: %s\r\n", glGetString(GL_VERSION));
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouseButton_callback);

	ship = new Ship(0, 0, 0, 0.2);
	zoom = 1;

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio*zoom, ratio*zoom, -1.f*zoom, 1.f*zoom, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);

		draw(window);

		glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
