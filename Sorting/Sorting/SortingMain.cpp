#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h>
#include <list>

using namespace std;

#define  MAX_NUM 100000  // Number of integers to be sorted

//Selection and insertion are the two sorting algortihms used in the main function
//Main function is located in Insertion Region

//Code for merge sort
#pragma region Merge
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
//void merge(vector<int>& arr, int l, int m, int r)
//{
//	int i, j, k;
//	int n1 = m - l + 1;
//	int n2 = r - m;
//
//	/* create temp arrays */
//	vector<int> L, R;
//
//	/* Copy data to temp arrays L[] and R[] */
//	for (i = 0; i < n1; i++)
//		L.push_back(arr[l + i]);
//	for (j = 0; j < n2; j++)
//		R.push_back(arr[m + 1 + j]);
//
//	/* Merge the temp arrays back into arr[l..r]*/
//	i = 0; // Initial index of first subarray 
//	j = 0; // Initial index of second subarray 
//	k = l; // Initial index of merged subarray 
//	while (i < n1 && j < n2) {
//		if (L[i] <= R[j]) {
//			arr[k] = L[i];
//			i++;
//		}
//		else {
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//
//	/* Copy the remaining elements of L[], if there
//	   are any */
//	while (i < n1) {
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	/* Copy the remaining elements of R[], if there
//	   are any */
//	while (j < n2) {
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//}
//
///* l is for left index and r is right index of the
//   sub-array of arr to be sorted */
//void mergeSort(vector<int>& arr, int l, int r)
//{
//	if (l < r) {
//		// Same as (l+r)/2, but avoids overflow for 
//		// large l and h 
//		int m = l + (r - l) / 2;
//
//		// Sort first and second halves 
//		mergeSort(arr, l, m);
//		mergeSort(arr, m + 1, r);
//
//		merge(arr, l, m, r);
//	}
//}
//
///* UTILITY FUNCTIONS */
///* Function to print an array */
//void printArray(vector<int>& A, int size)
//{
//	int i;
//	for (i = 0; i < size; i++)
//		printf("%d ", A[i]);
//	printf("\n");
//}

