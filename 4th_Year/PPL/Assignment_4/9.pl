create_list(Nums) :-
    read_num(Num),
    create_list(Num,Nums).

create_list(-1,[]) :-
    !.

create_list(Num,[Num|Nums]) :-
    read(Num1),
    create_list(Num1,Nums).

read_num(Num) :-
    read(Num),
    number(Num).

maximum_no([X],X).
maximum_no([H|T],X):-
    maximum_no(T,X),
    H @< X.
maximum_no([H|T],H):-
    maximum_no(T,M),
    M @< H.

minimum_no([X],X).
minimum_no([H|T],X):-
    minimum_no(T,X),
    X @< H.
minimum_no([H|T],H):-
    minimum_no(T,M),
    H @< M.


main:- nl,
    write('Enter a Number (-1 to stop) : '),nl,
    create_list(Nums),
    write('Your List : '),
    write(Nums),
    nl,
    maximum_no(Nums,Max),
    write('Maximum : '),
    write(Max),
    nl,
    minimum_no(Nums,Min),
    write('Minimum : '),
    write(Min),
    nl.