#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "queue.h"
#include "stack.h"

template <class B>
class LinkedList : public Queue<B>, public Stack<B>
{
    public:
        LinkedList(){}
        virtual ~LinkedList(){}

        void print(ostream& out) const {}

        ///Stack functions
        void push(B value){}
        B pop(){}

        ///Queue functions
        void add(B value){}
        B remove(){}

        friend ostream& operator << (ostream& out, const LinkedList<B> &lis) {
            lis.print(out);
            return out;
        }

    protected:

    private:
        LinkedList* head;
        LinkedList* tail;
        int counter;
};

#endif // LINKEDLIST_H
