
#include		<sstream>
#include		"Ilib.hh"
#include		"DLLoader.hh"
#include		"Core.hh"
#include		"NibblerError.hh"

int			main(int ac, char **av)
{
  if (ac != 4)
    {
      std::cout << USAGE << std::endl;
      return (0);
    }
  int			_w = 0;
  int			_h = 0;
  std::string		w(av[1]);
  std::string		h(av[2]);
  std::istringstream	iss(w + " " + h);

  iss >> _w;
  iss >> _h;
  if ((_w < 300 || _w > 800) || (_h < 300 || _h > 800))
    {
      std::cout << USAGE << std::endl;
      return (0);
    }
  try
    {
      std::string		str(av[3]);
      DLLoader<Ilib>	libloader("./" + str);
      Core			korfury(ac, av);
      Ilib			*lib;

      lib = libloader.getInstance(ac, av);
      srand (time(NULL));
      korfury.loop(*lib);
    }
  catch (const NibblerError & e)
    {
      std::cerr << "Exiting ... :" << e.what() << std::endl;
      return (false);
    }
  return (true);
}
