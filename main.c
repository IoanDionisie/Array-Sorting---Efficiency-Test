#include <stdio.h> 
#include <math.h>
#include <stddef.h>
#include <stdint.h>     // provides int8_t, uint8_t, int16_t etc.
#include <stdlib.h>
#include <time.h>
#include "test.h"
#include "sortingMethods.h"


int main(int argc, char* argv[]) {

	int n;
	int sortingMethod = -1;
	int otherSortingMethod = -1;
	int compare;
	int numberOfSortingMethods = 5;

	printf("Choose the size of the array: \n");
	scanf("%d", &n);

	int *arrayToSort1 = malloc(n * sizeof(int));
	int *arrayToSort2 = malloc(n * sizeof(int));
	int *arrayToSort3 = malloc(n * sizeof(int));
	int *arrayToSort4 = malloc(n * sizeof(int));
	int *arrayToSort5 = malloc(n * sizeof(int));

	int *arraySorted = malloc(n * sizeof(int));

	printf ("Choose the sorting method: \n");
	printf("1. BubbleSort\n2. InsertionSort\n3. MergeSort\n4. SelectionSort\n5. QuickSort\n6. All the methods\n");
	
	scanf("%d", &sortingMethod);

	if (sortingMethod != 6) {
		printf("Do you want to compare two sorting methods?\n");
	 	printf("1. Yes\n2. No\n");
		scanf("%d", &compare);

		if (compare == 1) {
			printf("What sorting method do you want to compare with?\n");
			printf("1. BubbleSort\n2. InsertionSort\n3. MergeSort\n4. SelectionSort\n5. QuickSort\n");
			scanf("%d", &otherSortingMethod);

			if (sortingMethod == otherSortingMethod) {
				perror("This method has been already chosen. Exiting");
				return -1;
			}
		}

		// Randomise the seed:
		srand(time(NULL));

		// Initialize the array:
		initialiseArray(arrayToSort1, n);

		// Make a copy of the array and sort it for tests:
		assignArray(arraySorted, arrayToSort1, n);
		assignArray(arrayToSort2, arrayToSort1, n);
		sort(arraySorted, n);

		// Sort the array and measure the efficiency (Most important step)
		clock_t beginTimer = clock();

		switch(sortingMethod) {
			case 1:
				bubbleSort(arrayToSort1, n);
				break;
			case 2:
				insertionSort(arrayToSort1, n);
				break;
			case 3:
				mergeSort(arrayToSort1, 0, n - 1);
				break;
			case 4:
				selectionSort(arrayToSort1, n);
				break;
			case 5:
				quickSort(arrayToSort1, 0, n - 1);
				break;
			default:
				break;
		}


		clock_t endTimer = clock();
		double timeElapsed1 = (double)(endTimer - beginTimer) / CLOCKS_PER_SEC;
		printf("The time for running the algorithm is : %f\n", timeElapsed1);

		beginTimer = clock();
		if (compare == 1) {
			switch(otherSortingMethod) {
				case 1:
				bubbleSort(arrayToSort2, n);
				break;
			case 2:
				insertionSort(arrayToSort2, n);
				break;
			case 3:
				mergeSort(arrayToSort2, 0, n - 1);
				break;
			case 4:
				selectionSort(arrayToSort2, n);
				break;
			case 5:
				quickSort(arrayToSort2, 0, n - 1);
				break;
			default:
				break;
			}
		

			endTimer = clock();
			double timeElapsed2 = (double)(endTimer - beginTimer) / CLOCKS_PER_SEC;
			printf("The time for running the second sorting algorithm is : %f\n", timeElapsed2);
			
			// Measure the more efficient algorithm
			efficiencyTime(timeElapsed1, timeElapsed2);
			
		}

		// Compare the arrays to be sorted correctly :
		if (checkResult(arrayToSort1, arraySorted, n) == 1)
			printf("The array is sorted correctly\n");
		else  {
			printf("The array is not sorted ok.\n");
			print(arrayToSort1, n);
			printf("The array sorted correctly should be: \n");
			print(arraySorted, n);
		}
		
		if (compare == 1) {
			if (checkResult(arrayToSort2, arraySorted, n) == 1) 
				printf("The second array is sorted correctly\n");
			else  {
				printf("The second array is not sorted ok.\n");
				print(arrayToSort2, n);
				printf("The second array sorted correctly should be: \n");
				print(arraySorted, n);
			}
		}
	} else if (sortingMethod == 6) {

		double *times = malloc(numberOfSortingMethods * sizeof(double));
		int index = 0;
		// Randomise the seed:
		srand(time(NULL));
	
		// Initialize the array:
		initialiseArray(arrayToSort1, n);

		// Make a copy of the array and sort it for tests:
		assignArray(arraySorted, arrayToSort1, n);
		assignArray(arrayToSort2, arrayToSort1, n);
		assignArray(arrayToSort3, arrayToSort1, n);
		assignArray(arrayToSort4, arrayToSort1, n);
		assignArray(arrayToSort5, arrayToSort1, n);

		sort(arraySorted, n);

		// BUBBLE SORT
		clock_t beginTimer = clock();

		bubbleSort(arrayToSort1, n);

		clock_t endTimer = clock();
		double timeElapsed = (double)(endTimer - beginTimer) / CLOCKS_PER_SEC;
		printf("Time for bubble sort: %f\n", timeElapsed);

		if (checkResult(arrayToSort1, arraySorted, n) != 1) {
				printf("The array is not sorted ok.\n");
				times[index++] = 9999999;
/*				print(arrayToSort1, n);
				printf("The array sorted correctly should be: \n");
				print(arraySorted, n);*/
		} else {
			times[index++] = timeElapsed;
		}

		// INSERTION SORT
		beginTimer = clock();

		insertionSort(arrayToSort2, n);

		endTimer = clock();
		timeElapsed = (double)(endTimer - beginTimer) / CLOCKS_PER_SEC;
		printf("Time for insertion sort: %f\n", timeElapsed);

		if (checkResult(arrayToSort2, arraySorted, n) != 1) {
				printf("The array is not sorted ok.\n");
				times[index++] = 9999999;
/*				print(arrayToSort2, n);
				printf("The array sorted correctly should be: \n");
				print(arraySorted, n);*/
		} else {
			times[index++] = timeElapsed;
		}


		// MERGE SORT
		beginTimer = clock();

		mergeSort(arrayToSort3, 0, n - 1);

		endTimer = clock();
		timeElapsed = (double)(endTimer - beginTimer) / CLOCKS_PER_SEC;
		printf("Time for merge sort: %f\n", timeElapsed);

		if (checkResult(arrayToSort3, arraySorted, n) != 1) { 
				printf("The array is not sorted ok.\n");
				times[index++] = 9999999;
/*				print(arrayToSort3, n);
				printf("The array sorted correctly should be: \n");
				print(arraySorted, n);*/
		} else {
			times[index++] = timeElapsed;
		}

		// SELECTION SORT
		beginTimer = clock();

		selectionSort(arrayToSort4, n);

		endTimer = clock();
		timeElapsed = (double)(endTimer - beginTimer) / CLOCKS_PER_SEC;
		printf("Time for selection sort: %f\n", timeElapsed);


		if (checkResult(arrayToSort4, arraySorted, n) != 1) { 
				printf("The array is not sorted ok.\n");
				times[index++] = 9999999;
/*				print(arrayToSort4, n);
				printf("The array sorted correctly should be: \n");
				print(arraySorted, n);*/
		} else {
			times[index++] = timeElapsed;
		}

		// QUICK SORT
		beginTimer = clock();

		quickSort(arrayToSort5, 0, n - 1);

		endTimer = clock();
		timeElapsed = (double)(endTimer - beginTimer) / CLOCKS_PER_SEC;
		printf("Time for quick sort: %f\n", timeElapsed);


		if (checkResult(arrayToSort5, arraySorted, n) != 1) { 
				printf("The array is not sorted ok.\n");
				times[index++] = 9999999;
/*				print(arrayToSort5, n);
				printf("The array sorted correctly should be: \n");
				print(arraySorted, n);*/
		} else {
			times[index++] = timeElapsed;
		}

		double bestTime = 9999999;
		int winnerIndex = -1;
		int i;

		for (i = 0; i < numberOfSortingMethods; ++i) {
			if (times[i] < bestTime) {
				bestTime = times[i];
				winnerIndex = i;
			}
		}
		
		printf("The most efficient is ");
		switch(winnerIndex) {
			case 0:
				printf("bubble sort\n");
				break;
			case 1:
				printf("insertion sort\n");
				break;
			case 2:
				printf("merge sort\n");
				break;
			case 3:
				printf("selection sort\n");
				break;
			case 4:
				printf("quick sort");
				break;
			default:
				break;
		}

	} else {
		printf("You didn't select one of the options. Exiting...");
		return -1;
	}

	free(arrayToSort1);
	free(arraySorted);
	free(arrayToSort2);
	free(arrayToSort3);
	free(arrayToSort4);
	free(arrayToSort5);
}
