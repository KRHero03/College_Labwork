extern /*@only@*/ int *glob;

/*@only@*/ int * f(/*@only@*/ int *x, int *y,int *z) /*@globals glob;@*/
{
  int *m = (int *)
  malloc(sizeof(int));
  glob = y;
  free(x);
  m = *x;
  return z;
}