#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    //Counting Sort for 0 to n;

    int n, m;
    //range and no of elems in your array
    cin >> n >> m;

    int freq_count[n + 1];
    memset(freq_count, 0, sizeof(freq_count));
    int arr[m];

    for(int i = 0; i < m; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++){
        freq_count[arr[i]]++;
    }
    for(int i = 0; i < n + 1; i++){
        cout << freq_count[i] << " ";
    }
    cout << endl;

    int cumm_freq_count[n + 1];
    int sum = 0;

    for(int i = 0; i < n + 1; i++){
        sum += freq_count[i];
        cumm_freq_count[i] = sum;
    }
    for(int i = 0; i < n + 1; i++){
        cout << cumm_freq_count[i] << " ";
    }
    cout << endl;

    int final_array[n + 1];
    for(int i = 0; i < n; i++){
        final_array[i + 1] = cumm_freq_count[i];
    }
    final_array[0] = 0;
    for(int i = 0; i < n + 1; i++){
        cout << final_array[i] << " ";
    }
    cout << endl;

    int sorted_array[m];

    //A stable sorting algorithm
    //Not comparison based

    for(int i = 0; i < m; i++){
        sorted_array[final_array[arr[i]]] = arr[i];
        final_array[arr[i]]++;
    }

    for(int i = 0; i < m; i++){
        cout << sorted_array[i] << " ";
    }
    cout << endl;










}