#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class AAnimal {
public:
    AAnimal();
    virtual ~AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual void makeSound() const = 0;
protected:
    std::string _name;
};

#endif