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
	std::cout << "Input length:"; std::cin >> length;
	int array[length];
	std::cout << "Input KASHA portions:\n";
	for (int i = 0; i <= length-1; i++)
	{
		std::cin >> array[i];
	}
	quicksort(array, 0, length-1);
	int min_dif = array[1] - array[0];
	for (int i = 1; i <= length-1; i++){
		if (min_dif > array[i] - array[i-1]){
			min_dif = array[i] - array[i-1];
		}
	}
	std::cout << "Min difference between KASHA portions:" << min_dif;
	return 0;
}
