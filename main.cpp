#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <sstream>

#include "radixSort.h"
#include "quickSort.h"

using namespace md_islam;
using namespace std;

int main(){
	const static int size = 144;
	int unsortedArray[size];
	int unsortedArray2[size];
	int unsortedArrayCounter = 0;
	std::ifstream file("dataset.txt");
	std::string str = "";

	while (std::getline(file, str)){
		unsortedArray[unsortedArrayCounter] = std::stoi(str);
		unsortedArray2[unsortedArrayCounter] = std::stoi(str);
		unsortedArrayCounter++;
	}
	auto t1 = std::chrono::high_resolution_clock::now();
	//radixSort radix(unsortedArray, size);
	quickSort<int> quickS(unsortedArray2, 0, 143);
	auto t2 = std::chrono::high_resolution_clock::now();
	//radix.print();
	cout << "----------------------------......----------------------------" << endl;
	quickS.print();
	cout << "Timings: (ns):" << endl;
	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;
	
}