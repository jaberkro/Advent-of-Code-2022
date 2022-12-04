/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/04 10:08:05 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/12/04 10:10:28 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(void)
{
	int	overlap = 0;
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
			if (!((ids.at(0) < ids.at(2) && ids.at(1) < ids.at(2)) || (ids.at(2) < ids.at(0) && ids.at(3) < ids.at(0))))
				overlap++;
			ids.clear();
		}
		std::cout << "overlap: " << overlap << std::endl;
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}
