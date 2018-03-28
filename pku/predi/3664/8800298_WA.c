#include <stdio.h>
#include <stdlib.h>

struct vote_f {
    int a;
    int b;
    int cownum;
} votes[50000];

comparea (struct vote_f *a, struct vote_f *b) { return b->a - a->a; }
compareb (struct vote_f *a, struct vote_f *b) { return b->b - a->b; }

main() {
    FILE *fin  = fopen ("elect.in", "r");
    FILE *fout = fopen ("elect.out", "w");
    int n, k, i;

    fscanf (fin, "%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        fscanf (fin, "%d %d", &votes[i].a, &votes[i].b);
        votes[i].cownum = i;
    }
    qsort(votes, n, sizeof (struct vote_f), comparea);
    qsort(votes, k, sizeof (struct vote_f), compareb);
    fprintf (fout, "%d\n", votes[0].cownum+1);
    exit (0);
}