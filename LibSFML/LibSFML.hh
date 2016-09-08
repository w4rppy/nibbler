
#ifndef LIBSFML_HH_
# define LIBSFML_HH_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Ilib.hh"

class LibSFML : public Ilib
{
  private :
    sf::Event event;
    sf::RenderWindow screen;
    sf::Image Image;
    sf::Image Image2;
    sf::Image Image3;
    sf::Sprite sp;
    sf::Sprite item;
    sf::Sprite spwall;

  public :
    LibSFML();
    virtual ~LibSFML();
    virtual bool getStatusWindow();
    virtual bool getStatusEvent();
    virtual void iRefresh(std::vector<Element> &, Element &, std::vector<Element> &);
    virtual void DrawSnake(std::vector<Element> &);
    virtual int getDirection();
    virtual void Exit();
    virtual void DrawItem(Element &);
    virtual void DrawWall(std::vector<Element> &);
};

#endif /* LIBSFML_HH_ */
