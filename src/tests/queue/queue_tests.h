#include <gtest/gtest.h>

#include <queue>

#include "../../sequence_containers/queue/custom_queue.h"

void CompareQueueInt(custom::Queue<int> result, std::queue<int> expect) {
  auto size_result = result.size();
  auto size_expect = expect.size();
  if (size_result == size_expect) {
    while (result.size()) {
      ASSERT_EQ(result.front(), expect.front());
      result.pop();
      expect.pop();
    }
  } else {
    ADD_FAILURE();
  }
}

TEST(Queue, constructor_default_1) {
  custom::Queue<int> result;
  std::queue<int> expect;
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Queue, constructor_initlist_2) {
  std::initializer_list<int> n{};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(result, expect);
}

TEST(Queue, constructor_initlist_3) {
  std::initializer_list<int> n{1};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Queue, constructor_initlist_4) {
  std::initializer_list<int> n{1, 2};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Queue, constructor_initlist_5) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(result, expect);
}

TEST(Queue, constructor_copy_6) {
  std::initializer_list<int> n{};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  custom::Queue<int> result(resultStart);
  std::queue<int> expect(expectStart);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, constructor_copy_7) {
  std::initializer_list<int> n{1};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  custom::Queue<int> result(resultStart);
  std::queue<int> expect(expectStart);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, constructor_copy_8) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  custom::Queue<int> result(resultStart);
  std::queue<int> expect(expectStart);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
  ASSERT_EQ(result.front(), expect.front());
  ASSERT_EQ(result.back(), expect.back());
}

TEST(Queue, constructor_move_9) {
  std::initializer_list<int> n{};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  custom::Queue<int> result(std::move(resultStart));
  std::queue<int> expect(std::move(expectStart));
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, constructor_move_10) {
  std::initializer_list<int> n{1};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  custom::Queue<int> result(std::move(resultStart));
  std::queue<int> expect(std::move(expectStart));
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, constructor_move_11) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  custom::Queue<int> result(std::move(resultStart));
  std::queue<int> expect(std::move(expectStart));
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, operator_move_1) {
  std::initializer_list<int> n{};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  custom::Queue<int> result = std::move(resultStart);
  std::queue<int> expect = std::move(expectStart);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, operator_move_2) {
  std::initializer_list<int> n{1};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  custom::Queue<int> result = std::move(resultStart);
  std::queue<int> expect = std::move(expectStart);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, operator_move_4) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  std::initializer_list<int> n1{1, 2, 3, 4, 5};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  custom::Queue<int> result(n1);
  std::queue<int> expect(n1);
  result = std::move(resultStart);
  expect = std::move(expectStart);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, operator_move_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  custom::Queue<int> result;
  std::queue<int> expect;
  result = std::move(resultStart);
  expect = std::move(expectStart);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(resultStart, expectStart);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, front_back_1) {
  std::initializer_list<int> n{1};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  ASSERT_EQ(resultStart.front(), expectStart.front());
  ASSERT_EQ(resultStart.back(), expectStart.back());
}

TEST(Queue, front_back_2) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  ASSERT_EQ(resultStart.front(), expectStart.front());
  ASSERT_EQ(resultStart.back(), expectStart.back());
}

TEST(Queue, empty_1) {
  custom::Queue<int> resultStart;
  std::queue<int> expectStart;
  ASSERT_TRUE((resultStart.empty() == expectStart.empty()));
}

TEST(Queue, empty_2) {
  std::initializer_list<int> n{4};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
}

TEST(Queue, empty_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  ASSERT_EQ(resultStart.empty(), expectStart.empty());
}

TEST(Queue, size_1) {
  custom::Queue<int> resultStart;
  std::queue<int> expectStart;
  ASSERT_TRUE((resultStart.size() == expectStart.size()));
}

TEST(Queue, size_2) {
  std::initializer_list<int> n{4};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, size_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5};
  custom::Queue<int> resultStart(n);
  std::queue<int> expectStart(n);
  ASSERT_EQ(resultStart.size(), expectStart.size());
}

