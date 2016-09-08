
#include "Element.hh"

Element::Element(int i, int j) : x(i), y(j)
{
}

Element::Element()
{
  this->x = 0;
  this->y = 0;
}


Element::~Element()
{
}

int Element::getX()
{
  return (this->x);
}

int Element::getY()
{
  return (this->y);
}

void Element::setX(int i)
{
  this->x = i;
}

void Element::setY(int j)
{
  this->y = j;
}

Element& Element::operator=(Element &other)
{
  if(this->x != other.getX() && this->y != other.getY())
    {
      this->x = other.getX();
      this->y = other.getY();
    }
  return (*this);
}
