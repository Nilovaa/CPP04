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

#define ARRAY_SIZE 10

int main()
{
	std::cout << "========== Subject test ==========" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}

	std::cout << std::endl;
	std::cout << "========== Array of Animals ==========" << std::endl;
	{
		Animal* animals[ARRAY_SIZE];
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			if (i < ARRAY_SIZE / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		std::cout << std::endl << "--- Sounds ---" << std::endl;
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			std::cout << animals[i]->getType() << ": ";
			animals[i]->makeSound();
		}
		std::cout << std::endl << "--- Deleting all animals ---" << std::endl;
		for (int i = 0; i < ARRAY_SIZE; i++)
			delete animals[i];
	}

	std::cout << std::endl;
	std::cout << "========== Deep copy test (Dog) ==========" << std::endl;
	{
		Dog original;
		original.getBrain()->setIdea(0, "Chase the ball");
		original.getBrain()->setIdea(1, "Eat the bone");

		Dog copy(original);
		std::cout << std::endl;
		std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;

		copy.getBrain()->setIdea(0, "Sleep all day");
		std::cout << "After modifying copy:" << std::endl;
		std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
		std::cout << "Brains differ: "
			<< (original.getBrain() != copy.getBrain() ? "YES" : "NO") << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Deep copy test (Cat) ==========" << std::endl;
	{
		Cat original;
		original.getBrain()->setIdea(0, "Catch the mouse");

		Cat copy(original);
		copy.getBrain()->setIdea(0, "Knock things off tables");
		std::cout << std::endl;
		std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
		std::cout << "Brains differ: "
			<< (original.getBrain() != copy.getBrain() ? "YES" : "NO") << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Assignment deep copy test ==========" << std::endl;
	{
		Dog dog1;
		dog1.getBrain()->setIdea(0, "Fetch the stick");
		Dog dog2;
		dog2 = dog1;
		dog2.getBrain()->setIdea(0, "Roll over");
		std::cout << std::endl;
		std::cout << "dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
		std::cout << "Brains differ: "
			<< (dog1.getBrain() != dog2.getBrain() ? "YES" : "NO") << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
