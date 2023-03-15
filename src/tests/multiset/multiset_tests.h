#include <gtest/gtest.h>

#include <set>

#include "../../associative_containers/multiset/custom_multiset.h"

template <class T>
void CompareMultisets(const std::multiset<T> &std_multiset,
                      const custom::Multiset<T> &s21_multiset) {
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
  ASSERT_EQ(std_multiset.max_size(), s21_multiset.max_size());
  auto std_i = std_multiset.begin();
  auto s21_i = s21_multiset.begin();
  while (std_i != std_multiset.end() && s21_i != s21_multiset.end()) {
    ASSERT_EQ(*std_i, *s21_i);
    ++std_i;
    ++s21_i;
  }
  ASSERT_EQ(std_i, std_multiset.end());
  ASSERT_EQ(s21_i, s21_multiset.end());
}

template <class T>
void CompareMultisets(const custom::Multiset<T> &s21_multiset,
                      const std::multiset<T> &std_multiset) {
  ASSERT_EQ(std_multiset.size(), s21_multiset.size());
  ASSERT_EQ(std_multiset.max_size(), s21_multiset.max_size());
  auto std_i = std_multiset.begin();
  auto s21_i = s21_multiset.begin();
  while (std_i != std_multiset.end() && s21_i != s21_multiset.end()) {
    ASSERT_EQ(*std_i, *s21_i);
    ++std_i;
    ++s21_i;
  }
  ASSERT_EQ(std_i, std_multiset.end());
  ASSERT_EQ(s21_i, s21_multiset.end());
}

template <class T>
void CompareMultisets(const custom::Multiset<T> &s21_multiset1,
                      const custom::Multiset<T> &s21_multiset2) {
  ASSERT_EQ(s21_multiset1.size(), s21_multiset2.size());
  ASSERT_EQ(s21_multiset1.max_size(), s21_multiset2.max_size());
  auto s21_i1 = s21_multiset1.begin();
  auto s21_i2 = s21_multiset2.begin();
  while (s21_i1 != s21_multiset1.end() && s21_i2 != s21_multiset2.end()) {
    ASSERT_EQ(*s21_i1, *s21_i2);
    ++s21_i1;
    ++s21_i2;
  }
  ASSERT_EQ(s21_i1, s21_multiset1.end());
  ASSERT_EQ(s21_i2, s21_multiset2.end());
}

template <class T>
void CompareMultisets(const std::multiset<T> &std_multiset1,
                      const std::multiset<T> &std_multiset2) {
  ASSERT_EQ(std_multiset2.size(), std_multiset1.size());
  ASSERT_EQ(std_multiset2.max_size(), std_multiset1.max_size());
  auto std_i = std_multiset2.begin();
  auto s21_i = std_multiset1.begin();
  while (std_i != std_multiset2.end() && s21_i != std_multiset1.end()) {
    ASSERT_EQ(*std_i, *s21_i);
    ++std_i;
    ++s21_i;
  }
  ASSERT_EQ(std_i, std_multiset2.end());
  ASSERT_EQ(s21_i, std_multiset1.end());
}

TEST(Multiset, default_constructor) {
  std::multiset<int> std_multiset;
  custom::Multiset<int> s21_multiset;
  CompareMultisets(std_multiset, s21_multiset);
}

TEST(Multiset, initializer_list_constructor) {
  std::multiset<double> std_multiset1{};
  custom::Multiset<double> s21_multiset1{};
  CompareMultisets(s21_multiset1, std_multiset1);

  std::multiset<int> std_multiset2{3, 3, 3, 2, 5, 18, 2, 5, 18, 222};
  custom::Multiset<int> s21_multiset2{3, 3, 3, 2, 5, 18, 2, 5, 18, 222};
  CompareMultisets(std_multiset2, s21_multiset2);
}

TEST(Multiset, copy_constructor) {
  std::multiset<int> std_multiset1{3, 2, 1, 3, 1, 2},
      std_multiset2(std_multiset1);
  custom::Multiset<int> s21_multiset1{3, 2, 1, 3, 1, 2},
      s21_multiset2(s21_multiset1);
  CompareMultisets(s21_multiset2, s21_multiset1);
  CompareMultisets(s21_multiset2, std_multiset2);
}

