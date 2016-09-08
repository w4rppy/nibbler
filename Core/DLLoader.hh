
#ifndef DLLOADER_HH_
# define DLLOADER_HH_

# include <iostream>
# include <string>
# include <cstdio>
# include <cstdlib>
# include <dlfcn.h>

template <typename T>
class DLLoader
{
  private:
    std::string	_libName;
    void*	_handle;
  T*	(*_externalCreator)(int ac, char **av);

    //  DLLoader(const DDLoader& other);
    //  DDLoader&	operator=(const DDLoader &other);

  public:
    DLLoader(std::string const &libName);
    virtual ~DLLoader();

  public:
    void  setLibName(std::string const &libName);
  T*	getInstance(int, char**) const;
};

#endif /* !DLLOADER_HH_ */
