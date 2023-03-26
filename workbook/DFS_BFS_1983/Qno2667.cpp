#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 25

using namespace std;

int apartMap[MAX][MAX];
int visited[MAX][MAX];
int x_dir[4] = {1, 0, -1, 0};
int y_dir[4] = {0, 1, 0, -1};

int getApart(int posX, int posY, int mapSize)
{
    int amount = 1;
    queue<pair<int, int>> q;

    visited[posX][posY]++;
    q.push(make_pair(posX, posY));

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        for(int i = 0; i < 4; i++)
        {
            int next_x = x + x_dir[i];
            int next_y = y + y_dir[i];

            if ((0 <= next_x && next_x < mapSize) && (0 <= next_y && next_y < mapSize) &&
                !visited[next_x][next_y] && apartMap[next_x][next_y] == 1)
            {
                q.push(make_pair(next_x, next_y));
                visited[next_x][next_y] = 1;
                amount++;
            }
        }

        q.pop();
    }

    return amount;
}

int main()
{
    int N, complexNum = 0;
    vector<int> complex;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string mapData;
        cin >> mapData;
        
        for (int j = 0; j < N; j++)
        {
            apartMap[i][j] = mapData[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (apartMap[i][j] == 1 && !visited[i][j])
            {
                complexNum++;
                complex.push_back(getApart(i, j, N));
            }
        }
    }

    sort(complex.begin(), complex.end());
    
    cout << complexNum << "\n";
    for(int i = 0; i < complex.size(); i++)
    {
        cout << complex[i] << "\n";
    }

    return 0;
}