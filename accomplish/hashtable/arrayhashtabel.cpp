#include <cstddef>
#include <vector>
#include <functional>
#include <optional>

template<typename T, typename S>
struct pair
{
    T keys;
    S values;
    pair(T key,S val):keys(key),values(val){}
};
template<typename T, typename S>
class ArrayHashtable
{
    
private:
    std::vector<std::optional<pair<T, S>>> hashtable;
    
public:
    ArrayHashtable() : hashtable(100)
    {
    }
    int capacity=hashtable.size();
    S& operator[](const T& key)
    {
        size_t index = std::hash<T>{}(key) % capacity;
        auto& slot= hashtable[index];
        if(!slot)
        {
            slot.emplace(key,S{});
        }
        return slot->values;
    }

    void erase(T key)
    {
        size_t index = std::hash<T>{}(key) % capacity;
        auto& slot = hashtable[index];

        if (slot && slot->keys == key)
        {
            slot.reset();
        }
    }
};