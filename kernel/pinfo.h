#ifndef _PINFO_H_
#define _PINFO_H_

#include "param.h"

struct pinfo {
  int pid[NPROC];
  int status[NPROC];
  int priority[NPROC];
  int tickets[NPROC];
  int num_processes;
};

#endif
