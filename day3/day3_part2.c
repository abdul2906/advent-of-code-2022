#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
    FILE *fp;
    char *line = NULL;
    ssize_t len = 0;
    ssize_t read;
    int sum = 0;
    int idx = 1;
    char *buff[2] = {"", ""};

    fp = fopen("input_day3.txt", "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        if (idx % 3 == 0) {
            for (int i = 0; i < strlen(buff[0]); i++) {
                for (int j = 0; j < strlen(buff[1]); j++) {
                    for (int k = 0; k < strlen(line); k++) {
                        if (buff[0][i] == buff[1][j] && buff[0][i] == line[k]) {
                            if ((int)line[k] > 90) {
                                sum += (int)line[k]-96;
                            } else {
                                sum += (int)line[k]-38;
                            }
                            free(buff[0]);
                            free(buff[1]);
                            goto DONE;
                        }
                    }
                }
            }
        } else {
            buff[idx % 3 -1] = (char*)malloc(strlen(line));
            strcpy(buff[idx % 3 -1], line);
        } 
        DONE: idx++;    
    }

    fclose(fp);
    if (line) free(line);

    printf("Sum of priorities: %d\n", sum);

    return 0;
}

