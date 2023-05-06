#include <string>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::unordered_map;
using std::unordered_set;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> word_map{};
        for (int i = 0; i < s.size(); i++)
        {
            if (word_map.find(s[i]) == word_map.end())
                word_map.emplace(s[i], t[i]);
            else if (word_map[s[i]] != t[i])
                return false;
        }
        unordered_set<char> set{};
        for (const auto &[key, value] : word_map)
        {
            if (set.find(value) == set.end())
                set.insert(value);
            else
                return false;
        }
        return true;
    }
};