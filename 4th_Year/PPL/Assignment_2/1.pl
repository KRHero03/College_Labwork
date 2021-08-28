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

husband(bob,juliet).
husband(peter,lisa).

child(X,Y) :- parent(Y,X).

mother(X,Y) :- parent(X,Y),female(X).
father(X,Y) :- parent(X,Y),male(X).

wife(X,Y) :- husband(Y,X).

son(X,Y) :- parent(Y,X),male(X).
daughter(X,Y) :- parent(Y,X),female(X).

brother(X,Y) :- parent(Z,X),parent(Z,Y),X \= Y,male(X).
sister(X,Y) :- parent(Z,X),parent(Z,Y),X \= Y,female(X).

uncle(X,Y) :- brother(X,F),parent(F,Y),not(parent(X,Y)),male(X).
aunt(X,Y) :- sister(X,F),parent(F,Y),not(parent(X,Y)),female(X).

nephew(X,Y) :- parent(G,Y),parent(G,F),parent(F,X),not(parent(Y,X)),male(X).
niece(X,Y) :- parent(G,Y),parent(G,F),parent(F,X),not(parent(Y,X)),female(X).
