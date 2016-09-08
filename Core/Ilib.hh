
#ifndef ILIB_HH_
# define ILIB_HH_
#include "Element.hh"
#include <vector>

enum{UP, DOWN, RIGHT, LEFT};

class Ilib
{


  public:

    virtual ~Ilib() {}

    virtual bool getStatusWindow() = 0;
    virtual bool getStatusEvent() = 0;
    virtual void iRefresh(std::vector<Element> &, Element &, std::vector<Element> &) = 0;
    virtual void DrawSnake(std::vector<Element> &) = 0;
    virtual int getDirection() = 0;
    virtual void Exit() = 0;
    virtual void DrawItem(Element &) = 0;
    virtual void DrawWall(std::vector<Element> &) = 0;
};



#endif /* ILIB_HH_ */
