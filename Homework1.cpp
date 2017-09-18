//Homework1.cpp
//Ryan Parziale
//COSC2030
//Homework01
//9-18-2017
//Topic: Destructor

#include <iostream>
#include <string>
using namespace std;

//Example class
class ClassName
{
private:
	string name; //Name of the object created

protected:

public:
	ClassName(string oName);
	~ClassName(); //Destructor. It takes no arguments and has no return type. It has the same name as the class name and is preceded by a ~.
};


int main()
{

	ClassName object1("object1");

	{
		cout << "\nWhen objects go out of scope, in this case, block scope, the destructor is called." << endl;
		ClassName object2("object2");
		ClassName object3("object3");
		ClassName object4("object4");
	}
	cout << "The destructor is called in the reverse order the constructor is called.\n" << endl;

	cout << "\nThe detsructor can also be called by using the 'delete' operator." << endl;
	ClassName* ptr = new ClassName("ptr");
	delete ptr;

	cout << "\n" << endl;
	ClassName object5("object5");
	cout << "The destructor can also be called explicitly, by using the command:\nobject5.~ClassName();\nbut this shouldn't normally be done\nas it could cause to destructor to be called twice, being called again when the object goes out of scope." << endl;
	//object5.~ClassName();
	//Explicit call to the destructor

	cout << "\nWhen the program ends, any other objects created will have their destructor called too as they go out of scope." << endl;
	return 0;
}


ClassName::ClassName(string oName)
{
	name = oName;
	cout << name << " created" << endl;
	//Constructors would not normally have output statements, but this is just to show the order of construction.
}

ClassName::~ClassName()
{
	//When the destructor is called, the resources used to store the 'name' variable are freed.
	cout << name << " destroyed" << endl;
	//Destructors would not normally have output statements, but this is just to show the order of destruction.
}