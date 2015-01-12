%and(A,B) finds the logical and of A and B

and(A,B) :-
	A,
	B.

%or(A,B) finds the logical or of A and B

or(A,_) :- A.
or(_,B) :- B.

%nand(A,B) finds the logical nand of A and B

nand(A,B) :-
	\+and(A,B).

%nor(A,B) finds the logical nor of A and B

nor(A,B) :-
	\+or(A,B).

%xor(A,B) finds the logical xor of A and B

xor(A,B) :-
	or(A,B),
	nand(A,B).


%bind initiates A and B as true false consecutively
bind(true).
bind(fail).

%table(A,B,Logic) takes logical arguments A and B and and the Logic and prints a table

table(A,B,Logic) :- bind(A), bind(B), do(A,B,Logic), fail.

do(A,B,_) :- write(A), write(' '), write(B), write(' '), fail.
do(_,_,Logic) :- Logic, !, write(true), nl.
do(_,_,_) :- write(fail), nl.