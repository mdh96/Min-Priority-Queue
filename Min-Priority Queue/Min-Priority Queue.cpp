// Min-Priority Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

class MinPriorityQueue
{
protected:
	int queue[1024];
	int queueSize;
	int largest;
	const int Large = 1000000;
public:
	MinPriorityQueue()
	{
		queueSize = 4;
		queue[1] = 1;
		queue[2] = 10;
		queue[3] = 100;
		queue[4] = 1000;
		largest = 1;
	}
	int parent(int i)
	{
		return i / 2;
	}
	int left(int i)
	{
		return 2*i;
	}
	int right(int i)
	{
		return 2*i + 1;
	}
	void MinHeapify(int i)
	{
		int l = left(i);
		int r = right(i);
		if (l <= queueSize && queue[l] < queue[i])
			largest = l;
		else
			largest = i;
		if (r <= queueSize && queue[r] < queue[largest])
			largest = r;
		if (largest != i)
		{
			//exchange A[i] with A[largest]
			int temp = queue[i];
			queue[i] = queue[largest];
			queue[largest] = temp;
			MinHeapify(largest);
		}
	}
	void printQueue()
	{
		cout << "printing queue" << endl;
		for (int i = 1; i <= queueSize; i++)
		{
			cout << queue[i] << endl;
		}
	}
	void printMin()
	{
		cout << "printing min" << endl;
		cout << queue[1] << endl;
	}
	//insert, minimum, extract-minimum, decreaseKey
	void MinHeapInsert(int key)
	{
		queueSize = queueSize + 1;
		queue[queueSize] = Large;
		HeapDecreaseKey(queueSize, key);
	}
	int HeapExtractMin()
	{
		if(queueSize > 1)
		{ 
			//heap overflow
			return -1;
		}
		int min = queue[1];
		queue[1] = queue[queueSize];
		queueSize = queueSize - 1;
		MinHeapify(1);
		return min;
	}
	void HeapDecreaseKey(int i, int key)
	{
		if (key < queue[i])
		{
			queue[i] = key;
			int blah = parent(i);
			blah = parent(2);
			blah = parent(3);
			blah = parent(4);
			while (i > 1 && queue[parent(i)] > queue[i])
			{
				//exchange A[i] with A[parent(i)]
				int temp = queue[i];
				queue[i] = queue[parent(i)];
				queue[parent(i)] = temp;
				i = parent(i);
			}
		}
		else
			cout << "new key is >= current key";
	}
	int minimum()
	{
		return queue[1];
	}
};
int main()
{
	MinPriorityQueue q;
	q.printQueue();
	q.printMin();
	//q.HeapExtractMin();
	//q.HeapDecreaseKey(3, 0);
	q.MinHeapInsert(12);
	q.MinHeapInsert(105);
	q.MinHeapInsert(0);
	q.printQueue();
	q.printMin();
	int asdf;
	cin >> asdf;
    return 0;
}

