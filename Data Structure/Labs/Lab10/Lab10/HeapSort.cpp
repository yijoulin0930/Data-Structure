#include"HeapSort.h"
#include<iostream>

using namespace std;

HeapSort::HeapSort(int s)
{
	//TO_DO:Initialize

	length = 0;
	size = s;
	arr = new int[size];
}

void HeapSort::addElement(int add)
{
	//TO_DO:add element into arr and let the tree still satisfy the rules of Max Heap Tree after adding
	//		Cureent length++ after adding 

	length++;
	int i = length;
	arr[length] = add;

	if (length != 1)
	{
		MaxHeapify(i);
	}
}

void HeapSort::MaxHeapSort()
{
	//TO_DO: Swap the last and the first element.
	//       After swapping,let the tree still be Max Heap Tree

	if (length == 1)
		return;

	int temp = arr[1];
	arr[1] = arr[length];
	arr[length] = temp;

	length--;

	for (int i = length; i > 1; i--)
		MaxHeapify(i);

	MaxHeapSort();
}

void HeapSort::MaxHeapify(int i)
{
	//TO_DO: make every nodes in tree be Max Heap

	while (i >= 2)
	{
		int upper = i / 2;
		if (arr[upper] < arr[i]) {
			int temp = arr[upper];
			arr[upper] = arr[i];
			arr[i] = temp;
			i = upper;
		}
		else
			break;
	}
}

void HeapSort::showArr()
{
	//TO_DO:show the Arr after sorting

	for (int i = 1; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}