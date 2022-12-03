/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 18:14:29 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/12/03 18:20:06 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	calculate_priority(std::string line1, std::string line2, std::string line3)
{
	for (unsigned long i = 0; i < line1.length(); i++)
	{
		for (unsigned long j = 0; j < line2.length(); j++)
		{
			for (unsigned long k = 0; k < line3.length(); k++)
			{
				if (line1.at(i) == line2.at(j) && line1.at(i) == line3.at(k))
				{
					if (line1.at(i) >= 'a' && line1.at(i) <= 'z')
						return (line1.at(i) - 96);
					else if (line1.at(i) >= 'A' && line1.at(i) <= 'Z')
						return (line1.at(i) - 38);
				}
			}
		}
	}
	std::cout << "no common item!" << std::endl;
	return (0);
}

int main(void)
{
	int	priorities = 0;
	std::string line1;
	std::string line2;
	std::string line3;
	std::ifstream myfile("input.txt");

	if (myfile.is_open())
	{
		while ( getline (myfile, line1) )
		{
			getline(myfile, line2);
			getline(myfile, line3);
			priorities += calculate_priority(line1, line2, line3);
		}
		std::cout << "priorities: " << priorities << std::endl;
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}
