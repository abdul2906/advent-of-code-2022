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
        switch (own_move) {
            case 'X':
                total_points += 1;
                switch (opponent_move) {
                    case 'A':
                        total_points += 3;
                        break;
                    case 'B':
                        total_points += 0;
                        break;
                    case 'C':
                        total_points += 6;
                        break;
                }
                break;
            case 'Y':
                total_points += 2;
                switch (opponent_move) {
                    case 'A':
                        total_points += 6;
                        break;
                    case 'B':
                        total_points += 3;
                        break;
                    case 'C':
                        total_points += 0;
                        break;
                }
                break;
            case 'Z':
                total_points += 3;
                switch (opponent_move) {
                    case 'A':
                        total_points += 0;
                        break;
                    case 'B':
                        total_points += 6;
                        break;
                    case 'C':
                        total_points += 3;
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

