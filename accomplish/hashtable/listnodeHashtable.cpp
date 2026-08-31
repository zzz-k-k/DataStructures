#include <cstddef>
#include <vector>
#include <functional>
#include"../listnode/listnode.hpp"

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
    std::vector<ListNode<pair<T, S>>*> hashtable;
    
public:
    ArrayHashtable() : hashtable(100,nullptr)
    {
    }
    ~ArrayHashtable()
    {
        for (auto& head : hashtable)
        {
            while (head != nullptr)
            {
                // 删除前必须先保存下一个节点
                ListNode<pair<T, S>>* next = head->next;

                delete head;

                head = next;
            }
        }
    }

    // 禁止复制构造
    ArrayHashtable(const ArrayHashtable&) = delete;

    // 禁止复制赋值
    ArrayHashtable& operator=(const ArrayHashtable&) = delete;

    S& operator[](const T& key)
    {
        size_t index = std::hash<T>{}(key) % hashtable.size();
        auto& slot= hashtable[index];
        if(!slot)
        {
            hashtable[index] =
                new ListNode<pair<T, S>>(pair<T, S>{key, S{}});

            return hashtable[index]->val.values;
        }
        
        ListNode<pair<T, S>>* current = slot;
        while (true)
        {
            if (current->val.keys == key)
            {
                return current->val.values;
            }

            if (current->next == nullptr)
            {
                // current就是最后一个节点
                break;
            }

            current = current->next;
        }

        current->next =
            new ListNode<pair<T, S>>(pair<T, S>{key, S{}});

        return current->next->val.values;
        
        
    }

    void erase(const T& key)
    {
        size_t index = std::hash<T>{}(key) % hashtable.size();
        auto& slot = hashtable[index];
        if(slot==nullptr)
        {
            return;
        }
        ListNode<pair<T, S>>* current = slot;

        ListNode<pair<T, S>>* previous = nullptr;
        while(current!=nullptr)
        {
            if (current->val.keys == key)
            {
                if(previous==nullptr)
                {
                    slot=current->next;
                }
                else 
                {
                    previous->next=current->next;
                }
                delete current;
                return;
            }

            previous=current;
            current = current->next;
        }
    }
};