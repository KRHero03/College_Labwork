create_list(Nums) :-
    read(Num),
    number(Num),
    create_list(Num,Nums).

create_list(-1,[]) :-
    !.

create_list(Num,[Num|Nums]) :-
    read(Num1),
    create_list(Num1,Nums).

list_sum([Item], Item).
list_sum([Item1,Item2 | Tail], Total) :-
    Sum is Item1 + Item2,
    list_sum([Sum|Tail], Total).

main:- nl,
    write('Enter a Number (-1 to stop) : '),nl,
    create_list(Nums),
    write('Your List : '),
    write(Nums),
    nl,
    write('Sum of List Elements : '),
    list_sum(Nums,Sum),
    write(Sum).