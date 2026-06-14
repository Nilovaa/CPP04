#include "Animal.hpp"

Animal::Animal() : _name("Unknown") {
    std::cout << "Animal created: " << _name << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destroyed: " << _name << std::endl;
}

Animal::Animal(const Animal& other) : _name(other._name) {
    std::cout << "Animal copied: " << _name << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        _name = other._name;
    }
    std::cout << "Animal assigned: " << _name << std::endl;
    return *this;
}

void Animal::makeSound() const {
    std::cout << _name << " makes a sound." << std::endl;
}
