#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> m1(10);
  m1[0]=1;
  TMatrix<int> m2(m1);
  
  EXPECT_EQ(true,m1==m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> m1(12);
  TMatrix<int> m2(m1);
  m1[1][1]=10;

  EXPECT_EQ(false,m1==m2);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> m1(1000);

  EXPECT_EQ(1000,m1.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> m1(100);
  m1[5][5]=1234;

  EXPECT_EQ(1234,m1[5][5]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int> m1(100);

  ASSERT_ANY_THROW(m1[5][-5]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> m1(100);
  ASSERT_ANY_THROW(m1[MAX_MATRIX_SIZE+1][1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int> m1(7);
  m1[1][1]=10;

  ASSERT_NO_THROW(m1=m1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> m1(70);
  TMatrix<int> m2(70);
  m1[1][1]=10;

  ASSERT_NO_THROW(m2=m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> m1(5);
  TMatrix<int> m2(70);

  m1[1][1]=10;
  m2=m1;
  EXPECT_EQ(5,m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix<int> m1(1);
  TMatrix<int> m2(10000);
  
  m1=m2;
  EXPECT_EQ(m1,m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> m1(100);
  TMatrix<int> m2(100);

  m1[1][10]=100;
  m2[1][10]=100;
  m1[2][20]=123;
  m2[2][20]=123;

  EXPECT_EQ(true,m1==m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> m1(10);

  m1[1][1]=100;

  EXPECT_EQ(true, m1==m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> m1(100);
  TMatrix<int> m2(10);

  EXPECT_EQ(false,m1==m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix<int> m1(100),m2(100);
  TMatrix<int> m3(100);
  
  m1[1][10]=100;
  m1=m2+m1;
  m3[1][10]=100;

  EXPECT_EQ(true,m3==m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> m1(10),m2(1000);

  ASSERT_ANY_THROW(m1+m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix<int> m1(10),m2(10);
  ASSERT_NO_THROW(m1-m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> m1(10),m2(1000);
  
  ASSERT_ANY_THROW(m1-m2);
}

