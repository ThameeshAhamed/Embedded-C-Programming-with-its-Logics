#include <stdio.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        // Child process
        printf("Child exiting...\n");
        return 0;
    } else {
        // Parent process
        sleep(10);  // Parent not calling wait()
        printf("Parent done\n");
    }
    return 0;
}
