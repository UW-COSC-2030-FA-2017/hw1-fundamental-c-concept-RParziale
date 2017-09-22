//Ryan Parziale
//COSC2030
//Homework 1 Part 3
//9-22-2017
//Collection Class Template

#pragma once

#ifndef COLLECTION_H
#define COLLECTION_H


template <class T>
class Collection
{
public:
	Collection();
	~Collection();
	bool isEmpty();
	void makeEmpty();
	void insert(T x);
	void remove(T x);
	void removeRandom();
	bool notContained(T x);
	void print();
protected:


private:
	int size;
	T* arr;
	int arraySize;


};

#endif