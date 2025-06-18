#include<stdio.h>
void bubbleSort(int arr[],int n){
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < n - i - 1;j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[],int n){
    for(int i = 0;i < n - 1;i++){
        int min = i;
        for(int j = i + 1;j < n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void insertionSort(int arr[],int n){
    for(int i = 1;i < n;i++){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n],arr2[n],arr3[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }
    bubbleSort(arr,n);
    selectionSort(arr2,n);
    insertionSort(arr3,n);
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
        printf("\n");
    }
    for(int i = 0;i < n;i++){
        printf("%d ",arr2[i]);
        printf("\n");
    }
    for(int i = 0;i < n;i++){
        printf("%d ",arr3[i]);
        printf("\n");
    }
}