#include <iostream>

int simpleSearch(int *array, int i, int length, int sum1, int sum2){
	if (i == length){
				return abs(sum1-sum2);
		}
	int minimum1 = simpleSearch(array,i+1,length,sum1+array[i],sum2);
	int minimum2 = simpleSearch(array,i+1,length,sum1,sum2+array[i]);
	return std::min(minimum1,minimum2);
}

int main(){
	int length;
	std::cout << "Input length:"; std::cin >> length;
	std::cout << "Input KASHA portions:\n";
	int array[length];
	for (int i = 0; i <= length-1; i++)
	{
		std::cin >> array[i];
	}
	int min_dif = simpleSearch(array,0,length,0,0);
	std::cout << min_dif;
	return 0;
}
