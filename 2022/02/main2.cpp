/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/03 17:01:03 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/12/03 17:45:47 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	calculate_round_score(std::string line)
{
	int	score;

	score = (line.at(2) - 88) * 3;
	if (line.at(2) == 'X')
	{
		if (line.at(0) == 'A')
			score += (line.at(0) - 64 + 2);
		else
			score += (line.at(0) - 64 - 1);
	}
	else if (line.at(2) == 'Y')
		score += line.at(0) - 64;
	else
	{
		if (line.at(0) == 'C')
			score += (line.at(0) - 64 - 2);
		else
			score += (line.at(0) - 64 + 1);
	}
	return (score);
}

int main(void)
{
	int	result = 0;
	std::string line;
	std::ifstream myfile("input.txt");

	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			result += calculate_round_score(line);
		}
		std::cout << "result: " << result << std::endl;
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}

/*
Explanation

By substracting 88 of the x/y/z value and multiplying that by 3 I get the score of the outcome of the round.

In a lose scenario I should play (opponents move - 1) (except in case a x, then I should play opponents move + 2)
In a draw scenario I should play opponents move
In a win scenario I should play (opponents move + 1) (except in case c z, then I should play opponents move - 2)

input	my move
a x		c lose
a y		a draw
a z		b win
b x		a lose
b y		b draw
b z		c win
c x		b lose
c y 	c draw
c z		a win
*/
