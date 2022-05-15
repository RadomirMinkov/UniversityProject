#ifndef _MYVECTOR_HPP
#define _MYVECTOR_HPP

#include <iostream>
#include <cassert>
/**
 * @brief template class for the vector which is list of data
 * 
 * @tparam T type of data
 */
template <typename T>
class MyVector
{
	///private properties to the class
private:
///pointer to data of type T
	T* data{ nullptr };
	///the size of the data
	size_t size{};
	///capacity of the array
	unsigned capacity{};
	///function that delete memory
	void clear();
	/**
	 * @brief function that resizes xthe array
	 * 
	 * @param newCap the new capacity
	 */
	void resize(unsigned newCap);
	/**
	 * @brief function that copies one object to other
	 * 
	 * @param other the object that will be copied
	 */
	void copy(MyVector const& other);
public:
/**
 * @brief deffault constructor
 * 
 */
	MyVector() = default;
	/**
	 * @brief Constructor with parameters
	 * 
	 * @param _capacity the capacity of the array
	 */
	MyVector(unsigned _capacity);
	/**
	 * @brief copy constructor
	 * 
	 * @param other the object that will be copied
	 */
	MyVector(MyVector const& other);
	/**
	 * @brief operator = tha provides the possibility to  appropriate one vector to other
	 * 
	 * @param other the object that will be copied
	 * @return MyVector& refference to the this
	 */
	MyVector& operator=(MyVector const& other);
	/**
	 * @brief Destroy the vector
	 * 
	 */
	~MyVector();
	///get the size of the vector
	size_t getSize() const { return size; }
	///get the capacity of the vector
	unsigned getCapacity() const { return capacity; }

	/**
	 * @brief changing the size
	 * 
	 * @param newSize the new size
	 */
	void setSize(size_t newSize);
	/**
	 * @brief printing the vector
	 * 
	 * @param out the stream that shows where information will be printed
	 */
	void print(std::ostream& out=std::cout) const;
	/**
	 * @brief function that adds new element to the vector
	 * 
	 * @param newEl the new element that will be added
	 */
	void addElement(T const& newEl);
	/**
	 * @brief function that removes element form the vector
	 * 
	 * @param element the element that will be removed
	 * @return true the element was removed successfully
	 * @return false the couldn't be removed
	 */
	bool removeElement(T const& element);
	/**
	 * @brief checks if two vectors are equal
	 * 
	 * @param other the second vector
	 * @return true they are equal
	 * @return false they are not equal
	 */
	bool operator==(MyVector const& other)const;
	/**
	 * @brief operator for returning the element in the vector with provided index
	 * 
	 * @param index the index that shows the position of the element
	 * @return T& refference to the e;ement
	 */
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
bool MyVector<T>::removeElement(T const& element)
{
	for (unsigned i = 0; i < size; i++)
	{
		if (data[i] == element)
		{
			for (unsigned j = i; j < size-1; j++)
			{
				data[j] = data[j + 1];
			}
			size--;
			return true;
		}
	}
	return false;
}

template <typename T>
bool MyVector<T>::operator==(MyVector<T> const& other)const
{
	return size == other.size && capacity == other.capacity && data == other.data;
}
#endif // !_MYVECTOR_HPP