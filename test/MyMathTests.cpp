#include "gtest/gtest.h"

#include "../include/mymath.h"

#include <vector>

#define MyMathTests_MATRIX_WIDTH 4
#define MyMathTests_MATRIX_HEIGHT 3

struct StaticMatrix2D_Tests 
    : public ::testing::Test 
{
    size_t width = MyMathTests_MATRIX_WIDTH;
    size_t height = MyMathTests_MATRIX_HEIGHT;
    StaticMatrix2D<int, MyMathTests_MATRIX_WIDTH, MyMathTests_MATRIX_HEIGHT> matrix;
};

TEST_F(StaticMatrix2D_Tests, set) {
    EXPECT_NO_THROW(matrix.set(0,0,8));
    EXPECT_NO_THROW(matrix.set(width-1,0,8));
    EXPECT_NO_THROW(matrix.set(0,height-1,8));
    EXPECT_NO_THROW(matrix.set(width-1,height-1,8));
    
    EXPECT_THROW(matrix.set(width,0,8), int);
    EXPECT_THROW(matrix.set(0,height,8), int);
    
    matrix.set(2,2,3128);
    EXPECT_EQ(matrix.get(2,2), 3128);
}

TEST_F(StaticMatrix2D_Tests, get) {
    matrix.set(0,0,5);
    EXPECT_EQ(matrix.get(0,0), 5);

    matrix.set(width-1,0,19);
    EXPECT_EQ(matrix.get(width-1,0), 19);

    matrix.set(0,height-1,8);
    EXPECT_EQ(matrix.get(0,height-1), 8);

    matrix.set(width-1,height-1,47);
    EXPECT_EQ(matrix.get(width-1,height-1), 47);
    
    EXPECT_THROW(matrix.get(width,0), int);
    EXPECT_THROW(matrix.get(0,height), int);
    EXPECT_THROW(matrix.get(width,height), int);
}

TEST_F(StaticMatrix2D_Tests, matrix_vector_multiplication) {
    int n = 1;

    for (int row_i = 0; row_i < height; row_i++) {
        for (int col_i = 0; col_i < width; col_i++) {
            matrix.set(row_i,col_i, (n++) * 10);
        }
    }

    std::vector<int> vec (width); 
    int m = 1;

    for (int i = 0; i < width; i++) {
        vec[i] = m++;
    }

    std::vector<int> out = matrix * vec;

    EXPECT_EQ(out.size(), 2);
    EXPECT_EQ(out[0], 140);
    EXPECT_EQ(out[1], 320);
}
