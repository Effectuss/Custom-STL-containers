#include <gtest/gtest.h>

#include <list>

#include "../../sequence_containers/list/custom_list.h"

void CompareListInt(custom::List<int> const &result,
                    std::list<int> const &expect) {
  auto i_result = result.begin();
  auto i_expect = expect.begin();
  while (i_result != result.end() && i_expect != expect.end()) {
    if (*i_result != *i_expect) {
      break;
    }
    ++i_result;
    ++i_expect;
  }
  if (i_result != result.end() || i_expect != expect.end()) {
    ADD_FAILURE();
  }
}

TEST(List, constructor_default_1) {
  custom::List<int> result;
  std::list<int> expect;
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
}

TEST(List, constructor_size_2) {
  custom::List<int> result(0);
  std::list<int> expect(0);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
}

TEST(List, constructor_size_3) {
  custom::List<int> result(1);
  std::list<int> expect(1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
}

TEST(List, constructor_size_4) {
  size_t n{5};
  custom::List<int> result(n);
  std::list<int> expect(n);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
}

TEST(List, constructor_size__5) {
  custom::List<int> result(12);
  std::list<int> expect(12);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, constructor_initlist_6) {
  std::initializer_list<int> n{};
  custom::List<int> result(n);
  std::list<int> expect(n);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
}

TEST(List, constructor_initlist_7) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
}

TEST(List, constructor_initlist_8) {
  std::initializer_list<int> n{1, 2};
  custom::List<int> result(n);
  std::list<int> expect(n);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
}

TEST(List, constructor_initlist__9) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
}

TEST(List, constructor_copy_10) {
  std::initializer_list<int> n{};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  custom::List<int> result(resultStart);
  std::list<int> expect(expectStart);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
  CompareListInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, constructor_copy_11) {
  std::initializer_list<int> n{1};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  custom::List<int> result(resultStart);
  std::list<int> expect(expectStart);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
  CompareListInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, constructor_copy_12) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  custom::List<int> result(resultStart);
  std::list<int> expect(expectStart);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
  CompareListInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, constructor_move_13) {
  std::initializer_list<int> n{};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  custom::List<int> result(std::move(resultStart));
  std::list<int> expect(std::move(expectStart));
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
  CompareListInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, constructor_move_14) {
  std::initializer_list<int> n{1};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  custom::List<int> result(std::move(resultStart));
  std::list<int> expect(std::move(expectStart));
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
  CompareListInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, constructor_move_15) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  custom::List<int> result(std::move(resultStart));
  std::list<int> expect(std::move(expectStart));
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
  CompareListInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, operator_move_1) {
  std::initializer_list<int> n{};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  custom::List<int> result = std::move(resultStart);
  std::list<int> expect = std::move(expectStart);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
  CompareListInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, operator_move_2) {
  std::initializer_list<int> n{1};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  custom::List<int> result = std::move(resultStart);
  std::list<int> expect = std::move(expectStart);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
  CompareListInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, operator_move_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  custom::List<int> result = std::move(resultStart);
  std::list<int> expect = std::move(expectStart);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.max_size(), expect.max_size());
  CompareListInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, front_back_1) {
  std::initializer_list<int> n{1};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  ASSERT_EQ(resultStart.front(), expectStart.front());
  ASSERT_EQ(resultStart.back(), expectStart.back());
}

TEST(List, front_back_2) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  ASSERT_EQ(resultStart.front(), expectStart.front());
  ASSERT_EQ(resultStart.back(), expectStart.back());
}

TEST(List, begin_end_1) {
  custom::List<int> resultStart;
  std::list<int> expectStart;
  ASSERT_TRUE((resultStart.begin() == resultStart.end()));
  ASSERT_TRUE((expectStart.begin() == expectStart.end()));
}

TEST(List, begin_end_2) {
  custom::List<int> resultStart(0);
  std::list<int> expectStart(0);
  ASSERT_TRUE((resultStart.begin() == resultStart.end()));
  ASSERT_TRUE((expectStart.begin() == expectStart.end()));
}

TEST(List, begin_end_3) {
  std::initializer_list<int> n{4};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  ASSERT_EQ(*resultStart.begin(), *expectStart.begin());
  auto resultEnd = resultStart.end();
  auto expectEnd = expectStart.end();
  --resultEnd, --expectEnd;
  ASSERT_EQ(*resultEnd, *expectEnd);
}

