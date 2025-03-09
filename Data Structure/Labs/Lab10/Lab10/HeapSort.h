#ifndef HEAPSORT_H
#define HEAPSORT_H

class HeapSort 
{
private:
	int* arr;
	int size;
	int length;
public:
	HeapSort(int s);
	void addElement(int add);
	void MaxHeapSort();
	void MaxHeapify(int i);
	void showArr();
};
#endif
#pragma once
