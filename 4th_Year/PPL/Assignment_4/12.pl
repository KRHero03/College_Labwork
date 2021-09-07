
create_list(Nums) :-
    read_num(Num),
    create_list(Num,Nums),
    number(Num).

create_list(-1,[]) :-
    !.

create_list(Num,[Num|Nums]) :-
    read(Num1),
    create_list(Num1,Nums),
    number(Num).

read_num(Num) :-
    read(Num),
    number(Num).


main:- nl,
    write('Enter a Number (-1 to stop) : '),nl,
    create_list(Nums),
    write('Enter position : '),nl,
    read_num(S),
    write('Your List : '),
    write(Nums),
    nl,
    write('Required Position : '),
    write(S),
    nl,
    write('Required Element : '),
    nth0(S,Nums,X),
    write(X),
    nl.