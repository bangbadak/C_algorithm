#include <stdio.h>
#include <stdlib.h>

int int_cmpr(const int *a, const int *b) {
    if(*a < *b)
        return 1;
    else if(*a > *b)
        return -1;
    else
        return 0;
}

int main(void) {
    int i, nx, ky;
    int *x;
    int *p;

    puts("Search using bsearch function");
    printf("Number of elements : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    printf("input sorted by descending order.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);

    for (i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] > x[i - 1]);
    }

    printf("Search value");
    scanf("%d", &ky);
    p = bsearch(&ky,
                x,
                nx,
                sizeof(int),
                (int (*)(const void *, const void *))int_cmpr);
    if(p == NULL)
        puts("failed to search");
    else
        printf("%d is at x[%d]", ky, (int)(p - x));
    free(x);
    return 0;
}