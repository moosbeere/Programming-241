#include <map>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>

int main()
{
    std::map<char, std::vector<char>> map = {
        {'i', {'h', 'g'}}, 
        {'h', {'g', 'f', 'i'}},
        {'f', {'g', 'h'}},
        {'g', {'j', 'h', 'f'}},
        {'e', {'g'}},
        {'s', {'a', 'e', 'd', 'b'}},
        {'b', {'d', 'c'}},
        {'c', {'j'}},
        {'j', {'g', 'i'}},
        {'d', {'b', 'g'}},
        {'a', {}},


    };
    std::deque<std::pair<char, std::string>> deq;
    char current = 's';
    std::set<char> checked;
    std::vector<std::string> result;
    std::string str = "";
    deq.push_back(std::make_pair('s', "s"));

    while (deq.size() > 0)
    {
        str = deq.front().second;
        current = deq.front().first;
        deq.pop_front();
        {   
            for (char room: map[current])
            {
                if (room == 'i')
                {
                    result.push_back(str+'i');
                    break;
                }
                else if (str.find(room) == str.npos) deq.push_back(std::make_pair(room, str+room));
            }
        }
    }
    auto min_way = std::min_element(result.begin(), result.end(), [](std::string a, std::string b){return a.length() < b.length();});
    result.erase(std::remove_if(result.begin(), result.end(), [min_way](std::string x){return x.length() != (*min_way).length();}), result.end());
    std::sort(result.begin(), result.end());
    for (auto r: result) std::cout << r << ' ';
    std::cout << std::endl;
    
    
    for (auto ch = result[0].begin(); ch != result[0].end(); ++ch) 
    {
        char ch2 = std::toupper(*ch);
       std::cout << ch2;
       if (ch != result[0].end() - 1) std::cout << '-';
    }
}   