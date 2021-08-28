
read_nums(Num1,Num2) :-
    nl,
    write('>    Enter number 1 followed by a period.'),nl,
    read(Num1),
    number(Num1),
    write('>    Enter number 2 followed by a period.'),nl,
    read(Num2),
    number(Num2).
    

run_opt(1) :-
    read_nums(Num1,Num2),
    write('Addition of 2 Numbers is : '),
    Sum is Num1 + Num2,
    write(Sum),nl.
run_opt(2) :-
    read_nums(Num1,Num2),
    write('Subtraction of 2 Numbers is : '),
    Diff is Num1 - Num2,
    write(Diff),nl.
run_opt(3) :-
    read_nums(Num1,Num2),
    write('Multiplication of 2 Numbers is : '),
    Mul is Num1*Num2,
    write(Mul),nl.
run_opt(4) :-
    read_nums(Num1,Num2),
    Num2 =\= 0,
    write('Division of 2 Numbers is : '),
    Div is Num1/Num2,
    write(Div),nl.    

run_opt(0) :- write('Bye'), nl, halt.
run_opt(_) :- write('Invalid option'), nl.



main :-
    nl,
    write('>   Menu based Calculator'), nl,
    write('>   Enter a selection followed by a period.'), nl,
    write('>   1. Add 2 numbers'), nl,
    write('>   2. Subtract 2 numbers'), nl,
    write('>   3. Multiply 2 numbers'), nl,
    write('>   4. Divide 2 numbers'), nl,
    write('>   0. Exit'), nl, nl,
    read(Choice),
    run_opt(Choice), main.