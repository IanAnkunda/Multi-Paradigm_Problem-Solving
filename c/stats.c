/**
 * Simple procedural program to compute mean, median, and mode.
 */

#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

double calculate_mean(int arr[], int length) {
    long sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return (double)sum / length;
}

double calculate_median(int arr[], int length) {
    int *sorted = malloc(length * sizeof(int));
    if (!sorted) return 0.0;

    for (int i = 0; i < length; i++) {
        sorted[i] = arr[i];
    }

    qsort(sorted, length, sizeof(int), compare_ints);

    double result;
    if (length % 2 == 1) {
        result = sorted[length / 2];
    } else {
        result = (sorted[length / 2 - 1] + sorted[length / 2]) / 2.0;
    }

    free(sorted);
    return result;
}

int calculate_mode(int arr[], int length) {
    int mode_value = arr[0];
    int highest_count = 1;

    for (int i = 0; i < length; i++) {
        int count = 1;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] == arr[i]) count++;
        }

        if (count > highest_count) {
            highest_count = count;
            mode_value = arr[i];
        }
    }
    return mode_value;
}

int main() {
    int numbers[] = {1, 2, 2, 3, 4, 5, 5, 5};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Input values: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    printf("Mean: %.2f\n", calculate_mean(numbers, length));
    printf("Median: %.2f\n", calculate_median(numbers, length));
    printf("Mode: %d\n", calculate_mode(numbers, length));

    return 0;
}
