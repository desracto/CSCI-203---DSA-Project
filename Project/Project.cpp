#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <istream>

// using namespace std;
using std::cout;

void file_reader1()
{
	std::fstream file("C:\\Users\\Dell i7\\OneDrive - University of Wollongong\\CSCI-203\\Assignment 2\\map_844x480.dat", std::ios::in);
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


const int ROWS = 480;
const int COLS = 844;

int fileReader() 
{


	// Open the input file

	std::ifstream file("C:\\Users\\Dell i7\\OneDrive - University of Wollongong\\CSCI-203\\Assignment 2\\map_844x480.dat", std::ios::binary); //specifying file is binary

	// Check if file was opened successfully

	if (!file.is_open()) {
		cout << "Failed to open file." << std::endl;
		return 1;
	}

	// Read the input data into a 1D array

	int data[ROWS * COLS];
	file.read(reinterpret_cast<char*>(data), ROWS * COLS * sizeof(int));

	// Close the input file

	file.close();

	// Transpose the row-major 1D array into a 2D array in column-major format

	int map[COLS][ROWS];

	for (int i = 0; i < ROWS; i++) 
	{
		for (int j = 0; j < COLS; j++) 
		{
			map[j][i] = data[i * COLS + j];
		}
	}

	//	Map test by printing the value at row 0, column 0

	cout << "Elevation at (0,0): " << map[0][0] << std::endl;

	return 0;
}



int main()
{
	fileReader();
}
