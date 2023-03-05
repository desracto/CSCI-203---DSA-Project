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

void sen1A()
{
    const int ROWS = 480;
    const int COLUMNS = 844;

    int map[ROWS][COLUMNS];

    // load map into vector from file (tried adding here, made everything red, so ill leave that to you)
    //above 2D matrix is just there so u understand my logic (if u can)

    int currentRow = 2;
    int currentColumn = 0; // left most starting column
    int currentElev = map[currentRow][currentColumn]; // initial elevation

    // Print starting point (location --> (row, column)) and elevation

    cout << "Start location: (" << currentRow << ", " << currentColumn << ")" << endl;
    cout << "Start elevation: " << currentElev << endl;

    // loop through each column

    for (int c = 1; c < COLUMNS; c++) // starting from the second column
    {
        int minDiff = abs(map[currentRow][c] - currentElev); // the difference between current locatio & forward location
        int rowChosen = currentRow;

        // check UPWARD locations

        if (currentRow > 0 && abs(map[currentRow - 1][c] - currentElev) < minDiff)
        {
            minDiff = abs(map[currentRow - 1][c] - currentElev);  // the difference between current locatio & upward location
            rowChosen = currentRow - 1;
        }

        // check DOWNWARD locations

        if (currentRow < ROWS - 1 && abs(map[currentRow + 1][c] - currentElev) < minDiff)
        {
            minDiff = abs(map[currentRow + 1][c] - currentElev); // the difference between current locatio & downward location
            rowChosen = currentRow + 1;
        }

        // In case of a tie, a coin toss will be conducted.

        if (currentRow > 0 && currentRow < ROWS - 1 && abs(map[currentRow - 1][c] - currentElev) == minDiff && abs(map[currentRow + 1][c] - currentElev) == minDiff)
        {
            int coinToss = rand() % 2; // random select between 0 or 1

            if (coinToss == 0)
            {
                rowChosen = currentRow - 1;
            }
            else
            {
                rowChosen = currentRow + 1;
            }
        }
        else if (currentRow > 0 && abs(map[currentRow - 1][c] - currentElev) == minDiff)   //Hiba Note: starting from here, in my head, these 2 else ifs are necessary for testing, THINK they might be redundant as i already wrote b4, but
        {
            rowChosen = currentRow - 1;
        }
        else if (currentRow < ROWS - 1 && abs(map[currentRow + 1][c] - currentElev) == minDiff)
        {
            rowChosen = currentRow + 1;
        }

        // update current location and elevation
        currentRow = rowChosen;
        currentColumn = c;
        currentElev = map[currentRow][currentColumn];

        // display current location and elevation
        cout << "Column " << c << ":\n";
        cout << "Current location: (" << currentRow << ", " << currentColumn << ")" << endl;
        cout << "Current elevation: " << currentElev << endl;
    }


}

int main()
{
	auto arr = load_array_vec();
	std::vector<std::pair<int, int>> selected_points = { {0, 0}, {1, 1}, {0, 2}, {0, 3}, {2, 4} };
	
	std::cout << "Total Cost: " << calculate_path_cost(arr, selected_points) << std::endl;
	print_coords(selected_points);
	
}
