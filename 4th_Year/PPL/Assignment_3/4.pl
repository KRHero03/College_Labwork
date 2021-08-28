read_num(Num1) :-
    nl,
    write('Enter a Year followed by a period.'),nl,
    read(Num1),
    number(Num1).

is_leap_year(Num1) :- 0 is Num1 mod 4, not(0 is Num1 mod 100).
is_leap_year(Num1) :- 0 is Num1 mod 100, 0 is Num1 mod 400. 

print_leap(Num1) :- Num1 >= 0, is_leap_year(Num1), write(Num1),write(' is a leap year.'),nl. 
print_leap(Num1) :- Num1 >= 0, not(is_leap_year(Num1)), write(Num1),write(' is not a leap year.'),nl. 

print_leap(_) :- nl, write('Invalid Year!'),nl.

main :-
    read_num(Num1),
    print_leap(Num1).