#include <gtest/gtest.h>

#include <vector>

#include "../../sequence_containers/vector/custom_vector.h"

template <class T>
void CompareTwoVectors(const custom::Vector<T> &s21_v,
                       const std::vector<T> &std_v) {
  ASSERT_EQ(s21_v.size(), std_v.size());
  ASSERT_EQ(s21_v.capacity(), std_v.capacity());
  auto s21_i = s21_v.begin();
  auto std_i = std_v.begin();
  while (s21_i != s21_v.end() && std_i != std_v.end()) {
    ASSERT_EQ(*s21_i, *std_i);
    ++s21_i;
    ++std_i;
  }
  ASSERT_EQ(s21_i, s21_v.end());
  ASSERT_EQ(std_i, std_v.end());
}

template <class T>
void CompareTwoVectors(const custom::Vector<T> &s21_v1,
                       const custom::Vector<T> &s21_v2,
                       bool ignore_capacity = false) {
  ASSERT_EQ(s21_v1.size(), s21_v2.size());
  if (!ignore_capacity) {
    ASSERT_EQ(s21_v1.capacity(), s21_v2.capacity());
  }
  auto s21_i1 = s21_v1.begin();
  auto s21_i2 = s21_v2.begin();
  while (s21_i1 != s21_v1.end() && s21_i2 != s21_v2.end()) {
    ASSERT_EQ(*s21_i1, *s21_i2);
    ++s21_i1;
    ++s21_i2;
  }
  ASSERT_EQ(s21_i1, s21_v1.end());
  ASSERT_EQ(s21_i2, s21_v2.end());
}

TEST(Vector, default_constructor) {
  const custom::Vector<int> s21_v;
  const std::vector<int> std_v;
  CompareTwoVectors(s21_v, std_v);
  ASSERT_EQ(s21_v.data(), std_v.data());
}

TEST(Vector, size_type_constructor) {
  const custom::Vector<double> s21_v(5);
  const std::vector<double> std_v(5);
  CompareTwoVectors(s21_v, std_v);
  ASSERT_NE(s21_v.data(), nullptr);
}

TEST(Vector, copy_constructor) {
  const custom::Vector<int> s21_v1{1, 2, 3}, s21_v2(s21_v1);
  const std::vector<int> std_v1{1, 2, 3}, std_v2(std_v1);
  CompareTwoVectors(s21_v1, s21_v2);
  CompareTwoVectors(s21_v2, std_v2);
}

TEST(Vector, move_constructor) {
  using value_type = long double;
  custom::Vector<value_type> s21_v1;
  std::vector<value_type> std_v1;
  for (long double i = -100.0L; i <= 100.0L; i += 0.01L) {
    s21_v1.push_back(i);
    std_v1.push_back(i);
  }
  auto s21_data_save = s21_v1.data();
  auto std_data_save = std_v1.data();
  custom::Vector<value_type> s21_v2(std::move(s21_v1));
  std::vector<value_type> std_v2(std::move(std_v1));
  ASSERT_EQ(s21_data_save, s21_v2.data());
  ASSERT_EQ(std_data_save, std_v2.data());
  CompareTwoVectors(s21_v2, std_v2);
}

TEST(Vector, initializer_list_constructor) {
  using value_type = float;
  custom::Vector<value_type> s21_v{1.1F, 2.2F, 3.3F, 4.4F, 5.5F};
  std::vector<value_type> std_v{1.1F, 2.2F, 3.3F, 4.4F, 5.5F};
  CompareTwoVectors(s21_v, std_v);
}

TEST(Vector, operator_equal_copy) {
  using value_type = double;
  custom::Vector<value_type> s21_v1(600), s21_v2;
  std::vector<value_type> std_v1(600), std_v2;
  ASSERT_NO_THROW(s21_v2 = s21_v1);
  std_v2 = std_v1;
  CompareTwoVectors(s21_v1, s21_v2);
  CompareTwoVectors(s21_v2, std_v2);
}

TEST(Vector, operator_equal_move) {
  using value_type = double;
  custom::Vector<value_type> s21_v1{1.1, 2.2, 3.3, 4.4};
  std::vector<value_type> std_v1{1.1, 2.2, 3.3, 4.4};
  auto s21_v1_data = s21_v1.data();
  auto std_v1_data = std_v1.data();
  custom::Vector<value_type> s21_v2 = std::move(s21_v1);
  std::vector<value_type> std_v2 = std::move(std_v1);
  ASSERT_EQ(s21_v1_data, s21_v2.data());
  ASSERT_EQ(std_v1_data, std_v2.data());
  CompareTwoVectors(s21_v2, std_v2);
}

