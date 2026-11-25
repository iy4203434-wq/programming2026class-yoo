#include <stdio.h>
#include <math.h>
#include <string.h>

#define SIZE 4

double calculateForce(double fx, double fy, double fz) {
    return sqrt(fx * fx + fy * fy + fz * fz);
}

int main(void) {
    char *strCableName[4] = {
        "Cable-1", "Cable-2", "Cable-3", "Cable-4"
    };

    double dArrCableForce[4][3] = {
        {120.0, 50.0, -30.0},
        {-80.0, 140.0, 60.0},
        {45.0, -95.0, 110.0},
        {-60.0, -70.0, -150.0}
    };

    double force[SIZE];
    int index[SIZE] = {0, 1, 2, 3};

    double sumFx = 0.0;
    double sumFy = 0.0;
    double sumFz = 0.0;

    // Calculate the force magnitude of each cable
    for (int i = 0; i < SIZE; i++) {
        force[i] = calculateForce(
            dArrCableForce[i][0],
            dArrCableForce[i][1],
            dArrCableForce[i][2]
        );

        sumFx += dArrCableForce[i][0];
        sumFy += dArrCableForce[i][1];
        sumFz += dArrCableForce[i][2];
    }

    // Print cable forces
    printf("%9s %8s %8s %8s | %8s\n",
           "Force", "Fx", "Fy", "Fz", "|F| (N)");

    for (int i = 0; i < SIZE; i++) {
        printf("%9s %8.1f %8.1f %8.1f | %8.1f\n",
               strCableName[i],
               dArrCableForce[i][0],
               dArrCableForce[i][1],
               dArrCableForce[i][2],
               force[i]);
    }

    // Calculate the resultant force
    double resultant = calculateForce(sumFx, sumFy, sumFz);

    printf("%9s %8.1f %8.1f %8.1f | %8.1f\n",
           "Resultant", sumFx, sumFy, sumFz, resultant);

    // Sort cable indices by force magnitude
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (force[index[i]] < force[index[j]]) {
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    // Print the cable with the largest force
    printf("Largest force : %s (%.1f N)\n",
           strCableName[index[0]], force[index[0]]);

    return 0;
}