TEST(Queue, push_1) {
  custom::Queue<int> result;
  std::queue<int> expect;
  int value{10};
  int &val = value;
  result.push(val);
  expect.push(val);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Queue, push_2) {
  std::initializer_list<int> n{1};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  int value{10};
  int &val = value;
  result.push(val);
  expect.push(val);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Queue, push_3) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  int value{10};
  int &val = value;
  result.push(val);
  expect.push(val);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Queue, pop_1) {
  std::initializer_list<int> n{1};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  result.pop();
  expect.pop();
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Queue, pop_2) {
  std::initializer_list<int> n{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  result.pop();
  expect.pop();
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
}

TEST(Queue, swap_1) {
  std::initializer_list<int> n{};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  custom::Queue<int> result1(n);
  std::queue<int> expect1(n);
  result.swap(result1);
  expect.swap(expect1);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Queue, swap_2) {
  std::initializer_list<int> n{};
  std::initializer_list<int> m{5};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  custom::Queue<int> result1(m);
  std::queue<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Queue, swap_3) {
  std::initializer_list<int> n{5};
  std::initializer_list<int> m{};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  custom::Queue<int> result1(m);
  std::queue<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Queue, swap_4) {
  std::initializer_list<int> n{1};
  std::initializer_list<int> m{5};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  custom::Queue<int> result1(m);
  std::queue<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Queue, swap_5) {
  std::initializer_list<int> n{};
  std::initializer_list<int> m{5, 6, 7, 8, 9};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  custom::Queue<int> result1(m);
  std::queue<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Queue, swap_6) {
  std::initializer_list<int> n{5, 6, 7, 8, 9};
  std::initializer_list<int> m{};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  custom::Queue<int> result1(m);
  std::queue<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Queue, swap_7) {
  std::initializer_list<int> n{1, 2};
  std::initializer_list<int> m{5, 6, 7, 8, 9};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  custom::Queue<int> result1(m);
  std::queue<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Queue, swap_8) {
  std::initializer_list<int> m{1, 2};
  std::initializer_list<int> n{5, 6, 7, 8, 9};
  custom::Queue<int> result(n);
  std::queue<int> expect(n);
  custom::Queue<int> result1(m);
  std::queue<int> expect1(m);
  result.swap(result1);
  expect.swap(expect1);
  CompareQueueInt(result, expect);
  ASSERT_EQ(result.empty(), expect.empty());
  ASSERT_EQ(result.size(), expect.size());
  CompareQueueInt(result1, expect1);
  ASSERT_EQ(result1.empty(), expect1.empty());
  ASSERT_EQ(result1.size(), expect1.size());
}

TEST(Queue, emplace_1) {
  custom::List<int> result;
  auto it = result.cbegin();
  result.emplace(it, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  int i = 1;
  for (it = result.cbegin(); it != result.cend(); ++it) {
    ASSERT_EQ(*it, i);
    ++i;
  }
}

TEST(Queue, emplace_back_1) {
  custom::List<int> result;
  result.emplace_back(1, 2, 3, 4, 5, 6, 7, 8, 9);
  int i = 1;
  for (auto it = result.begin(); it != result.end(); ++it) {
    ASSERT_EQ(*it, i);
    ++i;
  }
}

TEST(Queue, emplace_front_1) {
  custom::List<int> result;
  result.emplace_front(1, 2, 3, 4, 5, 6, 7, 8, 9);
  int i = 1;
  for (auto it = result.begin(); it != result.end(); ++it) {
    ASSERT_EQ(*it, i);
    ++i;
  }
}

TEST(Queue, emplace_back_3) {
  std::initializer_list<int> n{1, 2};
  custom::Queue<int> result(n);
  result.emplace_back(3, 4, 5, 6, 7);
  ASSERT_EQ(result.size(), 7);
  ASSERT_EQ(result.front(), 1);
  ASSERT_EQ(result.back(), 7);
}

TEST(Queue, emplace_back_2) {
  custom::Queue<int> result;
  ASSERT_EQ(result.size(), 0);
  result.emplace_back(3, 4, 5, 6, 7);
  ASSERT_EQ(result.size(), 5);
  ASSERT_EQ(result.front(), 3);
  ASSERT_EQ(result.back(), 7);
  result.pop();
  result.pop();
  ASSERT_EQ(result.size(), 3);
  ASSERT_EQ(result.front(), 5);
  ASSERT_EQ(result.back(), 7);
  result.emplace_back(8, 9, 10, 11, 12, 13, 14, 15, 16);
  ASSERT_EQ(result.size(), 12);
  ASSERT_EQ(result.front(), 5);
  ASSERT_EQ(result.back(), 16);
}

TEST(Queue, test1) {
  custom::Queue<int> my_queue;
  std::queue<int> lib_queue;
  my_queue.push(3);
  my_queue.push(5);
  lib_queue.push(3);
  lib_queue.push(5);
  ASSERT_EQ(lib_queue.front(), my_queue.front());
  ASSERT_EQ(lib_queue.back(), my_queue.back());
  ASSERT_EQ(lib_queue.size(), my_queue.size());
}

TEST(Queue, test2) {
  custom::Queue<int> my_queue({1, 2, 3, 4});
  std::queue<int> lib_queue({1, 2, 3, 4});
  ASSERT_EQ(lib_queue.front(), my_queue.front());
  ASSERT_EQ(lib_queue.back(), my_queue.back());
  lib_queue.pop();
  my_queue.pop();
  ASSERT_EQ(lib_queue.front(), my_queue.front());
  ASSERT_EQ(lib_queue.back(), my_queue.back());
  lib_queue.pop();
  my_queue.pop();
  ASSERT_EQ(3, my_queue.front());
  ASSERT_EQ(3, lib_queue.front());
  ASSERT_EQ(4, my_queue.back());
  ASSERT_EQ(4, lib_queue.back());
}

TEST(Queue, test3) {
  custom::Queue<int> test_queue;
  test_queue.push(500);
  test_queue.push(1000);
  std::queue<int> test_queue1;
  test_queue1.push(500);
  test_queue1.push(1000);
  custom::Queue<int> my_queue(test_queue);
  std::queue<int> lib_queue(test_queue1);
  ASSERT_EQ(lib_queue.size(), my_queue.size());
  ASSERT_EQ(lib_queue.front(), my_queue.front());
  ASSERT_EQ(lib_queue.back(), my_queue.back());
}

TEST(Queue, test4) {
  custom::Queue<int> test_queue;
  test_queue.push(500);
  test_queue.push(1000);
  std::queue<int> test_queue1;
  test_queue1.push(500);
  test_queue1.push(1000);
  custom::Queue<int> my_queue = std::move(test_queue);
  std::queue<int> lib_queue = std::move(test_queue1);
  ASSERT_EQ(lib_queue.size(), my_queue.size());
  ASSERT_EQ(lib_queue.front(), my_queue.front());
  ASSERT_EQ(lib_queue.back(), my_queue.back());
  ASSERT_EQ(0, test_queue.size());
  ASSERT_EQ(0, test_queue1.size());
}

TEST(Queue, test5) {
  custom::Queue<int> my_queue({1, 2, 3, 4});
  std::queue<int> lib_queue({1, 2, 3, 4});
  custom::Queue<int> to_swap({15, 125, 20});
  std::queue<int> to_swap1({15, 125, 20});
  my_queue.swap(to_swap);
  lib_queue.swap(to_swap1);
  ASSERT_EQ(3, my_queue.size());
  ASSERT_EQ(3, lib_queue.size());
  ASSERT_EQ(15, my_queue.front());
  ASSERT_EQ(15, lib_queue.front());
  ASSERT_EQ(4, to_swap.size());
  ASSERT_EQ(4, to_swap1.size());
  ASSERT_EQ(4, to_swap.back());
  ASSERT_EQ(4, to_swap1.back());
}

TEST(Queue, emplace_back) {
  custom::Queue<int> my_queue{6, 7, 9};
  custom::Queue<int> res_queue{6, 7, 9, 1, 2, 8};
  my_queue.emplace_back(1, 2, 8);
  for (size_t i = 0; i <= res_queue.size(); i++) {
    ASSERT_EQ(my_queue.back(), res_queue.back());
    my_queue.pop();
    res_queue.pop();
  }
}