#include <gtest/gtest.h>

#include <map>
#include <string>

#include "../../associative_containers/map/custom_map.h"

template <class Key, class T>
void CompareMaps(const std::map<Key, T> &map1, const std::map<Key, T> &map2) {
  ASSERT_EQ(map1.size(), map2.size());
  ASSERT_EQ(map1.max_size(), map2.max_size());
  auto i1 = map1.begin();
  auto i2 = map2.begin();
  while (i1 != map1.end() && i2 != map2.end()) {
    ASSERT_EQ((*i1).first, (*i2).first);
    ASSERT_EQ((*i1).second, (*i2).second);
    ++i1;
    ++i2;
  }
  ASSERT_EQ(i1, map1.end());
  ASSERT_EQ(i2, map2.end());
}

template <class Key, class T>
void CompareMaps(const std::map<Key, T> &map1,
                 const custom::Map<Key, T> &map2) {
  ASSERT_EQ(map1.size(), map2.size());
  ASSERT_EQ(map1.max_size(), map2.max_size());
  auto i1 = map1.begin();
  auto i2 = map2.begin();
  while (i1 != map1.end() && i2 != map2.end()) {
    ASSERT_EQ((*i1).first, (*i2).first);
    ASSERT_EQ((*i1).second, (*i2).second);
    ++i1;
    ++i2;
  }
  ASSERT_EQ(i1, map1.end());
  ASSERT_EQ(i2, map2.end());
}

template <class Key, class T>
void CompareMaps(const custom::Map<Key, T> &map1,
                 const std::map<Key, T> &map2) {
  ASSERT_EQ(map1.size(), map2.size());
  ASSERT_EQ(map1.max_size(), map2.max_size());
  auto i1 = map1.begin();
  auto i2 = map2.begin();
  while (i1 != map1.end() && i2 != map2.end()) {
    ASSERT_EQ((*i1).first, (*i2).first);
    ASSERT_EQ((*i1).second, (*i2).second);
    ++i1;
    ++i2;
  }
  ASSERT_EQ(i1, map1.end());
  ASSERT_EQ(i2, map2.end());
}

template <class Key, class T>
void CompareMaps(const custom::Map<Key, T> &map1,
                 const custom::Map<Key, T> &map2) {
  ASSERT_EQ(map1.size(), map2.size());
  ASSERT_EQ(map1.max_size(), map2.max_size());
  auto i1 = map1.begin();
  auto i2 = map2.begin();
  while (i1 != map1.end() && i2 != map2.end()) {
    ASSERT_EQ((*i1).first, (*i2).first);
    ASSERT_EQ((*i1).second, (*i2).second);
    ++i1;
    ++i2;
  }
  ASSERT_EQ(i1, map1.end());
  ASSERT_EQ(i2, map2.end());
}

TEST(Map, default_constructor) {
  std::map<int, int> std_map;
  custom::Map<int, int> s21_map;
  CompareMaps(std_map, s21_map);
}

TEST(Map, initializer_list_constructor) {
  std::map<int, int> std_map1{};
  custom::Map<int, int> s21_map1{};
  CompareMaps(s21_map1, std_map1);

  std::map<std::string, std::string> std_map2{
      {"train", "поезд"}, {"water", "вода"}, {"cup", "кружка"}};
  custom::Map<std::string, std::string> s21_map2{
      {"train", "поезд"}, {"water", "вода"}, {"cup", "кружка"}};
  CompareMaps(s21_map2, std_map2);
}

TEST(Map, copy_constructor) {
  std::map<int, int> std_map1{{1, 1}, {1, 2}, {2, 2}}, std_map2(std_map1);
  custom::Map<int, int> s21_map1{{1, 1}, {1, 2}, {2, 2}}, s21_map2(s21_map1);
  CompareMaps(s21_map2, std_map2);
  CompareMaps(s21_map2, s21_map1);
}

