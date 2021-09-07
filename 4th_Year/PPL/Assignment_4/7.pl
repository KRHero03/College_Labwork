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

concatenate(List1, List2, Result):-
   append(List1, List2, Result).

main:- nl,
    write('Enter a Number for List 1 (-1 to stop) : '),nl,
    create_list(L1),
    write('Enter a Number for List 2 (-1 to stop) : '),nl,
    create_list(L2),
    write('Your List 1 : '),
    write(L1),
    nl,
    write('Your List 2 : '),
    write(L2),
    nl,
    write('Concatenated List : '),
    concatenate(L1,L2,L),
    write(L),
    nl.