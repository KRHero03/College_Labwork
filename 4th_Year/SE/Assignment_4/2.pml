
proctype euclid_gcd(int a,b) {
    printf("GCD(%d,%d): \n",a,b);
    if
    :: (b == 0) -> printf("%d\n", a);
    :: (b != 0) -> run euclid_gcd(b, a % b);
    fi
}

init {
    run euclid_gcd(21,60);
}