TEST(Map, move_constructor) {
  std::map<int, int> std_map1{{1, 2}, {2, 3}, {3, 4}},
      std_map2(std::move(std_map1));
  custom::Map<int, int> s21_map1{{1, 2}, {2, 3}, {3, 4}},
      s21_map2(std::move(s21_map1));
  CompareMaps(s21_map2, std_map2);
}

TEST(Map, operator_equal_copy) {
  std::map<char, char> std_map1{{'a', 'b'}, {'b', 'c'}}, std_map2;
  custom::Map<char, char> s21_map1{{'a', 'b'}, {'b', 'c'}}, s21_map2;
  std_map2 = std_map1;
  s21_map2 = s21_map1;
  CompareMaps(s21_map2, s21_map1);
  CompareMaps(s21_map2, std_map2);
}

TEST(Map, operator_equal_move) {
  std::map<char, char> std_map1{{'a', 'b'}, {'b', 'c'}}, std_map2;
  custom::Map<char, char> s21_map1{{'a', 'b'}, {'b', 'c'}}, s21_map2;
  std_map2 = std::move(std_map1);
  s21_map2 = std::move(s21_map1);
  CompareMaps(s21_map2, std_map2);
}

TEST(Map, at) {
  const std::map<int, int> std_map{{1, 2}, {2, 3}, {3, 4}};
  const custom::Map<int, int> s21_map{{1, 2}, {2, 3}, {3, 4}};
  ASSERT_ANY_THROW(s21_map.at(666));

  auto std_i = std_map.begin();
  auto s21_i = s21_map.begin();
  while (std_i != std_map.end() && s21_i != s21_map.end()) {
    ASSERT_NO_THROW(std_map.at((*std_i).first));
    ASSERT_NO_THROW(s21_map.at((*s21_i).first));
    ++std_i;
    ++s21_i;
  }
  ASSERT_EQ(std_i, std_map.end());
  ASSERT_EQ(s21_i, s21_map.end());

  std::map<int, int> std_changable{{1, 5}, {6, 6}};
  custom::Map<int, int> s21_changable{{1, 5}, {6, 6}};
  std_changable.at(1) = 18;
  s21_changable.at(1) = 18;
  CompareMaps(std_changable, s21_changable);
}

TEST(Map, square_brackets) {
  std::map<int, int> std_changable{{5, 5}, {6, 6}, {888, 888}};
  custom::Map<int, int> s21_changable{{5, 5}, {6, 6}, {888, 888}};
  std_changable[5] = 18;
  s21_changable[5] = 18;
  CompareMaps(std_changable, s21_changable);
  auto std_i = std_changable.begin();
  auto s21_i = s21_changable.begin();
  while (std_i != std_changable.end() && s21_i != s21_changable.end()) {
    ASSERT_NO_THROW(std_changable[(*std_i).first]);
    ASSERT_NO_THROW(s21_changable[(*s21_i).first]);
    ASSERT_EQ(std_changable[(*std_i).first], s21_changable[(*s21_i).first]);
    ++std_i;
    ++s21_i;
  }
  ASSERT_EQ(std_i, std_changable.end());
  ASSERT_EQ(s21_i, s21_changable.end());
}

TEST(Map, begin) {
  const std::map<std::string, int> std_map1{{"pillows", 16}, {"beds", 11}};
  const custom::Map<std::string, int> s21_map1{{"pillows", 16}, {"beds", 11}};
  ASSERT_EQ((*std_map1.begin()).first, (*s21_map1.begin()).first);
  ASSERT_EQ((*std_map1.begin()).second, (*s21_map1.begin()).second);

  std::map<int, int> std_map2{{4, 5}, {5, 5}};
  custom::Map<int, int> s21_map2{{4, 5}, {5, 5}};
  ASSERT_EQ((*std_map2.begin()).first, (*s21_map2.begin()).first);
  ASSERT_EQ((*std_map2.begin()).second, (*s21_map2.begin()).second);

  (*std_map2.begin()).second = 666;
  (*s21_map2.begin()).second = 666;
  CompareMaps(std_map2, s21_map2);

  const std::map<void *, void *> std_empty;
  const custom::Map<void *, void *> s21_empty;
  ASSERT_EQ(std_empty.begin(), std_empty.end());
  ASSERT_EQ(s21_empty.begin(), s21_empty.end());
  CompareMaps(std_empty, s21_empty);
}