TEST(Vector, operator_equal_initializer_list) {
  custom::Vector<int> s21_v;
  s21_v = {1, 2, 3, 4};
  std::vector<int> std_v;
  std_v = {1, 2, 3, 4};
  CompareTwoVectors(s21_v, std_v);
}

TEST(Vector, square_brackets) {
  using value_type = double;
  custom::Vector<value_type> s21_v1;
  std::vector<value_type> std_v1;
  for (value_type i = -100.0; i <= 100.0; i += 0.01) {
    s21_v1.push_back(i);
    std_v1.push_back(i);
  }
  for (std::size_t i = 0; i <= s21_v1.size() * 2; ++i) {
    ASSERT_NO_THROW(s21_v1[i]);
    ASSERT_NO_THROW(std_v1[i]);
  }
  CompareTwoVectors(s21_v1, std_v1);
  for (value_type i = 0; i < s21_v1.size(); ++i) {
    s21_v1[i] = i;
    std_v1[i] = i;
  }
  CompareTwoVectors(s21_v1, std_v1);

  const custom::Vector<value_type> s21_v2{1.1, 2.2, 3.3, 4.4};
  const std::vector<value_type> std_v2{1.1, 2.2, 3.3, 4.4};
  for (std::size_t i = 0; i <= s21_v2.size() * 2UL; ++i) {
    if (i < s21_v2.size()) {
      ASSERT_NO_THROW(ASSERT_EQ(s21_v2[i], std_v2[i]));
    } else {
      ASSERT_NO_THROW(s21_v2[i]);
      ASSERT_NO_THROW(std_v2[i]);
    }
  }
}

TEST(Vector, at) {
  using value_type = double;
  custom::Vector<value_type> s21_v1;
  std::vector<value_type> std_v1;
  for (value_type i = -100.0; i <= 100.0; i += 0.01) {
    s21_v1.push_back(i);
    std_v1.push_back(i);
  }
  for (std::size_t i = 0; i <= s21_v1.size() * 2; ++i) {
    if (i >= s21_v1.size()) {
      ASSERT_ANY_THROW(s21_v1.at(i));
      ASSERT_ANY_THROW(std_v1.at(i));
    } else {
      ASSERT_NO_THROW(s21_v1.at(i));
      ASSERT_NO_THROW(std_v1.at(i));
    }
  }
  CompareTwoVectors(s21_v1, std_v1);
  for (value_type i = 0; i < s21_v1.size(); ++i) {
    s21_v1.at(i) = i;
    std_v1.at(i) = i;
  }
  CompareTwoVectors(s21_v1, std_v1);

  const custom::Vector<value_type> s21_v2{1.1, 2.2, 3.3, 4.4};
  const std::vector<value_type> std_v2{1.1, 2.2, 3.3, 4.4};
  for (std::size_t i = 0; i <= s21_v2.size() * 2UL; ++i) {
    if (i < s21_v2.size())
      ASSERT_NO_THROW(ASSERT_EQ(s21_v2.at(i), std_v2.at(i)));
    else
      ASSERT_ANY_THROW(ASSERT_EQ(s21_v2.at(i), std_v2.at(i)));
  }
}

TEST(Vector, front) {
  custom::Vector<int> s21_v1{1, 2, 3, 4, 5};
  std::vector<int> std_v1{1, 2, 3, 4, 5};
  ASSERT_EQ(s21_v1.front(), std_v1.front());

  const custom::Vector<int> s21_v2{1, 2, 3, 4, 5};
  const std::vector<int> std_v2{1, 2, 3, 4, 5};
  ASSERT_EQ(s21_v2.front(), std_v2.front());
}

TEST(Vector, back) {
  custom::Vector<int> s21_v1{1, 2, 3, 4, 5};
  std::vector<int> std_v1{1, 2, 3, 4, 5};
  ASSERT_EQ(s21_v1.back(), std_v1.back());

  const custom::Vector<int> s21_v2{1, 2, 3, 4, 5};
  const std::vector<int> std_v2{1, 2, 3, 4, 5};
  ASSERT_EQ(s21_v2.back(), std_v2.back());
}

