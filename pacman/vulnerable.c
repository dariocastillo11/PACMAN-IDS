#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// --- HIGH ---
void high_vulnerable() {
    char command[100];
    sprintf(command, "ls %s", getenv("USER"));  // HIGH
    system(command);
}

void high_cmd_injection() {
    char cmd[100];
    char user[50] = "test";
    sprintf(cmd, "ls %s", user);  // HIGH
    system(cmd);
}

void high_overflow() {
    char buf[10];
    strcpy(buf, "123456789012345");  // HIGH: buffer overflow
}

// --- MEDIUM ---
void medium_fgets() {
    char buf[50];
    fgets(buf, 50, stdin);  // MEDIUM: uso inseguro
}

void medium_snprintf() {
    char buf[50];
    char input[50] = "user input";
    snprintf(buf, sizeof(buf), "%s", input);  // MEDIUM: concatenación
}

// --- LOW ---
void low_print_secret() {
    char secret[20] = "123456"; 
    printf("Secret: %s\n", secret);  // LOW
}

void low_division_check() {
    int x = 5;
    int y = 0;
    if (y != 0) {
        int z = x / y;  // LOW: posible división por cero
        printf("%d\n", z);
    }
}
