#ifndef		CONSUMER_HH__
# define	CONSUMER_HH__

# include	"Thread.hh"
# include	"ScopedLock.hh"
# include	"SafeQueue.hh"

# include	<queue>

class	Consumer
{
public:
  Consumer(int id, SafeQueue *queue_, Mutex *mutex_, pthread_cond_t *cond) : _id(id), _queue(queue_), _mutex(mutex_), _cond(cond)
  {}

  ~Consumer() 
  {}

public:
  void	start();

protected:
  int			_id;
  SafeQueue		*_queue;
  Mutex			*_mutex;
  pthread_cond_t	*_cond;
};

void	*start_consumer(void *c);

#endif
