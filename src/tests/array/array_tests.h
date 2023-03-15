#include <gtest/gtest.h>

#include <array>

#include "../../sequence_containers/array/custom_array.h"

template <class T, std::size_t N>
void CompareArrays(const custom::Array<T, N> &s21_arr,
                   const std::array<T, N> &std_arr) {
  ASSERT_EQ(s21_arr.size(), std_arr.size());
  auto s21_i = s21_arr.begin();
  auto std_i = std_arr.begin();
  while (s21_i != s21_arr.end() && std_i != std_arr.end()) {
    ASSERT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }
  ASSERT_EQ(s21_i, s21_arr.end());
  ASSERT_EQ(std_i, std_arr.end());
}

template <class T, std::size_t N>
void CompareArrays(const std::array<T, N> &std_arr,
                   const custom::Array<T, N> &s21_arr) {
  ASSERT_EQ(s21_arr.size(), std_arr.size());
  auto s21_i = s21_arr.begin();
  auto std_i = std_arr.begin();
  while (s21_i != s21_arr.end() && std_i != std_arr.end()) {
    ASSERT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }
  ASSERT_EQ(s21_i, s21_arr.end());
  ASSERT_EQ(std_i, std_arr.end());
}

template <class T, std::size_t N>
void CompareArrays(const custom::Array<T, N> &s21_arr1,
                   const custom::Array<T, N> &s21_arr2) {
  ASSERT_EQ(s21_arr1.size(), s21_arr2.size());
  auto s21_i1 = s21_arr1.begin();
  auto s21_i2 = s21_arr2.begin();
  while (s21_i1 != s21_arr1.end() && s21_i2 != s21_arr2.end()) {
    ASSERT_EQ(*s21_i1, *s21_i2);
    ++s21_i1;
    ++s21_i2;
  }
  ASSERT_EQ(s21_i1, s21_arr1.end());
  ASSERT_EQ(s21_i2, s21_arr2.end());
}

TEST(Array, default_constructor) {
  std::array<int, 0> std_arr1;
  custom::Array<int, 0> s21_arr1;
  ASSERT_EQ(s21_arr1.size(), std_arr1.size());

  std::array<int, 5> std_arr2;
  custom::Array<int, 5> s21_arr2;
  ASSERT_EQ(s21_arr2.size(), std_arr2.size());
}

TEST(Array, initializer_list_constructor) {
  std::array<int, 0> std_arr1{};
  custom::Array<int, 0> s21_arr1{};
  CompareArrays(s21_arr1, std_arr1);

  std::array<double, 5> std_arr2{1.1, 2.2, 3.3, 4.4, 5.5};
  custom::Array<double, 5> s21_arr2{1.1, 2.2, 3.3, 4.4, 5.5};
  CompareArrays(s21_arr2, std_arr2);

  std::array<char, 3> std_arr3{'a', 'b', 'c'};
  custom::Array<char, 3> s21_arr3{'a', 'b', 'c'};
  CompareArrays(s21_arr3, std_arr3);
}

TEST(Array, copy_constructor) {
  std::array<int, 3> std_arr1{1, 2, 3}, std_arr2(std_arr1);
  custom::Array<int, 3> s21_arr1{1, 2, 3}, s21_arr2(s21_arr1);
  CompareArrays(s21_arr1, s21_arr2);
  CompareArrays(s21_arr2, std_arr2);
}

TEST(Array, move_constructor) {
  std::array<int, 2> std_arr1{1, 2}, std_arr2(std::move(std_arr1));
  custom::Array<int, 2> s21_arr1{1, 2}, s21_arr2(std::move(s21_arr1));
  CompareArrays(s21_arr2, std_arr2);
}

TEST(Array, operator_equal_copy) {
  std::array<int, 2> std_arr1{1, 2}, std_arr2{3, 4};
  std_arr2 = std_arr1;
  custom::Array<int, 2> s21_arr1{1, 2}, s21_arr2{3, 4};
  s21_arr2 = s21_arr1;
  CompareArrays(s21_arr2, s21_arr1);
  CompareArrays(s21_arr2, std_arr2);
}

