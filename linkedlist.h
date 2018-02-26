#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "queue.h"
#include "stack.h"
#include "Node.h"

class EmptyException{};

template <class T>
class LinkedList : public Queue<T>, public Stack<T>
{
    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        virtual ~LinkedList(){
            Node<T>* tmp_node = head;
            while(head != NULL){
                head = head->next;
                delete tmp_node;
                tmp_node = head;
            }
        }

        ///print override:
        virtual void print(ostream& out) const{
            Node<T>* node = head;
            while(node != NULL){
                cout << node->data << " ";
                node = node->next;
            }
        }

        ///Stack functions
        virtual void push(T value){
            Node<T>* node = new Node<T>(value);
            node->next = head;
            head = node;
        }

        virtual T pop(){
            if(isEmpty()){
                throw EmptyException();
            }
            Node<T>* tmp_node = head;
            head = tmp_node->next;
            T value = tmp_node->data;
            delete tmp_node;
            return value;
        }

        ///Queue functions
        virtual void add(T value){
            Node<T>* node = new Node<T>(value);
            if(head == NULL){
                head = node;
            }
            else{
                tail->next = node;
            }
            tail = node;
        }

        virtual T remove(){
            if(isEmpty()){
                throw EmptyException();
            }
            Node<T>* tmp_node = head;
            head = head->next;
            T value = tmp_node->data;
            delete tmp_node;
            return value;
        }

        ///Óþarfi??
        friend ostream& operator << (ostream& out, const LinkedList<T> &lis) {
            lis.print(out);
            return out;
        }

    protected:

    private:
        Node<T>* head;
        Node<T>* tail;
        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            return false;
        }
};

#endif // LINKEDLIST_H
