read_nums(Num1,Num2,Num3) :-
    nl,
    write('Enter Number 1 followed by a period.'),nl,
    read(Num1),
    number(Num1),
    write('Enter Number 2 followed by a period.'),nl,
    read(Num2),
    number(Num2),
    write('Enter Number 3 followed by a period.'),nl,
    read(Num3),
    number(Num3).

find_greatest(X,Y,Z) :- X > Y,X > Z,write('Greatest Number is '),write(X),nl.
find_greatest(X,Y,Z) :- Y > X,Y > Z,write('Greatest Number is '),write(Y),nl.
find_greatest(X,Y,Z) :- Z > X,Z > Y,write('Greatest Number is '),write(Z),nl.
find_greatest(X,Y,Z) :- X =:= Y, X > Z,write('Greatest Number is '),write(X),nl.
find_greatest(X,Y,Z) :- X > Y, X =:= Z,write('Greatest Number is '),write(X),nl.
find_greatest(X,Y,Z) :- Y > X, Y =:= Z,write('Greatest Number is '),write(Y),nl.
find_greatest(X,Y,Z) :- X =:= Y,Y =:= Z,write('All three numbers are equal'),nl.


find_least(X,Y,Z) :- X < Y,X < Z,write('Least Number is '),write(X),nl.
find_least(X,Y,Z) :- Y < X,Y < Z,write('Least Number is '),write(Y),nl.
find_least(X,Y,Z) :- Z < X,Z < Y,write('Least Number is '),write(Z),nl.
find_least(X,Y,Z) :- X =:= Y, X < Z,write('Least Number is '),write(X),nl.
find_least(X,Y,Z) :- X < Y, X =:= Z,write('Least Number is '),write(X),nl.
find_least(X,Y,Z) :- Y < X, Y =:= Z,write('Least Number is '),write(Y),nl.
find_least(X,Y,Z) :- X =:= Y,Y =:= Z,write('All three numbers are equal'),nl.

main :-
    read_nums(Num1,Num2,Num3),
    find_greatest(Num1,Num2,Num3),
    find_least(Num1,Num2,Num3).