TEST(List, begin_end_4) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  ASSERT_EQ(*resultStart.begin(), *expectStart.begin());
  auto resultEnd = resultStart.end();
  auto expectEnd = expectStart.end();
  --resultEnd, --expectEnd;
  ASSERT_EQ(*resultEnd, *expectEnd);
}

TEST(List, empty_1) {
  custom::List<int> resultStart;
  std::list<int> expectStart;
  ASSERT_TRUE((resultStart.empty() == expectStart.empty()));
}

TEST(List, empty_2) {
  custom::List<int> resultStart(0);
  std::list<int> expectStart(0);
  ASSERT_TRUE((resultStart.empty() == expectStart.empty()));
}

TEST(List, empty_3) {
  std::initializer_list<int> n{4};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
}

TEST(List, empty_4) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
}

TEST(List, size_1) {
  custom::List<int> resultStart;
  std::list<int> expectStart;
  ASSERT_TRUE((resultStart.size() == expectStart.size()));
}

TEST(List, size_2) {
  custom::List<int> resultStart(0);
  std::list<int> expectStart(0);
  ASSERT_TRUE((resultStart.size() == expectStart.size()));
}

TEST(List, size_3) {
  std::initializer_list<int> n{4};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(List, size_4) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(List, max_size_1) {
  custom::List<int> resultStart;
  std::list<int> expectStart;
  ASSERT_TRUE((resultStart.max_size() == expectStart.max_size()));
}

TEST(List, max_size_2) {
  custom::List<int> resultStart(0);
  std::list<int> expectStart(0);
  ASSERT_TRUE((resultStart.max_size() == expectStart.max_size()));
}

TEST(List, max_size_3) {
  std::initializer_list<int> n{4};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, max_size_4) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  ASSERT_EQ(resultStart.max_size(), expectStart.max_size());
}

TEST(List, clear_1) {
  custom::List<int> resultStart;
  std::list<int> expectStart;
  resultStart.clear(), expectStart.clear();
  ASSERT_TRUE((resultStart.size() == expectStart.size()));
  ASSERT_TRUE((resultStart.begin() == resultStart.end()));
  ASSERT_TRUE((expectStart.begin() == expectStart.end()));
}

TEST(List, clear_2) {
  custom::List<int> resultStart(0);
  std::list<int> expectStart(0);
  resultStart.clear(), expectStart.clear();
  ASSERT_TRUE((resultStart.size() == expectStart.size()));
  ASSERT_TRUE((resultStart.begin() == resultStart.end()));
  ASSERT_TRUE((expectStart.begin() == expectStart.end()));
}

TEST(List, clear_3) {
  std::initializer_list<int> n{4};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  resultStart.clear(), expectStart.clear();
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_TRUE((resultStart.begin() == resultStart.end()));
  ASSERT_TRUE((expectStart.begin() == expectStart.end()));
}

TEST(List, clear_4) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::List<int> resultStart(n);
  std::list<int> expectStart(n);
  resultStart.clear(), expectStart.clear();
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_TRUE((resultStart.begin() == resultStart.end()));
  ASSERT_TRUE((expectStart.begin() == expectStart.end()));
}

