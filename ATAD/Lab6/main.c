#include <stdio.h>
#include <stdlib.h>
#include "vector3d.h"

void printComponentsOf(PtVector3d vec);

int main()
{
    PtVector3d v1 = vector3dCreate(2, 1, -4);
    PtVector3d v2 = vector3dCreate(3, 2, -5);
    PtVector3d v3 = vector3dCreate(4, -9, 10);
    PtVector3d v4 = NULL;

    if (v1 == NULL || v2 == NULL || v3 == NULL)
    {
        printf("No memory available. \n");
        return EXIT_FAILURE;
    }

    vector3dPrint(v1, true);
    vector3dPrint(v3, true);
    vector3dPrint(v2, true);

    printComponentsOf(v1);
    printComponentsOf(v4);

    PtVector3d scalarMultiplication = vector3dMultiplyByScalar(v1, 3);
    vector3dPrint(scalarMultiplication, true);

    double magnitude;
    vector3dMagnitude(v1, &magnitude);
    printf("Magnitude: %.2f\n", magnitude);

    vector3dDestroy(&v1);
    vector3dDestroy(&v2);
    vector3dDestroy(&v3);
    vector3dDestroy(&v4);
    vector3dDestroy(&scalarMultiplication);

    return EXIT_SUCCESS;
}

void printComponentsOf(PtVector3d vec)
{
    double x = 0;
    double y = 0;
    double z = 0;

    vector3dX(vec, &x);
    vector3dY(vec, &y);
    vector3dZ(vec, &z);

    printf("x = <%.2f> | y = <%.2f> | z = <%.2f>\n", x, y, z);
}