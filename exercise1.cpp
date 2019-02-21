#include <iostream>
#include <algorithm>
#include <vector>


bool compare(const std::string& lhs, const std::string& rhs);

bool compare(const std::string& lhs, const std::string& rhs)
{
    return (lhs.length() > rhs.length()) ? false : (lhs <= rhs);
}

int main()
{
    std::vector<std::string> strings;
    unsigned long count = 0;
    std::cin >> count;
    strings.resize(count);

    for(int i = 0; i < count; i++)
    {
        std::cin >> strings[i];
    }
    std::sort(strings.begin(), strings.end(), compare);
    for(int i = 0; i < count; i++)
    {
        std::cout << strings[i] << " ";
    }
    return 0;
}