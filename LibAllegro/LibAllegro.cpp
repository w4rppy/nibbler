
#include <iostream>
#include <sstream>
#include "LibAllegro.hh"

extern "C"
{
  Ilib* create_lib(int ac, char **av)
  {
    return new LibAllegro(ac, av);
  }
}

LibAllegro::LibAllegro(int ac, char **av)
{
  (void)ac;
  std::string w(av[1]);
  std::string h(av[2]);
  std::istringstream iss(w + " " + h);
  iss >> _w;
  iss >> _h;

  this->display = NULL;
  this->event_queue = NULL;
  this->timer = NULL;
  this->sp = NULL;
  this->spitem = NULL;
  this->FPS = 10;
  this->quit = true;
  al_init();
  al_install_keyboard();

  timer = al_create_timer(1.0 / FPS);
  display = al_create_display(_w, _h);
  this->sp = al_create_bitmap(15, 15);
  al_set_target_bitmap(sp);
  al_clear_to_color(al_map_rgb(255, 0, 255));

  this->spitem = al_create_bitmap(15, 15);
  al_set_target_bitmap(spitem);
  al_clear_to_color(al_map_rgb(255, 255, 0));

  this->spwall = al_create_bitmap(15, 15);
  al_set_target_bitmap(spwall);
  al_clear_to_color(al_map_rgb(255, 0, 0));


  al_set_target_bitmap(al_get_backbuffer(display));

  event_queue = al_create_event_queue();

  al_register_event_source(event_queue, al_get_display_event_source(display));

  al_register_event_source(event_queue, al_get_timer_event_source(timer));

  al_register_event_source(event_queue, al_get_keyboard_event_source());

  al_clear_to_color(al_map_rgb(0,0,0));
  al_flip_display();
  al_start_timer(timer);
}

LibAllegro::~LibAllegro()
{
  al_destroy_bitmap(sp);
  al_destroy_timer(timer);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
}

bool	LibAllegro::getStatusWindow() const
{
  return (quit);
}

bool	LibAllegro::getStatusEvent()
{
  al_wait_for_event(event_queue, &event);
  return (true);
}


void LibAllegro::Exit()
{
  if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ||
     event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
    this->quit = false;
}


void LibAllegro::iRefresh(std::vector<Element> &snake, Element &item, std::vector<Element> &wall)
{
  al_clear_to_color(al_map_rgb(0,0,0));
  this->DrawItem(item);
  this->DrawSnake(snake);
  this->DrawWall(wall);
  al_flip_display();
}

int LibAllegro::getDirection()
{
  if (event.keyboard.keycode == ALLEGRO_KEY_UP)
    return (UP);
  else if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
    return (DOWN);
  else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
    return (RIGHT);
  else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
    return (LEFT);
  return (-1);
}

void LibAllegro::DrawSnake(std::vector<Element> &snake)
{
  int i = 0;
  int max = snake.size();

  while (i < max)
    {
      al_draw_bitmap(sp, snake[i].getX()*15, snake[i].getY()*15, 0);
      ++i;
    }
}

void LibAllegro::DrawItem(Element &obj)
{
  al_draw_bitmap(spitem, obj.getX()*15, obj.getY()*15, 0);
}

void LibAllegro::DrawWall(std::vector<Element> &wall)
{
  int i = 0;
  int max = wall.size();

  while (i < max)
    {
      al_draw_bitmap(spwall, wall[i].getX()*15, wall[i].getY()*15, 0);
      ++i;
    }
}
