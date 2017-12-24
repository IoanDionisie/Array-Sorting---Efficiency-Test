#ifndef SORTINGMETHODS_H_
#define SORTINGMETHODS_H_



void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void bubbleSort(int *array, int n) {
	int i, j, aux = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (array[i] < array[j]) {
				swap(array[i], array[j]);
			}
		}
	}
}

void insertionSort(int *array, int n) {
	int i, aux, j;

	for (i = 0; i < n; ++i) {
		j = i;
		while (j > 0 && array[j] < array[j - 1]) {
			aux = array[j];
			array[j] = array[j - 1];
			array[j - 1] = aux;
			--j;
		}
	}
}

// Selects the min from an array and puts it at the beggining of it
void selectMin(int *array, int index, int n) {
	int i, min = 100000, indexToSwap;
	int temp;

	for (i = index; i < n; ++i) {
		if (array[i] < min) {
			min = array[i];
			indexToSwap = i;
		} 
	}

	temp = array[index];
	array[index] = array[indexToSwap];
	array[indexToSwap] = temp;
} 

void selectionSort(int *array, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		selectMin(array, i, n);
	}
}

void mergeSort(int *array, int n, int r) {
	if (n < r) {
	 	int m = n + (r - n)/2;
 
        // Sort first and second halves
        mergeSort(array, n, m);
        mergeSort(array, m + 1, r);
 
        merge(array, n, m, r);
	}
}

void merge (int *arr, int l, int m, int r) {
 	int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
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


#endif
