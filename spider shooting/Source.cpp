
#include <stdlib.h>
#include <cstdlib>
#include <GL/glut.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <string>
// #include "Headers/pixMap.h"
// #include "Headers/point.h"
// #include "Headers/spider.h"
#include "Headers/Headers.h"

using namespace std;

int screenWidth = 640;
int screenHeight = 480;
bool isUpKeyPressed = false;


Spider spider(Point2(0, 0));
Bullet bullet(0.0, 0.0, 5.0, 10.0); // Initial position, speed, and size

void myDisplay(void) {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Check if the up arrow key is pressed
   if (isUpKeyPressed) {
       bullet.update(); // Move the bullet upwards
   }

   // Update the spider's position
   spider.changePosition(spider.spiderSpeed * cos(spider.theta),
       spider.spiderSpeed * sin(spider.theta));

   // Check if the spider is out of bounds, and change its direction if needed
   if (spider.pos_X < 0 || spider.pos_X > screenWidth ||
       spider.pos_Y < 0 || spider.pos_Y > screenHeight) {
       spider.theta += 3.14159; // Reverse direction when hitting the screen boundary
   }

   // Render the spider and bullet
   spider.render();
   bullet.render();

   glutPostRedisplay();
   glutSwapBuffers();
}

void myKeyboard(int key, int x, int y) {
   switch (key) {
   case GLUT_KEY_UP:
       isUpKeyPressed = true;
       break;
   }
}

void myKeyboardUp(int key, int x, int y) {
   switch (key) {
   case GLUT_KEY_UP:
       isUpKeyPressed = false;
       break;
   }
}

void myInit(void) {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

   glViewport(0, 0, screenWidth, screenHeight);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   gluOrtho2D(0, screenWidth, 0, screenHeight);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glEnable(GL_ALPHA_TEST);
   glAlphaFunc(GL_EQUAL, 1.0);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(screenWidth, screenHeight);
   glutInitWindowPosition(10, 10);
   glutCreateWindow("Spider Game");
   glutSpecialFunc(myKeyboard);
   glutSpecialUpFunc(myKeyboardUp);

   // Calculate the initial position to center the spider
   float initialX = (screenWidth - spider.pix[0].nCols) / 2.0f;
   float initialY = (screenHeight - spider.pix[0].nRows) / 2.0f;

   // Initialize the Spider object with the new initial position
   spider = Spider(Point2(initialX, initialY));

   // Initialize the Bullet object below the spider
   float bulletX = initialX + spider.pix[0].nCols / 2.0f; // Place bullet at the center of the spider
   float bulletY = initialY - spider.pix[0].nRows - bullet.size - 120.0f;
   bullet = Bullet(bulletX, bulletY, 5.0, 10.0); // Initial position, speed, and size

   glutDisplayFunc(myDisplay);
   myInit();

   glutMainLoop();
}
