#include <iostream>
#include <vector>
#include <stack>
#define MAX 101

using namespace std;

int visited[MAX];

int getDegree(int personA, int personB, const vector<vector<int>>& link)
{
    stack<int> st;

    st.push(personA);
    visited[personA]++;

    while(!st.empty())
    {
        bool isConnected = false;
        int member = st.top();

        if (member == personB)
        {
            break;
        }

        for(int i = 0; i < link[member].size(); i++)
        {
            int nextMember = link[member][i];

            if (!visited[nextMember])
            {
                st.push(nextMember);
                visited[nextMember]++;
                isConnected = true;
                break;
            }
        }

        if (!isConnected)
        {
            st.pop();
        }
    }

    return st.size() - 1;
}

int main()
{
    int people, personA, personB;
    int relation = 0;
    vector<vector<int>> link;

    cin >> people >> personA >> personB >> relation;

    link.assign(people + 1, vector<int>(0, 0));

    for(int i = 0; i < relation; i++)
    {
        int child, parent;
        cin >> parent >> child;

        link[parent].push_back(child);
        link[child].push_back(parent);
    }

    cout << getDegree(personA, personB, link);

    return 0;
}