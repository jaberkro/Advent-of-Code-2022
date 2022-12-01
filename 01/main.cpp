/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 06:20:17 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/12/01 06:57:37 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void update_max(int result, int *max1, int *max2, int *max3)
{
	if (result > *max3)
	{
		if (result > *max2)
		{
			*max3 = *max2;
			if (result > *max1)
			{
				*max2 = *max1;
				*max1 = result;
			}
			else
				*max2 = result;
		}
		else
			*max3 = result;	
	}
}

int main(void)
{
	int	result = 0;
	int max1 = 0;
	int max2 = 0;
	int max3 = 0;
	std::string line;
	std::ifstream myfile("input.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			if (line.compare("") == 0)
			{
				update_max(result, &max1, &max2, &max3);
				result = 0;
			}
			else
				result += stoi(line);
		}
		std::cout << "max calories top 3: " << max1 << ", " << max2 << ", " << max3 << std::endl;
		std::cout << "sum of 3 max calories: " << max1 + max2 + max3 << std::endl;
		myfile.close();
	}
  else std::cout << "Unable to open file"; 
  return (0);
}
