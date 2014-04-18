#include	<iostream>
#include	<cstdlib>
#include	"Producer.hh"
#include	"Consumer.hh"
#include	"SafeQueue.hh"
#include	"Thread.hh"

#include	<list>
#include	<pair>

int	main()
{
  Mutex			*mutex = new Mutex();
  SafeQueue		*_queue = new SafeQueue();
  pthread_cond_t	cond;

  std::list<std::pair<Producer *, Thread *> > _prod; 
  std::list<std::pair<Consumer *, Thread *> > _cons;

  for (int i = 0; i != 3; ++i)
    {
      Consumer	*c = new Consumer(i, _queue, _mutex, &cond);
      Thread	*th = new Thread(&start_consumer, (void *) c);
      std::pair<Consumer *, Thread *>	couple(c, th);

      th->start();
      _cons.push_back(couple);
    }

    for (int i = 0; i != 3; ++i)
    {
      Producer	*p = new Producer(i, _queue, _mutex, &cond);
      Thread	*th = new Thread(&start_producer, (void *) c);
      std::pair<Consumer *, Thread *>	couple(c, th);

      th->start();
      _prod.push_back(couple);
    }
  return (0);
}
