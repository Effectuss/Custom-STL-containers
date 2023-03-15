#include <gtest/gtest.h>

#include <stack>

#include "../../sequence_containers/stack/custom_stack.h"

void CompareStackInt(custom::Stack<int> &result, std::stack<int> &expect) {
  auto size_result = result.size();
  auto size_expect = expect.size();
  if (size_result == size_expect) {
    while (result.size()) {
      ASSERT_EQ(result.top(), expect.top());
      expect.pop();
      result.pop();
    }
  } else {
    ADD_FAILURE();
  }
}

TEST(Stack, constructor_default_1) {
  custom::Stack<int> result;
  std::stack<int> expect;
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Stack, constructor_initlist_2) {
  std::initializer_list<int> n{};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Stack, constructor_initlist_3) {
  std::initializer_list<int> n{1};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Stack, constructor_initlist_4) {
  std::initializer_list<int> n{1, 2};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Stack, constructor_initlist_5) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Stack, constructor_copy_6) {
  std::initializer_list<int> n{};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  custom::Stack<int> result(resultStart);
  std::stack<int> expect(expectStart);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, constructor_copy_7) {
  std::initializer_list<int> n{1};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  custom::Stack<int> result(resultStart);
  std::stack<int> expect(expectStart);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, constructor_copy_8) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  custom::Stack<int> result(resultStart);
  std::stack<int> expect(expectStart);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, constructor_move_9) {
  std::initializer_list<int> n{};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  custom::Stack<int> result(std::move(resultStart));
  std::stack<int> expect(std::move(expectStart));
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, constructor_move_10) {
  std::initializer_list<int> n{1};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  custom::Stack<int> result(std::move(resultStart));
  std::stack<int> expect(std::move(expectStart));
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, constructor_move_11) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  custom::Stack<int> result(std::move(resultStart));
  std::stack<int> expect(std::move(expectStart));
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, opertor_move_1) {
  std::initializer_list<int> n{};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  custom::Stack<int> result;
  std::stack<int> expect;
  result = std::move(resultStart);
  expect = std::move(expectStart);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, opertor_move_2) {
  std::initializer_list<int> n{1};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  custom::Stack<int> result;
  std::stack<int> expect;
  result = std::move(resultStart);
  expect = std::move(expectStart);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, opertor_move_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  custom::Stack<int> result;
  std::stack<int> expect;
  result = std::move(resultStart);
  expect = std::move(expectStart);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, top_1) {
  std::initializer_list<int> n{1};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  ASSERT_EQ(resultStart.top(), expectStart.top());
}

TEST(Stack, top_2) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  ASSERT_EQ(resultStart.top(), expectStart.top());
}

TEST(Stack, empty_1) {
  custom::Stack<int> resultStart;
  std::stack<int> expectStart;
  ASSERT_TRUE((resultStart.empty() == expectStart.empty()));
}

TEST(Stack, empty_2) {
  std::initializer_list<int> n{4};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
}

TEST(Stack, empty_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
}

TEST(Stack, size_1) {
  custom::Stack<int> resultStart;
  std::stack<int> expectStart;
  ASSERT_TRUE((resultStart.size() == expectStart.size()));
}

TEST(Stack, size_2) {
  std::initializer_list<int> n{4};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, size_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, size_4) {
  std::initializer_list<int> n{};
  custom::Stack<int> resultStart(n);
  std::stack<int> expectStart(n);
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Stack, push_1) {
  custom::Stack<int> result;
  std::stack<int> expect;
  int value{10};
  int &val = value;
  result.push(val);
  expect.push(val);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Stack, push_2) {
  std::initializer_list<int> n{1};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  int value{10};
  int &val = value;
  result.push(val);
  expect.push(val);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Stack, push_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  int value{10};
  int &val = value;
  result.push(val);
  expect.push(val);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Stack, pop_1) {
  std::initializer_list<int> n{1};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  result.pop();
  expect.pop();
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Stack, pop_2) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  result.pop();
  expect.pop();
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Stack, swap_1) {
  std::initializer_list<int> n{};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  custom::Stack<int> result1(n);
  std::stack<int> expect1(n);
  result.swap(result1);
  expect.swap(expect1);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Stack, swap_2) {
  std::initializer_list<int> n{};
  std::initializer_list<int> m{5};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  custom::Stack<int> result1(m);
  std::stack<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Stack, swap_3) {
  std::initializer_list<int> n{5};
  std::initializer_list<int> m{};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  custom::Stack<int> result1(m);
  std::stack<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Stack, swap_4) {
  std::initializer_list<int> n{1};
  std::initializer_list<int> m{5};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  custom::Stack<int> result1(m);
  std::stack<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Stack, swap_5) {
  std::initializer_list<int> n{};
  std::initializer_list<int> m{5, 6, 7, 8, 9};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  custom::Stack<int> result1(m);
  std::stack<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Stack, swap_6) {
  std::initializer_list<int> n{5, 6, 7, 8, 9};
  std::initializer_list<int> m{};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  custom::Stack<int> result1(m);
  std::stack<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Stack, swap_7) {
  std::initializer_list<int> n{1, 2};
  std::initializer_list<int> m{5, 6, 7, 8, 9};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  custom::Stack<int> result1(m);
  std::stack<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Stack, swap_8) {
  std::initializer_list<int> m{1, 2};
  std::initializer_list<int> n{5, 6, 7, 8, 9};
  custom::Stack<int> result(n);
  std::stack<int> expect(n);
  custom::Stack<int> result1(m);
  std::stack<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareStackInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareStackInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Stack, test1) {
  custom::Stack<int> my_stack;
  std::stack<int> lib_stack;
  my_stack.push(3);
  my_stack.push(5);
  lib_stack.push(3);
  lib_stack.push(5);
  ASSERT_EQ(lib_stack.top(), my_stack.top());
  ASSERT_EQ(lib_stack.size(), my_stack.size());
}

