
#include "NibblerError.hh"

NibblerError::NibblerError()
  :_msg(""), _nbrError(0)
{
}

NibblerError::NibblerError(std::string const& msg)
  :_msg(msg), _nbrError(0)
{
}

NibblerError::~NibblerError() throw()
{
}

void NibblerError::setMsg(std::string const& msg)
{
  _msg = msg;
}

std::string NibblerError::getMsg() const
{
  return _msg;
}

void NibblerError::incrNbrError()
{
  ++_nbrError;
}

unsigned int NibblerError::getNbrError() const
{
  return _nbrError;
}
