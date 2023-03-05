#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <istream>
#include <array>

std::vector<std::vector<int>> load_array_vec()
{
	std::fstream file("F:\\Programs\\Onedrive\\OneDrive - University of Wollongong\\Studies\\2023 Winter - 203, 317, 214\\CSCI 203\\Assignment\\Assignment 2\\map_844x480.dat", std::ios::in);
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
}

int main()
{
	/*
	try {
		//int (*arr)[844] = load_array_2D();
		std::vector<std::vector<int>> arr = load_array_vec();
		std::cout << arr[0][0];

		//std::vector<int> arr2 = load_array_1d();
		//std::cout << arr2[844*479+843]; // ignore warning. trust
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	*/



	std::vector<std::pair<int, int>> arr_of_points = { {1, 2}, {3, 4} };


	std::cout << arr_of_points[1].first;
}

