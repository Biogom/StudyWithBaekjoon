#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int mazeMap[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];

int x_dir[4] = {1, 0, -1, 0};
int y_dir[4] = {0, 1, 0, -1};

void bfs(int startX, int startY, int sizeX, int sizeY)
{
    queue<pair<int, int>> q;

    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;
    dist[startX][startY]++;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        for(int i = 0; i < 4; i++)
        {
            int next_x = x + x_dir[i];
            int next_y = y + y_dir[i];

            if ((0 <= next_x && next_x < sizeX) && (0 <= next_y && next_y < sizeY) &&
                !visited[next_x][next_y] && mazeMap[next_x][next_y] == 1)
            {
                q.push(make_pair(next_x, next_y));
                visited[next_x][next_y] = 1;
                dist[next_x][next_y] = dist[x][y] + 1;
            }
        }

        q.pop();
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        string mazeData;
        cin >> mazeData;

        for(int j = 0; j < M; j++)
        {
            mazeMap[i][j] = mazeData[j] - '0';
        }
    }

    bfs(0, 0, N, M);

    cout << dist[N - 1][M - 1];

    return 0;
}