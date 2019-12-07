/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printf("Turing was right!");
  alarm(1); //exit after printing
}

void time_handle(int sig){
  double total_time;
  clock_t start = clock();
  signal(SIGALRM, handler);
  clock_t end= clock();
  total_time += (end-start)/CLOCKS_PER_SEC;
  printf("Total Execution Time: %f\n", total_time);
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT,time_handle);
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1); //busy wait for signal to be delivered
  return 0; //never reached
}