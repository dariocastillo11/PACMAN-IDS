#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void vulnerable() {
    char command[100];
    sprintf(command, "ls %s", getenv("USER"));  // uso inseguro de sprintf
    system(command);  // HIGH
}

void cmd_injection() {
    char cmd[100];
    char user[50] = "test";
    sprintf(cmd, "ls %s", user);  // HIGH
    system(cmd);
}

void overflow() {
    char buf[10];
    strcpy(buf, "123456789012345");  // HIGH
}

// ejemplo de fallas nivel  MEDIO.  uso de función insegura fgets sin límites
void medium_risk() {
    char buf[50];
    fgets(buf, 50, stdin);  // Medium
}

//EJEMPLO DE FALLA NIVEL BAJO . variable sensible sin protección
void low_risk() {
    char secret[20] = "123456";  // Low
    printf("Secret: %s\n", secret);
}
