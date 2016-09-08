
#include <iostream>
#include "LibOpenGL.hh"

static int event = -1;

void spec_keyboard(int key, int x, int y)
{
  switch(key)
    {
      case GLUT_KEY_UP:
	event = DOWN;
	break;
      case GLUT_KEY_DOWN:
	event = UP;
	break;
      case GLUT_KEY_LEFT:
	event = LEFT;
	break;
      case GLUT_KEY_RIGHT:
	event = RIGHT;
	break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
  if (key == 27)
    exit(1);
}

LibOpenGL::LibOpenGL(int argc, char**argv)
{
  glutInit(&argc, argv);
  glutInitWindowPosition( -1, -1 );
  glutInitWindowSize(600, 400);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
  glutCreateWindow("snake");
  glutSpecialFunc(spec_keyboard);
  glutKeyboardFunc(keyboard);

}

LibOpenGL::~LibOpenGL()
{

}

bool	LibOpenGL::getStatusWindow()
{
  return (true);
}

bool	LibOpenGL::getStatusEvent()
{
  glutMainLoopEvent();
  return (true);
}


void LibOpenGL::Exit()
{
  glutKeyboardFunc(keyboard);
}

void display()
{

}

void LibOpenGL::iRefresh(std::vector<Element> &snake, Element &item, std::vector<Element> &wall)
{
  this->DrawSnake(snake);
  this->DrawItem(item);
  glutDisplayFunc(display);
  glClear(GL_COLOR_BUFFER_BIT);
  usleep(100000);
}

int LibOpenGL::getDirection()
{
  this->dir = event;
  return (this->dir);
}

void LibOpenGL::DrawSnake(std::vector<Element> &snake)
{
  int i = 0;
  int max = snake.size();

  while (i < max)
    {
      glPushMatrix();
      glColor3f( 1.0, 1.0, 0.0 );
      glTranslatef(((float)snake[i].getX()/20 - 1), (float)snake[i].getY()/20 - 1, 0);
      glutWireSphere(0.02, 12, 12);
      glPopMatrix();
      glFlush();
      ++i;
    }
  glutSwapBuffers();
}

void LibOpenGL::DrawItem(Element &obj)
{
  glPushMatrix();
  glColor3f( 0.0, 1.0, 1.0 );
  glTranslatef(((float)obj.getX()/20 - 1), (float)obj.getY()/20 - 1, 0);
  glutWireSphere(0.02, 12, 12);
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
}

void LibOpenGL::DrawWall(std::vector<Element> &wall)
{
  int i = 0;
  int max = wall.size();

  while (i < max)
    {
      glPushMatrix();
      glColor3f( 1.0, 0.0, 0.0 );
      glTranslatef(((float)wall[i].getX()/20 - 1), (float)wall[i].getY()/20 - 1, 0);
      glutWireSphere(0.02, 12, 12);
      glPopMatrix();
      glFlush();
      ++i;
    }
  glutSwapBuffers();
}
