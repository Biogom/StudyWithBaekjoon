#include <iostream>
#include <algorithm>
#include <vector>

int getAverage(std::vector<int> vec)
{
    int average = 0;

    for(auto num: vec)
    {
        average += num;
    }

    return average / (int)vec.size();
}

int getMean(std::vector<int> vec)
{
    return vec.at((int)(vec.size() / 2));
}

int main()
{
    std::vector<int> vec;

    for(int i = 0; i < 5; i++)
    {
        int tmp;
        std::cin >> tmp;

        vec.push_back(tmp);
    }

    std::sort(vec.begin(), vec.end(), std::less<int>());

    std::cout << getAverage(vec) << std::endl;
    std::cout << getMean(vec) << std::endl;

    return 0;
}