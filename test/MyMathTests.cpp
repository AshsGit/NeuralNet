#include "gtest/gtest.h"

#include "../include/mymath.h"

#include <vector>

#define MyMathTests_MATRIX_WIDTH 4
#define MyMathTests_MATRIX_HEIGHT 3

struct StaticMatrix2D_get_set_tests 
    : public ::testing::Test 
{
    size_t width = MyMathTests_MATRIX_WIDTH;
    size_t height = MyMathTests_MATRIX_HEIGHT;
    StaticMatrix2D<int, MyMathTests_MATRIX_WIDTH, MyMathTests_MATRIX_HEIGHT> matrix;
};

TEST_F(StaticMatrix2D_get_set_tests, set_bounds) {
    ASSERT_NO_FATAL_FAILURE(matrix.set(0,0,8));
    ASSERT_NO_FATAL_FAILURE(matrix.set(height-1,0,8));
    ASSERT_NO_FATAL_FAILURE(matrix.set(0,width-1,8));
    ASSERT_NO_FATAL_FAILURE(matrix.set(height-1,width-1,8));
}

TEST_F(StaticMatrix2D_get_set_tests, get_bounds) {
    ASSERT_NO_FATAL_FAILURE(matrix.get(0,0));
    ASSERT_NO_FATAL_FAILURE(matrix.get(height-1,0));
    ASSERT_NO_FATAL_FAILURE(matrix.get(0,width-1));
    ASSERT_NO_FATAL_FAILURE(matrix.get(height-1,width-1));
}

TEST_F(StaticMatrix2D_get_set_tests, set_invalid_bounds) {
    ASSERT_DEATH_IF_SUPPORTED(matrix.set(height,0,8), "");
    ASSERT_DEATH_IF_SUPPORTED(matrix.set(0,width,8), "");
}

TEST_F(StaticMatrix2D_get_set_tests, get_invalid_bounds) {
    ASSERT_DEATH_IF_SUPPORTED(matrix.get(height,0), "");
    ASSERT_DEATH_IF_SUPPORTED(matrix.get(0,width), "");
    ASSERT_DEATH_IF_SUPPORTED(matrix.get(height,width), "");
}

TEST_F(StaticMatrix2D_get_set_tests, set_then_get) {
    matrix.set(0,0,5);
    EXPECT_EQ(matrix.get(0,0), 5);

    matrix.set(height-1,0,19);
    EXPECT_EQ(matrix.get(height-1,0), 19);

    matrix.set(0,width-1,8);
    EXPECT_EQ(matrix.get(0,width-1), 8);

    matrix.set(height-1,width-1,47);
    EXPECT_EQ(matrix.get(height-1,width-1), 47);

    matrix.set(2,2,3128);
    EXPECT_EQ(matrix.get(2,2), 3128);
}

TEST(StaticMatrix2D_mat_vec_mul_Tests, matrix_vector_multiplication) {
    const size_t width = 3, height = 2;
    StaticMatrix2D<int, width, height> matrix;
    
    int n = 1;

    for (int row_i = 0; row_i < height; row_i++) {
        for (int col_i = 0; col_i < width; col_i++) {
            matrix.set(row_i,col_i, (n++) * 10);
        }
    }
    std::vector<int> vec = {1, 2, 3}; 

    std::vector<int> out = matrix * vec;

    EXPECT_EQ(out.size(), 2); 
    EXPECT_EQ(out[0], 140); 
    EXPECT_EQ(out[1], 320); 
}

//TODO Need more matrix_vector_multiplication tests. Especially for testing different (in)valid vector sizes. 
