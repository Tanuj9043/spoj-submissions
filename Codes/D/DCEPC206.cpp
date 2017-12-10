#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef long long in;
void mergeSort(in *arr, int begin, int end);
void merge(in *arr, int begin, int mid, int end);
in ans;
in arr[200000];
int main(){
    int ct;
    int i, n;
    scanf("%d", &ct);
    while(ct--){
        ans = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        mergeSort(arr, 0, n - 1);
        printf("%lld\n", ans);
    }
    return 0;
}
void mergeSort(in *arr, int begin, int end){
    int mid = 0;
    if(begin < end){
        mid = (begin + end) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}
void merge(in *arr, int begin, int mid, int end){
    int len = end - begin + 1;
    int tmp[len];
    int i = begin;
    int j = mid + 1;
    int k = 0;
    while(i < mid + 1 && j < end + 1)
        if (arr[i] < arr[j]){
            ans += arr[i] * (end - j + 1);
            tmp[k++] = arr[i++];
        }
        else{
            tmp[k++] = arr[j++];
        }
    while(i < mid + 1)
        tmp[k++] = arr[i++];

    while(j < end + 1)
        tmp[k++] = arr[j++];

    k = 0;
    i = begin;
    while(k < len)
        arr[i++] = tmp[k++];
}
