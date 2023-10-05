#include <iostream>

void swap(int *a, int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int array[], int start, int end){
	int pivot = array[end];
	int i = start - 1;
	for (int j = start; j <= end - 1; j++){
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i+1],&array[end]); // place pivot to its actual location
	return (i + 1); // return pivot index

}

void quicksort(int array[], int start, int end){
	if (start < end) {
		int pivot = partition(array,start,end);
		quicksort(array, start, pivot - 1); // left side of array
		quicksort(array, pivot + 1, end); // right side of array
	}
}

int main(){
	int length;
	// std::cout << "Input length:"; std::cin >> length;
	int array[32] = {509566391, 288831130, 705955723, 568149843, 715552798, 375579190, 153115961, 409783935, 11661308, 402389572, 518122104, 294256950, 690854883, 870104598, 494155609, 741518215, 928082887, 645809580, 244431276, 599352001, 1788721, 710088110, 670264952, 156017680, 472505234, 394766942, 174233214, 364728810, 972781081, 225755997, 63162138, 618705692};
	// std::cout << "Input KASHA portions:\n";
	//int array[6] = {5,2,2,4,8,9};
	length = 32;
	/*for (int i = 0; i <= length-1; i++)
	{
		std::cin >> array[i];
	} */
	quicksort(array, 0, length-1);
	long int accumulator = 0;
	long int summ = 0;
	long int previous = 0;
	for (int i = 0; i <= length -1; i++){
		summ += array[i];
	}
	long int min_dif = summ;
	int lsumm = summ / 2;
	for (int i = 0; i<= length - 1; i++){
		for (int j = i; j <= length - 1; i++){
			accumulator += array[j];
			if (accumulator > lsumm){
				previous = accumulator - array[j];
				accumulator = abs(summ - 2 * accumulator);
				previous = abs(summ - 2 * previous);
				min_dif = std::min(min_dif, std::min(previous,accumulator));
				break;
			}

		}
	}
	std::cout << "Min difference between KASHA portions:" << min_dif;
	return 0;
}
