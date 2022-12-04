/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main1.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/04 10:07:57 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/12/04 10:07:59 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(void)
{
	int	fully_contained = 0;
	std::vector<int> ids;
	std::string line;
	std::ifstream myfile("input.txt");

	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			ids.push_back(stoi(line.substr(0, line.find("-"))));
			ids.push_back(stoi(line.substr(line.find("-") + 1, line.find(","))));
			ids.push_back(stoi(line.substr(line.find(",") + 1, line.find_last_of("-"))));
			ids.push_back(stoi(line.substr(line.find_last_of("-") + 1)));
			if ((ids.at(0) <= ids.at(2) && ids.at(1) >= ids.at(3)) || (ids.at(2) <= ids.at(0) && ids.at(3) >= ids.at(1)))
				fully_contained++;
			ids.clear();
		}
		std::cout << "fully_contained: " << fully_contained << std::endl;
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}
