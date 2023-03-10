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

void print_coords(const std::vector < std::pair<int, int>>& selected_coords)
{
	cout << "Coordinates: " << endl;
	for (int i = 0; i < selected_coords.size(); i++)
	{
		cout << " (" << selected_coords[i].first << "," << selected_coords[i].second << ")" << endl;
	}
}

int  sen1A(const std::vector<std::vector<int>>& map, int startRow, int startColumn)
{
    // Possible change: Check if matrix is square.

    const int ROWS = map.size();
    const int COLS = map[0].size();

    int totalCost = 0;

    int currentRow = startRow;
    int currentColumn = startColumn; // left most starting column
    int currentElev = map[currentRow][currentColumn]; // initial elevation

    // Print starting point (location --> (row, column)) and elevation

    cout << "Start location: (" << currentRow << ", " << currentColumn << ")" << endl;
    cout << "Start elevation: " << currentElev << endl;

    // loop through each column
    for (int c = 1; c < COLS; c++) // starting from the second column
    {
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

        // cout << "Subtracting: " << currentElev << " " << map[currentRow][currentColumn] << endl;
        totalCost += abs(currentElev - map[currentRow][currentColumn]);

        currentElev = map[currentRow][currentColumn];

        // display current location and elevation
        cout << "Column " << c << ":\n";
        cout << "Current location: (" << currentRow << ", " << currentColumn << ")" << endl;
        cout << "Current elevation: " << currentElev << endl << endl;
    }
    return totalCost;
}

int main()
{
    auto map = load_array_vec();
    int cost = sen1A(map, 2, 0);

    std::cout << "\n Total path cost: " << cost << std::endl;

}

// Code Explanation for sen1A()
/*
    We define a constant int of rows and columns of the array size.
    The starting coordinate is predetermined to be (2, 0). We set the currentElv to the start.

    The minimum absolute difference of forward, upward and downward is chosen.

    The loop begins from the 2nd column until the final column. 
    At each iteration of the loop, we first take the forward difference as min. The forward coordinate is always [i][j+1].
    
    Then we check if there is a row above Betty's current location. If there is, we check upward difference [i-1][j+1]
    We then compare it to the minimum difference which is the forward difference as of right now. If it's lower than forward, minimum difference is now the upward difference.
    
    Then we check if there is a row below Betty's current location. If there is, we check the downward difference [i+1][j+1].
    We then coompare it to the minimum difference, which is the upward difference as of right now. If it's lower than upward, minimum difference is now the downward difference.

    If both, upward and downward are equal, a coin toss is flipped. If its 0, the upward direction is chosen. If it's 1, the downward direction is chosen.
*/