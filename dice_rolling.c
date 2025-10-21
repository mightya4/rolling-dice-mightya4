#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUF_SZ 1024
#define MAX_NUM 8
#define MIN_NUM 1

int roll_dice(int, int);

int main() {
    char buffer[BUF_SZ] = { 0 };
    int first_num = 0;
    int sec_num = 0;

    printf("Please enter a number to roll: Q to end program. \n");

    while(fgets(buffer, BUF_SZ, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;
        if(buffer[0] == 'Q') {
            printf("Exiting Program\n");
            break;
        }
        if(buffer[0] == 'd') {
            first_num = 1;
            sec_num = atoi(strtok(buffer, "d"));
        } else {
            first_num = atoi(strtok(buffer, "d"));;
            sec_num = atoi(strtok(NULL, "d"));
        }
        printf("%dd%d Dice val: %d\n",first_num, sec_num, roll_dice(first_num, sec_num));
        
        printf("Please enter a number to roll: Q to end program. \n");
    }

    return 0;
}

//roll dice takes the number on the die and the number of sides on the die
int roll_dice(int num_roll, int die_sides) {
    int total = 0;
    //Total is the random integer between 0 and number on the die
    for (int i = 0; i < num_roll; i++){
        total += rand() % (die_sides) + 1;
        printf("Inside roll dice function: %d\n", total);
    }
    return total;
}
