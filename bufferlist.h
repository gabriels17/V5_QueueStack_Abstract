#ifndef BUFFERLIST_H
#define BUFFERLIST_H

#include "stack.h"
#include "queue.h"

///You MUST use this value of initial capacity when you return you final version
///but feel free to change it while testing (to first test regular functionality)
#define INITIAL_CAPACITY 4

template <class T>
class BufferList : public Queue<T>, public Stack<T>
{
    public:
        BufferList() {
            cap = INITIAL_CAPACITY;
            buff_list = new T[cap];
            size = 0;
        }

        virtual ~BufferList() {
            delete[] buff_list;
        }

        ///print override:
        virtual void print(ostream &out) const {
            for(int i = 0; i < size; i++){
                cout << buff_list[i] << " ";
            }
        }

        ///Stack functions
        virtual void push(T value){
            if(size == cap){
                resize_array();
            }
            for(int i = size; i > 0; i--){
                buff_list[i] = buff_list[i - 1];
            }
            buff_list[0] = value;
            size++;
        }

        virtual T pop(){
            if(isEmpty()){
                throw EmptyException();
            }
            T value = buff_list[0];
            for(int i = 0; i < size - 1; i++){
                buff_list[i] = buff_list[i + 1];
            }
            size--;
            return value;
        }

        ///Queue functions
        virtual void add(T value){
            if(size == cap){
                resize_array();
            }
            buff_list[size] = value;
            size++;
        }

        virtual T remove(){
            if(isEmpty()){
                throw EmptyException();
            }
            T value = buff_list[0];
            for(int i = 0; i < size - 1; i++){
                buff_list[i] = buff_list[i + 1];
            }
            size--;
            return value;
        }

        ///Óþarfi??
        friend ostream& operator << (ostream& out, const BufferList<T> &lis) {
            lis.print(out);
            return out;
        }

    private:
        T* buff_list;
        int cap;
        int size;
        bool isEmpty(){
            if(size == 0){
                return true;
            }
            return false;
        }
        void resize_array(){
            cap *= 2;
            T* tmp_array = new T[cap];
            for(int i = 0; i < size; i++){
                tmp_array[i] = buff_list[i];
            }
            delete[] buff_list;
            buff_list = tmp_array;
        }
};

#endif // BUFFERLIST_H
