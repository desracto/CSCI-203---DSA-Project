#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <istream>


// using namespace std;
using std::cout;

void file_reader()
{
	std::fstream file("F:\\Programs\\Onedrive\\OneDrive - University of Wollongong\\Studies\\2023 Winter - 203, 317, 214\\CSCI 203\\Assignment\\Assignment 2\\map_844x480.dat", std::ios::in);
	std::vector<int> arr;
	std::string word;

	try
	{
		while (!file.eof())
		{
			file >> word;
			arr.push_back(stoi(word));
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
	
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i];
	}

}


void convert_to_array()
{
	std::fstream file("map_844x480.dat", std::ios::in);
	std::vector<std::vector<int>> arr;

	int i, j;

	std::string word;
	while (!file.eof())
	{
		file >> word;
	}
	std::cout << word;
}

int main()
{
	file_reader();
}