TEST(Array, operator_equal_move) {
  std::array<int, 2> std_arr1{1, 2}, std_arr2{3, 4};
  std_arr2 = std::move(std_arr1);
  custom::Array<int, 2> s21_arr1{1, 2}, s21_arr2{3, 4};
  s21_arr2 = std::move(s21_arr1);
  CompareArrays(s21_arr2, std_arr2);
}

TEST(Array, operator_equal_initializer_list) {
  std::array<int, 3> std_arr{1, 2, 3};
  std_arr = {4, 5, 6};
  custom::Array<int, 3> s21_arr{1, 2, 3};
  s21_arr = {4, 5, 6};
  CompareArrays(s21_arr, std_arr);
}

TEST(Array, at) {
  const std::array<int, 3> std_arr1{1, 2, 3};
  const custom::Array<int, 3> s21_arr1{1, 2, 3};
  for (std::size_t i = 0; i < s21_arr1.size(); ++i) {
    ASSERT_NO_THROW(s21_arr1.at(i));
    ASSERT_EQ(s21_arr1.at(i), std_arr1.at(i));
  }
  ASSERT_ANY_THROW(s21_arr1.at(3));

  std::array<double, 3> std_arr2{1.1, 2.2, 3.3};
  custom::Array<double, 3> s21_arr2{1.1, 2.2, 3.3};
  std_arr2.at(0) = 5.5;
  s21_arr2.at(0) = 5.5;
  CompareArrays(s21_arr2, std_arr2);
}

TEST(Array, operator_square_brackets) {
  const std::array<int, 3> std_arr1{1, 2, 3};
  const custom::Array<int, 3> s21_arr1{1, 2, 3};
  for (std::size_t i = 0; i < s21_arr1.size(); ++i) {
    ASSERT_NO_THROW(s21_arr1[i]);
    ASSERT_EQ(s21_arr1[i], std_arr1[i]);
  }
  ASSERT_NO_THROW(s21_arr1[3]);

  std::array<double, 3> std_arr2{1.1, 2.2, 3.3};
  custom::Array<double, 3> s21_arr2{1.1, 2.2, 3.3};
  std_arr2[0] = 5.5;
  s21_arr2[0] = 5.5;
  CompareArrays(s21_arr2, std_arr2);
}

TEST(Array, front) {
  std::array<int, 3> std_arr1{1, 2, 3};
  custom::Array<int, 3> s21_arr1{1, 2, 3};
  ASSERT_EQ(s21_arr1.front(), std_arr1.front());
  s21_arr1.front() = 18;
  std_arr1.front() = 18;
  CompareArrays(s21_arr1, std_arr1);

  const std::array<int, 3> std_arr2{1, 2, 3};
  const custom::Array<int, 3> s21_arr2{1, 2, 3};
  ASSERT_EQ(s21_arr2.front(), std_arr2.front());
}

TEST(Array, back) {
  std::array<int, 3> std_arr1{1, 2, 3};
  custom::Array<int, 3> s21_arr1{1, 2, 3};
  ASSERT_EQ(s21_arr1.back(), std_arr1.back());
  s21_arr1.back() = 18;
  std_arr1.back() = 18;
  CompareArrays(s21_arr1, std_arr1);

  const std::array<int, 3> std_arr2{1, 2, 3};
  const custom::Array<int, 3> s21_arr2{1, 2, 3};
  ASSERT_EQ(s21_arr2.back(), std_arr2.back());
}

TEST(Array, data) {
  std::array<int, 3> std_arr1{1, 2, 3};
  custom::Array<int, 3> s21_arr1{1, 2, 3};
  int *std_arr1_data = std_arr1.data();
  int *s21_arr1_data = s21_arr1.data();
  for (std::size_t i = 0; i < s21_arr1.size(); ++i)
    ASSERT_EQ(s21_arr1_data[i], std_arr1_data[i]);

  const std::array<int, 3> std_arr2{1, 2, 3};
  const custom::Array<int, 3> s21_arr2{1, 2, 3};
  const int *std_arr2_data = std_arr2.data();
  const int *s21_arr2_data = s21_arr2.data();
  for (std::size_t i = 0; i < s21_arr2.size(); ++i)
    ASSERT_EQ(s21_arr2_data[i], std_arr2_data[i]);
}

