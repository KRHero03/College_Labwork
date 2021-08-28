man(marcus).
man(caesar).
ruler(caesar).
trytoassassinate(marcus,caesar).

person(X) :- man(X).
roman(X):- loyal(X,caesar);hate(X,caesar).

loyal(X,Y) :- not(trytoassassinate(X,Y)),ruler(Y),person(X).
hate(X,Y) :- trytoassassinate(X,Y),ruler(Y),person(X).