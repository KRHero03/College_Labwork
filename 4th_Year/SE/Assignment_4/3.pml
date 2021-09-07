proctype fact(int n; chan p) {	
    
    // create channel which can have 1 integer
    chan child = [1] of { int };
    int result;
    if
    :: (n <= 1) -> p!1
    :: (n >= 2) ->
        run fact(n-1, child);
        // receives result from channel
        child?result;
        // sends message to channel
        p!n*result;
    fi
}
init {	
    // create channel which can have 1 integer
    chan child = [1] of { int };
    int result;
    // pass in channel to the function to store recursive returned values
    run fact(7, child);
    // get result from channel
    child?result;
    printf("Factorial: %d\n", result)
}