%Country(Country,Capital,Inhabitants_in_millions,Area_in_square_kilometers)
country('Sweden','Stockholm',9.3,449964).
country('Denmark','Copenhagen',5.5,43094).
country('Norway','Oslo',4.8,385199).
country('Finland','Helsinki',5.3,338145).
country('Iceland','Reykjavik',0.32,103125).
country('GreatBritain','London',60.6,244820).
country('Turkey','Ankara',71.5,783562).

%Nordic_country(Country)
nordic_country('Sweden').
nordic_country('Norway').
nordic_country('Denmark').
nordic_country('Finland').
nordic_country('Iceland').

%National_day(Country,date(Day,Month))
national_day('Sweden',date(6,'June')).
national_day('Norge',date(17,'May')).
national_day('Finland',date(6,'December')).
national_day('Turkey',date(29,'October')).
national_day('Denmark',date(5,'June')).
national_day('GreatBritain',date(11,'June')).
national_day('Iceland',date(17,'June')).

%Form_of_government(Country,Form)
form_of_government('Sweden',monarchy).
form_of_government('Norway',monarchy).
form_of_government('Finland',republic).
form_of_government('Denmark',monarchy).
form_of_government('GreatBritain',monarchy).
form_of_government('Iceland',republic).
form_of_government('Turkey',republic).

%Queen(Country,Name)
queen('Denmark','MargretheII').
queen('GreatBritain','ElisabethII').

%King(Country,Name)
king('Sweden','KarlXVIGustav').
king('Norway','HaraldV').

%Flag(Country,Colour_list)
flag('Sweden',[blue,yellow]).
flag('Norway',[red,blue,white]).
flag('Finland',[blue,white]).
flag('Denmark',[red,white]).
flag('GreatBritain',[blue,white,red]).

%ANSWERS

%large_capitals returns a list of capitals with large populations

large_capital(Capital) :-
	country(_,Capital,Population,_),
	Population > 5.

large_capitals(Countries) :-
	findall(Capital, large_capital(Capital), Countries).

%republic_governments returns a list of nordic countries with republi governments

republic_government(Country) :-
	nordic_country(Country),
	form_of_government(Country,republic).

republic_governments(Countries) :-
	findall(Country, republic_government(Country), Countries).

%national_days_june returns a list of countries that have their national day in june

national_day_june(Country) :-
	national_day(Country,date(_,'June')).

national_days_june(Countries) :-
	findall(Country, national_day_june(Country), Countries).

%monarchs returns a list of monarch(Name, Country) objects

monarch(monarch(Name,Country)) :- queen(Name,Country).
monarch(monarch(Name,Country)) :- king(Name,Country).

monarchs(Monarchs) :-
	findall(Monarch, monarch(Monarch), Monarchs).

%colour_in_flag returns a list of all countries with a given colour in their flag

flag_colour(Colour,Country) :-
	flag(Country,Colours),
	member(Colour,Colours).

colour_in_flag(Colour,Countries) :-
	findall(Country, flag_colour(Colour,Country), Countries).

%count_population_density computes inhabitants per square kilometer for all countries

population_density(population_density(Country,Number)) :-
	country(Country,_,Population,Area),
	Number is Population * 1000000 / Area.

count_population_density(List) :-
	findall(PopulationDensity, population_density(PopulationDensity), List).



%government_types returns a list of counties segregated by govenemnt type

government_type(Country,Type) :-
	nordic_country(Country),
	form_of_government(Country,Type).

government_types(Return) :-
	bagof(Country, government_type(Country,Type), Bag),
	Return = Type-Bag.

%national_infos returns lists of countries info segregated by govenment type

national_info(Country,CapitalCity,GovernmentType) :-
	country(Country,CapitalCity,_,_),
	form_of_government(Country,GovernmentType).

national_infos(List) :-
	setof(Country-CapitalCity, national_info(Country,CapitalCity,GovernmentType), Bag),
	List = GovernmentType-Bag.