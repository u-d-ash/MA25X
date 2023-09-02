#include <iostream>

using namespace std;

template <typename T> class kyu_node{

    public:
        T data;
        kyu_node<T> * next;

};

template <typename T> class kyu{

    private:
        int size;
        kyu_node<T> * start;
        kyu_node<T> * end;
    
    public:
        kyu(){
            size = 0;
        }

        void enkyu(T data){
            if(size == 0){
                start = new kyu_node<T>;
                start->data = data;
                start->next = nullptr;
                end = start;
                size++;
            }else{
                kyu_node<T> * newnode = new kyu_node<T>;
                newnode->data = data;
                newnode->next = end;
                end = newnode;
                size++;
            }

        }
        void dekyu(){
            if(size == 0){
                return;
            }else if(size == 1){
                delete start;
                delete end;
                size = 0;
            }else{
                kyu_node<T> * temp = end;
                while((temp->next)->next != nullptr){
                    temp = temp->next;
                }
                temp->next = nullptr;
                delete start;
                start = temp;
                size--;
            }

        }

        void print(){
            kyu_node<T> * temp = end;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            
        }

        

};

int main(){
    kyu<int> newkyu;
    newkyu.enkyu(1);
    newkyu.enkyu(2);
    newkyu.enkyu(3);
    newkyu.enkyu(4);
    newkyu.dekyu();
    newkyu.enkyu(5);
    newkyu.print();


}
