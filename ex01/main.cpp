/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrakoto <nyrakoto@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 07:02:39 by nyrakoto          #+#    #+#             */
/*   Updated: 2026/06/16 07:02:40 by nyrakoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	std::cout << std::endl;

	{
		Animal* animals[10];
		for (int i = 0; i < 10; i++)
		{
			if (i < 5)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for (int i = 0; i < 10; i++)
		{
			std::cout << animals[i]->getType() << ": ";
			animals[i]->makeSound();
		}
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	std::cout << std::endl;

	{
		Dog original;
		original.getBrain()->setIdea(0, "Chase the ball");

		Dog copy(original);
		std::cout << std::endl;
		std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;

		copy.getBrain()->setIdea(0, "Sleep all day");
		std::cout << "After modifying copy:" << std::endl;
		std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
		std::cout << "Brains differ: " << (original.getBrain() != copy.getBrain() ? "YES" : "NO") << std::endl;
		std::cout << std::endl;
	}

	{
		Cat original;
		original.getBrain()->setIdea(0, "Catch the mouse");

		Cat copy(original);
		copy.getBrain()->setIdea(0, "Knock things off tables");
		std::cout << std::endl;
		std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
		std::cout << "Brains differ: " << (original.getBrain() != copy.getBrain() ? "YES" : "NO") << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	{
		Dog dog1;
		dog1.getBrain()->setIdea(0, "Fetch the stick");
		Dog dog2;
		dog2 = dog1;
		dog2.getBrain()->setIdea(0, "Roll over");
		std::cout << std::endl;
		std::cout << "dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
		std::cout << "Brains differ: " << (dog1.getBrain() != dog2.getBrain() ? "YES" : "NO") << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
