#pragma once
#include <stdlib.h> 

template <typename T>
class Vector
{
private:
	T* data;
	int size;
	int space;

	void checkSpace()
	{
		if (size >= space)
		{
			alloc((int)(space * 0.3f + 1));
		}
	}

	void moveRightFrom(int index)
	{
		checkSpace();
		size++;

		for (int i = size - 1; i >= index; i--)
		{
			data[i] = data[i - 1];
		}
	}

	void moveLeftFrom(int index)
	{
		T temp;
		for (int i = index; i < size -1; i++)
		{
			data[i] = data[i + 1];
		}

		size--;
	}
public:
	Vector() { size = 0; space = 3; data = new T[3]; };
	int getSize() {return this->size;};
	int getSpace() { return this->space;}

	void pushBack(T item) // add at end
	{
		checkSpace();
		data[size] = item;
		size++;
	}
	void pushFront(T item)// add at start
	{
		moveRightFrom(0);
		data[0] = item;
	}
	void insert(int index,T item)   // add at X
	{
		moveRightFrom(index);
		data[index] = item;
	}

	T back()		 //get at end
	{
		return data[size - 1];
	}
	T front()		 //get at start
	{
		return data[0];
	}

	T at(int index)		 //get at X
	{
		return data[index];
	}

	void popBack()  //delete at end
	{
		size--;
	}

	void popFront() //delete at start
	{
		moveLeftFrom(0);
	}
	void erase(int index) //delete at X
	{
		moveLeftFrom(index);
	}

	void clear()	 //erase everything
	{
		size = 0;
		space = 0;
		delete[] data;

		data = new T[3];
	}

	void trim()     //delete unused space
	{
		data = (T*)realloc(data, size * sizeof(T));
		space = size;
	}


	void alloc(int n) // add space
	{
		space += n;
		T* temp = new T[space];

		//only copy data
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
	}

};