TEST(List, push_back_1) {
  custom::List<int> result;
  std::list<int> expect;
  int value{10};
  int &val = value;
  result.push_back(val);
  expect.push_back(val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, push_back_2) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  int value{10};
  int &val = value;
  result.push_back(val);
  expect.push_back(val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, push_back_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  int value{10};
  int &val = value;
  result.push_back(val);
  expect.push_back(val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, swap_1) {
  std::initializer_list<int> n{};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(n);
  std::list<int> expect1(n);
  result.swap(result1);
  expect.swap(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, swap_2) {
  std::initializer_list<int> n{};
  std::initializer_list<int> m{5};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, swap_3) {
  std::initializer_list<int> n{5};
  std::initializer_list<int> m{};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, swap_4) {
  std::initializer_list<int> n{1};
  std::initializer_list<int> m{5};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, swap_5) {
  std::initializer_list<int> n{};
  std::initializer_list<int> m{5, 6, 7, 8, 9};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, swap_6) {
  std::initializer_list<int> n{5, 6, 7, 8, 9};
  std::initializer_list<int> m{};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, swap_7) {
  std::initializer_list<int> n{1, 2};
  std::initializer_list<int> m{5, 6, 7, 8, 9};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, swap_8) {
  std::initializer_list<int> m{1, 2};
  std::initializer_list<int> n{5, 6, 7, 8, 9};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, insert_1) {
  custom::List<int> result;
  std::list<int> expect;
  int value{10};
  int &val = value;
  auto posResult = result.begin();
  auto itResult = result.insert(posResult, val);
  auto itExpect = expect.insert(expect.begin(), val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(*itResult, *itExpect);
}

TEST(List, insert_2) {
  custom::List<int> result;
  std::list<int> expect;
  int value{10};
  int &val = value;
  auto posResult = result.end();
  auto itResult = result.insert(posResult, val);
  auto itExpect = expect.insert(expect.end(), val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(*itResult, *itExpect);
}

TEST(List, insert_3) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  int value{10};
  int &val = value;
  auto posResult = result.begin();
  auto itResult = result.insert(posResult, val);
  auto itExpect = expect.insert(expect.begin(), val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(*itResult, *itExpect);
}

TEST(List, insert_4) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  int value{10};
  int &val = value;
  auto posResult = result.end();
  auto itResult = result.insert(posResult, val);
  auto itExpect = expect.insert(expect.end(), val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(*itResult, *itExpect);
}

TEST(List, insert_5) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  int value{10};
  int &val = value;
  auto posResult = result.begin();
  auto itResult = result.insert(posResult, val);
  auto itExpect = expect.insert(expect.begin(), val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(*itResult, *itExpect);
}

TEST(List, insert_6) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  int value{10};
  int &val = value;
  auto posResult = result.end();
  auto itResult = result.insert(posResult, val);
  auto itExpect = expect.insert(expect.end(), val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(*itResult, *itExpect);
}

TEST(List, insert_7) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  int value{10};
  int &val = value;
  auto posResult = result.begin();
  ++posResult;
  ++posResult;
  auto itResult = result.insert(posResult, val);
  auto itExpect = expect.insert(++(++expect.begin()), val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(*itResult, *itExpect);
}

TEST(List, insert_8) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  int value{10};
  int &val = value;
  auto posResult = result.end();
  --posResult;
  --posResult;
  auto itResult = result.insert(posResult, val);
  auto itExpect = expect.insert(--(--expect.end()), val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(*itResult, *itExpect);
}

TEST(List, erase1_1) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  auto posResult = result.begin();
  result.erase(posResult);
  expect.erase(expect.begin());
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, erase_2) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  auto posResult = result.begin();
  result.erase(posResult);
  expect.erase(expect.begin());
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, erase_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  auto posResult = result.begin();
  ++posResult;
  ++posResult;
  result.erase(posResult);
  expect.erase(++(++expect.begin()));
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, erase_4) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  auto posResult = result.end();
  --posResult;
  --posResult;
  result.erase(posResult);
  expect.erase(--(--expect.end()));
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, push_front_1) {
  custom::List<int> result;
  std::list<int> expect;
  int value{10};
  int &val = value;
  result.push_front(val);
  expect.push_front(val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, push_front_2) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  int value{10};
  int &val = value;
  result.push_front(val);
  expect.push_front(val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, push_front_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  int value{10};
  int &val = value;
  result.push_front(val);
  expect.push_front(val);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, pop_front_1) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.pop_front();
  expect.pop_front();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, pop_front_2) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.pop_front();
  expect.pop_front();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, pop_back_1) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.pop_back();
  expect.pop_back();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, pop_back_2) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.pop_back();
  expect.pop_back();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, merge_1) {
  std::initializer_list<int> n{};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(n);
  std::list<int> expect1(n);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_2) {
  std::initializer_list<int> n{};
  std::initializer_list<int> m{5};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_3) {
  std::initializer_list<int> n{5};
  std::initializer_list<int> m{};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_4) {
  std::initializer_list<int> n{1};
  std::initializer_list<int> m{5};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_5) {
  std::initializer_list<int> n{};
  std::initializer_list<int> m{5, 6, 7, 8, 9};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_6) {
  std::initializer_list<int> n{5, 6, 7, 8, 9};
  std::initializer_list<int> m{};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_7) {
  std::initializer_list<int> n{1, 2};
  std::initializer_list<int> m{5, 6, 7, 8, 9};
  custom::List<int> result(n);  // 1 2
  std::list<int> expect(n);     // 1 2
  custom::List<int> result1(m); // 5 6 7 8 9
  std::list<int> expect1(m);    // 5 6 7 8 9
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_8) {
  std::initializer_list<int> m{1, 2};
  std::initializer_list<int> n{5, 6, 7, 8, 9};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_9) {
  std::initializer_list<int> n{1, 3, 5, 7, 9};
  std::initializer_list<int> m{2, 4, 6, 8, 10, 12};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_10) {
  std::initializer_list<int> m{1, 3, 5, 7, 9};
  std::initializer_list<int> n{2, 4, 6, 8, 10, 12};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_11) {
  std::initializer_list<int> n{1, 3, 3, 9, 9};
  std::initializer_list<int> m{2, 3, 6, 9, 10, 12};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_12) {
  std::initializer_list<int> m{1, 3, 3, 9, 9};
  std::initializer_list<int> n{2, 3, 6, 9, 10, 12};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_13) {
  std::initializer_list<int> n{1, 3, 8, 4, 9};
  std::initializer_list<int> m{2, 6, 10, 9, 3, 12};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, merge_14) {
  std::initializer_list<int> m{5, 3, 5, 9, 9};
  std::initializer_list<int> n{2, 3, 6, 3, 1, 12};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  result.merge(result1);
  expect.merge(expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareListInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(List, splice_1) {
  custom::List<int> result;
  std::list<int> expect;
  custom::List<int> result1;
  std::list<int> expect1;
  auto posResult = result.cbegin();
  result.splice(posResult, result1);
  expect.splice(expect.begin(), expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, splice_2) {
  custom::List<int> result;
  std::list<int> expect;
  custom::List<int> result1;
  std::list<int> expect1;
  auto posResult = result.cend();
  result.splice(posResult, result1);
  expect.splice(expect.end(), expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, splice_3) {
  std::initializer_list<int> n{0};
  std::initializer_list<int> m{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  auto posResult = result.cbegin();
  result.splice(posResult, result1);
  expect.splice(expect.begin(), expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, splice_4) {
  std::initializer_list<int> n{1};
  std::initializer_list<int> m{0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  auto posResult = result.cbegin();
  result.splice(posResult, result1);
  expect.splice(expect.begin(), expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, splice_5) {
  std::initializer_list<int> n{};
  std::initializer_list<int> m{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  auto posResult = result.cend();
  result.splice(posResult, result1);
  expect.splice(expect.end(), expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, splice_6) {
  std::initializer_list<int> n{1};
  std::initializer_list<int> m{0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  auto posResult = result.cend();
  result.splice(posResult, result1);
  expect.splice(expect.end(), expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, splice_7) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  std::initializer_list<int> m{1, 7, 12};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  auto posResult = result.cbegin();
  result.splice(posResult, result1);
  expect.splice(expect.begin(), expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, splice_8) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  std::initializer_list<int> m{1, 7, 12};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  auto posResult = result.cend();
  result.splice(posResult, result1);
  expect.splice(expect.end(), expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, splice_9) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  std::initializer_list<int> m{1, 7, 12};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  auto posResult = result.cbegin();
  ++posResult;
  ++posResult;
  result.splice(posResult, result1);
  expect.splice(++(++expect.begin()), expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, splice_10) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  std::initializer_list<int> m{1, 7, 12};
  custom::List<int> result(n);
  std::list<int> expect(n);
  custom::List<int> result1(m);
  std::list<int> expect1(m);
  auto posResult = result.cend();
  --posResult;
  --posResult;
  result.splice(posResult, result1);
  expect.splice(--(--expect.end()), expect1);
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, reverse_1) {
  custom::List<int> result;
  std::list<int> expect;
  result.reverse();
  expect.reverse();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, reverse_2) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.reverse();
  expect.reverse();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, reverse_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.reverse();
  expect.reverse();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, unique_1) {
  custom::List<int> result;
  std::list<int> expect;
  result.unique();
  expect.unique();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, unique_2) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.unique();
  expect.unique();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, unique_3) {
  std::initializer_list<int> n{1, 2, 3, 2, 5, 6, 2, 8, 8, 8};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.unique();
  expect.unique();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, unique_4) {
  std::initializer_list<int> n{1, 2, 2, 2, 5, 6, 2, 8, 8, 8};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.unique();
  expect.unique();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, sort_1) {
  custom::List<int> result;
  std::list<int> expect;
  result.sort();
  expect.sort();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, sort_2) {
  std::initializer_list<int> n{1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.sort();
  expect.sort();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, sort_3) {
  std::initializer_list<int> n{1, 2, 3, 2, 5, 6, 2, 8, 8, 8};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.sort();
  expect.sort();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, sort_4) {
  std::initializer_list<int> n{1, 2, 2, 2, 5, 6, 2, 8, 8, 8};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.sort();
  expect.sort();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, sort_5) {
  std::initializer_list<int> n{9, 2, 5, 3, 4, 8, 7, 6, 9, 1};
  custom::List<int> result(n);
  std::list<int> expect(n);
  result.sort();
  expect.sort();
  CompareListInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(List, default_constructor) {
  custom::List<int> s21list;
  std::list<int> stdlist;
  ASSERT_EQ(s21list.empty(), stdlist.empty());
  ASSERT_EQ(s21list.size(), stdlist.size());
}

TEST(List, size_constructor) {
  custom::List<int> s21list(5);
  std::list<int> stdlist(5);
  custom::List<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, init_constructor) {
  custom::List<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  custom::List<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, init_char_constructor) {
  custom::List<char> s21list{'a', 'b', 'c'};
  std::list<char> stdlist{'a', 'b', 'c'};
  custom::List<char>::iterator s21it = s21list.begin();
  std::list<char>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, init_string_constructor) {
  custom::List<std::string> s21list{"just", "string", "constructor"};
  std::list<std::string> stdlist{"just", "string", "constructor"};
  custom::List<std::string>::iterator s21it = s21list.begin();
  std::list<std::string>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, copy_constructor) {
  custom::List<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  custom::List<int> s21list2(s21list);
  std::list<int> stdlist2(stdlist);
  custom::List<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, move_constructor) {
  custom::List<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  custom::List<int> s21list2(std::move(s21list));
  std::list<int> stdlist2(std::move(stdlist));
  custom::List<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, move_operator_constructor) {
  custom::List<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  custom::List<int> s21list2 = std::move(s21list);
  std::list<int> stdlist2 = std::move(stdlist);
  custom::List<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, front_back) {
  custom::List<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(77);
  s21list.push_back(66);
  s21list.push_back(11111);
  stdlist.push_front(77);
  stdlist.push_back(66);
  stdlist.push_back(11111);
  ASSERT_EQ(s21list.front(), stdlist.front());
  ASSERT_EQ(s21list.back(), stdlist.back());
}

TEST(List, empty_clear) {
  custom::List<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(77);
  s21list.push_back(66);
  s21list.push_back(11111);
  stdlist.push_front(77);
  stdlist.push_back(66);
  stdlist.push_back(11111);
  s21list.clear();
  stdlist.clear();
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list.empty(), stdlist.empty());
}

TEST(List, push) {
  custom::List<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(77);
  s21list.push_back(66);
  s21list.push_back(11111);
  stdlist.push_front(77);
  stdlist.push_back(66);
  stdlist.push_back(11111);
  custom::List<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, pop) {
  custom::List<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  s21list.pop_back();
  stdlist.pop_back();
  ASSERT_EQ(s21list.front(), stdlist.front());
  ASSERT_EQ(s21list.back(), stdlist.back());
  s21list.pop_front();
  stdlist.pop_front();
  custom::List<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  s21list.clear();
  stdlist.clear();
  ASSERT_EQ(s21list.empty(), stdlist.empty());
}

TEST(List, insert) {
  custom::List<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  custom::List<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.insert(s21it, 77);
  stdlist.insert(stdit, 77);
  s21it = s21list.end();
  stdit = stdlist.end();
  s21list.insert(s21it, 66);
  stdlist.insert(stdit, 66);
  ASSERT_EQ(s21list.front(), stdlist.front());
  ++s21it;
  ++stdit;
  s21list.insert(s21it, 1111);
  stdlist.insert(stdit, 1111);
  ASSERT_EQ(s21list.size(), stdlist.size());
  CompareListInt(s21list, stdlist);
}

TEST(List, erase) {
  custom::List<int> s21list{77, 55, 0, 87};
  std::list<int> stdlist{77, 55, 0, 87};
  custom::List<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.erase(s21it);
  stdlist.erase(stdit);
  ASSERT_EQ(s21list.front(), stdlist.front());
  s21it = s21list.begin();
  stdit = stdlist.begin();
  ++s21it;
  ++stdit;
  s21list.erase(s21it);
  stdlist.erase(stdit);
  s21it = s21list.begin();
  stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, swap) {
  custom::List<int> s21list{77, 55, 0, 87, 1111};
  custom::List<int> s21list2{5, 3};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  std::list<int> stdlist2{5, 3};
  s21list.swap(s21list2);
  stdlist.swap(stdlist2);
  custom::List<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, merge) {
  custom::List<int> s21list{77, 55, 0, 87, 1111};
  custom::List<int> s21list2{5, 3};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  std::list<int> stdlist2{5, 3};
  stdlist.sort();
  s21list.sort();
  s21list.merge(s21list2);
  stdlist.merge(stdlist2);
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  CompareListInt(s21list, stdlist);
  ASSERT_EQ(s21list2.empty(), stdlist2.empty());
}

TEST(List, splice) {
  custom::List<int> s21list{77, 55, 0, 87, 1111};
  custom::List<int> s21list2{5, 3};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  std::list<int> stdlist2{5, 3};
  custom::List<int>::const_iterator s21it = s21list.cbegin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.splice(s21it, s21list2);
  stdlist.splice(stdit, stdlist2);
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  CompareListInt(s21list, stdlist);
  ASSERT_EQ(s21list2.empty(), stdlist2.empty());
}

TEST(List, reverse) {
  custom::List<int> s21list{77, 55, 0, 87, 1111};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  s21list.reverse();
  stdlist.reverse();
  custom::List<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, unique) {
  custom::List<int> s21list{1, 1, 1, 1, 222, 222, 2, 33, 3, 3};
  std::list<int> stdlist{1, 1, 1, 1, 222, 222, 2, 33, 3, 3};
  s21list.unique();
  stdlist.unique();
  custom::List<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, sort) {
  custom::List<double> s21lone{7.19};
  s21lone.sort();
  custom::List<int> s21list{77, 55, 0, 87, 1111};
  std::list<int> stdlist{77, 55, 0, 87, 1111};
  s21list.sort();
  stdlist.sort();
  custom::List<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(List, iterator) {
  custom::List<int> s21list{77, 55, 0, 87, 1111};
  custom::List<int>::iterator begin = s21list.begin();
  custom::List<int>::iterator begin1 = begin;
  ASSERT_TRUE(begin == begin1);
  ASSERT_FALSE(begin != begin1);
}

TEST(List, emplace) {
  custom::List<int> s21list{6, 7, 9};
  custom::List<int> s21res_list{6, 7, 1, 2, 8, 9};
  custom::List<int>::const_iterator s21it = s21list.cbegin();
  ++s21it;
  ++s21it;
  s21list.emplace(s21it, 1, 2, 8);
  custom::List<int>::iterator it_i = s21list.begin();
  custom::List<int>::iterator it_j = s21res_list.begin();
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*it_i, *it_j);
    ++it_i;
    ++it_j;
  }
}

TEST(List, emplace_front) {
  custom::List<int> s21list{6, 7, 9};
  custom::List<int> s21res_list{1, 2, 8, 6, 7, 9};
  s21list.emplace_front(1, 2, 8);
  custom::List<int>::iterator it_i = s21list.begin();
  custom::List<int>::iterator it_j = s21res_list.begin();
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*it_i, *it_j);
    ++it_i;
    ++it_j;
  }
}

TEST(List, emplace_back) {
  custom::List<int> s21list{6, 7, 9};
  custom::List<int> s21res_list{6, 7, 9, 1, 2, 8};
  s21list.emplace_back(1, 2, 8);
  custom::List<int>::iterator it_i = s21list.begin();
  custom::List<int>::iterator it_j = s21res_list.begin();
  for (auto i = s21list.begin(); i != s21list.end(); ++i) {
    ASSERT_EQ(*it_i, *it_j);
    ++it_i;
    ++it_j;
  }
}

TEST(List, throw_iterator) {
  custom::List<int> s21list{};
  custom::List<int>::iterator it = s21list.begin();
  EXPECT_ANY_THROW(s21list.erase(it));
}

TEST(List, emplace_1) {
  custom::List<int> result;
  auto it = result.cbegin();
  result.emplace(it, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  int i = 1;
  for (it = result.cbegin(); it != result.cend(); ++it) {
    ASSERT_EQ(*it, i);
    ++i;
  }
}

TEST(List, emplace_back_1) {
  custom::List<int> result;
  result.emplace_back(1, 2, 3, 4, 5, 6, 7, 8, 9);
  int i = 1;
  for (auto it = result.begin(); it != result.end(); ++it) {
    ASSERT_EQ(*it, i);
    ++i;
  }
}

TEST(List, emplace_front_1) {
  custom::List<int> result;
  result.emplace_front(1, 2, 3, 4, 5, 6, 7, 8, 9);
  int i = 1;
  for (auto it = result.begin(); it != result.end(); ++it) {
    ASSERT_EQ(*it, i);
    ++i;
  }
}