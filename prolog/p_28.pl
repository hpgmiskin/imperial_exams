%Import random module for use
%use_module(library(random)).

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

%split divides a list in two with the first list of length N

split(L,0,[],L).

split([H|T],N,[H|T1],L2) :-
	N_ is N - 1,
	split(T,N_,T1,L2).

%slice takes a slice out of a list as defined by two integers

slice([H|_],_,1,[H]).

slice([H|T],N1,N2,[H|TS]) :-
	N1 < 2, !,
	N2_ is N2 - 1,
	slice(T,0,N2_,TS).

slice([_|T],N1,N2,LS) :-
	N1_ is N1 - 1,
	N2_ is N2 - 1,
	slice(T,N1_,N2_,LS).

%rotate rotates a list by N places to the left

rotate(L,0,L).

rotate(L,N,LR) :-
	N > 0,
	length(L1,N),
	append(L1,L2,L),
	append(L2,L1,LR).

rotate(L,N,LR) :-
	N < 0,
	N_ is N * - 1,
	length(L2,N_),
	append(L1,L2,L),
	append(L2,L1,LR).

%remove_at removes the element at the given position in a list

remove_at(E,[E|T],1,T) :- !.

remove_at(E,[H|T],N,[H|TR]) :-
	N_ is N - 1,
	remove_at(E,T,N_,TR).

%insert_at inserts an element at a given location in a list

insert_at(E,L,1,[E|L]).

insert_at(E,[H|T],N,[H|TN]) :-
	N_ is N - 1,
	insert_at(E,T,N_,TN).

%range creates a list of all integers in a given range

range(N2,N2,[N2]). 

range(N1,N2,[N1|T]) :-
	N1 < N2,
	N1_ is N1 + 1,
	range(N1_,N2,T).

%rnd_select selects N elements from a list randomly

rnd_select(_,0,[]) :- !.

rnd_select(L,N,[HR|TR]) :-
	length(L,Len),
	random(1,Len,Rand),
	N_ is N - 1,
	remove_at(HR,L,Rand,_),
	rnd_select(L,N_,TR).

%loto randomly selects N numbers between 1 and M and returns them in list LR

loto(N,M,LR) :-
	range(1,M,L),
	rnd_select(L,N,LR).

%permutation returns a random permutation of list L as list LP

permutation(L,LP) :-
	length(L,N),
	permutation(L,N,LP).

permutation(_,0,[]) :- !.

permutation(L,N,[HP|TP]) :-
	N_ is N - 1,
	permutation(L,N_,TP),
	member(HP,L),
	\+member(HP,TP).

%combination finds all the sets of N from the List and returns all possibilities

combination(0,_,[]) :- !.

combination(N,L,[HS|TS]) :-
	N_ is N - 1,
	combination(N_,L,TS),
	member(HS,L),
	\+member(HS,TS).

%group3(List,Lengths,Groups) returns the combinations of List where Groups of given Lengths can be created 

group3(List,[L1,L2,L3],[G1,G2,G3]) :-
	length(G1,L1),
	length(G2,L2),
	length(G3,L3),
	permutation(List,LP),
	append(G1,G2,G12),
	append(G12,G3,LP),
	sort(G1,G1),
	sort(G2,G2),
	sort(G3,G3).

%group(List,Lengths,Groups) finds the Groups with given Lengths that are found in List

group(List,Lengths,Groups) :-
	length(Lengths,N),
	length(Groups,N),
	permutation(List,ListPerm),
	groupPerm(ListPerm,Lengths,Groups).

groupPerm([],[],[]).

groupPerm(ListPerm,[LH|LT],[GH|GT]) :-
	groupPerm(ListPerm_,LT,GT),
	length(GH,LH),
	append(ListPerm_,GH,ListPerm),
	sort(GH,GH).

%lsort sorts a list of lists by there length

lsort(Lists,SortedLists) :-
	addLengthFirst(Lists,LFL),
	sort(LFL,SLFL),
	removeLengthFirst(SLFL,SortedLists).

%addLengthFirst adds the length of the sub list to the front of each sub list

addLengthFirst([],[]).

addLengthFirst([H|T],[LH|LT]) :-
	length(H,N),
	LH = [N|H],
	addLengthFirst(T,LT).

%removeLengthFirst removes the length of the sub list from the front of each sub list

removeLengthFirst([],[]).

removeLengthFirst([H|T],[NLH|NLT]) :-
	[_|NLH] = H,
	removeLengthFirst(T,NLT).

%lfsort TBC