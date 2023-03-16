#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <random>

using std::cout;
using std::endl;

std::vector<std::vector<int>> load_array_vec()
{

	std::ifstream file("map_844x480.dat");
	std::vector<std::vector<int>> arr(480, std::vector<int>(844)); // Row count, column count

	try
	{
		for (int r = 0; r < 480; r++)
		{
			for (int c = 0; c < 844; c++)
			{
                file >> arr[r][c];
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

void sen1A(const std::vector<std::vector<int>>& map, int startRow, int startColumn)
{
    clock_t start_time = clock();
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
        int forwardDiff = abs(map[currentRow][c] - currentElev); // the difference between current location & forward location
        int minDiff = forwardDiff;

        int rowChosen = currentRow;

        int upwardDiff = -1;
        int downwardDiff = -1;

        // check UPWARD locations
        if (currentRow > 0)
        {
            upwardDiff = abs(map[currentRow - 1][c] - currentElev); // the difference between current location & upward location
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
            if (downwardDiff < minDiff)
            {
                minDiff = downwardDiff;
                rowChosen = currentRow + 1;
            }
        }

        // In case of a tie of upward and downward, a coin toss will be conducted.
        if (upwardDiff == forwardDiff || downwardDiff == forwardDiff)
        {
            rowChosen = currentRow;
        }
        else if (upwardDiff == downwardDiff)
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

    clock_t end_time = clock();
    clock_t duration = end_time - start_time;

    std::cout << "Total cost of starting at (" << startRow << "," << startColumn << ") is: " << totalCost << std::endl;
    std::cout << "Total time for execution: " << duration << " (" << (float)duration / CLOCKS_PER_SEC << " seconds)";

    std::cout << std::endl;
    std::cout << std::endl;
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

// NEEDS FIXING
void sen1B(const std::vector<std::vector<int>>& map)
{
    clock_t start_time = clock();
    const int ROWS = map.size();
    const int COLS = map[0].size();

    int minCost = 0; 
    std::pair<std::pair<int, int>, int> var;

    // loop through the start of each row in the leftmost column
    for (int startingRow = 0; startingRow < ROWS; startingRow++)
    {
        int currentColumn = 0; // left most starting 
        int currentCost = 0;
        int currentElev = map[startingRow][currentColumn]; // initial elevation
        
        int currentRow = startingRow;
        int nextRow = currentRow;
        // loop through each of the columns
        for (int nextColumn = 1; nextColumn < COLS; nextColumn++) // starting from the second column
        {
            // check FORWARD location
            int forwardDiff = abs(map[currentRow][nextColumn] - currentElev); // the difference between current location & forward location
            int minDiff = forwardDiff;
            nextRow = currentRow;

            // Initalizing variables to -1 for comparison in ties. 
            // If variable is >= 0, then there is a row above and/or below the current location
            int upwardDiff = -1;
            int downwardDiff = -1;

            // check UPWARD locations
            if (currentRow > 0)
            {
                // the difference between current location & upward location
                upwardDiff = abs(map[currentRow - 1][nextColumn] - currentElev); 
                if (upwardDiff < minDiff)
                {
                    minDiff = upwardDiff;
                    nextRow = currentRow - 1;
                }
            }

            // check DOWNWARD location
            if (currentRow < ROWS - 1)
            {
                // the difference between current location & downward location
                downwardDiff = abs(map[currentRow + 1][nextColumn] - currentElev); 
                if (downwardDiff < minDiff)
                {
                    minDiff = downwardDiff;
                    nextRow = currentRow + 1;
                }
            }

            // In case of a tie, a coin toss will be conducted. Priority given to forward direction
            if (upwardDiff == forwardDiff || downwardDiff == forwardDiff)
            {
                nextRow = currentRow;
            }
            else if (upwardDiff == downwardDiff)
            {
                int coinToss = rand() % 2; // random select between 0 or 1
                if (coinToss == 0)
                {
                    nextRow = currentRow - 1;
                }
                else
                {
                    nextRow = currentRow + 1;
                }
            }

            // update total 
            currentCost += abs(currentElev - map[nextRow][nextColumn]);

            // update current location and elevation
            currentRow = nextRow;
            currentColumn = nextColumn;
            currentElev = map[currentRow][currentColumn];

            // display current location and elevation
            //cout << "Column " << currentColumn << ":\n";
            //cout << "Current location: (" << currentRow << ", " << currentColumn << ")" << endl;
            //cout << "Current elevation: " << currentElev << endl;
        }

        std::cout << "The cost for starting at: " << startingRow << " is: " << currentCost << std::endl;

        if ((startingRow == 1) || (startingRow != 1 && currentCost < minCost))
        {
            minCost = currentCost;
            var = { {currentRow, currentColumn}, minCost };
        }
    }
    clock_t end_time = clock();
    clock_t t = end_time - start_time;

    std::cout << "\nThe most efficient starting point is: (" << var.first.first << "," << 0 << "). The energy cost is: " << var.second;
    std::cout << "\nIt took clicks " << t << " (" << ((float)t) / CLOCKS_PER_SEC << " seconds)";
    std::cout << std::endl;
}

void sen2(const std::vector<std::vector<int>>& map)
{
    int col = 0;
    int nextCol = 1;
    std::vector<std::pair<std::pair<int, int>, int>> best_coords;
    int min_difference = INT_MAX;

    for (int r = 0; r < map.size(); r++)
    {
        // DEBUG
        //std::cout << "Starting point: " << map[r][col];
        //std::cout << " differences: ";
        for (int nextRow = 0; nextRow < map.size(); nextRow++)
        {
            int diff = abs(map[r][col] - map[nextRow][nextCol]);
            std::cout << diff << " ";

            // new min
            if (diff < min_difference)
            {
                min_difference = diff;
                best_coords.clear();
                best_coords.push_back({ {nextRow, nextCol}, diff });
            }
            // same diff
            else if (diff == min_difference)
            {
                best_coords.push_back({ {nextRow, nextCol}, diff });
            }

        }
        std::cout << std::endl;

        // get random index
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, best_coords.size());
        std::cout << distr(gen);
    }


}


int main()
{
    auto map = load_array_vec();
    bool run = true;
    //while (run)
    //{
    //    std::cout << "Choose which scenario to run : " << std::endl;
    //    std::cout << "1. Scenario 1-A";
    //    std::cout << "\n2. Scenario 1-B";
    //    std::cout << "\n3. Scenario 2";
    //    std::cout << "\n9. Exit";
    //    std::cout << "\nChoice: ";

    //    int choice;
    //    std::cin >> choice;

    //    if (choice == 1)
    //    {
    //        std::cout << "Choose your starting coordinate";
    //        std::cout << "\nX: ";
    //        int x = 0;
    //        std::cin >> x;
    //        std::cout << "\nY: ";
    //        int y = 0;
    //        std::cin >> y;
    //        sen1A(map, x, y);
    //    }
    //    else if (choice == 2)
    //    {
    //        sen1B(map);

    //    }
    //    else if (choice == 9)
    //    {
    //        run = false;
    //    }
    //}

    std::vector<std::vector<int>> arr =
    { {0, 30, 2, 3, 4},
      {5, 6, 7, 8, 9},
      {10, 11, 12, 13}
    };

    sen2(arr);
}

