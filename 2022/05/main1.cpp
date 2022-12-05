/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main1.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 20:28:27 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/12/05 20:56:11 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	move_stacks(std::string line, std::string *stacks)
{
	int	amount;
	int	from;
	int	to;

	amount = stoi(line.substr(5, line.find(" from ")));
	from = stoi(line.substr(line.find(" from ") + 6, line.find(" to "))) - 1;
	to = stoi(line.substr(line.find(" to ") + 4, line.length())) - 1;
	for (int i = 0; i < amount; i++)
	{
		if (stacks[from][0])
		{
			stacks[to] += stacks[from].at(stacks[from].length() - 1);
			stacks[from].pop_back();
		}
	}
}

void	fill_stacks(std::string line, std::string *stacks, int size)
{
	if (line.at(1) == '1')
		return ;
	for (int i = 0; i < size; i++)
	{
		if (line.at(1 + i * 4) != ' ')
			stacks[i] = line.at(1 + i * 4) + stacks[i];
	}	
}

int main(void)
{
	int	size = 9; // update this according to input size
	bool move = false;
	std::string stacks[size];
	std::string line;
	std::ifstream myfile("input.txt");

	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			if (line.compare("") == 0)
				move = true;
			else if (move == false)
				fill_stacks(line, stacks, size);
			else
				move_stacks(line, stacks);
		}
		myfile.close();
		for (int i = 0; i < size; i++)
			std::cout << stacks[i].at(stacks[i].length() - 1);
		std::cout << std::endl;
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}
