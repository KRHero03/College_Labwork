randomizer(X, N,Y) :-
    random_permutation(X, L1),
    take(N,L1,Y).

take(N, _, Xs) :- 
    N =< 0, 
    !, 
    N =:= 0, 
    Xs = [].
take(_, [], []).
take(N, [X|Xs], [X|Ys]) :- 
    M is N-1, 
    take(M, Xs, Ys).
