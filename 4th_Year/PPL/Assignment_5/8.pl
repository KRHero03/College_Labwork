    
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

count([],_,0).
count([subject(_,S)|T],S,C):-
    count(T,S,C1), 
    C is C1 + 1, 
    !.
count([_|T],S,C):-
    count(T,S,C).

req_sub(S,W):- 
    count(S,W,C), 
    forall(member(subject(_,W1), S),(count(S,W1,C1), C >=C1)).

required_subject(W):-
    findall(X,student(_,_,_,X), LL), 
    append_list(LL,L),
    req_sub(L,W).