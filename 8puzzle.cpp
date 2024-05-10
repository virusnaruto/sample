#include <iostream>
#include <vector>
#include <queue>

/*
start state
2 8 3
1 6 4
7 0 5
end state
1 2 3
8 0 4
7 6 5
*/

using namespace std;

// Function to calculate heuristic value
int heu(vector<vector<int>> &state, const vector<vector<int>> &grid, int level)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (state[i][j] == 0)
                continue;
            if (state[i][j] != grid[i][j])
                count++;
        }
    }
    return count + level;
}

int main()
{
    // Input start and end states
    vector<vector<int>> start(3, vector<int>(3));
    vector<vector<int>> end(3, vector<int>(3));
    cout << "start state" << endl;
    for (auto &row : start)
    {
        for (auto &elem : row)
            cin >> elem;
    }
    cout << "end state" << endl;
    for (auto &row : end)
    {
        for (auto &elem : row)
            cin >> elem;
    }

    // Priority queue for A* algorithm
    priority_queue<pair<int, pair<int, vector<vector<int>>>>,
                   vector<pair<int, pair<int, vector<vector<int>>>>>,
                   greater<pair<int, pair<int, vector<vector<int>>>>>>
        pq;

    // Push initial state into priority queue

    // hueristic ,g(n),grid

    pq.push({heu(start, end, 0), {0, start}});

    while (!pq.empty())
    {
        int val = pq.top().first;
        int level = pq.top().second.first;
        vector<vector<int>> state = pq.top().second.second;
        pq.pop();

        // Print state and evaluation function
        cout << "=============== Selected State ==============\n";
        cout << "Evaluation function: " << val << endl;
        cout << "Heuristic value: " << val - level << endl;
        cout << "Level: " << level << endl;
        for (auto &row : state)
        {
            for (auto &elem : row)
                cout << elem << " ";
            cout << endl;
        }

        if (state == end)
        {
            cout << "Final state reached" << endl;
            break;
        }

        // Generate possible moves
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        int cnt = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (state[i][j] == 0)
                {
                    for (int a = 0; a < 4; a++)
                    {
                        int ni = i + delrow[a];
                        int nj = j + delcol[a];

                        if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
                        {
                            vector<vector<int>> temp = state;
                            swap(temp[i][j], temp[ni][nj]);
                            cout << "Possible move :" << cnt << endl;
                            for (auto it : temp)
                            {
                                for (auto i : it)
                                {
                                    cout << i << " ";
                                }
                                cout << endl;
                            }
                            int t = heu(temp, end, level + 1);
                            cout << "Evaluation function value :" << t << endl;
                            cout << "Heuristic value: " << t - level << endl;
                            cout << "Level: " << level + 1 << endl;
                            cnt++;

                            pq.push({heu(temp, end, level + 1), {level + 1, temp}});
                        }
                    }
                }
            }
        }
    }
    return 0;
}
