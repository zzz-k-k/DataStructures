//层序遍历
//首先传入一个根节点，其实就是根节点的地址，有一个队列，他会将根节点遍历出啦的左右两个传入队列
//假如队列中有值那么就会一直这个循环
//实际运行就是一个根节点，传入队列中，然后取出队列中的第一个，赋值到node上，然后队列出栈一个
//然后找到值，然后队这个节点的左右节点也添加到队列中
#include<queue>
#include<vector>
#include"binarytree.cpp"
template<typename T>
std::vector<T> loadorder(binarytree<T> &root)
{
    std::vector<T> out;
    std::queue<binarytree<T>*> queue;
    queue.push(&root);
    while(!queue.empty())
    {
        binarytree<T> *node=queue.front();
        queue.pop();
        out.push_back(node->value);
        if(node->left!=nullptr)
        {
            queue.push(node->left);
        }
        if(node->right!=nullptr)
        {
            queue.push(node->right);
        }

    }

    return out;
}