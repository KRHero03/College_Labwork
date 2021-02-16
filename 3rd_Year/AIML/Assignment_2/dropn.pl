drop(1,[_|T],T).
drop(P,[X|Y],[X|R]):-
    P1 is P-1,
    drop(P1,Y,R).