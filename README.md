#Jak programować obiektowo? cz.1 – wstęp

>	Autorem poniższego artykułu jest Pan Sebastian Malaca. Ukazał się na blogu [webmastah.pl](https://webmastah.pl/jak-programowac-obiektowo-cz-1-wstep/) i dosyć czytelnie opisuje zasady dziedziczenia, będąc dobrym teoretycznym wstępem do programowania obiektowego. Na potrzeby laboratorium dostosowałem przykłady do języka C++.

Kiedy zaczynałem swoją przygodę z programowaniem obiektowym szybko trafiłem na tutoriale i wszelkiego rodzaju inne kursy, które pokazywały jak wykorzystywać struktury obiektowe w kodzie. Niestety większość z nich demonstrowało jedynie, jak napisać swoją pierwszą klasę, interfejs, czy też stworzyć obiekt. Wszystko sprowadzało się do „gramatyki” języka, czyli słów kluczy, sposobu tworzenia tych struktur, itp. Gdzieś po drodze „gubiła się” jednak informacja skąd takie, a nie inne decyzje, dlaczego np. interfejs ma same metody abstrakcyjne? Do tego publiczne? Po co te widoczności? I tak dalej.

Dlatego też postaram się oderwać Was trochę od kodu (choć oczywiście postaram się o wystarczającą ilość odpowiednich przykładów), a postaram się skupić na tym, co jest najistotniejsze – na obiektowym myśleniu. Bo wbrew temu co można sądzić, wszystko na co możecie sobie pozwolić i czego Wam nie wolno pisząc obiektowo, ma swoje uzasadnienie.

To, jak implementujecie obiektowe rozwiązania w danym języku, jest czymś zmiennym, stałe pozostają wybierane rozwiązania, sposób rozumowania, proces podejmowania decyzji. Nie ważne, czy piszesz kod w PHP, Javie, C++ itp., ponieważ, jeżeli potrafisz go poprawnie zaprojektować, to ten projekt będzie uniwersalny, zmieni się jedynie sposób przetłumaczenia go na język zrozumiały dla interpretera/kompilatora danego języka.

Dobra, ale żeby nie przedłużać już i tak wystarczająco długiego wstępu, przejdźmy do rzeczy. Dzisiaj będzie trochę podstaw. Od czegoś w końcu trzeba zacząć.

##Programowanie obiektowe – co to jest?

Programowanie obiektowe jest próbą przedstawienia świata rzeczywistego i relacji w nim zachodzących, za pomocą obiektów. Najważniejszymi cechami programowania obiektowego są:

- Abstrakcja
- Enkapsulacja
- Dziedziczenie
- Polimorfizm

Wszystkimi tymi pojęciami zajmiemy się w kolejnych wpisach. Dzisiaj skupimy się przede wszystkim na języku i na rzeczach, które są niezbędne do rozpoczęcia zabawy z OOP.

##Klasa

Klasa, z punktu widzenia programowania, jest to typ zmiennej. Natomiast w ujęciu projektowym jest to ogólna definicja pewnej grupy powiązanych ze sobą obiektów, które różnią się tożsamością. Klasa definiuje metody, czyli funkcjonalność, które są dostarczane przez obiekty. Poza tym definiuje również atrybuty, które są indywidualne (nie zawsze, ale do tego tematu wrócimy w przyszłości) dla konkretnych obiektów. Czym jest obiekt? Jest to instancja danej klasy, czyli konkretna zmienna danego typu.

Prosty przykład dla rozjaśnienia sprawy:

> Janek, Ania, Zosia to obiekty klasy Człowiek. Każde z nich może spać, jeść, poruszać się i to są właśnie metody zdefiniowane w klasie Człowiek. Oprócz tego każdy człowiek posiada imię oraz datę urodzenia, jednak są one indywidualne dla każdego obiektu, czyli nie są bezpośrednio powiązane z klasą, a z jej instancją (obiektem).

A jak coś takiego wyrazić za pomocą kodu?

	class Human
	{
	private:
		char *name;
		int birthDate;
	 
	public:
		Human(char *name, int birthDate){};
		void eat();
		void sleep();
		void move();
	};
	
	int main(int argc, char const *argv[])
	{
		Human janek = Human("Janek", 123);
		Human anna = Human("Anna", 123);
		Human zosia = Human("Zosia", 123);
	} 

##Abstrakcja i dziedziczenie

Klasa abstrakcyjna różni się od zwykłej klasy tym, że nie można utworzyć jej instancji. Może dostarczać zarówno metody zdefiniowane jak i abstrakcyjne, czyli takie, które zostały zadeklarowane i muszą zostać zdefiniowane w klasach potomnych.

Dodajmy coś więcej do przykładu z wcześniejszego akapitu:

> Oczywiście Janek, Ania, Zosia to obiekty klasy Człowiek. Niemniej jednak, oprócz tego wszyscy są ssakami, tak jak Pies Janka – Reksio.

Z powyższego wyłania nam się następujący kod:

	class Mammal
	{
	public:
	    virtual void drinkMilk(){};
	};
	
	class Human : Mammal
	{
	private:
		char *name;
		int birthDate;
	 
	public:
		Human(char *name, int birthDate){};
		void eat();
		void sleep();
		void move();
	};
	
	class Dog : Mammal
	{
	
	};

Dlaczego Mammal jest klasą abstrakcyjną? Ponieważ pomimo tego, że ssakiem jest zarówno pies jak i człowiek, to nie jesteśmy w stanie utworzyć ssaka (nie urodzi się taki), który nie będzie przynależał do jakiegoś konkretnego gatunku. Nie zmienia to jednak faktu, że chcemy tą wiedzę (o tym, co ssakiem jest) posiadać.

##Interfejs i realizacja

Specyficzną formą abstrakcji jest interfejs. Od klasy abstrakcyjnej odróżniają go dwie podstawowe rzeczy:

- nie może definiować żadnych atrybutów, jedynie metody i stałe
- wszystkie metody muszą być abstrakcyjne i publiczne

Interfejsy służą do zapewnienia pewnej pożądanej funkcjonalności, są pewnego rodzaju kontraktem pomiędzy klasami, które interfejs wykorzystują, a tymi, które go implementują. Interfejsy są po to, aby zagwarantować nam, że jakaś metoda istnieje, a nie jak się zachowuje.

I wracając do naszych przyjaciół ze wcześniejszych przykładów:

> Ssaki, jak wszystkie inne Zwierzęta, poruszają się i jedzą. Niemniej jednak inaczej przemieszczają się ryby, inaczej ptaki, a inaczej ludzie.
To samo tyczy się jedzenia.

I tak rodzi nam się kod przedstawiony poniżej:

	// Interfejs
	class Animal
	{
	public:
	    virtual void eat() = 0;
	    virtual void move() = 0;
	};
	
	// Klasa abstrakcyjna
	class Mammal : Animal
	{
	public:
	    virtual void drinkMilk()
	    {
	
	    };
	
	    void eat(){}
	    void move(){}
	};
	
	// Zwyczajna klasa
	class Human : Mammal
	{
	private:
		char *name;
		int birthDate;
	 
	public:
		Human(char *name, int birthDate){};
		void eat(){};
		void move(){};
	};
	
	class Dog : Mammal
	{
	
	};

Jeżeli chcielibyście sie dowiedzieć więcej o różnicach pomiędzy interfejsem, a klasą abstrakcyjną to zapraszam [tutaj](http://sebastian-malaca.blogspot.com/2012/12/roznice-miedzy-klasa-abstrakcyjna.html).
