#include <iostream>
#include <cstdio>
using namespace std;
class Vehicle
{
public:
	virtual void move() = 0;
	virtual void crash() = 0;
};

class Bicycle : Vehicle
{
	public:
	virtual void change_derailleur()
	{
		
	};
	void move(){}
	void crash(){}
};
class Car : Vehicle
{
	public:
	virtual void drink_fuel()
	{
		
	};
	void move(){}
	void crash(){}
};
class Plane : Vehicle
{
	public:
	virtual void change_height()
	{
	
	};
	void move(){}
	void crash(){}
};
class PapaMobile : Car
{
	private:
		string owner;
		char color;
	public:
		PapaMobile(string owner, char color){
			this->owner = owner;
			this->color = color;
		};
		void move(){};
		void crash(){};
};	
class  MountainBike : Bicycle
{
	private:
		string company;
		int model;
	public:
		MountainBike(string company, int model){
			this->company = company;
			this->model = model;
		};
		void move(){};
		void crash(){};
};
class Tank : Bicycle
{
	private:
		int age;
		string type;
	public:
		Tank(string type, int age){
			this->type = type;
			this->age = age;
		};
		void move(){};
		void crash(){};
};
class Fighter : Plane
{
	private:
		string country;
		int value;
	public:
		Fighter(string country, int value){
			this->country = country;
			this->value = value;
		};
		void move(){};
		void crash(){};
};
class RoadBike : Bicycle
{
	private:
		char size;
		int weight;
	public:
		RoadBike(char size, int weight){
			this->size = size;
			this->weight = weight;
		};
		void move(){};
		void crash(){};
};
int main(int argc, char const *argv[])
{
    RoadBike janek = RoadBike('m', 4500);
    Fighter anna = Fighter("Poland", 123);
    PapaMobile zosia = PapaMobile("JP2", 'w');
} 
	