/* Driver program to test above functions */
//int main()
//{
//	vector<int> arr;
//	clock_t t;
//
//	// Put random #'s (0 -99) into list
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < MAX_NUM; ++i) {
//		arr.push_back(rand() % 100);
//	}
//	printf("Given array is \n");
//	printArray(arr, arr.size());
//
//	t = clock();
//	mergeSort(arr, 0, arr.size() - 1);
//	t = clock() - t;
//
//	printf("\nSorted array is \n");
//	printArray(arr, arr.size());
//
//	cout << "Merge Sort took " << t << " clicks (" << ((float)t) / CLOCKS_PER_SEC << " seconds)\n";
//
//	return 0;
//}
#pragma endregion Merge
//Code for selection sort
//Main function is in this code
#pragma region Selection
void selectionSort(vector<int>& intList) {
	int i, j, iMin;

	int n = intList.size();
	for (j = 0; j < n - 1; j++) {
		iMin = j;
		for (i = j + 1; i < n; i++) {
			if (intList[i] < intList[iMin])
				iMin = i;
		}
		if (iMin != j)
			swap(intList[j], intList[iMin]);
	}
}

void displayList(vector<int>& intList) {
	for (int a : intList) {
		cout << a << " ";
	}
	cout << endl;
}

//int main() 
//{
//	vector<int> myList;
//	clock_t t;
//
//	// Put random #'s (0 -99) into list
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < MAX_NUM; ++i) {
//		myList.push_back(rand() % 100);
//	}
//	displayList(myList);
//
//	// Sort and display result
//	cout << "Selction Sort:" << endl;
//	t = clock();
//	selectionSort(myList);
//	t = clock() - t;
//	displayList(myList);
//	cout << "Selection Sort took " << t << " clicks (" << ((float)t) / CLOCKS_PER_SEC << " seconds)\n";
//	return 0;
//}
#pragma endregion Selection
//Code for insertion sort
#pragma region Insertion
void insertionSort(vector<int>& intList) {
	int n = intList.size();
	for (int p = 1; p < n; ++p) {
		int tmp = intList[p];

		int j = 0;
		for (j = p; j > 0 && tmp < intList[j - 1]; --j)
			intList[j] = intList[j - 1];
		intList[j] = tmp;
	}
}

void displayArray(vector<int>& intList) {
	for (int a : intList) {
		cout << a << " ";
	}
	cout << endl;
}

int main()
{
	//vector for selection sort
	vector<int> myList;
	//used for time to determine performance of algorithm
	clock_t t;

	// Put random #'s (0 -99) into list
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX_NUM; ++i) {
		//Add random numbers to the vector
		myList.push_back(rand() % 100);
	}
	//Display vector
	displayList(myList);

	// Sort and display result
	cout << "Selction Sort:" << endl;
	//Start timer
	t = clock();
	//Sort vector
	selectionSort(myList);
	//End timer
	t = clock() - t;
	//Display sorted list
	displayList(myList);
	//Display how long algorithm took to run
	cout << "Selection Sort took " << t << " clicks (" << ((float)t) / CLOCKS_PER_SEC << " seconds)\n";

	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;

	//Second sorting method

	//Vector for insertion algorithm
	vector<int> arr;

	//Put random #'s (0 -99) into list
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX_NUM; ++i) {
		//Add random numbers to vector
		arr.push_back(rand() % 100);
	}
	//Display vector
	displayList(arr);

	// Sort and display result
	cout << "Insertion Sort:" << endl;
	//Start timer
	t = clock();
	//Sort array
	insertionSort(arr);
	//Stop timer
	t = clock() - t;
	//Display sorted vector
	displayList(arr);
	//Display how long algorithm took to run
	cout << "Insertion Sort took " << t << " clicks (" << ((float)t) / CLOCKS_PER_SEC << " seconds)\n";

	return 0;
}
//int main() {
//	vector<int> myList;
//
//	// Put random #'s (0 -99) into list
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < MAX_NUM; ++i) {
//		myList.push_back(rand() % 100);
//	}
//	displayList(myList);
//
//	// Sort and display result
//	cout << "Insertion Sort:" << endl;
//	insertionSort(myList);
//	displayList(myList);
//
//	return 0;
//}
#pragma endregion Insertion
//Code for bubble sort
#pragma region Bubble
//void bubbleSort(vector<int>& intList) {
//	int n = intList.size();
//	int i, j;
//	for (i = 0; i < n - 1; i++)
//		for (j = 0; j < n - i - 1; j++)
//			if (intList[j] > intList[j + 1])
//				swap(intList[j], intList[j + 1]);
//}
//
//void displayArray2(vector<int>& intList) {
//	for (int a : intList) {
//		cout << a << " ";
//	}
//	cout << endl;
//}

//int main() {
//	vector<int> myList;
//
//	// Put random #'s (0 -99) into list
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < MAX_NUM; ++i) {
//		myList.push_back(rand() % 100);
//	}
//	displayList(myList);
//
//	// Sort and display result
//	cout << "Bubble Sort:" << endl;
//	bubbleSort(myList);
//	displayList(myList);
//
//	return 0;
//}
#pragma endregion Bubble
//Code for quick sort
#pragma region Quick
// A utility function to swap two elements  
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray3(vector<int>& arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//// Driver Code 
//int main()
//{
//	vector<int> arr;
//	clock_t t;
//
//	// Put random #'s (0 -99) into list
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < MAX_NUM; ++i) {
//		arr.push_back(rand() % 100);
//	}
//	printf("Given array is \n");
//	// printArray(arr, arr.size());
//
//	t = clock();
//	quickSort(arr, 0, arr.size() - 1);
//	t = clock() - t;
//
//	cout << "Sorted array: \n";
//	// printArray(arr, arr.size());
//
//	cout << "Merge Sort took " << t << " clicks (" << ((float)t) / CLOCKS_PER_SEC << " seconds)\n";
//
//	return 0;
//}
#pragma endregion Quick
//Code for heap sort
#pragma region Heap
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void  heapify(vector<int>& arr, int n, int i)
{
	int  largest = i; // Initialize largest as root 
	int  l = 2 * i + 1; // left = 2*i + 1 
	int  r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

// main function to do heap sort 
void  heapSort(vector<int>& arr, int n)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */
void  printArray4(vector<int>& arr, int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// //Driver program 
//int main()
//{
//	vector<int> arr;
//	clock_t t;
//
//	// Put random #'s (0 -99) into list
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < MAX_NUM; ++i) {
//		arr.push_back(rand() % 100);
//	}
//	printf("Given array is \n");
//	printArray4(arr, arr.size());
//
//	t = clock();
//	heapSort(arr, arr.size());
//	t = clock() - t;
//
//	cout << "Sorted array is \n";
//	printArray4(arr, arr.size());
//
//	cout << "Heap Sort took " << t << " clicks (" << ((float)t) / CLOCKS_PER_SEC << " seconds)\n";
//
//	return 0;
//}
#pragma endregion Heap