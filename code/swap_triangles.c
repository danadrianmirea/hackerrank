#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle {
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

void swapint(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

float area(triangle* tr) {
    float p = (float)(tr->a + tr->b + tr->c) / 2;
    return sqrt(p * (p - tr->a) * (p - tr->b) * (p - tr->c));
}

void swaptri(triangle* t1, triangle* t2) {
    swapint(&t1->a, &t2->a);
    swapint(&t1->b, &t2->b);
    swapint(&t1->c, &t2->c);
}

void sort_by_area(triangle* tr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (area(&tr[i]) > area(&tr[j])) {
                swaptri(&tr[i], &tr[j]);
            }
        }
    }
}

int main_triangles() {
    const char* input[] = {
        "3",        // Number of triangles
        "7 24 25",  // Triangle 1
        "5 12 13",  // Triangle 2
        "3 4 5"     // Triangle 3
    };

    int n;
    sscanf(input[0], "%d", &n); // Read the number of triangles
    triangle* tr = malloc(n * sizeof(triangle));

    for (int i = 0; i < n; i++) {
        sscanf(input[i + 1], "%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }

    sort_by_area(tr, n);

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }

    free(tr);
    return 0;
}
