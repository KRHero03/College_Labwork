read_num(Num1) :-
    nl,
    write('Enter a Number followed by a period.'),nl,
    read(Num1),
    number(Num1).

is_odd(Num1) :-
    X is Num1 mod 2,
    X is 1.

print_odd(Num1) :-
    is_odd(Num1),
    write(Num1),write(' is an odd number.'),nl.

print_odd(Num1) :-
    not(is_odd(Num1)),
    write(Num1),write(' is an even number.'),nl.

main :-
    read_num(Num1),
    print_odd(Num1).