TEST(Vector, data) {
  custom::Vector<int> s21_v1;
  std::vector<int> std_v1;
  int max = 10;
  for (int i = 0; i < max; ++i) {
    s21_v1.push_back(i);
    std_v1.push_back(i);
  }
  int *s21_v1_data = s21_v1.data();
  int *std_v1_data = std_v1.data();
  for (std::size_t i = 0; i < (std::size_t)max; ++i)
    ASSERT_EQ(s21_v1_data[i], std_v1_data[i]);
}

TEST(Vector, empty) {
  using value_type = custom::Vector<int>;
  custom::Vector<value_type> s21_v;
  std::vector<value_type> std_v;
  ASSERT_EQ(s21_v.empty(), std_v.empty());
  s21_v = {value_type{1, 2, 3}, value_type{1, 2, 3}, value_type{1, 2, 3}};
  std_v = {value_type{1, 2, 3}, value_type{1, 2, 3}, value_type{1, 2, 3}};
  s21_v.clear();
  std_v.clear();
  ASSERT_EQ(s21_v.empty(), std_v.empty());
}

TEST(Vector, size) {
  using value_type = double;
  custom::Vector<value_type> s21_v;
  std::vector<value_type> std_v;
  ASSERT_EQ(s21_v.size(), std_v.size());

  s21_v.push_back(value_type());
  std_v.push_back(value_type());
  ASSERT_EQ(s21_v.size(), std_v.size());

  s21_v = {1, 2, 3, 4, 5};
  std_v = {1, 2, 3, 4, 5};
  ASSERT_EQ(s21_v.size(), std_v.size());
}

// Fast test class
class VectorTestClass {
public:
  VectorTestClass() : data_(nullptr), size_(0) {}
  ~VectorTestClass() { delete[] data_; }

  VectorTestClass(const VectorTestClass &other) : size_(other.size_) {
    if (size_)
      data_ = new double[size_]();
    else
      data_ = nullptr;
    for (std::size_t i = 0; i < size_; i++)
      data_[i] = other.data_[i];
  }

  VectorTestClass(VectorTestClass &&other)
      : data_(other.data_), size_(other.size_) {
    other.data_ = nullptr;
  }

  VectorTestClass &operator=(VectorTestClass &&other) {
    if (this != &other) {
      delete[] data_;
      data_ = other.data_;
      other.data_ = nullptr;
      size_ = other.size_;
    }
    return *this;
  }

  explicit VectorTestClass(std::size_t size) : size_(size) {
    if (size_)
      data_ = new double[size_]{};
    else
      data_ = nullptr;
  }

  bool operator==(const VectorTestClass &other) const {
    if (size_ != other.size_)
      return false;
    for (std::size_t i = 0; i < size_; i++)
      if (data_[i] != other.data_[i])
        return false;
    return true;
  }

private:
  double *data_;
  std::size_t size_;
};

TEST(Vector, max_size) {
  ASSERT_EQ(custom::Vector<int>().max_size(), std::vector<int>().max_size());
  ASSERT_EQ(custom::Vector<char>().max_size(), std::vector<char>().max_size());
  ASSERT_EQ(custom::Vector<double>().max_size(),
            std::vector<double>().max_size());
  ASSERT_EQ(custom::Vector<char *>().max_size(),
            std::vector<char *>().max_size());
  ASSERT_EQ(custom::Vector<VectorTestClass>().max_size(),
            std::vector<VectorTestClass>().max_size());
  ASSERT_EQ(custom::Vector<long double>().max_size(),
            std::vector<long double>().max_size());
  ASSERT_EQ(custom::Vector<unsigned long long int>().max_size(),
            std::vector<unsigned long long int>().max_size());
}

TEST(Vector, reserve) {
  using value_type = int;
  custom::Vector<value_type> s21_v;
  std::vector<value_type> std_v;
  s21_v.reserve(100);
  std_v.reserve(100);
  ASSERT_EQ(s21_v.size(), std_v.size());
  ASSERT_EQ(s21_v.capacity(), std_v.capacity());

  s21_v = {1, 2, 3, 4, 5};
  std_v = {1, 2, 3, 4, 5};
  s21_v.reserve(100);
  std_v.reserve(100);
  ASSERT_EQ(s21_v.size(), std_v.size());
  ASSERT_EQ(s21_v.capacity(), std_v.capacity());
  CompareTwoVectors(s21_v, std_v);

  s21_v.reserve(1);
  std_v.reserve(1);
  ASSERT_EQ(s21_v.size(), std_v.size());
  ASSERT_EQ(s21_v.capacity(), std_v.capacity());
  CompareTwoVectors(s21_v, std_v);
}

