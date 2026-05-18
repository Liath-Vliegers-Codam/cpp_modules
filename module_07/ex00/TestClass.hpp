
#include <iostream>

class TestClass
{
	private:
		int _int_value;
		float _float_value;
		double _double_value;
		std::string _string_value;
	public:
		TestClass();
		TestClass(int value, float float_value, double double_value, std::string string_value);
		~TestClass();

		int getInt();
		float getFloat();
		double getDouble();
		std::string getString();
};

TestClass::TestClass() : _int_value(0), _float_value(0.0f), _double_value(0.0), _string_value("")
{
	// std::cout << "TestClass default constructor is called" << std::endl;
}


TestClass::TestClass(int value, float float_value, double double_value, std::string string_value) : _int_value(value), _float_value(float_value), _double_value(double_value), _string_value(string_value)
{
	// std::cout << "TestClass parameterized constructor is called" << std::endl;
}

TestClass::~TestClass()
{    
	// std::cout << "TestClass destructor is called" << std::endl;
}

int TestClass::getInt()
{
	return (this->_int_value);
}

float TestClass::getFloat()
{
	return (this->_float_value);
}

double TestClass::getDouble()
{
	return (this->_double_value);
}

std::string TestClass::getString()
{
	return (this->_string_value);
}

std::ostream& operator<<(std::ostream& output_stream, TestClass& src)
{
	output_stream << "TestClass info:" << std::endl;
	output_stream << "  int_value: " << src.getInt() << std::endl;
	output_stream << "  float_value: " << src.getFloat() << std::endl;
	output_stream << "  double_value: " << src.getDouble() << std::endl;
	output_stream << "  string_value: " << src.getString() << std::endl;

	return (output_stream);
}
