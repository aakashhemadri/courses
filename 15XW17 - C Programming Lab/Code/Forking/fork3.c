/* fork-with-exec.c */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  pid_t pid;    /* process id (int) */

  pid = fork();   /* create a child process */

  if ( pid == -1 )     /* why would fork() fail?  out of memory */
  {                                /* also RLIMIT_NPROC ... */
    perror( "fork() failed!" );
    return EXIT_FAILURE;
  }


  if ( pid == 0 )   /* child process */
  {
    printf( "CHILD: happy birthday!\n" );
	/*    sleep( 10 ); */

    /* execute the /bin/ls program in this child process */
    int rc = execlp( "/bin/ls", "ls",   "-al",  NULL );

                   /* path      argv[0] argv[1]  etc.   */

    if ( rc == -1 )
    {
      perror( "execlp() failed" );
      return EXIT_FAILURE;
    }
  }
  else /* pid > 0 so we're in the parent (calling) process */
  {
    printf( "PARENT: my child's pid is %d\n", pid );

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

  return 0;
}

