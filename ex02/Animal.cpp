#include "Animal.hpp"

AAnimal::AAnimal() : _name("Unknown") {
    std::cout << "Animal created: " << _name << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "Animal destroyed: " << _name << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _name(other._name) {
    std::cout << "Animal copied: " << _name << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        _name = other._name;
    }
    std::cout << "Animal assigned: " << _name << std::endl;
    return *this;
}
