read_num(Num1) :-
    nl,
    write('Enter your Percentage followed by a period.'),nl,
    read(Num1),
    number(Num1).

print_grade(Num1) :- Num1 =< 100, Num1 >= 80, write('Grade A'),nl.
print_grade(Num1) :- Num1 < 80, Num1 >= 60, write('Grade B'),nl.
print_grade(Num1) :- Num1 < 60, Num1 >= 35, write('Grade C'),nl.
print_grade(Num1) :- Num1 < 35, Num1 >= 0, write('Grade D'),nl.
print_grade(_) :- write('Invalid Percentage value!'),nl.

main :-
    read_num(Num1),
    print_grade(Num1).