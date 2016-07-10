

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

void merge(int a[],int low, int high, int mid, int size);
void mergesort(int a[], int low, int high, int size);
void insertion_sort(int *arr, int length);
void quickSort(int arr[], int left, int right);
void quick_sort_3_med(int a[],int start,int end);
int part_3_med(int a[],int c, int d);
void bucketSort(int array[],int n);
void ourSort(int *arr, int size, string answer);
void test();
void callTheSorts(int*b, int size, string answer);


/*
Resources Used:
    1) Merge Sort: http://www.sanfoundry.com/cpp-program-implement-merge-sort/
    2) Insertion Sort: http://cforbeginners.com/insertionsort.html
    3) Quick Sort: http://stackoverflow.com/questions/5666717/median-3-quick-sort-implementation
    4) Bucket Sort: http://stackoverflow.com/questions/27876525/array-bucket-sort-in-c
*/

int main(){
    //designate size
    //designate rand range
    srand (time(NULL));
    test();
//     int *b = NULL;
//     int size=100;
//     b = new int[size];
//     for(int k =0; k<size; k++){
//         int r = rand()%200+1;
//         b[k]=r;
//     }
//     int n = sizeof (b) / sizeof(b[0]);
//     // for(int i=0; i<size; i++){
//     //     cout << b[i] << endl;
//     // }
//   // insertion_sort(b, size);
//   // bucket_sort(b, size);
   
//     bucketSort(b, size);
//     //cout << "here" << endl;
//     for(int i=0; i<size; i++){
//         cout << b[i] << endl;
//     }
}


void ourSort(int *arr, int size, string answer){
	string method;
    int insertionPoints=0;
    int i=0;

    while(i < size-1){
            if(arr[i] < arr[i+1]){
                insertionPoints++;
            }
            else{
                insertionPoints--;
            }
            i++;
    }
     if(insertionPoints+1 == size){
            method = "done";
        }

    else if(answer== "yes" || answer== "Yes"){
        if(size < 200){
            method= "insertion sort";
        }
        else if(insertionPoints > (.65*size)){
            method= "insertion sort";
        }
        else if(size > 100000){
            method = "bucket sort";
        }
        else{
            method = "merge sort";
        }
    }
    else {
         if(size < 200){
            method= "insertion sort";
        }
        else if(insertionPoints > (.65*size)){
            method= "insertion sort";
        }
        else{
            method = "quick sort";
        }
    }

    if(method=="insertion sort"){
        insertion_sort(&arr[0], size);
    }
    else if(method == "quick sort"){
      quick_sort_3_med(arr,0, size);
    }
    else if(method == "merge sort"){
        mergesort(&arr[0], 0, size-1, size);
    }
    else if(method == "bucket sort"){
        int n = sizeof (arr) / sizeof(arr[0]);
      bucketSort(arr, size);
    }

    cout << method << ":     ";
}


void mergesort(int *a, int low, int high, int size){
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid, size);
        mergesort(a,mid+1,high, size);
        merge(a,low,high,mid, size);
    }
}

void merge(int *a, int low, int high, int mid, int size){
    int i, j, k, c[size];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }

}

void insertion_sort (int *arr, int length){
	 int j, temp;

	for (int i = 0; i < length; i++){
		j = i;

		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  }
		}
}

void quick_sort_3_med(int a[],int start,int end) {
    int b;
    //int count = 0;
    //count++;
    if (end-start<2) return;
    b=part_3_med(a,start,end);
    quick_sort_3_med(a,start,b);
    quick_sort_3_med(a,b,end);
}

int part_3_med(int a[],int c, int d) {
    int x=a[c];
    int y=a[(d-c)/2+c];
    int z=a[d-1];
    int i=c-1;
    int j=d;
    int count = 0;
    if (y>x && y<z || y>z && y<x ) x=y;
    else if (z>x && z<y || z>y && z<x ) x=z;
    while (1) {
        do  {j--;count++;} while (a[j] > x);
        do  {i++;count++;} while (a[i] < x);
        if  (i < j) swap(a[i],a[j]);
        else return j+1;
    }
}

struct bucket 
{
    int count;
    int* values;
};

int compareIntegers(const void* first, const void* second)
{
    int a = *((int*)first), b =  *((int*)second);
    if (a == b)
    {
        return 0;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void bucketSort(int array[],int n)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(sizeof(int) * n);
    }
    // Divide the unsorted elements among 3 buckets
    // < 0    : first
    // 0 - 10 : second
    // > 10   : third
    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            buckets[0].values[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10)
        {
            buckets[2].values[buckets[2].count++] = array[i];
        }
        else
        {
            buckets[1].values[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        // Use Quicksort to sort each bucket individually
        qsort(buckets[i].values, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].values[j];
        }
        k += buckets[i].count;
        free(buckets[i].values);
    }
}



