countlistelements([X|Y]):-
    count([X|Y],0).
countlistelements([]):-
    write(0).


count([],K):-
    write(K).
count([X|Y],K):-
    K1 is K + 1,
    count(Y,K1).