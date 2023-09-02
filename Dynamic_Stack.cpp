#include <iostream>

using namespace std;

template <typename T> class stack_node{
    public:
        T data;
        stack_node<T> * bottom;
};

template <typename T> class dynamic_stack{

    private:
        int size;
        stack_node<T> * top;
    
    public:
        dynamic_stack(){
            size = 0;
        }
        void push(T in_data){
            if(size == 0){
                top = new stack_node<T>;
                top->data = in_data;
                top->bottom = nullptr;
                size++;
            }else{
                stack_node<T> * newnode = new stack_node<T>;
                newnode->data = in_data;
                newnode->bottom = top;
                top = newnode;
                size++;
            }
        }

        void pop(){
            if(size == 0){
                return;
            }else{
                stack_node<T> * top_pointer = top;
                top = top->bottom;
                delete top_pointer;
                size--;
            }
        }
        void print(){
            stack_node<T> * temp = top;
            while(temp != nullptr){
                cout << temp->data << endl;
                temp = temp->bottom;
            }
        }

};

int main(){
    dynamic_stack<int> ds;
    ds.push(2);
    ds.push(3);
    ds.push(4);
    ds.push(5);
    ds.pop();
    ds.push(6);
    ds.print();
}