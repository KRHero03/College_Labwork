student(u223, ram, address(shlimar_park, surat, 395001),[subject(t2,physics),subject(t1,algebra),
subject(t3,english), subject(t5,hindi)]).
student(u226, lakshman, address(honey_park, delhi, 110002), [subject(t3, history), subject(t4,science),
subject(t1,geometry), subject(t5, hindi)] ).
student(u227, bharat, address(shally_tower, mumbai,400004 ), [subject(t1,geometry), subject(t2,
chemistry), subject(t3,english_grammer)] ).

append_list([],[]).
append_list([H|T],W):-
    append_list(T,W1), 
    append(W1,H,W).

unique([],[]).
unique([subject(H,_)|T],[H|T1]):-
    forall(member(subject(K,_),T), K \= H),unique(T,T1),!.
unique([_|T],T1):-unique(T,T1).

teaches(_,[],[]).
teaches(T,[subject(T,Subj)|Tail], Y):-
    member(subject(T,Subj), Tail), 
    teaches(T,Tail,Y).
teaches(T,[subject(T,Subj)|Tail], [Subj|Rest]):-
    teaches(T,Tail,Rest).
teaches(T,[_|Tail], Y):-
    teaches(T,Tail,Y).

subjects:- 
    findall(X,student(_,_,_,X),LL),
    append_list(LL,L), 
    unique(L,Teachers),
    forall(member(T,Teachers), 
        (
            teaches(T, L, Ans), 
            write(T), 
            write(Ans),
            nl
        )
    ).