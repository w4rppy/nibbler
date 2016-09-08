
#include <iostream>
#include "LibSFML.hh"

LibSFML::LibSFML()
{
  this->screen.Create(sf::VideoMode(600, 400, 32), "Snake");
  Image.LoadFromFile("png/snake.png");
  sp.SetImage(Image);
  sp.Resize(15, 15);
  Image2.LoadFromFile("png/item.png");
  item.SetImage(Image2);
  item.Resize(15, 15);
  Image3.LoadFromFile("png/wall.png");
  spwall.SetImage(Image3);
  spwall.Resize(15, 15);
}

LibSFML::~LibSFML()
{

}

bool	LibSFML::getStatusWindow()
{
  return (this->screen.IsOpened());
}

bool	LibSFML::getStatusEvent()
{
  return (this->screen.GetEvent(this->event));
}


void LibSFML::Exit()
{
  if (this->event.Type == sf::Event::Closed ||
      sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape)
    this->screen.Close();
}


void LibSFML::iRefresh(std::vector<Element> &snake, Element &item, std::vector<Element> &wall)
{
  this->screen.Clear();
  this->DrawSnake(snake);
  this->DrawItem(item);
  this->DrawWall(wall);
  this->screen.Display();
  sf::Sleep(0.1);
}

int LibSFML::getDirection()
{
  if (sf::Event::KeyPressed)
    {
      if (event.Key.Code == sf::Key::Up)
	return (UP);
      if (event.Key.Code == sf::Key::Down)
	return (DOWN);
      if (event.Key.Code == sf::Key::Right)
	return (RIGHT);
      if (event.Key.Code == sf::Key::Left)
	return (LEFT);
    }
  return (RIGHT);
}

void LibSFML::DrawSnake(std::vector<Element> &snake)
{
  int i = 0;
  int max = snake.size();

  while (i < max)
    {
      this->sp.SetPosition(snake[i].getX()*15, snake[i].getY()*15);
      this->screen.Draw(sp);
      ++i;
    }
}

void LibSFML::DrawItem(Element &obj)
{
  this->item.SetPosition(obj.getX()*15, obj.getY()*15);
  this->screen.Draw(item);
}

void LibSFML::DrawWall(std::vector<Element> &wall)
{
  int i = 0;
  int max = wall.size();

  while (i < max)
    {
      this->spwall.SetPosition(wall[i].getX()*15, wall[i].getY()*15);
      this->screen.Draw(spwall);
      ++i;
    }
}
