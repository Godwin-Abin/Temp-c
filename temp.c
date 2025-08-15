#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_READINGS 10
#define TEMP_THRESHOLD 40.0
#define LOG_FILE "temp_log.txt"

float get_temperature() {
    return (rand() % 6000) / 100.0;
}

void check_temperature(float temp) {
    if (temp > TEMP_THRESHOLD) {
        printf("Warning: High temperature detected: %.2f°C\n", temp);
    }
}

int main() {
    FILE *file;
    float temperature;
    int i;

    srand(time(NULL));

    file = fopen(LOG_FILE, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Starting Temperature Monitoring...\n\n");

    for (i = 0; i < NUM_READINGS; i++) {
        temperature = get_temperature();
        printf("Reading %d: %.2f°C\n", i + 1, temperature);
        check_temperature(temperature);
        fprintf(file, "Reading %d: %.2f°C\n", i + 1, temperature);
        sleep(2);
    }

    fclose(file);
    printf("\nAll readings saved in '%s'\n", LOG_FILE);

    return 0;
}
