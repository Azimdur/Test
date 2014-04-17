#ifndef		ISAFEQUEUE_HH__
# define	ISAFEQUEUE_HH__

class	ISafeQueue
{
public:
  virtual ~ISafeQueue() {}
  virtual void	push(int value) = 0;
  virtual bool	tryPop(int *value) = 0;
  virtual bool	isFinished() = 0;
  virtual void	setFinished() = 0;
};
#endif
