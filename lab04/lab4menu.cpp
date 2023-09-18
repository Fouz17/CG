#include <GL/glut.h>
#include <gl/glu.h>
#include <gl/gl.h>
// #include <GL/glui.h>
#include <string.h>
#include <iostream>

#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4
#define BLACK 5

using namespace std;

float angle = 0.0; // for rotating the triangle
float red = 1.0,
      blue = 1.0,
      green = 1.0; // possible triangle colors.

void renderScene(void)
{
    // the callback to draw the triangle

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angle, 1.0, 1.0, 1.0); // rotate the triangle a little more
    glColor3f(red, green, blue);     // change its color

    glBegin(GL_TRIANGLES); // draw the triangle
    glVertex3f(-0.5, -0.5, 0.0);

    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);

    glEnd();
    angle = angle + 0.1;
    // cout << angle << endl;
    glutSwapBuffers();
}

void processMenuEvents(int option)
{

    // mouse choice chooses color
    switch (option)
    {

    case RED:
        red = 1.0;
        green = 0.0;
        blue = 0.0;
        break;

    case GREEN:
        red = 0.0;
        green = 1.0;
        blue = 0.0;
        break;

    case BLUE:
        red = 0.0;
        green = 0.0;
        blue = 1.0;
        break;

    case WHITE:
        red = 1.0;
        green = 1.0;
        blue = 1.0;
        break;
    case BLACK:
        red = 0;
        green = 0;
        blue = 0;
        break;

        //---------MAIN---
    }
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);

    glutCreateWindow("Menu Test"); // open an OpenGL window
    glutDisplayFunc(renderScene);  // register display function

    glutIdleFunc(renderScene); // calls to functions to create

    glutCreateMenu(processMenuEvents);

    glutAddMenuEntry("Red", RED);
    glutAddMenuEntry("Blue", BLUE);
    glutAddMenuEntry("Green", GREEN);
    glutAddMenuEntry("White", WHITE);
    glutAddMenuEntry("Black", BLACK);

    glutAttachMenu(GLUT_RIGHT_BUTTON); // attach right mouse button

    glutMainLoop();
}
