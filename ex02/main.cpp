/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrakoto <nyrakoto@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 07:04:38 by nyrakoto          #+#    #+#             */
/*   Updated: 2026/06/16 07:04:39 by nyrakoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ARRAY_SIZE 10

int main()
{
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		std::cout << std::endl;
		std::cout << "Type of j: " << j->getType() << std::endl;
		std::cout << "Type of i: " << i->getType() << std::endl;
		j->makeSound();
		i->makeSound();
		std::cout << std::endl;
		delete j;
		delete i;
		std::cout << std::endl;
	}

	{
		AAnimal* animals[ARRAY_SIZE];
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			if (i < ARRAY_SIZE / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		std::cout << std::endl;
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			std::cout << animals[i]->getType() << ": ";
			animals[i]->makeSound();
		}
		std::cout << std::endl;
		for (int i = 0; i < ARRAY_SIZE; i++)
			delete animals[i];
		std::cout << std::endl;
	}

	{
		Dog original;
		original.getBrain()->setIdea(0, "Chase the ball");

		Dog copy(original);
		copy.getBrain()->setIdea(0, "Sleep all day");
		std::cout << std::endl;
		std::cout << "Original: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy: " << copy.getBrain()->getIdea(0) << std::endl;
		std::cout << "Brains differ: " << (original.getBrain() != copy.getBrain() ? "YES" : "NO") << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
