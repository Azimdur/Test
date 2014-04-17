#include	"SafeQueue.hh"

SafeQueue::SafeQueue() : _finish(false)
{}

SafeQueue::~SafeQueue()
{}

void	SafeQueue::push(int value)
{
  this->_queue.push(value);
}

bool	SafeQueue::tryPop(int *value)
{
  if (this->_queue.empty())
    return (false);
  *value = this->_queue.front();
  this->_queue.pop();
  return (true);
}

bool	SafeQueue::isFinished()
{
  if (this->_finish == true && this->_queue.empty() == true)
    return (true);
  return false;
}

void	SafeQueue::setFinished()
{
  this->_finish = true;
}
