

n_queens(N, Qs) :-
   length(Qs, N),
   Qs ins 1..N,
   safe_queens(Qs).

safe_queens([]).
safe_queens([Q|Qs]) :-
   safe_queens(Qs, Q, 1),
   safe_queens(Qs).

safe_queens([], _, _).
safe_queens([Q|Qs], Q0, D0) :-
   Q0 #\= Q,
   abs(Q0 - Q) #\= D0,
   D1 #= D0 + 1,
   safe_queens(Qs, Q0, D1).

n_queens_dfs(N,Qs):-
   statistics(walltime, [TimeSinceStart | [TimeSinceLastCall]]),
   length(Qs,N),
   maplist(between(1,N),Qs),
   n_queens(N,Qs),
   statistics(walltime, [NewTimeSinceStart | [ExecutionTime]]),
   write('Execution took '), write(ExecutionTime), write(' ms.'), nl.


n_queens_bfs(N,Qs):-
   statistics(walltime, [TimeSinceStart | [TimeSinceLastCall]]),
   n_queens(N,Qs),
   maplist(between(1,N),Qs),
   statistics(walltime, [NewTimeSinceStart | [ExecutionTime]]),
   write('Execution took '), write(ExecutionTime), write(' ms.'), nl.