TEST(Array, begin) {
  std::array<double, 2> std_arr1{1.1, 2.2};
  custom::Array<double, 2> s21_arr1{1.1, 2.2};
  ASSERT_EQ(*s21_arr1.begin(), *std_arr1.begin());

  const std::array<double, 2> std_arr2{1.1, 2.2};
  const custom::Array<double, 2> s21_arr2{1.1, 2.2};
  ASSERT_EQ(*s21_arr2.begin(), *std_arr2.begin());
}

TEST(Array, end) {
  std::array<double, 2> std_arr1{1.1, 2.2};
  custom::Array<double, 2> s21_arr1{1.1, 2.2};
  ASSERT_EQ(*(s21_arr1.end() - 1), *(std_arr1.end() - 1));
  ASSERT_EQ(s21_arr1.end(), s21_arr1.data() + s21_arr1.size());

  const std::array<double, 2> std_arr2{1.1, 2.2};
  const custom::Array<double, 2> s21_arr2{1.1, 2.2};
  ASSERT_EQ(*(s21_arr2.end() - 1), *(std_arr2.end() - 1));
  ASSERT_EQ(s21_arr2.end(), s21_arr2.data() + s21_arr2.size());
}

TEST(Array, empty) {
  const std::array<double, 2> std_arr1{};
  const custom::Array<double, 2> s21_arr1{};
  ASSERT_EQ(s21_arr1.empty(), std_arr1.empty());
  ASSERT_EQ(s21_arr1.empty(), false);

  const std::array<double, 0> std_arr2{};
  const custom::Array<double, 0> s21_arr2{};
  ASSERT_EQ(s21_arr2.empty(), std_arr2.empty());
  ASSERT_EQ(s21_arr2.empty(), true);
}

TEST(Array, size) {
  const std::array<double, 2> std_arr1{};
  const custom::Array<double, 2> s21_arr1{};
  CompareArrays(s21_arr1, std_arr1);

  const std::array<double, 188> std_arr2{};
  const custom::Array<double, 188> s21_arr2{};
  CompareArrays(s21_arr2, std_arr2);
}

class ArrayTestClass {
public:
  bool operator==(const ArrayTestClass &other) const {
    return int_ == other.int_ && double_ == other.double_ &&
           size_t_ == other.size_t_;
  }

  bool operator!=(const ArrayTestClass &other) const {
    return !(*this == other);
  }

private:
  int int_ = 0;
  double double_ = 0.0;
  std::size_t size_t_ = 0UL;
};

TEST(Array, max_size) {
  const std::array<double, 50> std_arr1{};
  const custom::Array<double, 50> s21_arr1{};
  ASSERT_EQ(s21_arr1.max_size(), std_arr1.max_size());

  const std::array<ArrayTestClass, 50> std_arr2{};
  const custom::Array<ArrayTestClass, 50> s21_arr2{};
  ASSERT_EQ(s21_arr2.max_size(), std_arr2.max_size());
}

TEST(Array, swap) {
  std::array<int, 5> std_arr1{1, 2, 3, 4, 5}, std_arr2{6, 7, 8, 9, 10};
  custom::Array<int, 5> s21_arr1{1, 2, 3, 4, 5}, s21_arr2{6, 7, 8, 9, 10};
  std_arr1.swap(std_arr2);
  s21_arr1.swap(s21_arr2);
  CompareArrays(s21_arr1, std_arr1);
  CompareArrays(s21_arr1, std::array<int, 5>{6, 7, 8, 9, 10});
  CompareArrays(s21_arr2, std_arr2);
  CompareArrays(s21_arr2, std::array<int, 5>{1, 2, 3, 4, 5});
}

TEST(Array, fill) {
  std::array<double, 188> std_arr{};
  custom::Array<double, 188> s21_arr{};
  std_arr.fill(123456.789);
  s21_arr.fill(123456.789);
  CompareArrays(std_arr, s21_arr);
}