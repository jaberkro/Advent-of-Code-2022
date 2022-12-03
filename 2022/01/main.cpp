/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 06:20:17 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/12/03 16:32:53 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(void)
{
	int	result = 0;
	std::vector<int> calories;
	std::string line;
	std::ifstream myfile("input.txt");

	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			if (line.compare("") == 0)
			{
				calories.push_back(result);
				result = 0;
			}
			else
				result += stoi(line);
		}
		std::sort(calories.begin(), calories.end());
		std::reverse(calories.begin(), calories.end());
		std::cout << "max calories top 3: " << calories.at(0) << ", " << calories.at(1) << ", " << calories.at(2) << std::endl;
		std::cout << "sum of 3 max calories: " << calories.at(0) + calories.at(1) + calories.at(2) << std::endl;
		myfile.close();
	}
  else std::cout << "Unable to open file"; 
  return (0);
}
