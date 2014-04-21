#include	"Producer.hh"

void	Producer::start()
{
  for (int i = 0; i < 3; ++i)
    {
      ScopedLock	*sdlock = new ScopedLock(this->_mutex);
      this->_queue->push(rand() % 42);
      delete sdlock;
      pthread_cond_signal(this->_cond);
    }
  return;
}

void	*start_producer(void *p)
{
  reinterpret_cast<Producer *>(p)->start();
  return NULL;
}
