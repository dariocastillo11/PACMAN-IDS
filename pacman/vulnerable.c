#include <stdlib.h>

void vulnerable() {
    char command[100];
    sprintf(command, "ls %s", getenv("USER"));  // uso inseguro de sprintf
    system(command);  // Horusec puede marcar esto como HIGH
}
