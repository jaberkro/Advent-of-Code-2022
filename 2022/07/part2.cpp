#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int	count_dir_size(std::ifstream *myfile, std::string line, std::vector<int> *dirs)
{
	int	count = 0;

	while ( getline (*myfile,line) )
	{
		if (line.compare("$ cd ..") == 0 || line.compare("") == 0)
			break ;
		else if (line.find("$ cd ") == 0)
			count += count_dir_size(myfile, line, dirs);
		else if (line.compare("$ ls") == 0 || line.find("dir") == 0)
			continue ;
		else
			count += stoi(line.substr(0, line.find(" ")));
	}
	(*dirs).push_back(count);
	return (count);
}

int main(void)
{
	std::string line;
	std::ifstream myfile("input.txt");
	std::vector<int> dirs;
	int	to_free;

	if (myfile.is_open())
	{
		count_dir_size(&myfile, line, &dirs);
		sort(dirs.begin(), dirs.end());
		dirs.pop_back();
		to_free = 30000000 - (70000000 - dirs.at(dirs.size() - 1));
		for (unsigned long i = 0; i < dirs.size(); i++)
		{
			if (dirs.at(i) >= to_free)
			{
				std::cout << "free dir with this size: " << dirs.at(i) << std::endl;
				break ;
			}
		}
		myfile.close();
	}
  	else std::cout << "Unable to open file"; 
  	return (0);
}
