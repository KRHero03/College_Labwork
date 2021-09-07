
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

product([X],X).

product([H|T],X) :-
    product(T,Y),
    X is H*Y.

main:- nl,
    write('Enter a Number (-1 to stop) : '),nl,
    create_list(Nums),
    write('Your List : '),
    write(Nums),
    nl,
    write('Product of Elements : '),
    product(Nums,X),
    write(X),
    nl.