#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUF_SZ 1024
int roll_dice(int, int);

int main() {
    char buffer[BUF_SZ] = { 0 };

    while(fgets(buffer, BUF_SZ, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;
    }

    return 0;
}

int roll_dice(int die_num, int die_sz){
    int total = 0;

    for (int i = 0; i < die_num; i++){
        total += rand() % die_sz + 1;
    }
    return total;
}
