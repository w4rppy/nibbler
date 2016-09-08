
#ifndef ELEMENT_HH_
# define ELEMENT_HH_

class Element
{
  private :
    int x;
    int y;

    public :
    Element();
    Element(int, int);
    ~Element();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    void setElement(int, int);
    Element& operator=(Element &);

};

#endif /* ELEMENT_HH_ */
