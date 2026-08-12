#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define LOOP_LIMIT 120000000

void do_heavy_work(int id, int expected_priority) {
  for(volatile int i = 0; i < LOOP_LIMIT; i++) {
     if(i == (LOOP_LIMIT / 4)) {
         printf("[Progress] Process %d (Priority %d) completed 25%%\n", id, expected_priority);
     } else if(i == (LOOP_LIMIT / 2)) {
         printf("[Progress] Process %d (Priority %d) completed 50%%\n", id, expected_priority);
     } else if(i == (3 * (LOOP_LIMIT / 4))) {
         printf("[Progress] Process %d (Priority %d) completed 75%%\n", id, expected_priority);
     }
  }
  printf(">>> Process %d (Priority %d) FINISHED <<<\n", id, expected_priority);
}

int main() {
  printf("\n=== STAGE 1: Different Priorities Test ===\n");
  int priorities[3] = {30, 60, 90};

  for(int i = 0; i < 3; i++) {
    int pid = fork();
    if(pid == 0) {
      setpriority(getpid(), priorities[i]);
      do_heavy_work(i + 1, priorities[i]);
      exit(0);
    }
  }
  for(int i = 0; i < 3; i++) wait(0);

  printf("\n=== STAGE 2: Equal Priorities Round-Robin Test ===\n");
  for(int i = 0; i < 2; i++) {
    int pid = fork();
    if(pid == 0) {
      setpriority(getpid(), 50);
      do_heavy_work(i + 4, 50);
      exit(0);
    }
  }
  for(int i = 0; i < 2; i++) wait(0);

  printf("\nAll scheduling tests completed successfully!\n");
  exit(0);
}
