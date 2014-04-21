#include	"Consumer.hh"

void	Consumer::start()
{
  int	i = -8;

  while (true)
    {
      ScopedLock	*sdlock = new ScopedLock(this->_mutex);
      
      if (this->_queue->tryPop(&i) == false)
	{
	  pthread_cond_wait(this->_cond, &(this->_mutex->getMut()));
	  delete sdlock;
	  if (this->_queue->isFinished())
	    break;
	}
      else
	{
	  if (!this->_queue->isEmpty())
	    {
	      delete sdlock;
	      pthread_cond_signal(this->_cond);
	    }
	  else
	    delete sdlock;
	  if (this->_queue->isFinished())
	    break;
	}
      if (i != -8)
	std::cout << "i : " << i << std::endl;
    }
  return;
}

void	*start_consumer(void *c)
{
  reinterpret_cast<Consumer *>(c)->start();
  return NULL;
}
