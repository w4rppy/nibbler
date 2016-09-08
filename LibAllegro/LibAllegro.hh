
#ifndef LIBALLEGRO_HH_
# define LIBALLEGRO_HH_

#include <allegro5/allegro.h>
#include "../Core/Ilib.hh"

class LibAllegro : public Ilib
{

    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_BITMAP *sp;
    ALLEGRO_BITMAP *spitem;
    ALLEGRO_BITMAP *spwall;

    ALLEGRO_EVENT event;
    float FPS;
    bool quit;
    int	_w;
    int	_h;

 public :
  LibAllegro(int, char **);
    virtual ~LibAllegro();
    virtual bool getStatusWindow() const;
    virtual bool getStatusEvent();
    virtual void iRefresh(std::vector<Element> &, Element &, std::vector<Element> &);
    virtual void DrawSnake(std::vector<Element> &);
    virtual int getDirection();
    virtual void Exit();
    virtual void DrawItem(Element &);
    virtual void DrawWall(std::vector<Element> &);
};

#endif /* LIBALLEGRO_HH_ */
