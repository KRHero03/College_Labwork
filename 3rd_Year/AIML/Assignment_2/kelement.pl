kelement([X|Y],K):-
    K1 is K - 1,
    kelement(Y,K1).

kelement([],K):-
    false.

kelement([Y|X],1):-
    write(Y).