
%Reverse a list

reverse([],[]).

reverse([H|T],RL) :-
	reverse(T,SRL),
	append(SRL,[H],RL).


%Flatten a list

flatten([],[]).

flatten([H|T],FlatList) :-
	append(H,T,List), !,
	flatten(List,FlatList).

flatten([H|LT],[H|FT]) :-
	flatten(LT,FT).

%remove duplicates

compress([],[]).

compress([H,H|T],CL) :-
	!,
	compress([H|T],CL).

compress([H|T],[H|CT]) :-
	compress(T,CT).

%pack consecutive elements into sublists

pack([E],[[E]]).

pack([H1,H2|T],[[H1]|TP]) :-
	H1 \= H2, !, 
	pack([H2|T],TP).

pack([H|T],[HP|TP]) :-
	pack(T,[_HP|TP]),
	member(H,_HP), !,
	append([H],_HP,HP).

%encode usese pack to shorten a list

encoder([],[]).

encoder([H|T],[HE|TE]) :-
	length(H,L),
	[E|_] = H,
	HE = [L,E],
	encoder(T,TE).

encode(L,LE) :-
	pack(L,LP),
	encoder(LP,LE).


%encode mod uses pack to shorten a list


modEncoder([],[]).


modEncoder([[H]|T],[H|TE]) :-
	!,
	modEncoder(T,TE).

modEncoder([H|T],[HE|TE]) :-
	length(H,L),
	[E|_] = H,
	HE = [L,E],
	modEncoder(T,TE).

modEncode(L,LE) :-
	pack(L,LP),
	modEncoder(LP,LE).

%create list creates a repeated list of characters of given length

createList(_,0,[]) :- !.

createList(E,Len,[E|T]) :-
	NewLen is Len - 1,
	createList(E,NewLen,T).

%decode modEncoding

decode([],[]).

decode([E|T],[E|DT]) :-
	[_|_] \= E,
	decode(T,DT).

decode([[Len,E]|T],DL) :-
	decode(T,_DL),
	createList(E,Len,List),
	append(List,_DL,DL).

%encodeDirect does the job of modEncode directly

encodeDirect([],[]).

encodeDirect(List,[HE|TE]) :-
	[H|_] = List,
	append(L1,L2,List),
	\+member(H,L2), !,
	length(L1,N),
	((HE = H, N = 1), !; HE = [N,H]),
	encodeDirect(L2,TE).


%Duplicate elements of a list

duplicate([],[]).

duplicate([H|T],[H,H|TD]) :-
	duplicate(T,TD).

%Duplicate elements N times

duplicate([],_,[]).

duplicate([H|T],N,LD) :-
	createList(H,N,LD1),
	duplicate(T,N,LD2),
	append(LD1,LD2,LD).

%drop drops every Nth element of a list

drop(L,N,L) :-
	length(L,Len),
	Len < N.
	
drop(L,N,LD) :-
	N_ is N - 1,
	length(L1,N_),
	append(L1,[_|L2],L),
	drop(L2,N,LD2),
	append(L1,LD2,LD).

