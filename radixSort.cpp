#include "radixSort.h"
#include <vector>
#include <iostream>

namespace md_islam{
	radixSort::radixSort(int unsortArray[], std::size_t size){
		this->size = size;
		this->largestDivisor = 1;
		this->unsortedArray_ptr = unsortArray;
		sort(unsortArray);
	}
	void radixSort::sort(int unsortedArr[]){
		std::size_t index = findLargestInt(unsortedArr); //get index of largest number in array
		int digit;
		int usedArraycounter = 0;
		findLargestDivisor(unsortedArr[index]); //get the divisor required to obtain the most significant place in the largest number

		for (int i = 1; i <= this->largestDivisor; i = (i * 10)){ //loop through for every place uptil the largest divisor
			for (std::size_t j = 0; j < this->size; j++){ //loop through every element in the array and place in vector depending on sig. digit.
				digit = (unsortedArr[j] / i) % 10; //check number's i-th place
				this->container[digit].push_back(unsortedArr[j]);
			}
			//put elements back in unsortedArray
			for (std::size_t v = 0; v < 10; v++){
				for (std::vector<int>::iterator it = this->container[v].begin(); it < this->container[v].end(); it++){
					unsortedArr[usedArraycounter] = *it;
					usedArraycounter++;
				}
			}
			usedArraycounter = 0; //reset counter for the unsorted array
			//erase vector elements
			for (std::size_t t = 0; t < 10; t++){
				this->container[t].clear();
			}

		}
	}
	void radixSort::findLargestDivisor(int number){ //recursively finds the largest divisor
		int result = (number / this->largestDivisor) % 10;
		if (result == 0){
			this->largestDivisor /= 10;
		}
		else{
			this->largestDivisor *= 10;
			findLargestDivisor(number);
		}
	}
	std::size_t radixSort::findLargestInt(int unsortedArr[]){ //find largest int in given array
		int temp = 0;
		std::size_t index = 0;
		for (std::size_t i = 0; i < size; i++){
			if (unsortedArr[i] > temp){
				temp = unsortedArr[i];
				index = i;
			}
		}
		return index;
	}

	void radixSort::print(){
		for (std::size_t i = 0; i < size; i++){
			std::cout << *(this->unsortedArray_ptr + i) << ", ";
		}
	}
}