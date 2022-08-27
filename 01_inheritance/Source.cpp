#include <iostream>
#include <string>
using namespace std;

class Person
{
private: // can access only from this class
	string name;
	float height;
	string country;
	const int id; // can initialize only

protected: // can access from this or derived classes
	int age;

public:
	Person(int id) : id(id), name(""), height(0), country(""), age(0)
	{
		//name = "";
		//height = 0;
		//country = "";
		//birthYear = 0;
		//this->id = id; // error
	}
	Person(int id, string n, float h, string c, int a)
		: id(id), name(n), height(h), country(c), age(a)
	{ }

	void Print() const
	{
		cout << "---------- PERSON: [" << id << "] ----------" << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Country: " << country << endl;
	}

	void SayHello() const
	{
		cout << "Hello, I'am " << name << ". How are you?\n";
	}
};

// Inheritance template: class Child : [specificator] Parent
// Inheritance specificators: private, protected, public

class Employee : public Person
{
	double salary;
public:
	Employee(int id, string n, float h, string c, int a, double s)
		: salary(s), Person(id, n, h, c, a) // parent class constructor
	{
		// ...
	}

	void IncreaseSalary(double value)
	{
		this->salary += value;
	}

	double GetBonus()
	{
		// age > 40 - 300$
		// age > 30 - 200$

		if (age > 40) return 300;
		else if (age > 30) return 200;
		else return 0;
	}
	void Print() const
	{
		Person::Print(); // parent class method
		cout << "Salary: " << salary << " $\n";
	}
};

class Manager : public Employee
{
public:
	Manager(int id, string n, float h, string c, int a, double s) 
		: Employee(id, n, h, c, a, s)
	{ }

	void ManageProcess()
	{
		cout << "Manage some process...\n";
	}
};

class Student : public Person
{
private: 
	float averageMark;
public:
	Student() : Person(1000) { }

	void Test()
	{
		//age = 0;	 // have an access
		//name = ""; // don't have an access
	}
};

int main()
{
	Person p1(344, "Vlad", 180, "Ukraine", 14);

	p1.Print();
	p1.SayHello();
	cout << "_______________________________\n\n";

	Employee em1(890, "Yura", 192, "Ukraine", 32, 700);

	em1.Print();
	em1.SayHello();
	em1.Print();
	cout << "_______________________________\n\n";

	Manager mg1(555, "Olga", 170, "Poland", 34, 1500);
	mg1.IncreaseSalary(100);
	cout << "Bonus: " << mg1.GetBonus() << " $\n";
	mg1.ManageProcess();
	mg1.Print();

	return 0;
}