#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::istringstream;
using std::string;
using std::unordered_map;
using std::unordered_set;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream iss(s);
        unordered_map<char, string> map{};
        string splited_word{};
        int i = 0;
        while (getline(iss, splited_word, ' '))
        {
            if (map.find(pattern[i]) == map.end())
                map.emplace(pattern[i], splited_word);
            else if (map[pattern[i]].compare(splited_word) != 0)
                return false;
            i++;
        }
        unordered_set<string> value_set{};
        for (const auto &[key, value] : map)
        {
            if (value_set.find(value) == value_set.end())
                value_set.insert(value);
            else
                return false;
        }
        if (i != pattern.size())
            return false;
        return true;
    }
};