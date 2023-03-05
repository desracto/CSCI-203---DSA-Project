#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <istream>
#include <array>

int (*load_array_2D())[844]
{
	std::fstream file("F:\\Programs\\Onedrive\\OneDrive - University of Wollongong\\Studies\\2023 Winter - 203, 317, 214\\CSCI 203\\Assignment\\Assignment 2\\map_844x480.dat", std::ios::in);

	int(*arr)[844] = new int[480][844];
	std::string word;
	try 
	{
		// File is column by row
		// Array needs to be row by column
		// This transposes the file automatically as it will 
		// select a column first then incremet row by row
		for (int c = 0; c < 844; c++)
		{
			for (int r = 0; r < 480; r++)
			{
				file >> word;
				arr[r][c] = stoi(word);
			}
		}
		return arr;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		return arr;
	}

}

int main()
{
	try {
		int (*arr)[844] = load_array_2D();

		std::cout << arr[479][843]; // ignore warning. trust
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}
