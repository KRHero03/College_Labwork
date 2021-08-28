extern int getVal (/*@in@*/ int *x);

int function_2(/*@out@*/ int *x)
{
    return getVal(x);
}