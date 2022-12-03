/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main1.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 06:20:17 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/12/03 17:45:48 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(void)
{
	int	result = 0;
	std::string line;
	std::ifstream myfile("input.txt");

	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			result += line.at(2) - 87;
			if ((line.at(2) - line.at(0)) % 3 == 0)
				result += 6;
			else if (line.at(2) - line.at(0) == 23)
				result += 3;
		}
		std::cout << "result: " << result << std::endl;
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}

/*
Explanation

By substracting 87 of the ascii value of my input I get the score of the shape I selected.

I calculated the distance between the ascii values of the possible inputs. 
By checking the outcomes of the matches I concluded that:
- a difference of 21 or 24 implies a win scenario (a.k.a. any difference of which % 3 == 0)
- a difference of 23 always implies a draw scenario
- a difference of 22 or 25 implies a lose scenario

a x		23 draw
a y		24 win
a z		25 lose
b x		22 lose
b y		23 draw
b z		24 win
c x		21 win
c y 	22 lose
c z		23 draw
*/