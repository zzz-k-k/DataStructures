#include"../listnode/listnode.hpp"
#include <stdexcept>

template<typename T>
class linkedListStack
{
private:
    ListNode<T> *stackTop;

public:
    linkedListStack()
    {
        stackTop=nullptr;
    }
    ~linkedListStack() {
        while (stackTop != nullptr) {
            pop();
        }
    }
    void push(T value)
    {
        ListNode<T> *stackSecond = new ListNode<T>(value);
        stackSecond->next=stackTop;
        stackTop=stackSecond;
    }
    void pop()
    {
        if(stackTop==nullptr)
        {
            throw std::out_of_range("stack is empty");
        }
        ListNode<T>* oldTop = stackTop;
        stackTop=stackTop->next;
        delete oldTop;
    }
    T peek()
    {
        if(stackTop==nullptr)
        {
            throw std::out_of_range("stack is empty");
        }
        return stackTop->val;
    }

};