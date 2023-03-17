#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;

bool* init(int N)
{
    return new bool[N + 1] {false, };
}

void DFS(bool* visited, int currentNode)
{
    visited[currentNode] = true;
    cout << currentNode << " ";

    for(int i = 0; i < graph[currentNode].size(); i++)
    {
        int chkNode = graph[currentNode][i];

        if (!visited[chkNode])
        {
            DFS(visited, chkNode);
        }
    }
}

void BFS(bool* visited, int start)
{
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int i = 0; i < graph[node].size(); i++)
        {
            int chkNode = graph[node][i];

            if (!visited[chkNode])
            {
                q.push(chkNode);
                visited[chkNode] = true;
            }
        }
    }
}

int main()
{
    int N, M, startVertex;

    cin >> N >> M >> startVertex;

    // 메모리 공간 할당 및 초기화
    graph.assign(N + 1, vector<int> (0, 0));
    bool* visited = init(N + 1);

    for(int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    // 낮은 노드번호 순으로 정렬
    for(int i = 0; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(visited, startVertex);
    cout << "\n";

    visited = init(N + 1);
    BFS(visited, startVertex);

    return 0;
}