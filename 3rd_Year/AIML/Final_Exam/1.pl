drop(E,[E|T],T).

drop(E,[H|T],[H|T1]) :-
    drop(E,T,T1).

drop(E,[],[]).
