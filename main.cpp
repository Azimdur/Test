#include	<iostream>
#include	"Mutex.hh"


/********************************************/
//
// tout le code commanté 
// ne marche pas.
//
// Pour switché du code qui marche 
// au code qui marche pas, t'as juste
// a commenté les ligne avec /**/ devant,
// et a décommenté celle qui le sont
//
/*******************************************/


// Structure envoyé dans la fonction

typedef struct	s_data
{
  int		i;
  /**/pthread_mutex_t mutex;
  //Mutex		*mutex;
}		t_data;

// fonctiond d'imcrementation threadé

void	*increment_counter(void *n)
{
  t_data	*data = reinterpret_cast<t_data *>(n);

  //data->mutex->trylock();  
  /**/pthread_mutex_lock(&data->mutex);
  for (int o = 0; o < 100000; ++o)
    ++(data->i);
  /**/pthread_mutex_unlock(&data->mutex);
  //data->mutex->unlock();
  return (NULL);
}

// Initialisation et destruction des données

void	init_data(t_data *d)
{
  d->i = 0;
  /**/pthread_mutex_init(&d->mutex, NULL);
}

void	clean_data(t_data *d)
{
  d->i = 0;
  /**/pthread_mutex_destroy(&d->mutex);
}


// Déclaration des données et logique

int	main()
{
  t_data	data;
  pthread_t	th1;
  pthread_t	th2;

  //Mutex		*m = new Mutex;
  
  //data = {0, m};
  
  /**/init_data(&data);
  
  pthread_create(&th1, NULL, &increment_counter, &data);
  pthread_create(&th2, NULL, &increment_counter, &data);

  void *ret;

  pthread_join(th1, &ret);
  pthread_join(th2, &ret);

  std::cout << "i : " << data.i << std::endl;
  /**/clean_data(&data);
  return (0);
}
