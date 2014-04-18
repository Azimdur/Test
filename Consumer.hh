#ifndef		CONSUMER_HH__
# define	CONSUMER_HH__

# include	"Thread.hh"
# include	"ScopedLock.hh"

class	Consumer
{
public:
  Consumer();
  ~Consumer();

public:
  void	start();

protected:
  Mutex			*_mutex;
  pthread_cond_t	*_cond;
};

void	*start_consumer(void *c);

#endif
