%Bratko Exercises

%evenlength succeds if the list input is of even length

evenlength([_,_]).

evenlength([_,_|T]) :-
	even_length(T).


%oddlenth succeds if the list input is of odd length

oddlength([_]).

oddlength([_,_|T]) :-
	oddlength(T).


%reverse reverses a list

reverse([],[]).

reverse([ListHead|ListTail],ReversedList) :-
	reverse(ListTail,StartReversedList),
	append(StartReversedList,[ListHead],ReversedList).

%palindrome is correct if the list reads the same in both directions

palindrome(List) :-
	reverse(List,List).

%shift shifts all elements of L1 one place to the left to create L2

shift([H1,H2|T1],[H2|T2]) :-
	append(T1,[H1],T2).

%subset retrurns a subset of a list

subset([],[]).

subset([SetHead|SetTail],[SubSetHead|SubSetTail]) :-
	SubSetHead = SetHead,
	subset(SetTail,SubSetTail).

subset([_|SetTail],SubSet) :-
	subset(SetTail,SubSet).

%dividelist takes a List and divedes it into List1 and List2 of similar length

dividelist([],[],[]).

dividelist([E],[E],[]).

dividelist([H1,H2|T],[H1|T1],[H2|T2]) :-
	dividelist(T,T1,T2).
	

%flatten removes all lists within a parent list

flatten([],[]).

flatten([H|T],FL) :-
	[] = H, !,
	flatten(T,FL).

flatten([H|T],FL) :-
	[_|_] = H, !,
	append(H,T,L),
	flatten(L,FL).

flatten([H|T],[H|FT]) :-
	flatten(T,FT).

%max returns te greater of two numbers

max(X,Y,Max) :-
	X > Y,
	Max = X.

max(X,Y,Max) :-
	Y > X,
	Max = Y.

%maxlist returns the maximum value in a list

maxlist([Max],Max).

maxlist([Head|Tail],Max) :-
	maxlist(Tail,CurrentMax),
	max(Head,CurrentMax,Max).


%sumlist sums all the values in a list

sumlist([Sum],Sum).

sumlist([Head|Tail],Sum) :-
	sumlist(Tail,CurrentSum),
	Sum is CurrentSum + Head.

%ordered checks if a list is in order

ordered([_]).

ordered([Head1|Tail]) :-
	[Head2|_] = Tail,
	Head1 =< Head2,
	ordered(Tail).

%subsum finds a subset of the set where the sum is unified with sum

subsum(Set,Sum,SubSet) :-
	subset(Set,SubSet),
	sumlist(SubSet,Sum).

%between generates all integers between N1 and N2

makelist(EN,EN,[EN]).

makelist(E1,EN,[E1|T]) :-
	E2 is E1 + 1,
	E2 =< EN,
	makelist(E2,EN,T).

between(N1,N2,X) :-
	makelist(N1,N2,List),
	member(X,List).

