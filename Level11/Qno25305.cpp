#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int N, k;
    std::vector<int> vec;

    std::cin >> N >> k;

    for(int i = 0; i < N; i++)
    {
        int score;
        std::cin >> score;

        vec.push_back(score);
    }

    std::sort(vec.begin(), vec.end(), std::greater<int>());

    std::cout << vec.at(k - 1) << std::endl;

    return 0;
}