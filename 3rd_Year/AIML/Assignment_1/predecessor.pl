predecessor(X,Y):-
    parent(X,Z),
    predecessor(Z,Y).

predecessor(X,Y):-
    parent(X,Y).