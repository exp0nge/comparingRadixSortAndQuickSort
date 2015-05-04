#include <iostream>
#include <vector>

#ifndef RADIXSORT_H
#define RADIXSORT_H
namespace md_islam
{
	class radixSort
	{
	public:
		radixSort(int unsortArray[], std::size_t size);

		void sort(int unsortedArr[]);
		void findLargestDivisor(int number);
		std::size_t findLargestInt(int unsortedArr[]);
		void print();

	private:
		int largestDivisor;
		std::size_t size;
		std::vector<int> container[10];
		int * unsortedArray_ptr;
	};
}

#endif