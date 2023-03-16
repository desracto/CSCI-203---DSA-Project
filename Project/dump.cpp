/*
std::pair<int, int> find_max_points(const std::vector<std::pair<int, int>>& selected_points)
{
	int max_x = 0;
	int max_y = 0;
	std::pair<int, int> max_coords;

	for (int i = 0; i < selected_points.size(); i++)
	{
		if (max_x < selected_points[i].first)
		{
			max_x = selected_points[i].first;
		}

		if (max_y < selected_points[i].second)
		{
			max_y = selected_points[i].second;
		}
	}

	max_coords.first = max_x;
	max_coords.second = max_y;

	return max_coords;
}

void print_array(std::vector<std::vector<int>>& arr, const std::vector<std::pair<int, int>>& selected_points)
{
	// .first is X
	// .second is Y
	int i = 0;
	std::pair<int, int> max_points = find_max_points(selected_points);

	for (int x = 0; x < max_points.first + 1; x++)
	{
		for (int y = 0; y < max_points.second + 1; y++)
		{
			if (x == selected_points[i].first && y == selected_points[i].second)
			{
				std::cout << " | " << arr[x][y] << " | ";
				i++;
				continue;
			}
			std::cout << "   " << arr[x][y] << "   ";
		}
		std::cout << std::endl;
	}
}

void print_array(std::vector<std::vector<int>>& arr, const std::vector<int>& selected_points, const int max_rows)
{
	for (int x = 0; x < max_rows + 1; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (selected_points[844 * x + y] == 1)
			{
				std::cout << " | " << arr[x][y] << " | ";
				continue;
			}
			std::cout << "   " << arr[x][y] << "   ";
		}
		std::cout << std::endl;
	}
}

void store_array(std::vector<std::vector<int>>& arr, const std::vector<int>& selected_points, const int max_rows)
{
	int counter = 0;
	int file_counter = 0;

	std::ofstream file("file" + std::to_string(file_counter) + ".txt");

	for (int x = 0; x < max_rows + 1; x++)
	{
		for (int y = 0; y < 45; y++)
		{
			if (selected_points[844 * x + y] == 1)
			{
				file << " | " << arr[x][y] << " | ";
				continue;
			}
			file << "   " << arr[x][y] << "   ";
		}
		file << std::endl;
	}
}




			// std::cout << "Comparing upward: " << map[currentRow - 1][c] << " Difference: " << upwardDiff << std::endl;

*/

// ALL FUNCTIONS HERE ARE DUMPED HERE.