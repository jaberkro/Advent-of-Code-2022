/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main1.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 06:20:17 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/12/03 18:11:12 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	calculate_priority(std::string line)
{
	for (unsigned long i = 0; i < line.length() / 2; i++)
	{
		for (unsigned long j = line.length() / 2; j < line.length(); j++)
		{
			if (line.at(i) == line.at(j))
			{
				if (line.at(i) >= 'a' && line.at(i) <= 'z')
					return (line.at(i) - 96);
				else if (line.at(i) >= 'A' && line.at(i) <= 'Z')
					return (line.at(i) - 38);
			}
		}
	}
	std::cout << "no common items!" << std::endl;
	return (0);
}

int main(void)
{
	int	priorities = 0;
	std::string line;
	std::ifstream myfile("input.txt");

	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			priorities += calculate_priority(line);
		}
		std::cout << "priorities: " << priorities << std::endl;
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}
