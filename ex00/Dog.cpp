#include "Dog.hpp"

Dog::Dog(const std::string& name) : Animal(name) {
    std::cout << "Dog created: " << _name << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destroyed: " << _name << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copied: " << _name << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Dog assigned: " << _name << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << _name << " Woof Woof!" << std::endl;
}
