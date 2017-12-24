#ifndef TEST_H_
#define TEST_H_


void initialiseArray(int *array, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		array[i] = rand() % 100;
	}
}

void assignArray(int *array, int *oldArray, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		array[i] = oldArray[i];
	}
}

// Using bubble sort for testing the array sorting
void sort(int *array, int size) {
	int i, j, aux = 0;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size; ++j) {
			if (array[i] < array[j]) {
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
	}
}

// Check if the array is sorted
int checkResult(int *array, int *oldArray, int size) {
	int correct = 1, i;
	for (i = 0; i < size; ++i) {
		if (array[i] != oldArray[i]) {
			correct = 0;
		}
	}

	if (correct == 1) 
		return 1;
	return 0;
}

// Start measuring the time for the sorting algorithm
void startClock() {
	clock_t beginTimer = clock();
}

// End measuring the time for the sorting algorithm
void endClock(clock_t beginTimer) {
	clock_t endTimer = clock();
	double timeElapsed = (double)(endTimer - beginTimer) / CLOCKS_PER_SEC;
	printf("The time for running the algorithm is : %f\n", timeElapsed);
}

// Measures the raport of efficiency between two sorting algorithms
void efficiencyTime(double time1, double time2) {
	if (time1 > time2) {
		double result = time1 / time2 * 100;
		printf("The first sorting method is %f percent more efficient.\n", result);
	} else {
		double result = time2 / time1 * 100;
		printf("The first sorting method is %f percent less efficient.\n", result);
	}
}

void print(int *array, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

#endif
