#include "port.h"
#include "semaphore.h"
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>

Semaphore::Semaphore(int semKey, int numSems, int val)
 : m_semid(0)
 , m_semflg(IPC_CREAT | 0666)
 , m_semopen(false)
 , m_semKey(semKey)
 , m_numSems(numSems)
{
  m_arg.val = (0);
  if(val)
  {
    if(create(val))
      exit(1);
  }
}

int Semaphore::clear_sem()
{
  int semid;
  // have num-sems set to 1 so that we remove regardless of how many
  // semaphores were present.
#if 0
  if((semid = SYS_semget(m_semKey, 1, 0666)) == -1)
  {
    perror("Can't get semaphore ID");
    return 1;
  }
  if(SYS_semctl(semid, 0, IPC_RMID, m_arg) == -1)
  {
    perror("Can't get remove semaphore");
    return 1;
  }
#endif
  printf("Semaphore removed.\n");
  return 0;
}

int Semaphore::create(int count)
{
#if 0
  if((m_semid = SYS_semget(m_semKey, m_numSems, m_semflg)) == -1)
  {
    perror("Can't get semaphore");
    return 1;
  }
  m_arg.val = count;
  int i;
  for(i = 0; i < m_numSems; ++i)
  {
    if(SYS_semctl(m_semid, i, SETVAL, m_arg) == -1)
    {
      perror("Can't set semaphore value");
      return 1;
    }
  }
#endif
  m_semopen = true;
  return 0;
}

int Semaphore::get_semid()
{
#if 0
  int semflg = 0666;
  if ((m_semid = SYS_semget(m_semKey, m_numSems, semflg)) == -1)
  {
    perror("Can't get semaphore ID");
    return 1;
  }
#endif
  m_semopen = true;
  return 0;
}

int Semaphore::decrement_and_wait(int nr_sem)
{
#if 0
  if(!m_semopen)
    return 0;
  struct sembuf sops;
  sops.sem_num = nr_sem;
  sops.sem_op = -1;
  sops.sem_flg = IPC_NOWAIT;
  if(SYS_semop(m_semid, &sops, 1) == -1)
  {
    perror("SYS_semop: SYS_semop failed.\n");
    return 1;
  }
  sops.sem_num = nr_sem;
  sops.sem_op = 0;
  sops.sem_flg = SEM_UNDO;
  if(SYS_semop(m_semid, &sops, 1) == -1)
  {
    perror("SYS_semop: SYS_semop failed.\n");
    return 1;
  }
#endif
  return 0;
}

int Semaphore::get_mutex()
{
#if 0
  if(!m_semopen)
    return 0;
  struct sembuf sops;
  sops.sem_num = 0;
  sops.sem_op = -1;
  sops.sem_flg = SEM_UNDO;
  if(SYS_semop(m_semid, &sops, 1) == -1)
  {
    perror("SYS_semop: SYS_semop failed.\n");
    return 1;
  }
#endif
  return 0;
}

int Semaphore::put_mutex()
{
#if 0
  if(!m_semopen)
    return 0;
  struct sembuf sops;
  sops.sem_num = 0;
  sops.sem_op = 1;
  sops.sem_flg = IPC_NOWAIT;
  if(SYS_semop(m_semid, &sops, 1) == -1)
  {
    perror("SYS_semop: SYS_semop failed.\n");
    return 1;
  }
#endif
  return 0;
}
