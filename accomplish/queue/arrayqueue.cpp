#include<vector>
#include <stdexcept>

template<typename T>
class ArrayQueue
{
private:
    std::vector<T> array;
    std::size_t frontIndex = 0;

public:
    void push(T value)
    {
        array.push_back(value);
    }
    void pop()
    {
        if (frontIndex >= array.size())
        {
            throw std::out_of_range("queue is empty");
        }
        frontIndex++;
        //array.erase(array.begin()); O(n)
    }
    T peek()
    {
        if(frontIndex >= array.size())
        {
            throw std::out_of_range("queue is empty");
        }
        return array[frontIndex];
    }
};