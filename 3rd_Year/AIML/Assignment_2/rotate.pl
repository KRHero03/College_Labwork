split(L,0,[],L).
split([X|Xs],N,[X|Ys],Zs) :- 
    N > 0, 
    N1 is N - 1, 
    split(Xs,N1,Ys,Zs).

rotate(L1,N,L2) :- 
    N >= 0, 
    length(L1,NL1), 
    N1 is N mod NL1, 
    rotate_left(L1,N1,L2).

rotate(L1,N,L2) :- 
    N < 0,
    length(L1,NL1), 
    N1 is NL1 + (N mod NL1), 
    rotate_left(L1,N1,L2).

rotate_left(L,0,L).

rotate_left(L1,N,L2) :- 
    N > 0, 
    split(L1,N,S1,S2), 
    append(S2,S1,L2).