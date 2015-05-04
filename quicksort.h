#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>

namespace md_islam{
	template<class Item>
	class quickSort{
	public:
		//Pre: size must be > 0
		static const std::size_t SIZE = 144;
		//Pre: array must contain atleast one element
		//Post: the array is sorted from greatest to smallest
		quickSort(Item xarr[], std::size_t l, std::size_t r);
		//Post: array is sorted
		void dosort(std::size_t l, std::size_t r);
		//Post: array is printed
		void print();
	private:
		std::size_t size;
		Item arr[SIZE];
	};
}
#include "quicksort.template"
#endif