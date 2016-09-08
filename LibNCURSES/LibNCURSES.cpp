
#include <iostream>
#include "LibNCURSES.hh"

extern "C"
{
  Ilib* create_assistant()
  {
    return new LibNCURSES();
  }
}

LibNCURSES::LibNCURSES() : _error(true)
{
  initscr();
  initColor();
  /*
  while (1)
    {
      printw("%d\n", ++g);
      refresh();
    }
*/
  keypad(stdscr, TRUE);
  noecho();
}

LibNCURSES::~LibNCURSES(){
}

void	LibNCURSES::initColor()
{
  start_color();
  init_pair(SNAKE, COLOR_GREEN, COLOR_GREEN);
  init_pair(WALL, COLOR_WHITE, COLOR_WHITE);
  init_pair(ITEM, COLOR_CYAN, COLOR_CYAN);
}

bool	LibNCURSES::getStatusWindow()
{
  return this->getError();
}

bool	LibNCURSES::getStatusEvent()
{
  return this->getError();
}

void	LibNCURSES::Exit() {
  endwin();
}

void	LibNCURSES::clearAllPoint(std::vector<Element> &v_wall) {
  int x;
  int	max = v_wall.size();
  
  for (int y = 1; y < v_wall[max - 1].getY(); ++y)
    {
      for (x = 1; x < v_wall[max - 1].getX(); ++x)
	mvaddch(y, x, ' ');
    }
}

void	LibNCURSES::iRefresh(std::vector<Element> &snake, Element &item, std::vector<Element> &wall) {
  usleep(100000);
  curs_set(0);
  initColor();
  clearAllPoint(wall);
  this->DrawSnake(snake);
  this->DrawItem(item);
  this->DrawWall(snake);
}

void	LibNCURSES::drawPoint(int y, int x, int element)
{
  attron(COLOR_PAIR(element));
  mvaddch(y, x, ' ');
  attroff(COLOR_PAIR(element));
  /*attrset(A_NORMAL);*/
}

void	LibNCURSES::DrawSnake(std::vector<Element> &snake) {
  int	max = snake.size();

  for (int i = 0; i < max; ++i)
    drawPoint(snake[i].getY(), snake[i].getX(), SNAKE);
}

int	LibNCURSES::getDirection() {
  int	ch;

  timeout(0);
  ch = getch();
  switch (ch)
    {
    case KEY_UP:
      return UP;
    case KEY_DOWN:
      return DOWN;
    case  KEY_LEFT:
      return LEFT;
    case KEY_RIGHT:
      return RIGHT;
    case KEY_ESC:
      endwin();
      exit(1);
      break;
    }
}

void	LibNCURSES::DrawItem(Element &item) {
  drawPoint(item.getY(), item.getX(), ITEM);
}

void	LibNCURSES::DrawWall(std::vector<Element> &wall) {
  int	max = wall.size();

  for (int i = 0; i < max; ++i)
    drawPoint(wall[i].getY(), wall[i].getX(), WALL);
}

void LibNCURSES::setError(bool value) {
  _error = value;
}

bool LibNCURSES::getError() const {
  return _error;
}
