#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

void Insertion_Sort(int * arr, int n){

    for(int j = 1; j < n; j++){
        int val = arr[j];
        int i = j - 1;
        while(i >= 0 && arr[i] > val){
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = val;
    }

}

int main(){
    srand(time(0));
    int n = (rand() % 50);
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = (rand() % 100);
    }
    system("clear");
    cout << endl;
    cout << "Insertion Sort" << " " << "(" << n << " Elements)" << endl;;
    cout << "===================" << endl;
    cout << endl;
    cout << "Before Sorting :" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    auto start = std::chrono::high_resolution_clock::now();
    Insertion_Sort(arr, n);
    auto stop = std::chrono::high_resolution_clock::now();
    double time2 = time(0);
    cout << "After Sorting :" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Time Taken : " << duration_cast<std::chrono::nanoseconds>(stop - start).count() << " nanoseconds" << endl;
}