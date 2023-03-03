#include <iostream>
#include <queue>

int main()
{
    int N, radix = 1;
    int maxValue = 0;
    std::queue<int> q[10];

    scanf("%d", &N);

    int *arr = new int[N];

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        maxValue = std::max(arr[i], maxValue);
    }

    while(maxValue != 0)
    {
         maxValue /= 10;
         radix *= 10;
    }

    for(int i = 1; i <= radix; i = i * 10)
    {
        for (int j = 0; j < N; j++)
        {
            int ind;

            if (arr[j] < i) {ind = 0;}
            else
            {
                ind = (arr[j] / i) % 10;
            }
            q[ind].push(arr[j]);
        }

        int idx = 0;
        for(int j = 0; j < 10; j++)
        {
            while (q[j].empty() == 0)
            {
                arr[idx] = q[j].front();
                q[j].pop();
                idx++;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}