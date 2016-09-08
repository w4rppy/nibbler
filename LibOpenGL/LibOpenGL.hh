
#ifndef LIBOPENGL_HH_
# define LIBOPENGL_HH_

#include <GL/glut.h>
#include <GL/freeglut.h>
#include "Ilib.hh"

class LibOpenGL : public Ilib
{
  private :
    int dir;

  public :
    LibOpenGL(int, char**);
    virtual ~LibOpenGL();
    virtual bool getStatusWindow();
    virtual bool getStatusEvent();
    virtual void iRefresh(std::vector<Element> &, Element &, std::vector<Element> &);
    virtual void DrawSnake(std::vector<Element> &);
    virtual int getDirection();
    virtual void Exit();
    virtual void DrawItem(Element &);
    virtual void DrawWall(std::vector<Element> &);

};

#endif /* LIBOPENGL_HH_ */
