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

    fp = fopen("input_day3.txt", "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        for (int i = 0; i < strlen(line)/2; i++) {
            for (int j = strlen(line)/2; j < strlen(line); j++) {
                if (line[i] == line[j]) {
                    if ((int)line[i] > 90) {
                        sum += (int)line[i]-96;
                    } else {
                        sum += (int)line[i]-38;
                    }
                    goto DONE;
                }
            }
        }
        DONE:
    }

    fclose(fp);
    if (line) free(line);

    printf("Sum of priorities: %d\n", sum);

    return 0;
}

