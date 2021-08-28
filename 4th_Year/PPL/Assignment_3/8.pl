read_num(Num1) :-
    nl,
    write('Enter a Number followed by a period.'),nl,
    read(Num1),
    number(Num1).



check(Num1) :- Num1 > 0, write(Num1),write(' is a positive number!'),nl.
check(Num1) :- Num1 < 0, write(Num1),write(' is a negative number!'),nl.
check(Num1) :- Num1 =:= 0, write(Num1),write(' is a 0!'),nl.

main :-
    read_num(Num1),
    check(Num1).