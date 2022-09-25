#include <stdio.h>
#define VMAX 21

typedef struct {
    char name[20];
    int height;
    double vision;
} PhysCheck;

double ave_height(const PhysCheck dat[], int n) {
    int i;
    double sum = 0;
    for (i = 0; i < n; i++)
        sum += dat[i].height;
    return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[]) {
    int i;
    for (i = 0; i < VMAX; i++)
        dist[i] = 0;
    for (i = 0; i < VMAX; i++)
        if(dat[i].vision >= 0.0 && dat[i].vision <= VMAX/10.0)
            dist[(int)(dat[i].vision * 10)]++;
}

int main(void) {
    int i;
    PhysCheck x[] = {
        {"이요셉", 180, 0.3},
        {"박현규", 162, 0.5},
        {"김이박", 134, 1.0}};

    int nx = sizeof(x) / sizeof(x[0]);

    int dvist[VMAX];

    for (i = 0; i < nx; i++)
        printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
    printf("\n평균 키 : %5.1f cm\n", ave_height(x, nx));
    dist_vision(x, nx, dvist);

    for (i = 0; i < VMAX; i++)
        printf("%3.1f ~ : %2d명\n", i / 10.0, dvist[i]);

    return 0;
}