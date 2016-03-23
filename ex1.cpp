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