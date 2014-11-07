#include "bubbleSort.h"

void SWAP(Student students[], int i, int j) {
	Student tmp = students[i];
	students[i] = students[j];
	students[j] = tmp;
}

void sort(Student students[], int headCount){
	for (int j = headCount; j > 0; j--)
		for (int i = 0; i < j - 1; i++)
			if (students[i].score > students[i+1].score)
				SWAP(students, i, i+1);
}

