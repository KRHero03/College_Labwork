sibling(X,Y):-
    parent(D,X),
    parent(D,Y),
    X \= Y.