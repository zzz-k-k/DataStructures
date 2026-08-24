#include"../listnode/listnode.hpp"
#include <stdexcept>

template<typename T>
class ListNodeQueue
{
private:
    ListNode<T>* queuetop;
    ListNode<T>* ptr;

public:
    ListNodeQueue(): queuetop(nullptr), ptr(nullptr)
    {
        
    }
    ~ListNodeQueue() 
    {
        while (queuetop != nullptr) 
        {
            pop();
        }
    }

    void push(T value)
    {
        ListNode<T>* newNode = new ListNode<T>(value);
        if(queuetop==nullptr)
        {
            queuetop=newNode;
            ptr=newNode;
            return;
        }
        ptr->next=newNode;
        ptr=newNode;

    }
    void pop()
    {
        if(queuetop==nullptr)
        {
            throw std::out_of_range("queue is empty");
        }
        ListNode<T>* oldTop = queuetop;
        queuetop=queuetop->next;
        delete oldTop;
        if(queuetop==nullptr)
        {
            ptr = nullptr;
        }
    }
    T peek()
    {
        if(queuetop==nullptr)
        {
            throw std::out_of_range("queue is empty");
        }
        return queuetop->val;
    }


};

