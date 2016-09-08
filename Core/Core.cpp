#include "Core.hh"
// #include "LibSFML.hh"
#include "LibOpenGL.hh"

Core::Core()
{
  this->CreateSnake();
  this->CreateWall();
  item.setX(rand() % 25);
  item.setY(rand() % 20);
}

Core::~Core()
{
}

void Core::CreateSnake()
{
  int i = 1;

  while (i <= 4)
    {
      this->snake.push_back(Element(i+15,15));
      ++i;
    }
}


void Core::CreateWall()
{
  int i = 0;

  while (i < 600)
    this->wall.push_back(Element(i++,0));
  i = 0;
  while (i < 400)
    this->wall.push_back(Element(0,i++));
  i = 0;
  while (i < 400)
    this->wall.push_back(Element((600/15)-1,i++));
  i = 0;
  while (i < 600)
    this->wall.push_back(Element(i++, 400/15));
}


void Core::setDirection(int dir)
{
  if (dir == RIGHT && direction != LEFT)
    direction = dir;
  if (dir == LEFT && direction != RIGHT)
    direction = dir;
  if (dir == UP && direction != DOWN)
    direction = dir;
  if (dir == DOWN && direction != UP)
    direction = dir;
}

void Core::MoveSnake()
{
  int i = snake.size();

  while (i > 0)
    {
      snake[i].setX(snake[i-1].getX());
      snake[i].setY(snake[i-1].getY());
      --i;
    }
  if (direction == RIGHT)
    snake[0].setX(snake[0].getX() + 1);
  if (direction == LEFT)
    snake[0].setX(snake[0].getX() - 1);
  if (direction == UP)
    snake[0].setY(snake[0].getY() - 1);
  if (direction == DOWN)
    snake[0].setY(snake[0].getY() + 1);
}

void Core::check_item()
{
  if (snake[0].getX() == item.getX()
 && snake[0].getY() == item.getY())
    {
      snake.push_back(Element((snake[1].getX()+1), (snake[1].getY()+1) ));
      item.setX(rand() % 25);
      item.setY(rand() % 25);
    }
}

void Core::check_snake()
{
  int i = 3;
  int max = snake.size();

  while (i < max)
    {
      if (snake[0].getX() == snake[i].getX()
	  && snake[0].getY() == snake[i].getY())
	{
	  std::cout << "GAME OVER !"  << std::endl;
	  exit(1);
	}

      ++i;
    }
  i = 0;
  max = wall.size();
  while (i < max)
    {
      if (snake[0].getX() == wall[i].getX()
	  && snake[0].getY() == wall[i].getY())
	{
	  std::cout << "GAME OVER !"  << std::endl;
	  exit(1);
	}

      ++i;
    }
}

void Core::loop(Ilib &lib)
{
  int dir = RIGHT;
  this->direction = dir;

  while(lib.get_status_window())
    {
      lib.get_status_event();
      lib.Exit();
      dir = lib.getDirection();
      check_snake();
      check_item();
      setDirection(dir);
      MoveSnake();
      lib.refresh(snake, item, wall);
    }
}


/*int main(int ac, char **av)
{
  LibOpenGL b(ac, av);
  Core a;
  srand (time(NULL));
  a.loop(b);

  }*/
