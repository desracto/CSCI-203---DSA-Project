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
	}
	catch (std::exception& e)
	{
		std::cout << "EXCEPTION: " << e.what();
	}

	return arr;
	file.close();
}

int calculate_path_cost(const std::vector<std::vector<int>>& arr, const std::vector<std::pair<int, int>>& selected_points)
{
	int total_cost = 0;
	for (int i = 0; i < selected_points.size() - 1; i++)
	{
		// DEBUG PRINTS - remove later 
		//std::cout << "First Point: " << arr[selected_points[i].first][selected_points[i].second] << " Y = " << selected_points[i].second << std::endl;
		//std::cout << "Second Point: " << arr[selected_points[i + 1].first][selected_points[i + 1].second] << " Y = " << selected_points[i + 1].second << std::endl;

		total_cost += abs(arr[selected_points[i].first][selected_points[i].second] - arr[selected_points[i + 1].first][selected_points[i + 1].second]);
	}
	return total_cost;
}

void print_coords(const std::vector < std::pair<int, int>>& selected_coords)
{
	std::cout << "Coordinates: " << std::endl;
	for (int i = 0; i < selected_coords.size(); i++)
	{
		std::cout << " (" << selected_coords[i].first << "," << selected_coords[i].second << ")" << std::endl;
	}
}

int main()
{
	auto arr = load_array_vec();
	std::vector<std::pair<int, int>> selected_points = { {0, 0}, {1, 1}, {0, 2}, {0, 3}, {2, 4} };
	
	std::cout << "Total Cost: " << calculate_path_cost(arr, selected_points) << std::endl;
	print_coords(selected_points);
	
}
