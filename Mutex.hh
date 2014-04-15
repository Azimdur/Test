#ifndef		MUTEX_HH__
# define	MUTEX_HH__

# include	"IMutex.hh"

class	Mutex : public IMutex
{
public:
  Mutex() {
    _mutex = PTHREAD_MUTEX_INITIALIZER;
  }

  ~Mutex() {
    pthread_mutex_destroy(&this->_mutex);
  }

public:
  void	lock() {
    pthread_mutex_lock(&this->_mutex);
  }
  void	unlock() {
    pthread_mutex_lock(&this->_mutex);
  }

  bool	trylock() {
    pthread_mutex_lock(&this->_mutex);
  }

private:
  pthread_mutex_t	_mutex;
};

#endif
