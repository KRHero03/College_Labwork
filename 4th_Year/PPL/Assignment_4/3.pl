create_list(Nums) :-
    read(Num),
    number(Num),
    create_list(Num,Nums).

create_list(-1,[]) :-
    !.

create_list(Num,[Num|Nums]) :-
    read(Num1),
    create_list(Num1,Nums).

list_size([],0).
list_size([_|Xs],L) :- 
    list_size(Xs,N), 
    L is N+1 .

main:- nl,
    write('Enter a Number (-1 to stop) : '),nl,
    create_list(Nums),
    write('Your List : '),
    write(Nums),
    nl,
    write('Size of List : '),
    list_size(Nums,Size),
    write(Size).