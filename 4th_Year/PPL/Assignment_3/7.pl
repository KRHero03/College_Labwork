read_nums(A,B,C) :-
    nl,
    write('Enter Coefficient 1 followed by a period.'),nl,
    read(A),
    number(A),
    write('Enter Coefficient 2 followed by a period.'),nl,
    read(B),
    number(B),
    write('Enter Coefficient 3 followed by a period.'),nl,
    read(C),
    number(C).

find_roots(A,B,C) :- 
    A > 0, D is B^2 - 4*A*C, D > 0,Z is sqrt(D), X1 is (-B + Z)/(2*A), X2 is (-B - Z)/(2*A), 
    write('Roots are '),write(X1),write(' and '),write(X2),nl.

find_roots(A,B,C) :- 
    A > 0, D is B^2 - 4*A*C, D =:= 0, X1 is (-B)/(2*A), 
    write('Repeated Root is '),write(X1),nl.

find_roots(A,B,C) :- 
    A > 0, D is B^2 - 4*A*C, D < 0,D1 is -D,Z is sqrt(D1),Real is -B/(2*A),Imaginary is sqrt(Z)/(2*A),
    write('Roots are '),
    write(Real),write('+'),write(Imaginary),write('i'),
    write(' and '),
    write(Real),write('-'),write(Imaginary),write('i'),
    nl.

find_roots(_,_,_) :- write('Invalid Coefficients! Coefficient 1 needs to be non zero.'),nl.

main :-
    read_nums(A,B,C),
    find_roots(A,B,C).
