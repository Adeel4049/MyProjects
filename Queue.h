#pragma once

template<typename T>
class Queue
{

private:
	T *D;
	int size;
	int capacity;
	bool Fixed;

	int start;
	int end;



public:
	Queue()
	{
		size = 0;
		D = new T[size];
		capacity = 1;
		D = new T[capacity];
		Fixed = false;
		this->start = 0;
		end = size;


	}
	Queue(int c)
	{
		capacity = c;
		D = new T[c];
		size = 0;

		this->Fixed = true;
		end = size;

	}
	void Queue<T>::Print();
	bool Queue<T>::Push(T V);
	bool Queue<T>::Is_full();
	bool Queue<T>::Is_Empty();
	T Queue<T>::Pop();



	~Queue(){ ; }
};


template<typename T>
void Queue<T>::Print()
{

	for (int i = start; i < end; i++)
	{
		cout << this->D[i] << endl;
	}

}

template<typename T>
bool Queue<T>::Push(T V)
{
	if (Fixed == true)
	{
		if (size == capacity)
		{
			return 0;

		}
		else
		{
			this->D[size] = V;
			size++;
			end++;
		}

	}
	else
	{
		if (size == capacity)
		{
			capacity = capacity * 2;

			T *temp = new T[capacity];
			for (int i = start; i < size; i++)
			{
				temp[i] = this->D[i];

			}

			temp[size] = V;
			size++;
			end++;
			delete[]this->D;

			this->D = temp;

		}
		else
		{
			this->D[size] = V;
			size++;
			end++;
		}

	}

	return 1;
}


template <class T>
bool Queue<T>::Is_full()
{
	if (capacity - size == 1)
	{
		return 1;
	}

	return 0;
}

template <class T>
bool Queue<T>::Is_Empty()
{
	if (size == 0)
	{
		return 1;
	}

	return 0;
}
template <class T>
T Queue<T>::Pop()
{

	size--;
	int t = this->D[start];
	start++;

	return t;

}