TEST(Vector, capacity) {
  using value_type = long long unsigned;
  custom::Vector<value_type> s21_v;
  std::vector<value_type> std_v;
  CompareTwoVectors(s21_v, std_v);

  for (std::size_t i = 0; i < 1000; ++i) {
    s21_v.push_back(value_type());
    std_v.push_back(value_type());
    CompareTwoVectors(s21_v, std_v);
  }
}

TEST(Vector, shrink_to_fit) {
  using value_type = int;
  custom::Vector<value_type> s21_v;
  std::vector<value_type> std_v;
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  CompareTwoVectors(s21_v, std_v);

  s21_v.reserve(50);
  std_v.reserve(50);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  CompareTwoVectors(s21_v, std_v);

  s21_v = {1, 2, 3, 4, 5};
  std_v = {1, 2, 3, 4, 5};
  s21_v.push_back(6);
  std_v.push_back(6);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  CompareTwoVectors(s21_v, std_v);
}

TEST(Vector, clear) {
  using value_type = VectorTestClass;
  custom::Vector<value_type> s21_v;
  std::vector<value_type> std_v;
  s21_v.clear();
  std_v.clear();
  CompareTwoVectors(s21_v, std_v);

  s21_v.reserve(50);
  std_v.reserve(50);
  s21_v.clear();
  std_v.clear();
  CompareTwoVectors(s21_v, std_v);

  s21_v.push_back(VectorTestClass());
  std_v.push_back(VectorTestClass());
  s21_v.clear();
  std_v.clear();
  CompareTwoVectors(s21_v, std_v);

  s21_v = std::move(custom::Vector<value_type>(150));
  std_v = std::move(std::vector<value_type>(150));
  s21_v.clear();
  std_v.clear();
  CompareTwoVectors(s21_v, std_v);
}

TEST(Vector, push_back) {
  using value_type = VectorTestClass;
  custom::Vector<value_type> s21_v;
  std::vector<value_type> std_v;
  s21_v.push_back(value_type(189));
  std_v.push_back(value_type(189));
  CompareTwoVectors(s21_v, std_v);

  for (std::size_t i = 0; i <= 801; ++i) {
    s21_v.push_back(value_type(i));
    std_v.push_back(value_type(i));
    CompareTwoVectors(s21_v, std_v);
  }
}

TEST(Vector, pop_back) {
  using value_type = VectorTestClass;
  custom::Vector<value_type> s21_v;
  std::vector<value_type> std_v;
  ASSERT_NO_THROW(s21_v.pop_back());
  CompareTwoVectors(s21_v, std_v);

  s21_v.push_back(value_type());
  std_v.push_back(value_type());
  ASSERT_NO_THROW(s21_v.pop_back());
  ASSERT_NO_THROW(std_v.pop_back());
  CompareTwoVectors(s21_v, std_v);

  s21_v = std::move(custom::Vector<value_type>(400));
  std_v = std::move(std::vector<value_type>(400));
  while (!s21_v.empty() && !std_v.empty()) {
    ASSERT_NO_THROW(s21_v.pop_back());
    ASSERT_NO_THROW(std_v.pop_back());
    CompareTwoVectors(s21_v, std_v);
  }
  CompareTwoVectors(s21_v, std_v);
}

TEST(Vector, swap) {
  using value_type = VectorTestClass;
  custom::Vector<value_type> s21_v1{
      value_type(1),
      value_type(2),
      value_type(3),
      value_type(4),
  };
  custom::Vector<value_type> s21_v2(50);
  std::vector<value_type> std_v1{
      value_type(1),
      value_type(2),
      value_type(3),
      value_type(4),
  };
  std::vector<value_type> std_v2(50);
  ASSERT_NO_THROW(s21_v1.swap(s21_v2));
  ASSERT_NO_THROW(std_v1.swap(std_v2));
  CompareTwoVectors(s21_v1, std_v1);
  CompareTwoVectors(s21_v2, std_v2);
}

