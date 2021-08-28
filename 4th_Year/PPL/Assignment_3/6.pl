read_nums(Num1,Num2) :-
    nl,
    write('Enter Breadth followed by a period.'),nl,
    read(Num1),
    number(Num1),
    write('Enter Length followed by a period.'),nl,
    read(Num2),
    number(Num2).


check_square(Num1,Num2) :- Num1 > 0, Num2 > 0, Num1 =:= Num2, write('It is a square!'),nl.
check_square(Num1,Num2) :- Num1 > 0, Num2 > 0, Num1 =\= Num2, write('It is a rectangle!'),nl.
check_square(_,_) :- write('Invalid value for Breadth or Length!'),nl.

main :-
    read_nums(Num1,Num2),
    check_square(Num1,Num2).