#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;

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
		cout << "EXCEPTION: " << e.what();
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
		//cout << "First Point: " << arr[selected_points[i].first][selected_points[i].second] << " Y = " << selected_points[i].second << endl;
		//cout << "Second Point: " << arr[selected_points[i + 1].first][selected_points[i + 1].second] << " Y = " << selected_points[i + 1].second << endl;

		total_cost += abs(arr[selected_points[i].first][selected_points[i].second] - arr[selected_points[i + 1].first][selected_points[i + 1].second]);
	}
	return total_cost;
}

void print_coords(const std::vector < std::pair<int, int>>& selected_coords)
{
	cout << "Coordinates: " << endl;
	for (int i = 0; i < selected_coords.size(); i++)
	{
		cout << " (" << selected_coords[i].first << "," << selected_coords[i].second << ")" << endl;
	}
}

std::vector<std::pair<int, int>>  sen1A(const std::vector<std::vector<int>>& map)
{
    // Possible change: Check if matrix is square.

    std::vector<std::pair<int, int>> selected_coords;
    const int ROWS = map.size();
    const int COLS = map[0].size();

    int currentRow = 2;
    int currentColumn = 0; // left most starting column
    int currentElev = map[currentRow][currentColumn]; // initial elevation

    // Print starting point (location --> (row, column)) and elevation

    cout << "Start location: (" << currentRow << ", " << currentColumn << ")" << endl;
    cout << "Start elevation: " << currentElev << endl;

    // loop through each column
    for (int c = 1; c < COLS; c++) // starting from the second column
    {
        std::cout << std::endl;
        // check FORWARD location
        int minDiff = abs(map[currentRow][c] - currentElev); // the difference between current location & forward location
        // DEBUG FORWARD: 
        // std::cout << "Comparing forward: " << map[currentRow][c] << " Difference: " << minDiff << std::endl;
        int rowChosen = currentRow;

        int upwardDiff = -1;
        int downwardDiff = -1;

        // check UPWARD locations
        if (currentRow > 0)
        {
            upwardDiff = abs(map[currentRow - 1][c] - currentElev); // the difference between current location & upward location
            // DEBUG UPWARD:
            // std::cout << "Comparing upward: " << map[currentRow - 1][c] << " Difference: " << upwardDiff << std::endl;
            if (upwardDiff < minDiff)
            {
                minDiff = upwardDiff;
                rowChosen = currentRow - 1;
            }
        }

        // check DOWNWARD location
        if (currentRow < ROWS - 1)
        {
            downwardDiff = abs(map[currentRow + 1][c] - currentElev); // the difference between current location & downward location
            // DEBUG DOWNARD:
            // std::cout << "Comparing downward: " << map[currentRow + 1][c] << " Difference: " << downwardDiff << std::endl;
            if (downwardDiff < minDiff)
            {
                minDiff = downwardDiff;
                rowChosen = currentRow + 1;
            }
        }

        // In case of a tie of upward and downward, a coin toss will be conducted.
        if (upwardDiff >= 0 && downwardDiff >= 0)
        {
            if (upwardDiff == downwardDiff)
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
        }
        // LIMITATION: No code for if forward and up/down match, priority given to up/down direction

        // update current location and elevation
        currentRow = rowChosen;
        currentColumn = c;
        currentElev = map[currentRow][currentColumn];

        // display current location and elevation
        cout << "Column " << c << ":\n";
        cout << "Current location: (" << currentRow << ", " << currentColumn << ")" << endl;
        cout << "Current elevation: " << currentElev << endl;

        selected_coords.push_back({ currentRow, currentColumn });
    }
    return selected_coords;
}

int main()
{
    auto map = load_array_vec();
    std::vector<std::pair<int, int>> selected_cords = sen1A(map);

    std::cout << "\n Total Path cost: " << calculate_path_cost(map, selected_cords) << std::endl;
	
}
