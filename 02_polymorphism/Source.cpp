#include <iostream>
#include <string>
using namespace std;

// Example: Bus, Trolebus, Tram, Taxi...
class Transport
{
private:
	string model;
	float maxSpeed;
	float currentSpeed;
	int totalPalces;
	int freePlaces;

public:
	Transport() : model(""), currentSpeed(0), freePlaces(0), maxSpeed(0), totalPalces(0) { }
	Transport(string model, float maxS, int places)
		: model(model), currentSpeed(0), freePlaces(places), maxSpeed(maxS), totalPalces(places)
	{
		// TODO: add validations	
	}

	void ShowInfo() const
	{
		cout << "Model: " << model << endl;
		cout << "Speed: " << currentSpeed << " of " << maxSpeed << "km/h" << endl;
		cout << "Free places: " << freePlaces << " of " << totalPalces << endl;
	}

	// you can override virtual method in derived classes
	virtual string GetType() const 
	{ 
		return "some transport"; 
	}

	void Stop()
	{
		this->currentSpeed = 0;
	}
	void SetSpeed(float speed)
	{
		//if (speed > maxSpeed) this->currentSpeed = maxSpeed;
		//else this->currentSpeed = speed;
		this->currentSpeed = (speed > maxSpeed ? maxSpeed : speed);
	}
	bool AddPassengers(int count = 1)
	{
		if (count > freePlaces)
		{
			freePlaces = 0;
			return false;
		}
		else
		{
			freePlaces -= count;
			return true;
		}
	}
};

enum Category { Ecomon, Standart, Comfort };

class Taxi : public Transport
{
private:
	Category category;

public:
	Taxi(string model, float maxS, int places, Category cat)
		: Transport(model, maxS, places), category(cat)
	{ }

	string GetType() const override { return "taxi"; }
	void PlaySong(string trackName)
	{
		cout << "Song " << trackName << " is playing now...\n";
	}
	void TurnOnAC()
	{
		if (category == Category::Comfort)
			cout << "Conditioner is turned on!\n";
		else
			cout << "Sorry, does not have a conditioner in this category.\n";
	}
};

class Trolebus : public Transport
{
public:
	Trolebus(string model, float maxS, int places)
		: Transport(model, maxS, places)
	{ }

	string GetType() const override { return "trolebus"; }
};


void Move(string from, string to, Transport& transoprt)
{
	cout << "You moving from " << from << " to " << to << endl;
	cout << "With transport: " << transoprt.GetType() << endl;
	transoprt.SetSpeed(60);
	transoprt.ShowInfo();
	//transoprt.TurnOnAC(); // not exists in class Transport
	cout << "_________________________________\n\n";
}

int main()
{
	Transport t1("TATA B5", 120, 32);
	t1.SetSpeed(50);
	t1.AddPassengers(5);
	//t1.ShowInfo();

	/*if (!t1.AddPassengers(20))
		cout << "There are not enough places for 50 passengers!\n";
	else
		cout << "Everything is good!\n";*/

	//t1.ShowInfo();
	//cout << "\n-------------------------------------------------------\n\n";

	Taxi t2("Toyota Camry", 190, 5, Category::Ecomon);
	t2.AddPassengers(3);
	//t2.PlaySong("Stefania");
	//t2.TurnOnAC();
	//t2.ShowInfo();

	Trolebus t3("VW 78", 190, 5);

	Move("Rivne", "Kostopil", t1);
	Move("Kyiv", "Lviv", t2);
	Move("Rivne", "Ternopil", t3);

	return 0;
}