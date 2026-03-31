
# include "Array.hpp"

template <typename T>
class Array
{
	private:
		T*			 _data;         
		unsigned int _size;

	public:
		// Member functions
		unsigned int size() const;

		// Getters and Setters

		// Constructors
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);

		// Destructors
		~Array();

		// Overload operators
		Array &operator=(const Array& src);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
};
