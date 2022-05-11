#ifndef _MYVECTOR_HPP
#define _MYVECTOR_HPP

#include <iostream>
#include <cassert>
template <typename T>
class MyVector
{
private:
	T* data{ nullptr };
	size_t size{};
	unsigned capacity{};
	void clear();
	void resize(unsigned newCap);
	void copy(MyVector const& other);
public:
	MyVector() = default;
	MyVector(unsigned _capacity);
	MyVector(MyVector const& other);
	MyVector& operator=(MyVector const& other);
	~MyVector();

	size_t getSize() const { return size; }
	unsigned getCapacity() const { return capacity; }

	void setSize(size_t newSize);
	void print(std::ostream& out=std::cout) const;
	void addElement(T const& newEl);
	bool removeElement(T element);

	T& operator[](int index) const;
};




template <typename T>
void MyVector<T>::clear() 
{
//	std::cout << &data;
	delete[] data;
}

template <typename T>
void MyVector<T>::copy(MyVector const& other)
{
//	clear();
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];
	for (unsigned i = 0; i < size; i++)
		data[i] = other.data[i];
}

template <typename T>
void MyVector<T>::resize(unsigned newCap)
{
	if (capacity >= newCap)
		return;
	capacity = newCap;
	T* newArr = new T[newCap];
	for (unsigned i = 0; i < size; i++)
		newArr[i] = data[i];
	delete[] data;
	data = newArr;
}

template <typename T>
MyVector<T>::~MyVector()
{
	clear();
}

template <typename T>
MyVector<T>::MyVector(unsigned _capacity)
	:size(0), capacity(_capacity), data(nullptr)
{
	data = new T[capacity];
}

template <typename T>
MyVector<T>::MyVector(MyVector const& other)
	:data(nullptr)
{
	copy(other);
}

template <typename T>
void MyVector<T>::setSize(size_t newSize)
{
	size = newSize;
}
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T> const& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

template <typename T>
void MyVector<T>::print(std::ostream& out) const
{
	for (unsigned i = 0; i < size; i++)
		out << data[i];
}



template <typename T>
T& MyVector<T>::operator[](int index) const
{
	assert(index >= 0);
	return data[index];
}
template <typename T>
void MyVector<T>::addElement(T const& newEl)
{
	if (size == capacity)
		resize(2 * capacity + 1);
	data[size++] = newEl;

}

template <typename T>
bool MyVector<T>::removeElement(T element)
{
	for (unsigned i = 0; i < size; i++)
	{
		if (data[i] == element)
		{
			for (unsigned j = i; j < size; j++)
			{
				data[j] = data[j + 1];
			}
			size--;
			return true;
		}
	}
	return false;
}

#endif // !_MYVECTOR_HPP