TEST(Map, end) {
  const std::map<std::string, int> std_map1{{"pillows", 16}, {"beds", 11}};
  const custom::Map<std::string, int> s21_map1{{"pillows", 16}, {"beds", 11}};
  ASSERT_EQ((*(--std_map1.end())).first, (*(--s21_map1.end())).first);
  ASSERT_EQ((*(--std_map1.end())).second, (*(--s21_map1.end())).second);

  std::map<int, int> std_map2{{4, 5}, {5, 5}};
  custom::Map<int, int> s21_map2{{4, 5}, {5, 5}};
  ASSERT_EQ((*(--std_map2.end())).first, (*(--s21_map2.end())).first);
  ASSERT_EQ((*(--std_map2.end())).second, (*(--s21_map2.end())).second);

  (*(--std_map2.end())).second = 666;
  (*(--s21_map2.end())).second = 666;
  CompareMaps(std_map2, s21_map2);
}

TEST(Map, empty) {
  std::map<int, int> std_map;
  custom::Map<int, int> s21_map;
  ASSERT_EQ(std_map.empty(), s21_map.empty());
  ASSERT_EQ(std_map.empty(), true);
  ASSERT_EQ(s21_map.empty(), true);

  std_map[18] = 666;
  s21_map[18] = 666;
  ASSERT_EQ(std_map.empty(), s21_map.empty());
  ASSERT_EQ(std_map.empty(), false);
  ASSERT_EQ(s21_map.empty(), false);
}

TEST(Map, size) {
  std::map<int, int> std_map;
  custom::Map<int, int> s21_map;
  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.size(), 0);
  ASSERT_EQ(s21_map.size(), 0);

  std_map[123] = 456;
  s21_map[123] = 456;
  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.size(), 1);
  ASSERT_EQ(s21_map.size(), 1);

  std_map.erase(std_map.find(123));
  s21_map.erase(s21_map.find(123));
  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.size(), 0);
  ASSERT_EQ(s21_map.size(), 0);

  std_map = std::move(std::map<int, int>{{1, 1}, {2, 2}, {-2, 2}});
  s21_map = std::move(custom::Map<int, int>{{1, 1}, {2, 2}, {-2, 2}});
  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.size(), 3);
  ASSERT_EQ(s21_map.size(), 3);

  std_map.clear();
  s21_map.clear();
  ASSERT_EQ(std_map.size(), s21_map.size());
  ASSERT_EQ(std_map.size(), 0);
  ASSERT_EQ(s21_map.size(), 0);
}

class MapTestClass {
public:
  bool operator<(const MapTestClass &other) const {
    return string_ < other.string_ && size_t_ < other.size_t_ &&
           long_double_ < other.long_double_;
  }

  bool operator==(const MapTestClass &other) const {
    return string_ == other.string_ && size_t_ == other.size_t_ &&
           long_double_ == other.long_double_;
  }

  bool operator!=(const MapTestClass &other) const { return !(*this == other); }

private:
  std::string string_ = "Test string here";
  std::size_t size_t_ = 5000UL;
  long double long_double_ = 123456.654321L;
};

TEST(Map, max_size) {
  std::map<MapTestClass, MapTestClass> std_map1;
  custom::Map<MapTestClass, MapTestClass> s21_map1;
  ASSERT_EQ(std_map1.max_size(), s21_map1.max_size());

  std::map<int, char> std_map2;
  custom::Map<int, char> s21_map2;
  ASSERT_EQ(std_map2.max_size(), s21_map2.max_size());
}

