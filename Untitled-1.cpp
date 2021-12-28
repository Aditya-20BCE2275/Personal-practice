#include <iostream>
#include <climits>


void MinMaxIterative(int arr[], int n){
    //std::cout << n << std::endl;
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i<n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    std::cout << "Max element using iterative function: " << max << std::endl;
    std::cout << "Min element using iterative function: " << min << std::endl;
}

void MinMaxDaC(int arr[], int l, int h, int &min, int &max){
    
    if (l == h){
        if (max < arr[l]) {
            max = arr[l];
        }
        if (min > arr[h]) {
            min = arr[h];
        }
        return;
    }
    
    if (h - l == 1){
        if (arr[l] < arr[h]){
            if (min > arr[l]){
                min = arr[l];
            }
            
            if (max < arr[h]) {
                max = arr[h];
            }
        }
        else {
            if (min > arr[h]) {
                min = arr[h];
            }
            
            if (max < arr[l]) {
                max = arr[l];
            }
        }
        return;
    }
    
    int mid = (l + h) / 2;
    MinMaxDaC(arr, l, mid, min, max);
    MinMaxDaC(arr, mid + 1, h, min, max);
}

int main() {
    int arr[] = {92,8,48,10,42,74,90,67,39,26};
    int n = sizeof(arr)/sizeof(arr[0]);
   // MinMaxIterative(arr,n);
    int max = INT_MIN, min = INT_MAX;
    MinMaxDaC(arr, 0, n - 1, min, max);
    
    std::cout << std::endl;
    std::cout << "The max array element using divide and conquer is " << max << std::endl;
    std::cout << "The min array element using divide and conquer is " << min<< std::endl;
    int prod =min*max;
    std::cout <<"the prod of min max is "<<prod;
    return 0;
}