TEST(Multiset, move_constructor) {
  std::multiset<int> std_multiset1{3, 2, 1, 1},
      std_multiset2(std::move(std_multiset1));
  custom::Multiset<int> s21_multiset1{3, 2, 1, 1},
      s21_multiset2(std::move(s21_multiset1));
  CompareMultisets(s21_multiset2, std_multiset2);
}

TEST(Multiset, operator_equal_copy) {
  std::multiset<double> std_multiset1{3.3, 1.1, 2.2, 3.3}, std_multiset2;
  custom::Multiset<double> s21_multiset1{3.3, 1.1, 2.2, 3.3}, s21_multiset2;
  std_multiset2 = std_multiset1;
  s21_multiset2 = s21_multiset1;
  CompareMultisets(s21_multiset2, s21_multiset1);
  CompareMultisets(s21_multiset2, std_multiset2);
}

TEST(Multiset, operator_equal_move) {
  std::multiset<double> std_multiset1{3.3, 1.1, 2.2}, std_multiset2;
  custom::Multiset<double> s21_multiset1{3.3, 1.1, 2.2}, s21_multiset2;
  std_multiset2 = std::move(std_multiset1);
  s21_multiset2 = std::move(s21_multiset1);
  CompareMultisets(s21_multiset2, std_multiset2);
}

TEST(Multiset, begin) {
  const std::multiset<double> std_multiset1{5.5, 55.5};
  const custom::Multiset<double> s21_multiset1{5.5, 55.5};
  ASSERT_EQ(*std_multiset1.begin(), *s21_multiset1.begin());

  std::multiset<int> std_multiset2{3, 4, 1, 3, 3};
  custom::Multiset<int> s21_multiset2{3, 4, 1, 3, 3};
  ASSERT_EQ(*std_multiset2.begin(), *s21_multiset2.begin());

  std::multiset<char> std_multiset3;
  custom::Multiset<char> s21_multiset3;
  ASSERT_EQ(std_multiset3.begin(), std_multiset3.end());
  ASSERT_EQ(s21_multiset3.begin(), s21_multiset3.end());
}

TEST(Multiset, end) {
  const std::multiset<double> std_multiset1{5.5, 55.5};
  const custom::Multiset<double> s21_multiset1{5.5, 55.5};
  ASSERT_EQ(*(--std_multiset1.end()), *(--s21_multiset1.end()));

  std::multiset<int> std_multiset2{3, 4, 1};
  custom::Multiset<int> s21_multiset2{3, 4, 1};
  ASSERT_EQ(*(--std_multiset2.end()), *(--s21_multiset2.end()));
}

TEST(Multiset, empty) {
  const std::multiset<double> std_multiset1;
  const custom::Multiset<double> s21_multiset1;
  ASSERT_EQ(s21_multiset1.empty(), std_multiset1.empty());

  std::multiset<char> std_multiset2{'a', 'c', 'b', 'a', 'a'};
  custom::Multiset<char> s21_multiset2{'a', 'c', 'b', 'a', 'a'};
  CompareMultisets(s21_multiset2, std_multiset2);
  ASSERT_EQ(s21_multiset2.empty(), std_multiset2.empty());
}

TEST(Multiset, size) {
  const std::multiset<long double> std_multiset1;
  const custom::Multiset<long double> s21_multiset1;
  ASSERT_EQ(s21_multiset1.size(), std_multiset1.size());

  const std::multiset<long double> std_multiset2{5.5L, 6.6L, 777.777L, 777.777L,
                                                 777.777L};
  const custom::Multiset<long double> s21_multiset2{5.5L, 6.6L, 777.777L,
                                                    777.777L, 777.777L};
  ASSERT_EQ(s21_multiset2.size(), std_multiset2.size());
}

