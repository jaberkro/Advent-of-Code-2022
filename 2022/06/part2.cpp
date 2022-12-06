#include <iostream>
#include <fstream>

int	doubles(char *last14)
{
	for (int i = 0; i < 14; i++)
	{
		for (int j = i + 1; j < 14; j++)
		{
			if (last14[i] == last14[j])
				return (1);
		}
	}
	return (0);
}

int main(void)
{
	char 			last14[14];
	std::string 	line;
	std::ifstream 	myfile("input.txt");

	if (myfile.is_open())
	{
		getline (myfile,line);
		for (int i = 0; i < 14; i++)
			last14[i] = line.at(0);
		for (unsigned long i = 0; i < line.length(); i++)
		{
			last14[i % 14] = line.at(i);
			if (!doubles(last14))
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
