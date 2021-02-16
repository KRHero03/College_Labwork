duplicate(L1,N,L2) :- 
    duplicate(L1,N,L2,N).
duplicate([],_,[],_).
duplicate([_|Xs],N,Ys,0) :- 
    duplicate(Xs,N,Ys,N).
duplicate([X|Xs],N,[X|Ys],K) :- 
    K > 0, 
    K1 is K - 1, 
    duplicate([X|Xs],N,Ys,K1).