class MultisetTestClass {
public:
  bool operator<(const MultisetTestClass &other) const {
    return data_ < other.data_;
  }
  bool operator==(const MultisetTestClass &other) const {
    return data_ == other.data_;
  }
  bool operator!=(const MultisetTestClass &other) const {
    return data_ == other.data_;
  }

private:
  int data_ = 0;
};

TEST(Multiset, max_size) {
  const std::multiset<long double> std_multiset1;
  const custom::Multiset<long double> s21_multiset1;
  CompareMultisets(s21_multiset1, std_multiset1);

  const std::multiset<MultisetTestClass> std_multiset2;
  const custom::Multiset<MultisetTestClass> s21_multiset2;
  CompareMultisets(s21_multiset2, std_multiset2);
}

TEST(Multiset, clear) {
  std::multiset<long double> std_multiset1{1.1L, 2.2L, 3.3L, 2.2L};
  custom::Multiset<long double> s21_multiset1{1.1L, 2.2L, 3.3L, 2.2L};
  std_multiset1.clear();
  s21_multiset1.clear();
  CompareMultisets(s21_multiset1, std_multiset1);

  std::multiset<long double> std_multiset2;
  custom::Multiset<long double> s21_multiset2;
  std_multiset2.clear();
  s21_multiset2.clear();
  CompareMultisets(s21_multiset2, std_multiset2);
}

TEST(Multiset, insert) {
  std::multiset<int> std_multiset;
  custom::Multiset<int> s21_multiset;
  auto std_result = std_multiset.insert(4);
  auto s21_result = s21_multiset.insert(4);
  ASSERT_EQ(*std_result, *s21_result);
  CompareMultisets(s21_multiset, std_multiset);

  std_result = std_multiset.insert(4);
  s21_result = s21_multiset.insert(4);
  ASSERT_EQ(*std_result, *s21_result);
  CompareMultisets(s21_multiset, std_multiset);

  std_result = std_multiset.insert(44);
  s21_result = s21_multiset.insert(44);
  ASSERT_EQ(*std_result, *s21_result);
  CompareMultisets(s21_multiset, std_multiset);
}

TEST(Multiset, erase) {
  std::multiset<int> std_multiset{5, 4, 3, 2, 1, 55, 66, -543, -78976, 55, 5};
  custom::Multiset<int> s21_multiset{5,  4,    3,      2,  1, 55,
                                     66, -543, -78976, 55, 5};
  CompareMultisets(s21_multiset, std_multiset);

  std_multiset.erase(std_multiset.begin());
  s21_multiset.erase(s21_multiset.begin());
  CompareMultisets(s21_multiset, std_multiset);

  std_multiset.erase(std_multiset.find(55));
  s21_multiset.erase(s21_multiset.find(55));
  CompareMultisets(s21_multiset, std_multiset);

  while (!s21_multiset.empty() && !std_multiset.empty()) {
    std_multiset.erase(std_multiset.begin());
    s21_multiset.erase(s21_multiset.begin());
    CompareMultisets(s21_multiset, std_multiset);
  }
}

TEST(Multiset, swap) {
  std::multiset<double> std_multiset1{1, 2, 3, 4, -55, 4, 3, 2, 1},
      std_multiset2{-5, -6, -7, -6, -5};
  custom::Multiset<double> s21_multiset1{1, 2, 3, 4, -55, 4, 3, 2, 1},
      s21_multiset2{-5, -6, -7, -6, -5};
  std_multiset1.swap(std_multiset2);
  s21_multiset1.swap(s21_multiset2);
  CompareMultisets(std_multiset1, s21_multiset1);
  CompareMultisets(std_multiset2, s21_multiset2);
  CompareMultisets(s21_multiset1, custom::Multiset<double>{-5, -6, -7, -6, -5});
  CompareMultisets(s21_multiset2,
                   custom::Multiset<double>{1, 2, 3, 4, -55, 4, 3, 2, 1});
}

