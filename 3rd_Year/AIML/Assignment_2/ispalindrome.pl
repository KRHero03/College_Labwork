ispalindrome([]).
ispalindrome([_]).
ispalindrome(P) :-
    append([H|T], [H], P),
    ispalindrome(T).