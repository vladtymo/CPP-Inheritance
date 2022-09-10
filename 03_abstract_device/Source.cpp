#include <iostream>
using namespace std;

// abstract class - that has at least one pure virtual method
class Device
{
private:
	string model;
	float weight;
	double price;
	bool isPowerOn;

public:
	Device() : model(""), weight(0), price(0), isPowerOn(false) { }
	Device(string m, float w, double p)
		: model(m), weight(w), price(p), isPowerOn(false) { }

	void SwitchPower()
	{
		this->isPowerOn = !this->isPowerOn;
	}
	// pure virtual method - without realisation
	virtual void DoWork() = 0;
	//{
		//...
		//cout << "Do something...\n";
		//...
	//}
	virtual void ShowInfo() const
	{
		cout << "Model: " << model << endl;
		cout << "Price: " << price << "$" << endl;
		cout << "Weight: " << weight << "g" << endl;
		cout << "Power: " << (isPowerOn ? "ON" : "OFF") << endl;
	}
};

class Printer : public Device
{
private:
	short cartridgeVolume;
public:
	Printer(string m, float w, double p) : Device(m, w, p), cartridgeVolume(100) { }

	void DoWork() override
	{
		cout << "Document printing...\n";
		cartridgeVolume -= 5;
	}
	void ShowInfo() const override
	{
		Device::ShowInfo();
		cout << "Cartridge volume: " << cartridgeVolume << "%" << endl;
	}
};

class Router : public Device
{
private:
	float frequency;
public:
	Router(string m, float w, double p, float f) : Device(m, w, p), frequency(f) { }

	void DoWork() override
	{
		cout << "Transfer data in the network with " << frequency << "GHz...\n";
	}
	void ShowInfo() const override
	{
		Device::ShowInfo();
		cout << "Frequency: " << frequency << "GHz" << endl;
	}
};

void TestDevice(Device& device)
{
	cout << "=========== Device information ===========\n";
	device.SwitchPower();
	device.ShowInfo();
	cout << "=========== Testing ===========\n";
	device.DoWork();
}

void main()
{
	// can not create an instance of the abstract class
	//Device device;
	//device1.DoWork(); // empty method

	//cout << "\n___________________________________________\n\n";

	Printer printer1("Canon Pixma", 3500, 240);
	/*printer1.SwitchPower();
	printer1.DoWork();
	printer1.ShowInfo();*/

	//cout << "\n___________________________________________\n\n";

	Router router1("TP-Link 3456", 800, 50, 2.4);
	/*router1.SwitchPower();
	router1.DoWork();
	router1.ShowInfo();*/

	TestDevice(printer1);
	TestDevice(router1);
}