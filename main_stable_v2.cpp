#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int simpleSearch(int *array, int i, int length, int sum1, int sum2, auto &table){ // c++11 required!
	if (i == length){
				return abs(sum1-sum2);
		}
	std::string key = std::to_string(i) + "." + std::to_string(sum1);
	
	if (table.find(key) == table.end()){
		int minimum1 = simpleSearch(array,i+1,length,sum1+array[i],sum2,table);
		int minimum2 = simpleSearch(array,i+1,length,sum1,sum2+array[i],table);
		table[key] = std::min(minimum1,minimum2);
	}
    return table[key];
}

int main(){
	int length;
	std::cout << "Input length:"; std::cin >> length;
	std::cout << "\nInput KASHA portions:\n";
	int array[length];
	for (int i = 0; i <= length-1; i++)
	{
		std::cin >> array[i];
	}
	std::unordered_map<std::string,int> table;
	int min_dif = simpleSearch(array,0,length,0,0,table);
	std::cout << min_dif;
	return 0;
}
