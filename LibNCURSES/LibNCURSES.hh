
#ifndef LIBNCURSES_HH_
# define LIBNCURSES_HH_

#include <cstdlib>
#include <ncurses.h>
#include "Ilib.hh"

#define	KEY_ESC		27
//#define	KEY_QUIT	3 // A VOIR

class LibNCURSES : public Ilib
{
private:
  enum {SNAKE = 1, WALL, ITEM};
  bool	_error;

private:
  void	initColor();
  void	drawPoint(int, int, int);
  void	clearAllPoint(std::vector<Element>&);

public:
  LibNCURSES();
  virtual ~LibNCURSES();
  virtual void DrawSnake(std::vector<Element> &);
  virtual int getDirection();
  virtual bool getStatusWindow();
  virtual bool getStatusEvent();
  virtual void iRefresh(std::vector<Element> &, Element &, std::vector<Element> &);
  virtual void Exit();
  virtual void DrawItem(Element &);
  virtual void DrawWall(std::vector<Element> &);

public:
  void  setError(bool);

public:
  bool  getError() const;
};

#endif /* !LIBNCURSES_HH_ */
