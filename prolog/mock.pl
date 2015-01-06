
% child_mother(C, M) means C is a child of mother M.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

child_mother(amy, mary).
child_mother(arthur, mary).
child_mother(angel, jane).
child_mother(anton, rita).
child_mother(alan, rita).
child_mother(axel, susan).
child_mother(ann, tina).    


% age(C, A) means C is of age A.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

age(amy, 6).
age(arthur, 15).
age(angel, 16).
age(anton, 4).
age(alan, 8).
age(axel, 16).
age(ann, 4).

% employed(X) means X is employed.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

employed( susan).
employed(rita).


% mother_child_age(Mother,ChildAge) means Mother with child of age ChildAge
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

mother_child_age(Mother,ChildAge) :-
	child_mother(Child,Mother),
	age(Child,ChildAge).

% ecb(Mother) means Mother is entitled to child benefits
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ecb(Mother) :-
	mother_child_age(Mother,ChildAge),
	ChildAge =< 14.

ecb(Mother) :-
	mother_child_age(Mother,ChildAge),
	\+ employed(Mother),
	ChildAge =< 16.

% mother_of_the_youngest(Mother) means Mother is the mother of the youngest child
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

mother_of_the_youngest(Mother) :-
	setof(ChildAge-Mother,mother_child_age(Mother,ChildAge),[_-Mother|_]).

% mother_of_young(Mother) means Mother is a mother of a child of 10 or younger
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

mother_of_young(Mother) :-
	mother_child_age(Mother,ChildAge),
	ChildAge =< 10.

% mothers_of_young(ListOfMothers) means ListOfMother is a list of all mothers with a child of 10 or younger
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

mothers_of_young(ListOfMothers) :-
	setof(Mother,mother_of_young(Mother),ListOfMothers).

% merge(L1,L2,L) unifies List with a sorted merge of List1 and List2
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%base case where L1 is consumed
merge([],L,L).

%base case where L2 is consumed
merge(L,[],L).

%case where first letter of L1 < first letter of L2
merge([H|T1],L2,[H|T]) :-
	[H2|_] = L2,
	H =< H2,
	merge(T1,L2,T).

%case where first letter of L2 < first letter of L1
merge(L1,[H|T2],[H|T]) :-
	[H1|_] = L1,
	H =< H1,
	merge(L1,T2,T).

% findElement(N+,L+,E?) finds E the Nth element of list L
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

findElement(1,[E|_],E).

findElement(N,[_|T],E) :-
	NewN is N - 1,
	findElement(NewN,T,E).