#include <gtest/gtest.h>

#include <set>

#include "../../associative_containers/set/custom_set.h"

template <class T>
void CompareSets(const std::set<T> &std_set, const custom::Set<T> &s21_set) {
  ASSERT_EQ(std_set.size(), s21_set.size());
  ASSERT_EQ(std_set.max_size(), s21_set.max_size());
  auto std_i = std_set.begin();
  auto s21_i = s21_set.begin();
  while (std_i != std_set.end() && s21_i != s21_set.end()) {
    ASSERT_EQ(*std_i, *s21_i);
    ++std_i;
    ++s21_i;
  }
  ASSERT_EQ(std_i, std_set.end());
  ASSERT_EQ(s21_i, s21_set.end());
}

template <class T>
void CompareSets(const custom::Set<T> &s21_set, const std::set<T> &std_set) {
  ASSERT_EQ(std_set.size(), s21_set.size());
  ASSERT_EQ(std_set.max_size(), s21_set.max_size());
  auto std_i = std_set.begin();
  auto s21_i = s21_set.begin();
  while (std_i != std_set.end() && s21_i != s21_set.end()) {
    ASSERT_EQ(*std_i, *s21_i);
    ++std_i;
    ++s21_i;
  }
  ASSERT_EQ(std_i, std_set.end());
  ASSERT_EQ(s21_i, s21_set.end());
}

template <class T>
void CompareSets(const custom::Set<T> &s21_set1,
                 const custom::Set<T> &s21_set2) {
  ASSERT_EQ(s21_set1.size(), s21_set2.size());
  ASSERT_EQ(s21_set1.max_size(), s21_set2.max_size());
  auto s21_i1 = s21_set1.begin();
  auto s21_i2 = s21_set2.begin();
  while (s21_i1 != s21_set1.end() && s21_i2 != s21_set2.end()) {
    ASSERT_EQ(*s21_i1, *s21_i2);
    ++s21_i1;
    ++s21_i2;
  }
  ASSERT_EQ(s21_i1, s21_set1.end());
  ASSERT_EQ(s21_i2, s21_set2.end());
}

template <class T>
void CompareSets(const std::set<T> &std_set1, const std::set<T> &std_set2) {
  ASSERT_EQ(std_set2.size(), std_set1.size());
  ASSERT_EQ(std_set2.max_size(), std_set1.max_size());
  auto std_i = std_set2.begin();
  auto s21_i = std_set1.begin();
  while (std_i != std_set2.end() && s21_i != std_set1.end()) {
    ASSERT_EQ(*std_i, *s21_i);
    ++std_i;
    ++s21_i;
  }
  ASSERT_EQ(std_i, std_set2.end());
  ASSERT_EQ(s21_i, std_set1.end());
}

TEST(Set, default_constructor) {
  std::set<int> std_set;
  custom::Set<int> s21_set;
  CompareSets(std_set, s21_set);
}

TEST(Set, initializer_list_constructor) {
  std::set<double> std_set1{};
  custom::Set<double> s21_set1{};
  CompareSets(s21_set1, std_set1);

  std::set<int> std_set2{3, 2, 5, 18, 222};
  custom::Set<int> s21_set2{222, 5, 18, 2, 3};
  CompareSets(std_set2, s21_set2);
}

TEST(Set, copy_constructor) {
  std::set<int> std_set1{3, 2, 1}, std_set2(std_set1);
  custom::Set<int> s21_set1{3, 2, 1}, s21_set2(s21_set1);
  CompareSets(s21_set2, s21_set1);
  CompareSets(s21_set2, std_set2);
}

TEST(Set, move_constructor) {
  std::set<int> std_set1{3, 2, 1}, std_set2(std::move(std_set1));
  custom::Set<int> s21_set1{3, 2, 1}, s21_set2(std::move(s21_set1));
  CompareSets(s21_set2, std_set2);
}

TEST(Set, operator_equal_copy) {
  std::set<double> std_set1{3.3, 1.1, 2.2}, std_set2;
  custom::Set<double> s21_set1{3.3, 1.1, 2.2}, s21_set2;
  std_set2 = std_set1;
  s21_set2 = s21_set1;
  CompareSets(s21_set2, s21_set1);
  CompareSets(s21_set2, std_set2);
}

TEST(Set, operator_equal_move) {
  std::set<double> std_set1{3.3, 1.1, 2.2}, std_set2;
  custom::Set<double> s21_set1{3.3, 1.1, 2.2}, s21_set2;
  std_set2 = std::move(std_set1);
  s21_set2 = std::move(s21_set1);
  CompareSets(s21_set2, std_set2);
}

TEST(Set, begin) {
  const std::set<double> std_set1{5.5, 55.5};
  const custom::Set<double> s21_set1{5.5, 55.5};
  ASSERT_EQ(*std_set1.begin(), *s21_set1.begin());

  std::set<int> std_set2{3, 4, 1};
  custom::Set<int> s21_set2{3, 4, 1};
  ASSERT_EQ(*std_set2.begin(), *s21_set2.begin());

  std::set<char> std_set3;
  custom::Set<char> s21_set3;
  ASSERT_EQ(std_set3.begin(), std_set3.end());
  ASSERT_EQ(s21_set3.begin(), s21_set3.end());
}

