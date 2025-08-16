#include "Serializer.hpp"

int main()
{
    Data    original_data;
    original_data.value = 42;
    original_data.str = "Test string";

    std::cout << "\n-------Original Data-------\n";
    std::cout << "str:   " << original_data.str << std::endl;
    std::cout << "value: " << original_data.value << std::endl;

    uintptr_t serialized_data = Serializer::serialize(&original_data);
    Data*   deserialized_data = Serializer::deserialize(serialized_data);

    std::cout << "\n-----Deserialized Data-----\n";
    std::cout << "str:   " << (*deserialized_data).str << std::endl;
    std::cout << "value: " << (*deserialized_data).value << std::endl;

    std::cout << "\nMemory address of Original data:     " << &original_data << std::endl;
    std::cout << "Memory address of Deserialized data: " << deserialized_data << std::endl;

}
