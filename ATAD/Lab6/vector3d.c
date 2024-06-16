#include "vector3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct vector3d
{
    double x, y, z;
} Vector3d;

PtVector3d vector3dCreate(double x, double y, double z)
{
    PtVector3d vector = (PtVector3d)malloc(1 * sizeof(Vector3d));

    if (vector == NULL)
        return NULL;

    vector->x = x;
    vector->y = y;
    vector->z = z;

    return vector;
}

void vector3dPrint(PtVector3d vec, bool lineBreakAfter)
{
    printf("<%.2f, %.2f, %.2f>", vec->x, vec->y, vec->z);

    if (lineBreakAfter)
        printf("\n");
}

int vector3dX(PtVector3d vec, double *x)
{
    if (vec == NULL)
        return VECTOR3D_NULL;

    *x = vec->x;

    return VECTOR3D_OK;
}

int vector3dY(PtVector3d vec, double *y)
{
    if (vec == NULL)
        return VECTOR3D_NULL;

    *y = vec->y;

    return VECTOR3D_OK;
}

int vector3dZ(PtVector3d vec, double *z)
{
    if (vec == NULL)
        return VECTOR3D_NULL;

    *z = vec->z;

    return VECTOR3D_OK;
}

int vector3dDestroy(PtVector3d *pVec)
{
    if (pVec == NULL)
        return VECTOR3D_NULL;

    free(*pVec);

    return VECTOR3D_OK;
}

PtVector3d vector3dMultiplyByScalar(PtVector3d vec, double scalar)
{
    if (vec == NULL)
        return NULL;

    double x = vec->x * 3;
    double y = vec->y * 3;
    double z = vec->z * 3;

    return vector3dCreate(x, y, z);
}

PtVector3d vector3dAdd(PtVector3d vec1, PtVector3d vec2)
{
    return NULL;
}

int vector3dMagnitude(PtVector3d vec, double *magnitude)
{
    if (vec == NULL)
        return VECTOR3D_NULL;

    double result = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
    *magnitude = result;

    return VECTOR3D_OK;
}

PtVector3d vector3dNormalize(PtVector3d vec)
{
    return NULL;
}
