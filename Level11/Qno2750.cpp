#include <iostream>
#include <string>

int main()
{
    std::string nickName;

    std::cout << "당신의 닉네임은? ";
    std::cin >> nickName;
    std::cout << "Welcome! " +  nickName << std::endl;

    return 0;
}