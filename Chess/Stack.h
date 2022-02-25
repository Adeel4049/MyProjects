#pragma once

template<typename T>
class Stack
{

private:
	T *D;
	int size;
	int capacity;
	bool Fixed;

public:
	Stack()
	{
		size = 1;
		D = new T[size];
		capacity = 1;
		Fixed = false;


	}
	Stack(int c)
	{
		capacity = c;
		D = new T[c];
		size = 1;

		this->Fixed = true;

	}
	void Stack<T>::Print();
	bool Stack<T>::Push(T V);
	bool Stack<T>::Is_full();
	bool Stack<T>::Is_Empty();
	T Stack<T>::Pop();
	T Stack<T>::Top();


	~Stack(){ ;}
};


template<typename T>
void Stack<T>::Print()
{
	
	for (int i = 0; i < size-1; i++)
	{
		cout << this->D[i] << endl;
	}

}

template<typename T>
bool Stack<T>::Push( T V)
{
	if (Fixed == true)
	{
		if (size > capacity)
		{
			return 0;

		}
		else
		{
			this->D[size - 1] = V;
			size++;
		}

	}
	else
	{


		if (size > capacity)
		{
			capacity = capacity * 2;

			T *temp = new T[capacity];
			for (int i = 0; i < size; i++)
			{
				temp[i] = this->D[i];

			}

			temp[size - 1] = V;
			size++;
			delete[]this->D;

			this->D = temp;

		}
		else
		{
			this->D[size - 1] = V;
			size++;

		}

	}

	return 1;
}


template <class T>
bool Stack<T>::Is_full()
{
	if (size == capacity)
	{
		return 1;
	}

	return 0;
}

template <class T>
bool Stack<T>::Is_Empty()
{
	if (size == 1)
	{
		return 1;
	}

	return 0;
}
template <class T>
T Stack<T>::Pop()
{

	if (!Is_Empty())
	{
		size--;
		return this->D[size - 1];

	}

	
}
template <class T>
T Stack<T>::Top()
{

	if (!Is_Empty())
	{
		return this->D[size - 1];

	}


}

