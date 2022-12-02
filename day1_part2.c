#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int most_calories[3] = {0, 0, 0};
    int current_calorie_count = 0;

    fp = fopen("input_day1.txt", "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] != '\n') {
            int current_calories = 0;
            sscanf(line, "%d", &current_calories);
            current_calorie_count += current_calories;
        } else {
            for (int i = 0; i < 3; i++) {
                if (current_calorie_count > most_calories[i]) {
                    most_calories[i] = current_calorie_count;
                    break;
                }
            }
            current_calorie_count = 0;
        }
    }

    fclose(fp);
    if (line) free(line);

    int total_calories = most_calories[0] + most_calories[1] + most_calories[2];
    printf("Top 3 calories: %d\n", total_calories);
    return 0;
}

