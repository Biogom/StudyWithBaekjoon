#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

int visited[MAX];

int bfs(vector<vector<int>> links, int virus)
{
    int infect = 0;
    queue<int> q;

    q.push(virus);
    visited[virus]++;

    while(!q.empty())
    {
        int com = q.front();

        for(int i = 0; i < links[com].size(); i++)
        {
            int next = links[com][i];

            if (!visited[next])
            {
                q.push(next);
                visited[next]++;
                infect++;
            }
        }

        q.pop();
    }

    return infect;
}

int main()
{
    int computers, link;
    vector<vector<int>> links;

    cin >> computers >> link;

    links.assign(computers + 1, vector<int> (0, 0));

    for(int i = 0; i < link; i++)
    {
        int start, end;

        cin >> start >> end;
        links[start].push_back(end);
        links[end].push_back(start);
    }

    cout << bfs(links, 1);
    return 0;
}