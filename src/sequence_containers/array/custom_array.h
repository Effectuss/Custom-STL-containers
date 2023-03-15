#ifndef _SEQUENCE_CONTAINERS_ARRAY_CUSTOM_ARRAY_H_
#define _SEQUENCE_CONTAINERS_ARRAY_CUSTOM_ARRAY_H_

#include <initializer_list>
#include <limits>
#include <stdexcept>
#include <utility>

namespace custom {

/**
 * @brief Container that stores fix number of values and uses memory that
 * allocates on stack
 *
 * @tparam T types to store
 * @tparam N size of the container
 */
template <class T, const std::size_t N> class Array {
public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using double_reference = value_type &&;
  using size_type = std::size_t;
  using pointer = value_type *;
  using const_pointer = const value_type *;
  using iterator = pointer;
  using const_iterator = const_pointer;
  using difference_type = std::ptrdiff_t;

  constexpr Array() = default;
  ~Array() = default;
  constexpr Array(const Array &) = default;
  constexpr Array(Array &&other) noexcept = default;
  constexpr explicit Array(const std::initializer_list<value_type> &items);

  constexpr Array &operator=(const Array &) = default;
  constexpr Array &operator=(Array &&) noexcept = default;
  constexpr Array &operator=(const std::initializer_list<value_type> &items);

  constexpr reference at(size_type pos);
  constexpr const_reference at(size_type pos) const;
  constexpr reference operator[](size_type pos);
  constexpr const_reference operator[](size_type pos) const;
  constexpr reference front();
  constexpr const_reference front() const;
  constexpr reference back();
  constexpr const_reference back() const;
  constexpr iterator data();
  constexpr const_iterator data() const;

  constexpr iterator begin();
  constexpr const_iterator begin() const;
  constexpr iterator end();
  constexpr const_iterator end() const;

  constexpr bool empty() const;
  constexpr size_type size() const;
  constexpr size_type max_size() const;

  constexpr void swap(Array &other);
  constexpr void fill(const_reference value);

private:
  value_type data_[N];
};

#include "custom_array.tpp"

} // namespace custom

#endif // _SEQUENCE_CONTAINERS_ARRAY_CUSTOM_ARRAY_H_