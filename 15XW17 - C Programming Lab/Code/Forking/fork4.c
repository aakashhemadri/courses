/* pipe.c */

/* a pipe is means of interprocess communication (IPC) */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int p[2];   /* array to hold the two pipe (file) descriptors
                 p[0] is the read end of the pipe
                 p[1] is the write end of the pipe */

  int rc = pipe( p );

  if ( rc == -1 )
  {
    perror( "pipe() failed" );
    return EXIT_FAILURE;
  }

  /* fd table:

        0: stdin
        1: stdout
        2: stderr
        3: p[0] <=======READ============= (buffer)  think of this as
        4: p[1] ========WRITE===========> (buffer)   a temporary file...
   */

  /* write some data to the pipe */
  int bytes_written = write( p[1], "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26 );
  printf( "Wrote %d bytes\n", bytes_written );

  close( p[1] );


  /* read data from the pipe */
  char buffer[100];
  int bytes_read = read( p[0], buffer, 10 );    /* BLOCKING */
  buffer[bytes_read] = '\0';
  printf( "Read %d bytes: %s\n", bytes_read, buffer );

  bytes_read = read( p[0], buffer, 20 );    /* BLOCKING */
  buffer[bytes_read] = '\0';
  printf( "Read %d bytes: %s\n", bytes_read, buffer );

  close( p[0] );

  return EXIT_SUCCESS;
}