TEST(Set, end) {
  const std::set<double> std_set1{5.5, 55.5};
  const custom::Set<double> s21_set1{5.5, 55.5};
  ASSERT_EQ(*(--std_set1.end()), *(--s21_set1.end()));

  std::set<int> std_set2{3, 4, 1};
  custom::Set<int> s21_set2{3, 4, 1};
  ASSERT_EQ(*(--std_set2.end()), *(--s21_set2.end()));
}

TEST(Set, empty) {
  const std::set<double> std_set1;
  const custom::Set<double> s21_set1;
  ASSERT_EQ(s21_set1.empty(), std_set1.empty());

  std::set<char> std_set2{'a', 'c', 'b'};
  custom::Set<char> s21_set2{'a', 'c', 'b'};
  CompareSets(s21_set2, std_set2);
  ASSERT_EQ(s21_set2.empty(), std_set2.empty());
}

TEST(Set, size) {
  const std::set<long double> std_set1;
  const custom::Set<long double> s21_set1;
  ASSERT_EQ(s21_set1.size(), std_set1.size());

  const std::set<long double> std_set2{5.5L, 6.6L, 777.777L};
  const custom::Set<long double> s21_set2{5.5L, 6.6L, 777.777L};
  ASSERT_EQ(s21_set2.size(), std_set2.size());
}

class SetTestClass {
public:
  bool operator<(const SetTestClass &other) const {
    return data_ < other.data_;
  }
  bool operator==(const SetTestClass &other) const {
    return data_ == other.data_;
  }
  bool operator!=(const SetTestClass &other) const {
    return data_ == other.data_;
  }

private:
  int data_ = 0;
};

TEST(Set, max_size) {
  const std::set<long double> std_set1;
  const custom::Set<long double> s21_set1;
  CompareSets(s21_set1, std_set1);

  const std::set<SetTestClass> std_set2;
  const custom::Set<SetTestClass> s21_set2;
  CompareSets(s21_set2, std_set2);
}

TEST(Set, clear) {
  std::set<long double> std_set1{1.1L, 2.2L, 3.3L};
  custom::Set<long double> s21_set1{1.1L, 2.2L, 3.3L};
  std_set1.clear();
  s21_set1.clear();
  CompareSets(s21_set1, std_set1);

  std::set<long double> std_set2;
  custom::Set<long double> s21_set2;
  std_set2.clear();
  s21_set2.clear();
  CompareSets(s21_set2, std_set2);
}

TEST(Set, insert) {
  std::set<int> std_set;
  custom::Set<int> s21_set;
  auto std_result = std_set.insert(4);
  auto s21_result = s21_set.insert(4);
  ASSERT_EQ(std_result.second, s21_result.second);
  ASSERT_EQ(*std_result.first, *s21_result.first);
  CompareSets(s21_set, std_set);

  std_result = std_set.insert(4);
  s21_result = s21_set.insert(4);
  ASSERT_EQ(std_result.second, s21_result.second);
  ASSERT_EQ(*std_result.first, *s21_result.first);
  CompareSets(s21_set, std_set);

  std_result = std_set.insert(44);
  s21_result = s21_set.insert(44);
  ASSERT_EQ(std_result.second, s21_result.second);
  ASSERT_EQ(*std_result.first, *s21_result.first);
  CompareSets(s21_set, std_set);
}

TEST(Set, erase) {
  std::set<int> std_set{5, 4, 3, 2, 1, 55, 66, -543, -78976};
  custom::Set<int> s21_set{5, 4, 3, 2, 1, 55, 66, -543, -78976};
  CompareSets(s21_set, std_set);

  std_set.erase(std_set.begin());
  s21_set.erase(s21_set.begin());
  CompareSets(s21_set, std_set);

  std_set.erase(std_set.find(4));
  s21_set.erase(s21_set.find(4));
  CompareSets(s21_set, std_set);

  while (!s21_set.empty() && !std_set.empty()) {
    std_set.erase(std_set.begin());
    s21_set.erase(s21_set.begin());
    CompareSets(s21_set, std_set);
  }
}

TEST(Set, swap) {
  std::set<double> std_set1{1, 2, 3, 4, -55}, std_set2{-5, -6, -7};
  custom::Set<double> s21_set1{1, 2, 3, 4, -55}, s21_set2{-5, -6, -7};
  std_set1.swap(std_set2);
  s21_set1.swap(s21_set2);
  CompareSets(std_set1, s21_set1);
  CompareSets(std_set2, s21_set2);
  CompareSets(s21_set1, custom::Set<double>{-5, -6, -7});
  CompareSets(s21_set2, custom::Set<double>{1, 2, 3, 4, -55});
}

