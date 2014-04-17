#ifndef		SAFEQUEUE_HH__
# define	SAFEQUEUE_HH__

# include	<queue>
# include	"ISafeQueue.hh"

class	SafeQueue : ISafeQueue
{
public:
  SafeQueue();
  ~SafeQueue();

public:
  void	push(int value);
  bool	tryPop(int *value);
  bool	isFinished();
  void	setFinished();

protected:
  std::queue<int>	_queue;
  bool			_finish;
};
#endif
