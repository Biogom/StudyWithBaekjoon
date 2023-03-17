#include <iostream>

int main()
{
    int N;
    int maxNum = 10000;
    int *arr = new int[maxNum]{0, };

    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);

        arr[tmp - 1]++;
    }

    for(int i = 0; i < maxNum; i++)
    {
        for(int j = 0; j < arr[i]; j++)
        {
            printf("%d\n", i + 1);
        }
    }

    delete arr;

    return 0;
}