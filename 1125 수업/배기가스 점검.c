#include <stdio.h>

#define ENGINE 3
#define DATA 5

// Sort temperature values in ascending order
void sorting(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(void) {

    // Given temperature data
    double dArrEngTemp1[5] = {
        612.5, 618.0, 615.3, 620.1, 616.4
    };

    double dArrEngTemp2[5] = {
        605.2, 648.8, 598.7, 652.3, 610.0
    };

    double dArrEngTemp3[5] = {
        630.0, 628.4, 633.9, 631.2, 629.5
    };

    char *strEngName[3] = {
        "ENG-A", "ENG-B", "ENG-C"
    };

    double dEst[3][5];

    double min[ENGINE];
    double max[ENGINE];
    double range[ENGINE];

    // Copy temperature data into 2D array
    for (int i = 0; i < DATA; i++) {
        dEst[0][i] = dArrEngTemp1[i];
        dEst[1][i] = dArrEngTemp2[i];
        dEst[2][i] = dArrEngTemp3[i];
    }

    // Calculate min, max and range
    for (int i = 0; i < ENGINE; i++) {

        double temp[DATA];

        for (int j = 0; j < DATA; j++) {
            temp[j] = dEst[i][j];
        }

        sorting(temp, DATA);

        min[i] = temp[0];
        max[i] = temp[DATA - 1];

        range[i] = max[i] - min[i];
    }

    // Print temperature data
    printf("%9s", "Engine");

    for (int i = 0; i < DATA; i++) {
        printf("%8s", i == 0 ? "#1" :
                       i == 1 ? "#2" :
                       i == 2 ? "#3" :
                       i == 3 ? "#4" : "#5");
    }

    printf(" | %8s %8s %8s\n", "Min", "Max", "Range");

    for (int i = 0; i < ENGINE; i++) {

        printf("%9s", strEngName[i]);

        for (int j = 0; j < DATA; j++) {
            printf("%8.1f", dEst[i][j]);
        }

        printf(" | %8.1f %8.1f %8.1f\n",
               min[i], max[i], range[i]);
    }

    // Find engine with largest temperature variation
    int largestIndex = 0;

    for (int i = 1; i < ENGINE; i++) {
        if (range[i] > range[largestIndex]) {
            largestIndex = i;
        }
    }

    printf("Largest variation : %s (%.1f deg C)\n",
           strEngName[largestIndex],
           range[largestIndex]);

    return 0;
}