TEST(Map, clear) {
  std::map<int, int> std_map;
  custom::Map<int, int> s21_map;
  std_map.clear();
  s21_map.clear();
  CompareMaps(s21_map, std_map);

  std_map[123] = 456;
  s21_map[123] = 456;
  std_map.clear();
  s21_map.clear();
  CompareMaps(s21_map, std_map);

  std_map = std::move(
      std::map<int, int>{{1, 1}, {2, 2}, {-1, -1}, {-2, -2}, {888, 888}});
  s21_map = std::move(
      custom::Map<int, int>{{1, 1}, {2, 2}, {-1, -1}, {-2, -2}, {888, 888}});
  std_map.clear();
  s21_map.clear();
  CompareMaps(s21_map, std_map);
}

TEST(Map, insert) {
  std::map<int, int> std_map;
  custom::Map<int, int> s21_map;
  auto std_insert_result = std_map.insert({1, 2});
  auto s21_insert_result = s21_map.insert({1, 2});
  ASSERT_EQ(*std_insert_result.first, *s21_insert_result.first);
  ASSERT_EQ(std_insert_result.second, s21_insert_result.second);
  CompareMaps(std_map, s21_map);

  std_insert_result = std_map.insert({1, 555});
  s21_insert_result = s21_map.insert({1, 555});
  ASSERT_EQ(*std_insert_result.first, *s21_insert_result.first);
  ASSERT_EQ(std_insert_result.second, s21_insert_result.second);
  CompareMaps(std_map, s21_map);

  // * std::map returns different value in this case
  s21_insert_result = s21_map.insert(5, 6);
  ASSERT_EQ((*s21_insert_result.first).first, 5);
  ASSERT_EQ((*s21_insert_result.first).second, 6);
  ASSERT_EQ(s21_insert_result.second, true);

  s21_insert_result = s21_map.insert(5, 555);
  ASSERT_EQ((*s21_insert_result.first).first, 5);
  ASSERT_EQ((*s21_insert_result.first).second, 6);
  ASSERT_EQ(s21_insert_result.second, false);
}

TEST(Map, insert_or_assign) {
  std::map<int, int> std_map;
  custom::Map<int, int> s21_map;
  auto std_insert_result = std_map.insert_or_assign(5, 6);
  auto s21_insert_result = s21_map.insert_or_assign(5, 6);
  ASSERT_EQ(*std_insert_result.first, *s21_insert_result.first);
  ASSERT_EQ(std_insert_result.second, s21_insert_result.second);
  CompareMaps(std_map, s21_map);

  std_insert_result = std_map.insert_or_assign(5, 555);
  s21_insert_result = s21_map.insert_or_assign(5, 555);
  ASSERT_EQ(*std_insert_result.first, *s21_insert_result.first);
  ASSERT_EQ(std_insert_result.second, s21_insert_result.second);
  CompareMaps(std_map, s21_map);
}

TEST(Map, erase) {
  std::map<int, int> std_map{{1, 1}, {1, 2}, {3, 2}};
  custom::Map<int, int> s21_map{{1, 1}, {1, 2}, {3, 2}};
  CompareMaps(s21_map, std_map);

  std_map.erase(1);
  s21_map.erase(1);
  CompareMaps(s21_map, std_map);

  std_map.erase(3);
  s21_map.erase(3);
  CompareMaps(s21_map, std_map);
}

