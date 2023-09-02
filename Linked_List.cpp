#include <iostream>

using namespace std;

template <typename T> class node{

    public:
        T data;
        node<T> * next;


};

template <typename T> class linked_list{

    private:
        int size;
        node <T> * head;
        node <T> * current;
    
    public:
        linked_list(){
            size = 0;
        }

        void insert(T in_data){
            if(size == 0){
                head = new node<T>;
                head->data = in_data;
                head->next = nullptr;
                current = head;
                size++;
            }else{
                node<T> * newnode = new node<T>;
                newnode->data = in_data;
                newnode->next = current;
                current = newnode;
                size++;
            }
        }

        void print(){
            node<T> * temp = current;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

int main(){
    linked_list<int> ll;
    ll.insert(4);
    ll.insert(5);
    ll.insert(3);
    ll.print();
}