void test(){
	int size;
	string answer;
	int *b = NULL;

	//Check for stable <65% sorted, size>100000  (should be bucket sort)
	cout<<"Unsorted array of size 100001 sorted using a stable sort: "<<endl;
	answer = "yes";
    size=100001;
    b = new int[size];
    for(int k =0; k<size; k++){
        int r = rand()%200+1;
        b[k]=r;
    }
    callTheSorts(b,size,answer);
	delete []b;

	//Check for unstable <65% sorted, size>100000  (should be quick sort)
	cout<<"Unsorted array of size 100001 sorted using an unstable sort: "<<endl;
	answer = "no";
    size=100001;
    b = new int[size];
    for(int k =0; k<size; k++){
        int r = rand()%200+1;
        b[k]=r;
    }
    callTheSorts(b,size,answer);
	delete []b;

	//Check for stable <65% sorted, size=1000  (should be merge sort)
	cout<<"Unsorted array of size 1000 sorted using a stable sort: "<<endl;
	answer = "yes";
    size=1000;
    b = new int[size];
    for(int k =0; k<size; k++){
        int r = rand()%200+1;
        b[k]=r;
    }
    callTheSorts(b,size,answer);
	delete []b;

	//Check for unstable <65% sorted, size=1000  (should be quick sort)
	cout<<"Unsorted array of size 1000 sorted using an unstable sort: "<<endl;
	answer = "no";
    size=1000;
    b = new int[size];
    for(int k =0; k<size; k++){
        int r = rand()%200+1;
        b[k]=r;
    }
    callTheSorts(b,size,answer);
	delete []b;

	//Check for stable >65% sorted, size>200  (should be insertion sort)
	cout<<"Sorted array of size 300 sorted using a stable sort: "<<endl;
	answer = "yes";
    size=300;
    b = new int[size];
    for(int k =0; k<size; k++){
        int r = k;
        b[k]=r;
    }
    b[140]=3;
    b[79]=60;
    b[7]=267;
    callTheSorts(b,size,answer);
	delete []b;

	//Check for unstable >65% sorted, size>200  (should be insertion sort)
	cout<<"Sorted array of size 300 sorted using an unstable sort: "<<endl;
	answer = "yes";
    size=300;
    b = new int[size];
    for(int k =0; k<size; k++){
        int r = k;
        b[k]=r;
    }
    b[140]=3;
    b[79]=60;
    b[7]=267;
    callTheSorts(b,size,answer);
	delete []b;

	//Check for stable size<200  (should be insertion sort)
	cout<<"Unsorted array of size 100 sorted using a stable sort: "<<endl;
	answer = "yes";
    size=100;
    b = new int[size];
    for(int k =0; k<size; k++){
        int r = rand()%200+1;
        b[k]=r;
    }
    callTheSorts(b,size,answer);
	delete []b;

	//Check for unstable size<200  (should be insertion sort)
	cout<<"Unsorted array of size 100 sorted using an unstable sort: "<<endl;
	answer = "no";
    size=100;
    b = new int[size];
    for(int k =0; k<size; k++){
        int r = rand()%200+1;
        b[k]=r;
    }
    callTheSorts(b,size,answer);
	delete []b;
}

void callTheSorts(int*b, int size, string answer){
	clock_t t1,t2;
	int *arr = new int[size];

	copy(b, b+size, arr);
	//insertion sort
	t1=clock();
	insertion_sort(&arr[0], size);
	t2=clock();
	float diff ((float)t2-(float)t1);
	cout<<"Insertion Sort:   ";
	cout<<diff<<endl;

	copy(b, b+size, arr);
	//quick sort
	t1=clock();
	quick_sort_3_med(arr,0, size);
	t2=clock();
	diff=((float)t2-(float)t1);
	cout<<"Quick Sort:   ";
	cout<<diff<<endl;

	copy(b, b+size, arr);
	//merge sort
	t1=clock();
	mergesort(&arr[0], 0, size-1, size);
	t2=clock();
	diff=((float)t2-(float)t1);
	cout<<"Merge Sort:   ";
	cout<<diff<<endl;

	copy(b, b+size, arr);
	//bucket sort
	t1=clock();
	int n = sizeof (arr) / sizeof(arr[0]);
	bucketSort (arr, size);
	t2=clock();
	diff=((float)t2-(float)t1);
	cout<<"Bucket Sort:   ";
	cout<<diff<<endl;


	copy(b, b+size, arr);
	//our sort algorithm
	cout<<"Our Sort:   ";
	t1=clock();
	ourSort(arr,size,answer);
	t2=clock();
	diff=((float)t2-(float)t1);
	cout<<diff<<endl;
	cout<<endl;
	delete []arr;
}