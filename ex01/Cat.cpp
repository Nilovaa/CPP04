#include "Cat.hpp"

Cat::Cat(const std::string& name) : Animal(name) {
    std::cout << "Cat created: " << _name << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destroyed: " << _name << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copied: " << _name << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cat assigned: " << _name << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << _name << " Meow Meow!" << std::endl;
}