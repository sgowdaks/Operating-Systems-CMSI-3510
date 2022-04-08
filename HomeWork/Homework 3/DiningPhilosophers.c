#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct {
  int place;
  int count;
  sem_t *forks;
  sem_t *lock;
} param_t;

void initialize_semaphores(sem_t *lock, sem_t *forks, int num_forks);
void run_threads(pthread_t *threads, sem_t *forks, sem_t *lock, int num_philosophers);

void *philosopher(void *param);
void think(int place);
void eat(int place);

int main(int argc, char *args[])
{
  int num_philosophers = 5;

  sem_t lock;
  sem_t forks[num_philosophers];
  pthread_t philosophers[num_philosophers];

  initialize_semaphores(&lock, forks, num_philosophers);
  run_threads(philosophers, forks, &lock, num_philosophers);
  pthread_exit(NULL);
}

void initialize_semaphores(sem_t *lock, sem_t *forks, int num_forks)
{
  int i;
  for(i = 0; i < num_forks; i++) {
    sem_init(&forks[i], 0, 1);
  }

  sem_init(lock, 0, num_forks - 1);
}

void run_threads(pthread_t *threads, sem_t *forks, sem_t *lock, int num_philosophers)
{
  int i;
  for(i = 0; i < num_philosophers; i++) {
    param_t *arg = malloc(sizeof(param_t));
    arg->place = i;
    arg->count = num_philosophers;
    arg->lock = lock;
    arg->forks = forks;

    pthread_create(&threads[i], NULL, philosopher, (void *)arg);
  }
}

void *philosopher(void *param)
{
  int i;
  param_t self = *(param_t *)param;

  for(i = 0; i < 3; i++) {
    think(self.place);

    sem_wait(self.lock);
    sem_wait(&self.forks[self.place]);
    sem_wait(&self.forks[(self.place + 1) % self.count]);
    eat(self.place);
    sem_post(&self.forks[self.place]);
    sem_post(&self.forks[(self.place + 1) % self.count]);
    sem_post(self.lock);
  }

  think(self.place);
  pthread_exit(NULL);
}

void think(int place)
{
  printf("Philosopher %d is thinking...\n", place);
}

void eat(int place)
{
  printf("Philosopher %d is eating...\n", place);
}
