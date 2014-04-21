#ifndef		PRODUCER_HH__
# define	PRODUCER_HH__

# include	"SafeQueue.hh"
# include	"Mutex.hh"
# include	"ScopedLock.hh"

# include	<cstdlib>

class	Producer
{
public:
  Producer(int id, SafeQueue *queue_, Mutex *mutex_, pthread_cond_t *cond) : _id(id), _queue(queue_), _mutex(mutex_), _cond(cond)
  {}

  ~Producer()
  {}

public:
  void	start();

protected:
  int		_id;
  SafeQueue	*_queue;
  Mutex		*_mutex;
  pthread_cond_t *_cond;
};

void	*start_producer(void *);

#endif
