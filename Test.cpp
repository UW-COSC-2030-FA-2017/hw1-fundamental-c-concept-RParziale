//Ryan Parziale
//COSC2030
//Homework 1 Part 3
//9-22-2017
//Collection Class Template and Driver

#include "Collection.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


int main()
{
	cout << "Creating an object, object1. Object1 will be an array of integers." << endl;
	Collection<int> object1;
	object1.print();
	cout << endl;


	cout << "Checking if the array is empty." << endl;
	if (object1.isEmpty())
	{
			cout << "The array is empty." << endl;
	}
	else
	{
		cout << "The array is not empty." << endl;
	}
	cout << endl;

	cout << "Inserting 1 into the array." << endl;
	object1.insert(1);
	object1.print();
	cout << endl;


	cout << "Checking if the array is empty." << endl;
	if (object1.isEmpty())
	{
		cout << "The object is empty." << endl;
	}
	else
	{
		cout << "The array is not empty." << endl;
	}
	cout << endl;


	cout << "Inserting 3, 2, 5, and 10 into the array." << endl;
	object1.insert(3);
	object1.insert(2);
	object1.insert(5);
	object1.insert(10);
	object1.print();
	cout << endl;


	cout << "Inserting 12, 10, and 12 into the array. This time the array will surpass its originally created size." << endl;
	object1.insert(12);
	object1.insert(10);
	object1.insert(12);
	object1.print();
	cout << endl;
	
	
	cout << "Checking if 10 is contained within the array." << endl;
	if (object1.notContained(10))
	{
		cout << "10 is not contained within the array." << endl;
	}
	else
	{
		cout << "10 is contained within the array." << endl;
	}
	cout << endl;

	
	cout << "Removing the (first) element of 10 from the array." << endl;
	object1.remove(10);
	object1.print();
	cout << endl;

	cout << "Removing the (second) element of 10 from the array." << endl;
	object1.remove(10);
	object1.print();
	cout << endl;

	cout << "Checking if 10 is contained within the array." << endl;
	if (object1.notContained(10))
	{
		cout << "10 is not contained within the array." << endl;
	}
	else
	{
		cout << "10 is contained within the array." << endl;
	}
	cout << endl;

	cout << "Trying to remove 10 from the array again." << endl;
	object1.remove(10);
	object1.print();
	cout << endl;
	
	cout << "Removing a random element from the array." << endl;
	object1.removeRandom();
	object1.print();
	cout << endl;

	cout << "Removing another random element from the array." << endl;
	object1.removeRandom();
	object1.print();
	cout << endl;

	cout << "Making the array empty using the makeEmpty function." << endl;
	object1.makeEmpty();
	object1.print();
	cout << endl;

	cout << "Checking if the array is empty." << endl;
	if (object1.isEmpty())
	{
		cout << "The object is empty." << endl;
	}
	else
	{
		cout << "The array is not empty." << endl;
	}
	cout << endl;

	cout << "Trying to remove element 7 from the array." << endl;
	object1.remove(7);
	object1.print();
	cout << endl;

	cout << "Trying to remove a random object from the array." << endl;
	object1.removeRandom();
	object1.print();
	cout << endl;

	return 0;
}





//Constructor. Makes an empty array of arraySize = 5 and initializes the size to 0 (no objects in the array)
template <class T>
Collection<T>::Collection()
{
	size = 0;
	arraySize = 5;
	arr = new T[arraySize];
}

//Destructor. Deletes the array
template <class T>
Collection<T>::~Collection()
{
	delete arr;
}

//Checks if the array is empty by checking if the size is 0
template <class T>
bool Collection<T>::isEmpty()
{
	if (size == 0)
	{
		return true;
	}

	return false;
}

//Makes the array empty by deleting the array then makes a new, empty array, if the array isn't empty already
template <class T>
void Collection<T>::makeEmpty()
{
	//If the array is not empty already
	if (!isEmpty())
	{
		delete[] arr;
		arraySize = 5;
		size = 0;
		arr = new T[arraySize];
	}
}


//If the array isn't full, a new object is inserted at the end of the array. 
//If the array is full, the array is copied into a new, larger array, and the old array is deleted
template <class T>
void Collection<T>::insert(T x)
{
	//If the array is full
	if (size == arraySize)
	{
		//Make a new array double the size of the original array
		arraySize = arraySize * 2;
		T* newArray = new T[arraySize];
		//Copy the new old array into the new array
		for (int i = 0; i < arraySize; i++)
		{
			newArray[i] = arr[i];
		}

		//Delete the old array
		delete[] arr;
		arr = newArray;
	}

	arr[size] = x;
	size++;
}

//If the element is contained in the array, it is deleted from the array. 
//notContained will already check is the array is empty.
//This function only removes the first element found that matches the element that is input.
template <class T>
void Collection<T>::remove(T x)
{
	//If the element is contained within the array
	if (!notContained(x))
	{
		bool deleted = false;
		int i = 0;
		
		//Find that element in the array
		while (i < (size) && !deleted)
		{
			if (arr[i] == x)
			{
				while (i < (size - 1))
				{
					//Move all the following elements back one space
					arr[i] = arr[i + 1];
					i++;
				}

				deleted = true;
			}
			i++;
		}
		//Reduce the size by one
		size = size - 1;
	}
}


template <class T>
void Collection<T>::removeRandom()
{
	//If the array is not empty already
	if (!isEmpty())
	{
		//Pick a random number between 0 and the size - 1
		int x = rand() % (0 - size);
		while (x < (size - 1))
		{
			//Move all the following elements back one space
			arr[x] = arr[x + 1];
			x++;
		}
		//Redice the size by one
		size = size - 1;
	}
}

//Returns true if the element input isn't contained within the array.
template <class T>
bool Collection<T>::notContained(T x)
{
	bool notContained = true;
	//If the array isnn't empty to begin with
	if (!isEmpty())
	{
		int i = 0;
		while (i < (size) && notContained)
		{
			if (arr[i] == x)
			{
				notContained = false;
			}
			i++;
		}

	}
	return notContained;
}

//Prints all the elements of the array in the form [ element1, element2, ... ]
template <class T>
void Collection<T>::print()
{
	
	cout << "[ ";

	if (!isEmpty())
	{
	for (int i = 0; i < (size); i++)
	{
		if (i == (size - 1))
		{
			cout << arr[i] << " ";
		}
		else
		{
			cout << arr[i] << ", ";
		}
	}
	}

	cout << "]" << endl;
	
}