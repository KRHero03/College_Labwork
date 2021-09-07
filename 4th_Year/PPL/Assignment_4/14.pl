
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

evenNumbers([],[]).
evenNumbers([H|T],L1):-
    integer(H),
    (H mod 2 =:=0 -> L1=[H|T1],evenNumbers(T,T1);
    evenNumbers(T,L1) ).

oddNumbers([],[]).
oddNumbers([H|T],L1):-
    integer(H),
    (H mod 2 =:=1 -> L1=[H|T1],oddNumbers(T,T1);
    oddNumbers(T,L1) ).


main:- nl,
    write('Enter a Number (-1 to stop) : '),nl,
    create_list(Nums),
    write('Your List : '),
    write(Nums),
    nl,
    evenNumbers(Nums,E),
    oddNumbers(Nums,O),
    write('Even Elements : '),
    write(E),
    nl,
    write('Odd Elements : '),
    write(O),
    nl.