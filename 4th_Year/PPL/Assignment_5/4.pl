    
student(u223, ram, address(shlimar_park, surat, 395001),[subject(t2,physics),subject(t1,algebra),
subject(t3,english), subject(t5,hindi)]).
student(u226, lakshman, address(honey_park, delhi, 110002), [subject(t3, history), subject(t4,science),
subject(t1,geometry), subject(t5, hindi)] ).
student(u227, bharat, address(shally_tower, mumbai,400004 ), [subject(t1,geometry), subject(t2,
chemistry), subject(t3,english_grammer)] ).

count_subjects([subject(Teacher,N)|T],Teacher):-
    write(N),
    nl,
    count_subjects(T,Teacher).

count_subjects([_|T],Teacher):-
    count_subjects(T,Teacher).

count_subjects([],_).

print_subjects(Teacher):-
    student(_,_,_,X),
    count_subjects(X,Teacher).