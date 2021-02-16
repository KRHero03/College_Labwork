% grandparent(GrandParent, GrandChild)
grandparent(X,Y):-
    parent(X,D),
    parent(D,Y).