TEST(Vector, insert) {
  using value_type = VectorTestClass;
  custom::Vector<value_type> s21_v;
  std::vector<value_type> std_v;
  ASSERT_NO_THROW(s21_v.insert(s21_v.begin(), value_type()));
  ASSERT_NO_THROW(std_v.insert(std_v.begin(), value_type()));
  CompareTwoVectors(s21_v, std_v);

  ASSERT_NO_THROW(s21_v.insert(s21_v.end(), value_type(2)));
  ASSERT_NO_THROW(std_v.insert(std_v.end(), value_type(2)));
  CompareTwoVectors(s21_v, std_v);

  value_type value(18);

  ASSERT_NO_THROW(s21_v.insert(s21_v.begin(), value));
  ASSERT_NO_THROW(std_v.insert(std_v.begin(), value));
  CompareTwoVectors(s21_v, std_v);

  value = std::move(value_type(50));

  ASSERT_NO_THROW(s21_v.insert(s21_v.end(), value));
  ASSERT_NO_THROW(std_v.insert(std_v.end(), value));
  CompareTwoVectors(s21_v, std_v);

  // ! Invalidated iterators have undefined behavior in std
}

TEST(Vector, erase) {
  using value_type = VectorTestClass;
  custom::Vector<value_type> s21_v{value_type(), value_type(1), value_type(2)};
  std::vector<value_type> std_v{value_type(), value_type(1), value_type(2)};
  ASSERT_NO_THROW(s21_v.erase(s21_v.end() - 1));
  ASSERT_NO_THROW(std_v.erase(std_v.end() - 1));
  CompareTwoVectors(s21_v, std_v);

  ASSERT_NO_THROW(s21_v.erase(s21_v.begin()));
  ASSERT_NO_THROW(std_v.erase(std_v.begin()));
  CompareTwoVectors(s21_v, std_v);

  ASSERT_NO_THROW(s21_v.erase(s21_v.begin()));
  ASSERT_NO_THROW(std_v.erase(std_v.begin()));
  CompareTwoVectors(s21_v, std_v);
}

TEST(Vector, begin) {
  using value_type = VectorTestClass;
  custom::Vector<value_type> s21_v{value_type()};
  std::vector<value_type> std_v{value_type()};
  ASSERT_EQ(*s21_v.begin(), *std_v.begin());

  s21_v = std::move(custom::Vector<value_type>(50));
  std_v = std::move(std::vector<value_type>(50));
  while (!s21_v.empty() && !std_v.empty()) {
    s21_v.erase(s21_v.begin());
    std_v.erase(std_v.begin());
    ASSERT_EQ(*s21_v.begin(), *std_v.begin());
    CompareTwoVectors(s21_v, std_v);
  }
}

TEST(Vector, end) {
  using value_type = VectorTestClass;
  custom::Vector<value_type> s21_v{value_type()};
  std::vector<value_type> std_v{value_type()};
  ASSERT_EQ(*(s21_v.end() - 1), *(std_v.end() - 1));

  s21_v = std::move(custom::Vector<value_type>());
  std_v = std::move(std::vector<value_type>());
  for (int i = 0; i <= 50; ++i) {
    s21_v.push_back(value_type(i));
    std_v.push_back(value_type(i));
  }
  while (!s21_v.empty() && !std_v.empty()) {
    ASSERT_EQ(*(s21_v.end() - 1), *(std_v.end() - 1));
    CompareTwoVectors(s21_v, std_v);
    s21_v.erase(s21_v.end() - 1);
    std_v.erase(std_v.end() - 1);
  }
}

TEST(Vector, emplace) {
  // * Original method behavior completely differs so we are testing manually
  custom::Vector<double> v1, v2{1.0, 2.2, 3.0, 4.4, 5.0};
  v1.emplace(v1.begin(), 1.0, 2.2, 3.0, 4.4, 5.0);
  CompareTwoVectors(v1, v2, true);

  v1 = {};
  v1.emplace(v1.end(), 1.0, 2.2, 3.0, 4.4, 5.0);
  CompareTwoVectors(v1, v2, true);

  v1 = {1.0, 5.0};
  auto i1 = v1.begin() + 1;
  v1.emplace(i1, 2.2, 3.0, 4.4);
  CompareTwoVectors(v1, v2, true);
}

TEST(Vector, emplace_back) {
  // * Original method behavior completely differs so we are testing manually
  custom::Vector<double> v1, v2{1.0, 2.2, 3.0, 4.4, 5.0};
  v1.emplace_back(1.0, 2.2, 3.0, 4.4, 5.0);
  CompareTwoVectors(v1, v2, true);

  v1 = {1.0, 2.2};
  v1.emplace_back(3.0, 4.4, 5.0);
  CompareTwoVectors(v1, v2, true);
}