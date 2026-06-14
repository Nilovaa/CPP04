#include "Dog.hpp"

Dog::Dog(const std::string& name) : AAnimal() {
    _name = name;
    std::cout << "Dog created: " << _name << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destroyed: " << _name << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog copied: " << _name << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
    }
    std::cout << "Dog assigned: " << _name << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << _name << " Woof Woof!" << std::endl;
}
