#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::vector<int>> load_array_vec()
{
  // make sure to change the path
  std::ifstream file("F:\\Programs\\Onedrive\\OneDrive - University of Wollongong\\Studies\\2023 Winter - 203, 317, 214\\CSCI 203\\Assignment\\Assignment 2\\map_844x480.dat");
  std::vector<std::vector<int>> arr(480, std::vector<int>(844)); // Row count, column count
  
	try
	{
		std::string word;
		for (int r = 0; r < 480; r++)
		{
			for (int c = 0; c < 844; c++)
			{
				file >> word;
				arr[r][c] = stoi(word);
			}
		}

		return arr;
	}
	catch (std::exception& e)
	{
		std::cout << "EXCEPTION: " << e.what();
		return arr;
	}
  
  file.close();
}

void print_array(std::vector<std::vector<int>>& arr)
{
	for (int r = 0; r < arr.size(); r++)
	{
		for (int c = 0; c < arr[r].size(); c++)
		{
			std::cout << arr[r][c] << std::endl;
		}
	}
}

int main()
{

}
