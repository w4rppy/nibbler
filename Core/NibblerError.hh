
#ifndef NIBBLERERROR_HH_
# define NIBBLERERROR_HH_

# include <stdexcept>

# define	USAGE	"Usage ./nibbler x y PATHLIB with x and y between 300 and 800."

class NibblerError : public std::exception
{
  public:
    NibblerError();
    NibblerError(std::string const&);
    ~NibblerError() throw();

  public:
    void setMsg(std::string const&);
    std::string getMsg() const;
    void incrNbrError();
    unsigned int getNbrError() const;

  public:
    const char *what() const throw(){return _msg.c_str();}

  private:
    std::string  _msg;
    unsigned int _nbrError;
};

#endif
