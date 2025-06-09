class Solution {
    // Function to sort an array using quick sort algorithm.
    static void quickSort(int arr[], int low, int high) {
        if(low<high){
            int pivot = partition(arr,low,high);
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
        
    }

    static int partition(int arr[], int low, int high) {
        int mid = low;
        int left = low;
        int right = high;
        int pivot = arr[high];
        while(mid<=right){
            if(arr[mid]<pivot){
                swap(arr,mid,left);
                left++;
                mid++;
            }else if(arr[mid]==pivot){
                mid++;
            }else if(arr[mid]>pivot){
                swap(arr,mid,right);
                right--;
            }
        }
        return right;
    }
    static void swap(int[]arr,int left,int right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
}