TEST(Multiset, merge) {
  std::multiset<int> std_multiset1{1, 1, 2, 2, 3, 3}, std_multiset2;
  custom::Multiset<int> s21_multiset1{1, 1, 2, 2, 3, 3}, s21_multiset2;
  s21_multiset1.merge(s21_multiset2);
  std_multiset1.merge(std_multiset2);
  CompareMultisets(s21_multiset1, custom::Multiset<int>{1, 1, 2, 2, 3, 3});
  CompareMultisets(std_multiset1, std::multiset<int>{1, 1, 2, 2, 3, 3});
  CompareMultisets(s21_multiset2, custom::Multiset<int>());
  CompareMultisets(std_multiset2, std::multiset<int>());
  CompareMultisets(s21_multiset1, std_multiset1);
  CompareMultisets(s21_multiset2, std_multiset2);

  s21_multiset2.merge(s21_multiset1);
  std_multiset2.merge(std_multiset1);
  CompareMultisets(s21_multiset2, custom::Multiset<int>{1, 1, 2, 2, 3, 3});
  CompareMultisets(std_multiset2, std::multiset<int>{1, 1, 2, 2, 3, 3});
  CompareMultisets(s21_multiset1, custom::Multiset<int>());
  CompareMultisets(std_multiset1, std::multiset<int>());
  CompareMultisets(s21_multiset1, std_multiset1);
  CompareMultisets(s21_multiset2, std_multiset2);

  // std::multiset<int> std_multiset3{2, 3, 4, 5}, std_multiset4{2, 4, 6, 8};
  // custom::Multiset<int> s21_multiset3{2, 3, 4, 5}, s21_multiset4{2, 4, 6, 8};
  // s21_multiset3.merge(s21_multiset4);
  // std_multiset3.merge(std_multiset4);
  // CompareMultisets(s21_multiset3, custom::Multiset<int>{2, 2, 3, 4, 4, 5, 6,
  // 8}); CompareMultisets(std_multiset3, std::multiset<int>{2, 2, 3, 4, 4, 5,
  // 6, 8}); CompareMultisets(s21_multiset4, custom::Multiset<int>());
  // CompareMultisets(std_multiset4, std::multiset<int>());
  // CompareMultisets(s21_multiset3, std_multiset3);
  // CompareMultisets(s21_multiset4, std_multiset4);
}

TEST(Multiset, find) {
  std::multiset<int> std_multiset;
  custom::Multiset<int> s21_multiset;
  auto std_i = std_multiset.find(4);
  auto s21_i = s21_multiset.find(4);
  ASSERT_EQ(std_i, std_multiset.end());
  ASSERT_EQ(s21_i, s21_multiset.end());

  std_multiset.insert(4);
  s21_multiset.insert(4);
  std_i = std_multiset.find(4);
  s21_i = s21_multiset.find(4);
  ASSERT_EQ(*std_i, *s21_i);

  std_multiset.insert(88);
  s21_multiset.insert(88);
  std_i = std_multiset.find(87);
  s21_i = s21_multiset.find(87);
  ASSERT_EQ(std_i, std_multiset.end());
  ASSERT_EQ(s21_i, s21_multiset.end());

  std_multiset = std::move(std::multiset<int>{5, 6, 4, 7, 3, 8, 2, 4});
  s21_multiset = std::move(custom::Multiset<int>{5, 6, 4, 7, 3, 8, 2, 4});
  std_i = std_multiset.begin();
  s21_i = s21_multiset.begin();
  while (std_i != std_multiset.end() && s21_i != s21_multiset.end()) {
    auto std_find_result = std_multiset.find(*std_i);
    auto s21_find_result = s21_multiset.find(*s21_i);
    ASSERT_EQ(*std_find_result, *s21_find_result);
    ASSERT_EQ(*std_i, *std_find_result);
    ASSERT_EQ(*s21_i, *s21_find_result);
    ++std_i;
    ++s21_i;
  }
  ASSERT_EQ(s21_i, s21_multiset.end());
  ASSERT_EQ(std_i, std_multiset.end());
}

