#include <iostream>
#include <fstream>

int	doubles(char *last4)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (last4[i] == last4[j])
				return (1);
		}
	}
	return (0);
}

int main(void)
{
	char 			last4[4];
	std::string 	line;
	std::ifstream 	myfile("input.txt");

	if (myfile.is_open())
	{
		getline (myfile,line);
		for (int i = 0; i < 4; i++)
			last4[i] = line.at(0);
		for (unsigned long i = 0; i < line.length(); i++)
		{
			last4[i % 4] = line.at(i);
			if (!doubles(last4))
			{
				std::cout << i + 1 << std::endl;
				break;
			}	
		}
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}
