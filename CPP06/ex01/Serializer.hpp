#pragma once

# include <iostream>
# include <stdint.h>
# include "Data.h"

class Serializer
{
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer& src);
    Serializer &operator=(const Serializer& src);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

