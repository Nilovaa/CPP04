#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual void makeSound() const;
protected:
    std::string _name;
};

#endif