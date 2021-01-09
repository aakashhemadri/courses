/* create a child process */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  int x = 5;
  int * y = &x;
  int * z = (int *)malloc( sizeof( int ) );   /* heap */

  pid_t pid;    /* process id (int) */

  pid = fork();   /* create a child process */

  if ( pid == -1 )
  {               
    perror( "fork() failed!" );
    return EXIT_FAILURE;
  }

  if ( pid == 0 )   /* child process */
  {
    x += 10;
    printf( "CHILD: happy birthday!\n" );
    printf( "CHILD: x is %d Addr of X is %x\n", x,&x );
    printf( "CHILD: bye\n" );
/*    sleep( 10 ); */
    return 12;
  }
  else /* pid > 0 so we're in the parent (calling) process */
  {
    x += 30;
    printf( "PARENT: my child's pid is %d\n", pid );
    printf( "PARENT: x is %d Addr of X is %x\n", x,&x );

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
     -- list of cesource allocation (CPU usage, total runtime)
     -- memory lohild processes (NULL)
     -- data on rcation / locks
     -- pending signals
   */

  return 0;
}

