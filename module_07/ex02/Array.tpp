
# include "Array.hpp"


// Member functions
template <typename T>
size_t Array<T>::size(void)
{
	return (_size);
}

// Getters and Setters

// Constructors
template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
	std::cout << BLUE << "Array default constructor is called" << DEFAULT << std::endl;
}

template <typename T>
Array<T>::Array(size_t n) : _data(NULL), _size(n)
{
	_data = new T[_size];
	// for (size_t i = 0; i < _size; i++)
	// {
	// 	_data[i] = NULL;
	// }
	std::cout << BLUE << "Array parameterized constructor is called" << DEFAULT << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	_size = other._size;
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
	std::cout << BLUE << "Array copy constructor is called" << DEFAULT << std::endl;

}

// Destructors
template <typename T>
Array<T>::~Array()
{
	delete[] _data;
	std::cout << BLUE << "Array deconstructor is called" << DEFAULT << std::endl;
}

// Overload operators
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _data;

		_size = other._size;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = other._data[i];
		}
	}
	std::cout << BLUE << "Array copy assignment is called" << DEFAULT << std::endl;
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return _data[index];
}


