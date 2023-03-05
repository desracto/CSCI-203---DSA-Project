#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::vector<int>> load_array_vec()
{

	std::ifstream file("map_844x480.dat");
	std::vector<std::vector<int>> arr(480, std::vector<int>(844)); // Row count, column count
	std::string word;

	try
	{
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

void print_array(std::vector<std::vector<int>>& arr, const std::vector<std::pair<int, int>>& selected_points)
{
	int i = 0;
	for (int r = 0; r < arr.size(); r++)
	{
		for (int c = 0; c < arr[r].size(); c++)
		{
			if (r == selected_points[i].first && c == selected_points[i].second)
			{
				std::cout << " | " << arr[r][c] << " | ";
				continue;
			}
			std::cout << arr[r][c] << "  ";
		}
		std::cout << std::endl;
	}
}

int main()
{

}
