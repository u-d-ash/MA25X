#include <iostream>

using namespace std;

class MaxHeap{

    //left : 2*i
    //right : 2*i + 1

    private:
        int heap_size;
        int elems;
        int * arr;

    public:
        MaxHeap(int n = 10){
            heap_size = n;
            arr = new int[n + 1];
            elems = 0;
        }

        void MaxHeapify(int i, int els = -1){
            //First we see whether the children are larger than the current index or not
            //Swap the current value with the largest one and call MaxHeapify on the child
            //CLRS : Page 155

            if(els == -1){
                els = elems;
            }

            int l_index = 2 * i;
            int r_index = 2 * i + 1;
            int largest_index = i;
            if(l_index <= els){
                if(arr[l_index] > arr[i]){
                    largest_index = l_index;
                }
            }
            if(r_index <= els){
                if(arr[r_index] > arr[largest_index]){
                    largest_index = r_index;
                }
            }
            if(largest_index == i){
                return;
            }
            int temp = arr[largest_index];
            arr[largest_index] = arr[i];
            arr[i] = temp;
            MaxHeapify(largest_index, els);

        }
        
        void print(){
            for(int i = 1; i <= elems; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void insert(int data){
            //Check whether the parent is smaller or what... If it is, keep on swaping the values until it's not
            if(elems == heap_size){
                cout << "Heap Full" << endl;
                return;
            }
            arr[elems + 1] = data;
            int index = elems + 1;
            while(index > 1){
                int p_index = index/2;
                if(arr[p_index] < arr[index]){
                    int tmp = arr[index];
                    arr[index] = arr[p_index];
                    arr[p_index] = tmp;
                    index = p_index;
                }else{
                    break;
                }
            }
            elems++;
        }

        void delete_root(){
            //To delete the root
            if(elems == 0){
                cerr << "No elems" << endl;
                return;
            }
            //Take the root to be the last elem in heap and then maxheapify
            arr[1] = arr[elems];

            elems--;
            MaxHeapify(1);
        }

        void heap_sort(){
            for(int i = 0; i < elems; i++){
                int last = arr[elems - i];
                int first = arr[1];
                arr[1] = last;
                arr[elems - i] = first;
                MaxHeapify(1, elems - i - 1);
            }
        }

        


};
//Support Function for Build Heap Function
void MaxHeapify(int * arr, int n, int i){
    int l_index = 2 * i;
    int r_index = 2 * i + 1;
    int largest_index = i;
    if(l_index <= n){
        if(arr[l_index] > arr[i]){
            largest_index = l_index;
        }
    }
    if(r_index <= n){
        if(arr[r_index] > arr[largest_index]){
            largest_index = r_index;
        }
    }
    if(largest_index == i){
        return;
    }
    int temp = arr[largest_index];
    arr[largest_index] = arr[i];
    arr[i] = temp;
    MaxHeapify(arr, n, largest_index);  
}

void BuildMaxHeap(int * arr, int n){
    for(int i = (n/2); i >= 1; i--){
        MaxHeapify(arr, n, i);
    }
}

int main(){

    //play around !!
    MaxHeap myheap = MaxHeap(67);

}