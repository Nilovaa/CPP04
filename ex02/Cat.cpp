#include "Cat.hpp"

Cat::Cat(const std::string& name) : AAnimal() {
    _name = name;
    std::cout << "Cat created: " << _name << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destroyed: " << _name << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    std::cout << "Cat copied: " << _name << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
    }
    std::cout << "Cat assigned: " << _name << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << _name << " Meow Meow!" << std::endl;
}