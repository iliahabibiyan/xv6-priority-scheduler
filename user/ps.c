#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pinfo.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  struct pinfo info;

  if(getinfo(&info) < 0) exit(1);

  printf("PID\tSTATE\tPRIORITY\tTICKETS\n");
  for(int i = 0; i < info.num_processes; i++){
    printf("%d\t%d\t%d\t\t%d\n",
           info.pid[i], info.status[i], info.priority[i], info.tickets[i]);
  }

  exit(0);
}
