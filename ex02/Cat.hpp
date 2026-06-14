#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public AAnimal {
public:
    Cat(const std::string& name);
    virtual ~Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual void makeSound() const;
};

#endif