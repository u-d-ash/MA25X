#include <iostream>
#include <cmath>

using namespace std;

class dyna_stack{

    private:
        int stack_size;
        int current_size;
        int* stack;

    public:

        dyna_stack(){
            stack_size = 2;
            current_size = 0;
            stack = new int[stack_size];
            
        }

        void print_pvt(){
            cout << "Stack Size: " << stack_size << endl;
            cout << "Current Size: " << current_size << endl; 
        }

        void insert(int x){
            if(current_size == stack_size){
                stack_size *= 2;
                int * newall = new int[stack_size];
                for(int i = 0; i < current_size; i++){
                    newall[i] = stack[i];
                }
                newall[current_size] = x;
                current_size++;
                delete stack;
                stack = newall;
            }else{
                stack[current_size] = x;
                current_size++;
            }
            //print_pvt();
        }

        void pop(){
            if(current_size == 0){
                return;
            }

            current_size--;
            double d = log2((double)current_size);
            if(floor(d) == d){
                stack_size /= 2;
                int * newall = new int[stack_size];
                for(int i = 0; i < current_size; i++){
                    newall[i] = stack[i];
                }
                delete stack;
                stack = newall;
            }
            //print_pvt();

        }

        void print_stack(){
            for(int i = 0; i < current_size; i++){
                cout << stack[i] << " ";
            }
            cout << endl;
        }

        


};

int main(){

    dyna_stack ds = dyna_stack();

}