#include<vector>
#include <stdexcept>

template<typename T>
class ArraStack
{
private:
    std::vector<T> array;

public:
    void push(T value)
    {
        array.push_back(value);
    }
    void pop()
    {
        if (array.empty())
        {
            throw std::out_of_range("stack is empty");
        }
        array.pop_back();
        
    }
    T peek()
    {
        if(array.empty())
        {
            throw std::out_of_range("stack is empty");
        }
        return array.back();
    }
};