TEST(Multiset, contains) {
  // * There is no contains function in std::multiset
  custom::Multiset<int> s21_multiset;
  ASSERT_EQ(s21_multiset.contains(4), false);

  s21_multiset.insert(5);
  ASSERT_EQ(s21_multiset.contains(5), true);
  ASSERT_EQ(s21_multiset.contains(4), false);

  s21_multiset = {5, 6, 4, 7, 3, 8, 4, 7, 6};
  for (auto &i : s21_multiset)
    ASSERT_EQ(s21_multiset.contains(i), true);
}

TEST(Multiset, emplace) {
  // * emplace behavior in std::multiset differs completely
  custom::Multiset<int> s21_multiset;
  custom::Multiset<int> compare{1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1};
  auto emplace_result =
      s21_multiset.emplace(1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1);
  CompareMultisets(s21_multiset, compare);
  for (auto &i : emplace_result)
    ASSERT_EQ(i.second, true);

  s21_multiset.clear();
  compare = {1, 1, 2, 2, 3, 3, 4, 4, -5, 6, -5};
  custom::Vector<std::pair<int, bool>> pair_compare{
      {1, true}, {1, true}, {2, true},  {2, true}, {3, true}, {3, true},
      {4, true}, {4, true}, {-5, true}, {6, true}, {-5, true}};
  auto pair_compare_iterator = pair_compare.begin();
  emplace_result = s21_multiset.emplace(1, 1, 2, 2, 3, 3, 4, 4, -5, 6, -5);
  CompareMultisets(s21_multiset, compare);
  for (auto &i : emplace_result) {
    ASSERT_EQ(*i.first, (*pair_compare_iterator).first);
    ASSERT_EQ(i.second, (*pair_compare_iterator).second);
    ++pair_compare_iterator;
  }
}

TEST(Multiset, count) {
  const std::multiset<int> std_multiset{1, 1, 2, 2, 3, 3, 3};
  const custom::Multiset<int> s21_multiset{1, 1, 2, 2, 3, 3, 3};
  ASSERT_EQ(std_multiset.count(3), s21_multiset.count(3));
  ASSERT_EQ(std_multiset.count(2), s21_multiset.count(2));
  ASSERT_EQ(std_multiset.count(1), s21_multiset.count(1));
  ASSERT_EQ(std_multiset.count(0), s21_multiset.count(0));
}

TEST(Multiset, equal_range) {
  const std::multiset<int> std_multiset{1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
  const custom::Multiset<int> s21_multiset{1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
  auto std_equal_range_result = std_multiset.equal_range(1);
  auto s21_equal_range_result = s21_multiset.equal_range(1);
  auto std_i = std_equal_range_result.first;
  auto s21_i = s21_equal_range_result.first;
  while (*std_i == *std_equal_range_result.first &&
         *std_i == *std_equal_range_result.second &&
         *s21_i == *s21_equal_range_result.first &&
         *s21_i == *s21_equal_range_result.second) {
    ASSERT_EQ(*std_i, *s21_i);
    ++s21_i;
    ++std_i;
  }
}

TEST(Multiset, lower_bound) {
  const std::multiset<int> std_multiset{1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
  const custom::Multiset<int> s21_multiset{1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
  auto std_lower_bound_result = std_multiset.lower_bound(1);
  auto s21_lower_bound_result = s21_multiset.lower_bound(1);
  for (std::size_t i = 0; i < 6; ++i) {
    ASSERT_EQ(*s21_lower_bound_result, *std_lower_bound_result);
    ++std_lower_bound_result;
    ++s21_lower_bound_result;
  }
}

TEST(Multiset, upper_bound) {
  const std::multiset<int> std_multiset{1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
  const custom::Multiset<int> s21_multiset{1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
  auto std_upper_bound_result = std_multiset.upper_bound(1);
  auto s21_upper_bound_result = s21_multiset.upper_bound(1);
  for (std::size_t i = 0; i < 6; ++i) {
    ASSERT_EQ(*s21_upper_bound_result, *std_upper_bound_result);
    --std_upper_bound_result;
    --s21_upper_bound_result;
  }
}