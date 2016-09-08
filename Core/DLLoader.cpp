
#include "Ilib.hh"
#include "DLLoader.hh"
#include "NibblerError.hh"

template <typename T>
DLLoader<T>::DLLoader(std::string const &libName) : _libName(""), _handle(NULL), _externalCreator(NULL)
{
  setLibName(libName);
}

template <typename T>
DLLoader<T>::~DLLoader() {
  if (_handle)
    dlclose(_handle);
}

template <typename T>
void	DLLoader<T>::setLibName(std::string const &libName)
{
  if (libName == "")
    return ;
  if (_handle)
    dlclose(_handle);
  _libName = libName;
  _handle = dlopen(_libName.c_str(), RTLD_LAZY);
  if (!_handle)
    throw NibblerError(dlerror());
  _externalCreator = reinterpret_cast<T* (*)(int, char**)>
    (dlsym(_handle, "create_lib"));
  if (dlerror() != NULL)
    throw NibblerError(dlerror());
}

template <typename T>
T*	DLLoader<T>::getInstance(int ac, char **av) const
{
  if (_externalCreator)
    return _externalCreator(ac, av);
  return NULL;
}

template class DLLoader<Ilib>;
