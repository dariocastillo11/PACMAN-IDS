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


void low_risk() {
    char secret[20] = "123456"; 
    printf("Secret: %s\n", secret);
}
void medium_risk() {
    char buf[50];
    char input[50] = "user input";  
    snprintf(buf, sizeof(buf), "%s", input);  // uso seguro de snprintf, pero Horusec puede marcarlo como medium por concatenación
}

// --- Low ---
void low_risk() {
    int x = 5;
    int y = 0;
    if (y != 0) {  // operación segura pero Horusec puede marcar un cálculo sospechoso
        int z = x / y;  // Horusec puede advertir por posible división por cero
        printf("%d\n", z);
    }
}