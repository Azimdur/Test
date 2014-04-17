#include	<iostream>
#include	<cstdlib>
#include	"ScopedLock.hh"
#include	"Thread.hh"

typedef struct	s_data
{
  int		i;
  Mutex		*mutex;
}		t_data;

void	*increment_counter(void *n)
{
  t_data	*data = reinterpret_cast<t_data *>(n);
  ScopedLock	sl(data->mutex);
  
  for (int o = 0; o < 100000; ++o)
    ++(data->i);
  return (NULL);
}

int	main()
{
  t_data	data;
  Mutex		*m = new Mutex;
  
  data = {0, m};

  Thread	*t1 = new Thread(&increment_counter, &data);
  Thread	*t2 = new Thread(&increment_counter, &data);
  
  t1->start();
  t2->start();
  
  t1->wait();
  t2->wait();
  
  std::cout << "i : " << data.i <<std::endl;
  return (0);
}
