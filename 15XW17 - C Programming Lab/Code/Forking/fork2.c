/* fork-three-levels.c */

/* create a child process */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  printf( "my pid is %d\n", getpid() );

  pid_t pid;    /* process id (int) */

  pid = fork();   /* create a child process */

  /* this fork() system call, if successful, will
     return twice.....once in the parent process,
      once in the child process */

  /* from man fork: On success, the PID of the
      child process is returned in the parent,
       and 0 is returned in the child. */

  if ( pid == -1 )     /* why would fork() fail?  out of memory */
  {                                /* also RLIMIT_NPROC ... */
    perror( "fork() failed!" );
    return EXIT_FAILURE;
  }

  /* when a child process is created, the child is an exact */
  /*  duplicate of the parent's memory.... */

  if ( pid == 0 )   /* child process */
  {
    printf( "CHILD: happy birthday!\n" );
    printf( "CHILD: bye\n" );

   /*   +--------+
        | parent | 13283    (return value from fork() was 13284)
        +--------+
            |
            v
        +--------+
        |  child | 13284    (return value from fork() was 0)
        +--------+
   */


    pid = fork();  /* have this child process create its own child */
    printf( "fork() returned %d (my pid is %d)\n", pid, getpid() );
    sleep( 20 );

   /*   +--------+
        | parent | 13283
        +--------+
            |
            v
        +--------+
        |  child | 13284   fork() returned 13285
        | parent |
        +--------+
            |
            v
        +--------+
        |  child | 13285   fork() returned 0
        +--------+
   */

    return 12;  /* explicitly terminating the child process */
  }
  else /* pid > 0 so we're in the parent (calling) process */
  {
    printf( "PARENT: my child's pid is %d\n", pid );

    /* wait for the child to terminate */
    int status;
    pid_t child_pid = wait( &status );
                   /* wait() blocks indefinitely ... */

    printf( "PARENT: child %d terminated...", (int)child_pid );

    if ( WIFSIGNALED( status ) )  /* core dump or kill or kill -9 */
    {
      printf( "abnormally\n" );
    }
    else if ( WIFEXITED( status ) ) /* child called return or exit() */
    {
      int rc = WEXITSTATUS( status );
      printf( "successfully with exit status %d\n", rc );
    }

    printf( "PARENT: bye\n" );
  }

  printf( "got here!\n" );


  /* things that get duplicated from parent to child:
     -- program counter (PC)
     -- variables and their values (anything in memory,
            including the stack and the heap)
     -- file descriptors (fd table)
     -- environment (env variables)
     -- process priority
     -- controlling terminal
     -- current working directory
     -- signal handlers ???
     -- etc.

     things that do NOT get duplicated:
     -- process id (pid)
     -- parent process id
     -- list of child processes (NULL)
     -- data on resource allocation (CPU usage, total runtime)
     -- memory location / locks
     -- pending signals
   */

  return 0;
}

