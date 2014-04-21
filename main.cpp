#include	<iostream>
#include	<cstdlib>
#include	"Producer.hh"
#include	"Consumer.hh"
#include	"SafeQueue.hh"
#include	"Thread.hh"

#include	<list>
#include	<utility>

int	main()
{
  std::cout << "Première ligne" << std::endl;  
  Mutex			*_mutex = new Mutex();
  SafeQueue		*_queue = new SafeQueue();
  std::cout << "queue ok" << std::endl;  
  pthread_cond_t	cond;

  std::list<std::pair<Producer *, Thread *> > _prod; 
  std::list<std::pair<Consumer *, Thread *> > _cons;

  for (int i = 0; i != 3; ++i)
    {
      Consumer	*c = new Consumer(i, _queue, _mutex, &cond);
      Thread	*th = new Thread(&start_consumer, (void *) c);
      std::pair<Consumer *, Thread *>	couple(c, th);

      std::cout << "avant start" << std::endl;  
      th->start();
      std::cout << "après start" << std::endl;  
      _cons.push_back(couple);
    }

  std::cout << "Etape 1" << std::endl;  
  for (int i = 0; i != 3; ++i)
    {
      Producer	*p = new Producer(i, _queue, _mutex, &cond);
      Thread	*th = new Thread(&start_producer, (void *) p);
      std::pair<Producer *, Thread *>	couple(p, th);
      
      th->start();
      _prod.push_back(couple);
    }

  std::cout << "Etape 2" << std::endl;  
  for (int i = 0; i != 3; ++i)
    {
      std::pair<Producer *, Thread *> couple = _prod.back();
      
      couple.second->wait();
      delete couple.first; delete couple.second;
      _cons.pop_back();
    }
  _queue->setFinished();

  std::cout << "Etape 3" << std::endl;  
  for (int i = 0; i != 3; ++i)
    {
      std::pair<Consumer*, Thread *> couple = _cons.back();
      
      pthread_cond_broadcast(&cond);
      couple.second->wait();
      delete couple.first; delete couple.second;
      _cons.pop_back();
    }

  std::cout << "Etape 4" << std::endl;  
  return (0);
}
