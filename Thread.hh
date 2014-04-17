#ifndef		THREAD_HH__
# define	THREAD_HH__

# include	<pthread.h>

typedef	void*	(*handle)(void *);

enum	e_status
  {
    OFF,
    RUNNING,
    DEAD
  };

class Thread
{
public:
  Thread(handle handle, void *arg) : _handle(handle), _arg(arg) 
  {
    _status = OFF;
    _return = NULL;
  }
  ~Thread()
  {
    /*kill du thread voir cour*/
  }

public:
  void	start() {
    pthread_create(&this->_thr, NULL, this->_handle, this->_arg);
    this->_status = RUNNING;
  }
  void	wait() {
    pthread_join(this->_thr, &this->_return);
  }
  e_status	getStatus() const {
    return (this->_status);
  }
  void		*getRet() const {
    return (this->_return);
  }

protected:
  handle	_handle;
  void		*_arg;
  pthread_t	_thr;
  e_status	_status;
  void		*_return;
};

#endif
