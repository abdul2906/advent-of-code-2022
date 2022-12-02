#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char *line = NULL;
    ssize_t len = 0;
    ssize_t read;
    int total_points = 0;

    fp = fopen("input_day2.txt", "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        char opponent_move;
        char own_move;
        sscanf(line, "%c %c", &opponent_move, &own_move);
        switch (opponent_move) {
            case 'A':
                switch (own_move) {
                    case 'X':
                        total_points += 3;
                        break;
                    case 'Y':
                        total_points += 4;
                        break;
                    case 'Z':
                        total_points += 8;
                        break;
                }
                break;
            case 'B':
                switch (own_move) {
                    case 'X':
                        total_points += 1;
                        break;
                    case 'Y':
                        total_points += 5;
                        break;
                    case 'Z':
                        total_points += 9;
                        break;
                }
                break;
            case 'C':
                switch (own_move) {
                    case 'X':
                        total_points += 2;
                        break;
                    case 'Y':
                        total_points += 6;
                        break;
                    case 'Z':
                        total_points += 7;
                        break;
                }
                break;
        } 
    }

    fclose(fp);
    if (line) free(line);

    printf("Total points: %d\n", total_points);
    return 0;
}

