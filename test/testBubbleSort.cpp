#include "CppUTest/TestHarness.h"
#include "bubbleSort.h"
#include "student.h"
#include "math.h"
using namespace std;

TEST_GROUP(TestDojo) {
};
struct Grid
{
	Grid(int ColumCount, int RowCount, const int *buf)
		: ColumCount(ColumCount)
		, RowCount(RowCount)
		, value(buf)
	{}
	int getNum(int row, int col)
	{
		return *(value + row * ColumCount + col);
	}

	int ProductOfRow(int rowStart, int colStartIndex)
	{
		int product = 1;
		for (int colIndex = colStartIndex; colIndex < colStartIndex + 4; colIndex++) {
			product *= getNum(rowStart, colIndex);
		}
		return product;
	}

	int maxProductsWithNeighbors()
	{
		int maxProduct = 0;

		for(int colIndex = 0; colIndex < ColumCount - 3; colIndex++)
		{
			int tempMaxProduct = ProductOfRow(0, colIndex);
			maxProduct = max(maxProduct, tempMaxProduct);
		}
		return maxProduct;

	}
private:
	int ColumCount;
	int RowCount;
	const int *value;
};


TEST(TestDojo, testOnly4NumbersInARow1) {
	int num[1][4] = { { 1, 2, 3, 4 } };
	Grid grid(4, 1, (int *)num);
	int result = grid.maxProductsWithNeighbors();
	CHECK_EQUAL(24, result);
}

TEST(TestDojo, testOnly5NumbersInARow) {
	int num[1][5] = { { 1, 2, 3, 5, 6 } };
	Grid grid(5, 1, (int *)num);
	int result = grid.maxProductsWithNeighbors();
	CHECK_EQUAL(180, result);
}

TEST(TestDojo, testOnly6NumbersInARow) {
	int num[1][6] = { { 1, 2, 3, 5, 6, 10 } };
	Grid grid(6, 1, (int *)num);
	int result = grid.maxProductsWithNeighbors();
	CHECK_EQUAL(900, result);
}

TEST(TestDojo, test2X4) {
	int num[2][4] = { { 1, 2, 3, 5 } ,{2,4,6,8}};
	Grid grid(4, 2, (int *)num);
	int result = grid.maxProductsWithNeighbors();
	CHECK_EQUAL(384, result);
}



