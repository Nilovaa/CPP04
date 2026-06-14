#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();
delete j;//should not create a leak
delete i;

return 0;
}