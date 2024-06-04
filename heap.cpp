#include <iostream>
using namespace std;


typedef struct Heap
{
	int* elems = nullptr;
	unsigned int capacity = 0;
	unsigned int size = 0;
}Heap;

Heap* initHeap(unsigned int capacity)
{
	Heap* newHeap = new Heap;
	newHeap->elems = new int[capacity];
	newHeap->capacity = capacity;
	newHeap->size = 0;
	return newHeap;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


bool insertHeap(Heap* heap, int elem)
{
	if (heap->size==heap->capacity)
	{
		cout << "heap is full, insert fail" << endl;
		return false;
	}

	unsigned int index = heap->size;
	heap->elems[index] = elem;
	heap->size++;

	//ascending filtration
	unsigned int root = (index - 1) / 2;
	while (index != 0 && heap->elems[root] < heap->elems[index])
	{
		swap(heap->elems[root], heap->elems[index]);
		index = root;
		root = (index - 1) / 2;
	}
}

int extractHeap(Heap& h)
{
	if (h.size==0)
	{
		cout << "heap is empty, extract fail" << endl;
		return false;
	}

	int retuVal = h.elems[0];
	h.elems[0] = h.elems[h.size];
	h.size--;

	//decending filtration
	unsigned int index = 0;
	unsigned int branch = 1;
	while (index < h.size && h.elems[index] < h.elems[branch])
	{
		swap(h.elems[index], h.elems[branch]);
		index = branch;
		branch = 2 * index + 1;
	}

	return retuVal;
}

void printHeap(Heap* heap)
{
	for (unsigned int i = 0; i < heap->size; i++)
		cout << heap->elems[i] << ' ';
}

int main()
{
	Heap* h = initHeap(10);
	insertHeap(h, 0);
	insertHeap(h, 2);
	insertHeap(h, 1);
	insertHeap(h, 1);
	insertHeap(h, 1);
	insertHeap(h, 17);
	insertHeap(h, 100);

	printHeap(h);

	return 0;
}