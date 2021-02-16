last([Y|Tail]):-
    last(Tail).

last([X]):-
    write(X).