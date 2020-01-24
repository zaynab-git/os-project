#include "types.h"
#include "stat.h"
#include "user.h"
#include "ticketlock.h"

struct ticketlock lock;
void ticketlockInit();
void ticketlockTest();
    int i =0;   

void ticketlockInit()
{
  initTicketlock(&lock);
}

void ticketlockTest()
{

    acquireTicketlock(&lock);
    i++;
    printf(1,"value is  now  :  %d\n", i);
    releaseTicketlock(&lock);
}

int main(int argc, char *argv[])  
{


  ticketlockInit();
  for(int i =0;i<10;i++)
     ticketlockTest();


  exit();
 
}
