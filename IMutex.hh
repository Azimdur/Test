#ifndef		IMUTEX_HP__
# define	IMUTEX_HH__

# include	<pthread.h>

class	IMutex
{
public:
  virtual ~IMutex() {}
  virtual void lock() = 0;
  virtual void unlock() = 0;
  virtual bool trylock() = 0;
};

#endif
