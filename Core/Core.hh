
#ifndef CORE_HH_
# define CORE_HH_

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Element.hh"
#include "Ilib.hh"

class Core
{
  private :
    std::vector<Element> snake;
    std::vector<Element> wall;
    Element item;
    int direction;

  public :
    Core();
    ~Core();
    void CreateWall();
    void CreateSnake();
    void loop(Ilib &);
    void MoveSnake();
    void setDirection(int dir);
    void check_item();
    void check_snake();

};

#endif /* CORE_HH_ */
