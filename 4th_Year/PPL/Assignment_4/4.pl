create_list(L):-
    read(C),
    create_list(C,L),
    is_alpha(C).

create_list(-1,[]) :- !.

create_list(C,[C | L]) :-
    read(C1),
    create_list(C1,L),
    is_alpha(C).

vowel(a).
vowel(e).
vowel(i).
vowel(o).
vowel(u).

count_vowels([], 0).

count_vowels([X|T], N):-
    vowel(X),
    count_vowels(T,N1),
    N is N1+1.

count_vowels([X|T], N):-
    count_vowels(T,N).

main:- nl,
    write('Enter a Letter (-1 to stop) : '),nl,
    create_list(L),
    write('Your List : '),
    write(L),
    nl,
    write('No. of Vowels : '),
    count_vowels(L,Count),
    write(Count),
    nl.
