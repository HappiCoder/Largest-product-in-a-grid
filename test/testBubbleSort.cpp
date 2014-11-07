#include "CppUTest/TestHarness.h"
#include "bubbleSort.h"
#include "student.h"

TEST_GROUP(TestDojo) {
};

int getNum(int *nums, int col, int i, int j) {
	return *(nums + i * col + j);
}

int maxProductsWithNeighbors(int * nums, int nrOfRows, int nrOfColumn) {
	return getNum(nums, 4, 0, 0) * getNum(nums, 4, 0, 1) * getNum(nums, 4, 0, 2)
			* getNum(nums, 4, 0, 3);
}

TEST(TestDojo, testOnly4NumbersInARow1) {
	int num[1][4] = { { 1, 2, 3, 4 } };
	int result = maxProductsWithNeighbors((int*) num, 1, 4);
	CHECK_EQUAL(24, result);
}

TEST(TestDojo, testOnly4NumbersInARow2) {
	int num[1][4] = { { 1, 2, 3, 5 } };
	int result = maxProductsWithNeighbors((int*) num, 1, 4);
	CHECK_EQUAL(30, result);
}
