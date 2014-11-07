#include "CppUTest/TestHarness.h"
#include "bubbleSort.h"
#include "student.h"
#include "math.h"
using namespace std;

TEST_GROUP(TestDojo) {
};

int getNum(int *nums, int col, int i, int j) {
	return *(nums + i * col + j);
}

int maxProductsWithNeighbors(int * nums, int nrOfRows, int nrOfColumn) {
	if (nrOfColumn == 4) {
		return getNum(nums, 4, 0, 0) * getNum(nums, 4, 0, 1)
				* getNum(nums, 4, 0, 2) * getNum(nums, 4, 0, 3);
	}

	int maxProduct = 0;
	int product1 = getNum(nums, 5, 0, 0) * getNum(nums, 5, 0, 1)
			* getNum(nums, 5, 0, 2) * getNum(nums, 5, 0, 3);
	int product2 = getNum(nums, 5, 0, 1) * getNum(nums, 5, 0, 2)
			* getNum(nums, 5, 0, 3) * getNum(nums, 5, 0, 4);
	return max(product1, product2);
}

TEST(TestDojo, testOnly4NumbersInARow1) {
int num[1][4] = { { 1, 2, 3, 4 } };
int result = maxProductsWithNeighbors((int*) num, 1, 4);
CHECK_EQUAL(24, result);
}

TEST(TestDojo, testOnly5NumbersInARow) {
int num[1][5] = { { 1, 2, 3, 5, 6 } };
int result = maxProductsWithNeighbors((int*) num, 1, 5);
CHECK_EQUAL(180, result);
}
