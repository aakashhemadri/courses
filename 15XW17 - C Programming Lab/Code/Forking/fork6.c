/* pipe-send-data.c */

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
  double answer = 1.23456;

  int bytes_written = write( p[1], &answer, sizeof( double ) );
  printf( "Wrote %d bytes\n", bytes_written );

  int result = 123;
  bytes_written = write( p[1], &result, sizeof( int ) );
  printf( "Wrote %d bytes\n", bytes_written );

  close( p[1] );


  /* read data from the pipe */
  double x;
  int bytes_read = read( p[0], &x, sizeof( double ) );    /* BLOCKING */
  printf( "Read %d bytes: %lf\n", bytes_read, x );

  int r;
  bytes_read = read( p[0], &r, sizeof( int ) );    /* BLOCKING */
  printf( "Read %d bytes: %d\n", bytes_read, r );


#if 0
  char buffer[100];
  int bytes_read = read( p[0], buffer, 20 );    /* BLOCKING */
  buffer[bytes_read] = '\0';
  printf( "Read %d bytes: %s\n", bytes_read, buffer );
#endif

  close( p[0] );

  return EXIT_SUCCESS;
}

