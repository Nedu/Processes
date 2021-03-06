// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int rc = fork();

    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("Hello!\n");
    } else {
        int wc = waitpid(rc, NULL, 0);    // `waitpid` call added here
        printf("Goodbye!\n");
    }

    return 0;
}
