%subList means that every element of L1 is also in L2

subList([],_).

subList([H1|T1],L2) :-
	member(H1,L2),
	subList(T1,L2).

%difference(L1,L2,L) computes L which is all elements of L1 not in L2

difference([],_,[]).

difference([H1|T1],L2,L) :-
	member(H1,L2),
	difference(T1,L2,L).

difference([H1|T1],L2,[H1|T]) :-
	\+member(H1,L2),
	difference(T1,L2,T).

%sift(L,N,Result) computes result with all values grater than N removed

sift([],_,[]).

sift([H|T],N,R) :-
	H > N, !,
	sift(T,N,R).

sift([H|T],N,[H|RT]) :-
	sift(T,N,RT).

%common(L1,L2,I) computes I which is a list of common elements

common([],_,[]).

common([H1|T1],L2,[H1|IT]) :-
	member(H1,L2),
	common(T1,L2,IT),
	\+member(H1,IT), !.

common([_|T1],L2,I) :-
	common(T1,L2,I).

%delete(L,Result) removes every other element from L to for Result

delete([],[]).

delete([H1,_|T],[H1|RT]) :-
	!,
	delete(T,RT).

delete([E],[E]).

% process(L1,L2,C,I) takes consisten information from L1 and L2 to make
% C and inconsistent information to make L2

process(_,[],[],[]).

process(L1,[H2|T2],[H2|CT],I) :-
	(Name,Age,_) = H2,
	member((Name,Age),L1),
	!,
	process(L1,T2,CT,I).

process(L1,[H2|T2],C,[H2|IT]) :-
	process(L1,T2,C,IT).

%dupli(L,X) duplicates all elements in L to make X

dupli([],[]).

dupli([H|T],[H,H|XT]) :-
	dupli(T,XT).

%make(E,N,L) makes a list of length N made up of element E

make(_,0,[]) :- !.

make(E,N,[E|T]) :-
	N_ is N - 1,
	make(E,N_,T).

%dupli(L,N,X) duplicates all elements in L N times to make X

dupli([],_,[]).

dupli([H|T],N,X) :-
	make(H,N,SL),
	dupli(T,N,X_),
	append(SL,X_,X).

%drop(L,N,X) drops every Nth value from L to make X

drop(L,N,L) :-
	length(L,Len),
	Len < N.

drop(L,N,X) :-
	N_ is N - 1,
	length(L1,N_),
	append(L1,[_|L2],L),
	drop(L2,N,X_),
	append(L1,X_,X).

%split(L,N,L1,L2) splits L into L1 of length N and L2

split(L,N,L1,L2) :-
	length(L1,N),
	append(L1,L2,L).