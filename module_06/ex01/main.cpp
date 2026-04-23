
#include "Serializer.hpp"



int main(void)
{
	Data person_one;
	Data person_two;

	person_one.name = "Liath";
	person_one.age = 30;
	person_one.favourite_colour = "Yellow";

	person_two.name = "Jisse";
	person_two.age = 22;
	person_two.favourite_colour = "Purple";

	uintptr_t person_one_serialized_data = Serializer::serialize(&person_one);
	std::cout << YELLOW << "serialized data person one: " << DEFAULT << person_one_serialized_data << std::endl;

	Data* person_one_deserialized_data = Serializer::deserialize(person_one_serialized_data);
	std::cout << YELLOW << "name: " << DEFAULT << person_one_deserialized_data->name << std::endl;
	std::cout << YELLOW << "age: " << DEFAULT << person_one_deserialized_data->age << std::endl;
	std::cout << YELLOW << "favourite colour: " << DEFAULT << person_one_deserialized_data->favourite_colour << std::endl;

	uintptr_t person_two_serialized_data = Serializer::serialize(&person_two);
	std::cout << YELLOW << "serialized data person two: " << DEFAULT << person_two_serialized_data << std::endl;

	Data* person_two_deserialized_data = Serializer::deserialize(person_two_serialized_data);
	std::cout << YELLOW << "name: " << DEFAULT << person_two_deserialized_data->name << std::endl;
	std::cout << YELLOW << "age: " << DEFAULT << person_two_deserialized_data->age << std::endl;
	std::cout << YELLOW << "favourite colour: " << DEFAULT << person_two_deserialized_data->favourite_colour << std::endl;

	return (0);
}
