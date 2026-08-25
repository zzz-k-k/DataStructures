#include <iostream>
#include <ostream>
#include <string>
#include<unordered_map>
std::unordered_map<int,std::string> map;

int main()
{
    map[12345]="hh";

    std::string name=map[12345];

    //遍历哈希表
    for(auto kv:map)
    {
        std::cout<<kv.first<<"->"<<kv.second<<std::endl;

    }
    for(auto iter=map.begin();iter!=map.end();iter++)
    {
        std::cout<<iter->first<<"->"<<iter->second<<std::endl;
    }

    map.erase(12345);

    return 0;
}
