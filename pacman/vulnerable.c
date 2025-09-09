#include <stdlib.h>

void vulnerable() {
    char command[100];
    sprintf(command, "ls %s", getenv("USER"));  // uso inseguro de sprintf
    system(command);  // Horusec puede marcar esto como HIGH
}



void cmd_injection() {
    char cmd[100];
    char user[50] = "test";
    sprintf(cmd, "ls %s", user);  // Inseguro
    system(cmd);
}

// overflow de  buffer
#include <string.h>
void overflow() {
    char buf[10];
    strcpy(buf, "123456789012345");  // Demasiado largo para buf
}