TEST(Set, merge) {
  std::set<int> std_set1{1, 1, 2, 2, 3, 3}, std_set2;
  custom::Set<int> s21_set1{1, 1, 2, 2, 3, 3}, s21_set2;
  s21_set1.merge(s21_set2);
  std_set1.merge(std_set2);
  CompareSets(s21_set1, custom::Set<int>{1, 1, 2, 2, 3, 3});
  CompareSets(std_set1, std::set<int>{1, 1, 2, 2, 3, 3});
  CompareSets(s21_set2, custom::Set<int>());
  CompareSets(std_set2, std::set<int>());
  CompareSets(s21_set1, std_set1);
  CompareSets(s21_set2, std_set2);

  s21_set2.merge(s21_set1);
  std_set2.merge(std_set1);
  CompareSets(s21_set2, custom::Set<int>{1, 1, 2, 2, 3, 3});
  CompareSets(std_set2, std::set<int>{1, 1, 2, 2, 3, 3});
  CompareSets(s21_set1, custom::Set<int>());
  CompareSets(std_set1, std::set<int>());
  CompareSets(s21_set1, std_set1);
  CompareSets(s21_set2, std_set2);

  std::set<int> std_set3{2, 3, 4, 5}, std_set4{2, 4, 6, 8};
  custom::Set<int> s21_set3{2, 3, 4, 5}, s21_set4{2, 4, 6, 8};
  s21_set3.merge(s21_set4);
  std_set3.merge(std_set4);
  CompareSets(s21_set3, custom::Set<int>{2, 3, 4, 5, 6, 8});
  CompareSets(std_set3, std::set<int>{2, 3, 4, 5, 6, 8});
  CompareSets(s21_set4, custom::Set<int>{2, 4});
  CompareSets(std_set4, std::set<int>{2, 4});
  CompareSets(s21_set3, std_set3);
  CompareSets(s21_set4, std_set4);
}

TEST(Set, find) {
  std::set<int> std_set;
  custom::Set<int> s21_set;
  auto std_i = std_set.find(4);
  auto s21_i = s21_set.find(4);
  ASSERT_EQ(std_i, std_set.end());
  ASSERT_EQ(s21_i, s21_set.end());

  std_set.insert(4);
  s21_set.insert(4);
  std_i = std_set.find(4);
  s21_i = s21_set.find(4);
  ASSERT_EQ(*std_i, *s21_i);

  std_set.insert(88);
  s21_set.insert(88);
  std_i = std_set.find(87);
  s21_i = s21_set.find(87);
  ASSERT_EQ(std_i, std_set.end());
  ASSERT_EQ(s21_i, s21_set.end());

  std_set = std::move(std::set<int>{5, 6, 4, 7, 3, 8, 2});
  s21_set = std::move(custom::Set<int>{5, 6, 4, 7, 3, 8, 2});
  std_i = std_set.begin();
  s21_i = s21_set.begin();
  while (std_i != std_set.end() && s21_i != s21_set.end()) {
    auto std_find_result = std_set.find(*std_i);
    auto s21_find_result = s21_set.find(*s21_i);
    ASSERT_EQ(*std_find_result, *s21_find_result);
    ASSERT_EQ(std_i, std_find_result);
    ASSERT_EQ(s21_i, s21_find_result);
    ++std_i;
    ++s21_i;
  }
  ASSERT_EQ(s21_i, s21_set.end());
  ASSERT_EQ(std_i, std_set.end());
}

TEST(Set, contains) {
  // * There is no contains function in std::set
  custom::Set<int> s21_set;
  ASSERT_EQ(s21_set.contains(4), false);

  s21_set.insert(5);
  ASSERT_EQ(s21_set.contains(5), true);
  ASSERT_EQ(s21_set.contains(4), false);

  s21_set = {5, 6, 4, 7, 3, 8};
  for (auto &i : s21_set)
    ASSERT_EQ(s21_set.contains(i), true);
}

TEST(Set, emplace) {
  // * emplace behavior in std::set differs completely
  custom::Set<int> s21_set;
  custom::Set<int> compare{1, 2, 3, 4, 5, 6};
  auto emplace_result = s21_set.emplace(1, 2, 3, 4, 5, 6);
  CompareSets(s21_set, compare);
  for (auto &i : emplace_result)
    ASSERT_EQ(i.second, true);

  s21_set.clear();
  compare = {1, 1, 2, 2, 3, 3, 4, 4, -5, 6, -5};
  custom::Vector<std::pair<int, bool>> pair_compare{
      {1, true}, {1, false}, {2, true},  {2, false}, {3, true},  {3, false},
      {4, true}, {4, false}, {-5, true}, {6, true},  {-5, false}};
  auto pair_compare_iterator = pair_compare.begin();
  emplace_result = s21_set.emplace(1, 1, 2, 2, 3, 3, 4, 4, -5, 6, -5);
  CompareSets(s21_set, compare);
  for (auto &i : emplace_result) {
    ASSERT_EQ(*i.first, (*pair_compare_iterator).first);
    ASSERT_EQ(i.second, (*pair_compare_iterator).second);
    ++pair_compare_iterator;
  }
}