TEST(Stack, test2) {
  custom::Stack<int> my_stack({1, 2, 3, 4});
  std::stack<int> lib_stack({1, 2, 3, 4});
  ASSERT_EQ(lib_stack.size(), my_stack.size());
  ASSERT_EQ(lib_stack.top(), my_stack.top());
  lib_stack.pop();
  my_stack.pop();
  ASSERT_EQ(lib_stack.top(), my_stack.top());
  lib_stack.pop();
  my_stack.pop();
  ASSERT_EQ(2, my_stack.top());
  ASSERT_EQ(2, lib_stack.top());
}

TEST(Stack, test3) {
  custom::Stack<int> test_stack;
  test_stack.push(500);
  test_stack.push(1000);
  std::stack<int> test_stack1;
  test_stack1.push(500);
  test_stack1.push(1000);
  custom::Stack<int> my_stack(test_stack);
  std::stack<int> lib_stack(test_stack1);
  ASSERT_EQ(lib_stack.size(), my_stack.size());
  ASSERT_EQ(lib_stack.top(), my_stack.top());
}

TEST(Stack, test4) {
  custom::Stack<int> test_stack;
  test_stack.push(500);
  test_stack.push(1000);
  std::stack<int> test_stack1;
  test_stack1.push(500);
  test_stack1.push(1000);
  custom::Stack<int> my_stack = std::move(test_stack);
  std::stack<int> lib_stack = std::move(test_stack1);
  ASSERT_EQ(lib_stack.size(), my_stack.size());
  ASSERT_EQ(lib_stack.top(), my_stack.top());
  ASSERT_EQ(0, test_stack.size());
  ASSERT_EQ(0, test_stack1.size());
}

TEST(Stack, test5) {
  custom::Stack<int> my_stack({1, 2, 3, 4});
  std::stack<int> lib_stack({1, 2, 3, 4});
  custom::Stack<int> to_swap({15, 125, 20});
  std::stack<int> to_swap1({15, 125, 20});
  my_stack.swap(to_swap);
  lib_stack.swap(to_swap1);
  ASSERT_EQ(3, my_stack.size());
  ASSERT_EQ(3, lib_stack.size());
  ASSERT_EQ(20, my_stack.top());
  ASSERT_EQ(20, lib_stack.top());
  ASSERT_EQ(4, to_swap.size());
  ASSERT_EQ(4, to_swap1.size());
  ASSERT_EQ(4, to_swap.top());
  ASSERT_EQ(4, to_swap1.top());
}

TEST(Stack, emplace_front) {
  custom::Stack<int> my_stack{6, 7, 9};
  custom::Stack<int> res_stack{6, 7, 9, 1, 2, 8};
  my_stack.emplace_front(1, 2, 8);
  size_t stack_size = res_stack.size();
  for (size_t i = 0; i < stack_size; i++) {
    ASSERT_EQ(my_stack.top(), res_stack.top());
    my_stack.pop();
    res_stack.pop();
  }
}

TEST(Stack, emplace_front_1) {
  std::initializer_list<int> m{1, 2, 3, 4, 5, 6, 7};
  std::initializer_list<int> n{1, 2};
  std::stack<int> expect(m);
  custom::Stack<int> result(n);
  result.emplace_front(3, 4, 5, 6, 7);
  ASSERT_EQ(result.size(), 7);
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(result.top(), 7);
  ASSERT_EQ(result.top(), expect.top());
  CompareStackInt(result, expect);
}

TEST(Stack, emplace_front_2) {
  custom::Stack<int> result;
  ASSERT_EQ(result.size(), 0);
  result.emplace_front(3, 4, 5, 6, 7);
  ASSERT_EQ(result.size(), 5);
  ASSERT_EQ(result.top(), 7);
  result.pop();
  result.pop();
  ASSERT_EQ(result.size(), 3);
  ASSERT_EQ(result.top(), 5);
  result.emplace_front(8, 9, 10, 11, 12, 13, 14, 15, 16);
  ASSERT_EQ(result.size(), 12);
  ASSERT_EQ(result.top(), 16);
}