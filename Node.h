#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node
{
    public:
        Node(T data) : data(data), next(NULL){};
        virtual ~Node(){};

        T data;
        Node<T>* next;
};


#endif // NODE_H
