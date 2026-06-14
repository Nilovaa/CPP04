#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    setType("WrongCat");
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed: " << getType() << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copied: " << getType() << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat assigned: " << getType() << std::endl;
    return *this;
}

