/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrakoto <nyrakoto@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 06:59:34 by nyrakoto          #+#    #+#             */
/*   Updated: 2026/06/16 06:59:35 by nyrakoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	
	std::cout << "Type of j: " << j->getType() << std::endl;
	std::cout << "Type of i: " << i->getType() << std::endl;

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << "Type of wrongMeta: " << wrongMeta->getType() << std::endl;
	std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;
	std::cout << std::endl;
	
	wrongCat->makeSound();
	wrongMeta->makeSound();
	std::cout << std::endl;

	delete wrongMeta;
	delete wrongCat;
	std::cout << std::endl;

	Dog myDog;
	Cat myCat;
	std::cout << std::endl;

	std::cout << "myDog type: " << myDog.getType() << std::endl;
	std::cout << "myCat type: " << myCat.getType() << std::endl;
	myDog.makeSound();
	myCat.makeSound();
	std::cout << std::endl;

	Dog copyDog(myDog);
	Cat copyCat(myCat);
	std::cout << "copyDog type: " << copyDog.getType() << std::endl;
	std::cout << "copyCat type: " << copyCat.getType() << std::endl;
	copyDog.makeSound();
	copyCat.makeSound();
	std::cout << std::endl;

	Dog assignDog;
	assignDog = myDog;
	std::cout << "assignDog type: " << assignDog.getType() << std::endl;
	assignDog.makeSound();
	std::cout << std::endl;

	WrongCat directWrongCat;
	std::cout << "Direct WrongCat makeSound: ";
	directWrongCat.makeSound();
	std::cout << std::endl;

	return 0;
}
