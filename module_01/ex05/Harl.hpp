
#include <iostream>

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();

	public:
		void complain(std::string level);
};

typedef void (Harl::*function_ptr)();
