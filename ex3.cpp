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

int main(int argc, char const *argv[])
 {
 	Human janek = Human("Janek", 123);
 	Human anna = Human("Anna", 123);
 	Human zosia = Human("Zosia", 123);
 	Dog burek = Dog();
 } 