void merge(parkir &p, string arr[],int lower ,int mid,int upper){
    int n1 = mid - lower - 1;
    int n2 = upper - mid;
    string L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[lower + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = lower;
 
    while (i < n1 && j < n2) {
        if (compare(L[i],R[j])){
            arr[k] = L[i];
            p.namaKendaraan[k] = L[i];
            p.plat[k] = L[i];
            p.jam[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            p.namaKendaraan[k] = R[j];
            p.plat[k] = R[j];
            p.jam[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        p.namaKendaraan[k] = L[i];
        p.plat[k] = L[i];
        p.jam[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        p.namaKendaraan[k] = R[j];
        p.plat[k] = R[j];
        p.jam[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(parkir &p, string* arr, int lower, int upper)
{
    if(lower == upper) return;
    int mid = (lower+upper)/2;

    mergeSort(p,arr,lower,mid);
    mergeSort(p,arr,mid+1,upper);
    merge(p,arr,lower,mid,upper);
}
