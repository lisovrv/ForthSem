#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <map>
#include <stdio.h>

struct Statistics
{
    int count;
    std::string word;
};

bool compare(const Statistics& lhs, const Statistics& rhs)
{
    return (lhs.count > rhs.count);
}


std::string prepare(const std::string& word)
{
    std::string result_word;
    std::transform(word.begin(), word.end(), back_inserter(result_word) , ::tolower);

    if(ispunct(*(--result_word.end())))
    {
        result_word.pop_back();
    }
    return result_word;
}


int main()
{
    std::ifstream file("martin_eden.txt");
    if(file.is_open())
    {
        std::string word;
        std::map<std::string, int> map_of_words;
        while(file >> word)
        {

            word = prepare(word);
            map_of_words[word]++;
        }
        std::vector<Statistics> statistics;
        statistics.resize(map_of_words.size());
        int i = 0;
        for(const auto &it: map_of_words)
        {
            statistics[i].count = it.second;
            statistics[i].word = it.first;
            i++;
        }

        std::sort(statistics.begin(), statistics.end(), compare);

        for(const auto &it: statistics)
        {

            std::cout << "Word: "       << it.word;
            std::cout << "  Quantity: " << it.count << "\n";
        }

        file.close();
    }
    return 0;
}



