/*
   pair_forces.c
   C version of the spring force calculation (Task 6).

   Same algorithm as the python double loop:
   for every pair i < j, if the distance is smaller than the cutoff rc,
   the spring force k (r - r0) acts along the line joining the two atoms.

   pos    : array of length 2*n  -> x0, y0, x1, y1, ...
   forces : array of length 2*n  (output)

   compile (linux / mac):   gcc -O2 -shared -fPIC -o libpairforces.so pair_forces.c -lm
   compile (windows/mingw): gcc -O2 -shared -o pair_forces.dll pair_forces.c
*/

#include <math.h>

void pair_forces_c(int n, double *pos, double *forces, double k, double r0, double rc)
{
    int i, j;
    double dx, dy, dist, f;

    for (i = 0; i < 2 * n; i++) {
        forces[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            dx = pos[2 * j] - pos[2 * i];
            dy = pos[2 * j + 1] - pos[2 * i + 1];
            dist = sqrt(dx * dx + dy * dy);
            if (dist < rc && dist > 0.0) {
                f = k * (dist - r0) / dist;
                forces[2 * i]     += f * dx;
                forces[2 * i + 1] += f * dy;
                forces[2 * j]     -= f * dx;   /* Newton's third law */
                forces[2 * j + 1] -= f * dy;
            }
        }
    }
}
