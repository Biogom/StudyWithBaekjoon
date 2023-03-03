#include <iostream>

void merge(int *arr, int left, int mid, int right)
{
    int ptLeft, ptRight, ind;

    ptLeft = left;
    ptRight = mid + 1;
    ind = 0;

    int *tmparr = new int[right - left + 1]();

    while(ptLeft <= mid && ptRight <= right)
    {
        if(arr[ptLeft] <= arr[ptRight])
        {
            tmparr[ind++] = arr[ptLeft++];
        }
        else
        {
            tmparr[ind++] = arr[ptRight++];
        }
    }

    if (ptLeft > mid)
    {
        for(int i = ptRight; i <= right; i++)
        {
            tmparr[ind++] = arr[i];
        }
    }
    else
    {
        for(int i = ptLeft; i <= mid; i++)
        {
            tmparr[ind++] = arr[i];
        }
    }

    for(int j = 0; j <= right - left; j++)
    {
        arr[left + j] = tmparr[j];
    }
}

void mergeSort(int *arr, int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int N;

    std::cin >> N;

    int *arr = new int[N]();

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, N - 1);

    for(int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}