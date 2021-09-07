
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

pal([]).
pal([_]).
pal(Pal) :-
    append([H|T], [H], Pal),
    pal(T).

main:- nl,
    write('Enter a Number (-1 to stop) : '),nl,
    create_list(Nums),
    write('Your List : '),
    write(Nums),
    nl,
    pal(Nums),
    nl.