TEST(Map, swap) {
  std::map<int, int> std_map1{{1, 2}, {2, 1}, {-2, -2}},
      std_map2{{5, 6}, {6, 5}};
  custom::Map<int, int> s21_map1{{1, 2}, {2, 1}, {-2, -2}},
      s21_map2{{5, 6}, {6, 5}};
  CompareMaps(s21_map1, std_map1);
  CompareMaps(s21_map2, std_map2);

  std_map1.swap(std_map2);
  s21_map1.swap(s21_map2);
  CompareMaps(std_map1, std::map<int, int>{{5, 6}, {6, 5}});
  CompareMaps(s21_map1, custom::Map<int, int>{{5, 6}, {6, 5}});
  CompareMaps(std_map1, s21_map1);
  CompareMaps(std_map2, std::map<int, int>{{1, 2}, {2, 1}, {-2, -2}});
  CompareMaps(s21_map2, custom::Map<int, int>{{1, 2}, {2, 1}, {-2, -2}});
  CompareMaps(std_map2, s21_map2);
}

TEST(Map, merge) {
  std::map<bool, int> std_map1{{true, 1}, {false, 55}},
      std_map2{{true, 88}, {false, 156}};
  custom::Map<bool, int> s21_map1{{true, 1}, {false, 55}},
      s21_map2{{true, 88}, {false, 156}};
  CompareMaps(s21_map1, std_map1);
  CompareMaps(s21_map2, std_map2);

  std_map1.merge(std_map2);
  s21_map1.merge(s21_map2);
  CompareMaps(std_map1, std::map<bool, int>{{true, 1}, {false, 55}});
  CompareMaps(std_map1, s21_map1);
  CompareMaps(std_map2, std::map<bool, int>{{true, 88}, {false, 156}});
  CompareMaps(std_map2, s21_map2);
  CompareMaps(s21_map1, custom::Map<bool, int>{{true, 1}, {false, 55}});
  CompareMaps(s21_map2, custom::Map<bool, int>{{true, 88}, {false, 156}});

  std::map<int, int> std_map3{{1, 2}, {2, 2}, {3, 2}},
      std_map4{{1, 3}, {4, 3}, {5, 8}};
  custom::Map<int, int> s21_map3{{1, 2}, {2, 2}, {3, 2}},
      s21_map4{{1, 3}, {4, 3}, {5, 8}};

  std_map3.merge(std_map4);
  s21_map3.merge(s21_map4);
  CompareMaps(std_map3,
              std::map<int, int>{{1, 2}, {2, 2}, {3, 2}, {4, 3}, {5, 8}});
  CompareMaps(std_map3, s21_map3);
  CompareMaps(std_map4, std::map<int, int>{{1, 3}});
  CompareMaps(std_map4, s21_map4);
  CompareMaps(s21_map3,
              custom::Map<int, int>{{1, 2}, {2, 2}, {3, 2}, {4, 3}, {5, 8}});
  CompareMaps(s21_map4, custom::Map<int, int>{{1, 3}});
}

TEST(Map, contains) {
  // * std::map has no contains function
  const custom::Map<std::string, std::string> s21_map{
      {"123", "456"},
      {"111", "111"},
      {"welcome", "yeah"},
      {"School21", "Great place!"}};

  ASSERT_EQ(s21_map.contains("School42"), false);
  for (auto &i : s21_map)
    ASSERT_EQ(s21_map.contains(i.first), true);
}

TEST(Map, emplace) {
  // * std::map emplace function behavior differs completely
  custom::Map<int, int> s21_map;
  custom::Map<int, int> compare{{1, 2},   {2, 3},   {3, 2},  {4, 4},
                                {88, 88}, {88, 87}, {88, 86}};
  auto emplace_result = s21_map.emplace(
      std::pair{1, 2}, std::pair{2, 3}, std::pair{3, 2}, std::pair{4, 4},
      std::pair{88, 88}, std::pair{88, 87}, std::pair{88, 86});
  CompareMaps(s21_map, compare);

  auto emplace_result_i = emplace_result.begin();
  for (auto &i : s21_map) {
    ASSERT_EQ((*(emplace_result_i->first)).second, i.second);
    ++emplace_result_i;
  }

  ASSERT_EQ(emplace_result[emplace_result.size() - 1].second, false);
  ASSERT_EQ(emplace_result[emplace_result.size() - 2].second, false);
}