#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int tomatoStorage[MAX][MAX][MAX];
int growInfect[MAX][MAX][MAX];
int M, N, H;

int growTomato()
{
    
}

int main()
{
    cin >> M >> N >> H;

    for(int k = 0; k < H; k++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int i = 0; i < M; i++)
            {
                cin >> tomatoStorage[i][j][k];
            }
        }
    }

    cout << growTomato();

    return 0;
}