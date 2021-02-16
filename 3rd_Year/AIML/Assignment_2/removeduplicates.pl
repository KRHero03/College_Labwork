removeduplicates([], []).   
removeduplicates([X], [X]). 

removeduplicates([X,X|T], [X|R]) :-
    removeduplicates([X|T], [X|R]).

removeduplicates([X,Y|T], [X|R]) :-
    X \== Y,
    removeduplicates([Y|T], R).