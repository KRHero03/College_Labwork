female(mary).
female(sandra).
female(juliet).
female(lisa).

male(peter).
male(paul).
male(dick).
male(bob).
male(harry).

parent(bob, lisa).
parent(bob, paul).
parent(bob, mary).
parent(juliet, lisa).
parent(juliet, paul).
parent(juliet, mary).
parent(peter, harry).
parent(lisa, harry).
parent(mary, dick).
parent(mary, sandra).

father(X,Y) :- male(X),parent(X,Y).
sister(X,Y) :- parent(Z,X),parent(Z,Y),X \= Y,female(X).
grandmother(X,Y) :- parent(X,Z),parent(Z,Y),female(X).
cousin(X,Y) :- parent(A,B),parent(B,X),parent(A,D),parent(D,Y),B\=D.