#ifdef __ia16__
#define NMAX 30
#else
#define NMAX 3000
#endif
#define MEASURE_TIME 1

static double a[NMAX][NMAX], c[NMAX][NMAX];

void dsyrk(long N) 
{
  int i,j,k;

#pragma scop
  for (i=0; i<N; i++) {
    for (j=0; j<N; j++) {
      for (k=j; k<N; k++) {
        c[j][k] += a[i][j] * a[i][k];
      }
    }
  }
#pragma endscop
}

/* { dg-final { scan-tree-dump-times "number of SCoPs: 1" 1 "graphite" } } */
