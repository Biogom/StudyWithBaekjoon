#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec;
    int N;

    std::cin >> N;

    for(int i = 0; i < N; ++i)
    {
        int tmp;
        std::cin >> tmp;

        vec.push_back(tmp);
    }

    std::sort(vec.begin(), vec.end(), std::less<int>());

    for(auto n : vec)
    {
        std::cout << n << std::endl;
    }

    return 0;
}