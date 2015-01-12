%is_prime defines if the given number is prime

is_prime(_,1) :-
	!,
	fail.

is_prime(N,I) :-
	I > 1,
	N_Div is N/I,
	N_Int is N//I,
	float(N_Int),
	N_Div = N_Int.

is_prime(N,I) :-
	I_ is I - 1,
	is_prime(N,I_).

is_prime(N) :-
	I is N - 1,
	\+is_prime(N,I).