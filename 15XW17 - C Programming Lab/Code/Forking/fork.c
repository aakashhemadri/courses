/** Forks
*   *Wait*
* 
*   @author: Aakash Hemadri
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int **argc, char **argv)
{
    int x = 5; /**< Variable 1 */
    int *y = &x; /**< Variable 2 */
    int *z = (int*) malloc(sizeof(int)); /**< Heap */
    pid_t pid; /**< Process ID*/

    pid = fork(); /**< Creates a child process*/
    
    /**
    *
    */
    if (pid == -1)
    {
        perror("Fork() Failed!");
        return EXIT_FAILURE;
    }
    /**< Fork Success */
    /**< Child process */
    if (pid == 0)
    {
        x += 10;
        printf("[%d] CHILD: My Parent's PID is: %d\n", getpid(), getppid());
        printf("[%d] CHILD: x is %d, Address off x is %x\n",getpid(),x,&x);
        printf("[%d] CHILD: Bye!\n",getpid());
        return 12;
    }
    else 
    {
        printf("[%d] PARENT: My child's PID is %d\n", getpid(), pid);
        printf("[%d] PARENT: x is Address of x is %x\n", getpid(), x, &x);

        int status;
        pid_t child_pid = wait(&status);
        printf("[%d] PARENT: Child [%d] terminated...", getpid(),(int)child_pid);
        if(WIFSIGNALED(status)) /* Core Dump or kill or kill -9 */
        {
            printf("abnormally\n");
        }
        else if(WIFEXITED(status))
        {
            int rc = WEXITSTATUS(status);
            printf("sucessfully with exit code %d\n", rc);
        }

        printf("[%d] PARENT: Bye\n", getpid());
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