#ifndef _SEQUENCE_CONTAINERS_VECTOR_CUSTOM_VECTOR_H_
#define _SEQUENCE_CONTAINERS_VECTOR_CUSTOM_VECTOR_H_

#include <cstddef>
#include <initializer_list>
#include <limits>
#include <stdexcept>

#include "../../interfaces/custom_iterator.h"
#include "../../misc/custom_sequence_allocator.h"

namespace custom {

/**
 * @brief Container that stores variable number of values and uses dynamic
 * memory
 *
 * @tparam T type to store
 */
template <class T> class Vector {
public:
  using allocator_type = SequenceAllocator__<T>;
  using value_type = typename allocator_type::value_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using double_reference = value_type &&;
  using pointer = value_type *;
  using const_pointer = const value_type *;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using iterator = pointer;
  using const_iterator = const_pointer;

  constexpr Vector() noexcept;
  ~Vector();
  constexpr explicit Vector(size_type size);
  constexpr Vector(const Vector &other);
  constexpr Vector(Vector &&other) noexcept;

  constexpr explicit Vector(std::initializer_list<value_type> const &items);

  constexpr Vector &operator=(const Vector &other);
  constexpr Vector &operator=(Vector &&other) noexcept;
  constexpr Vector &operator=(const std::initializer_list<value_type> &items);

  constexpr reference at(size_type pos);
  constexpr const_reference at(size_type pos) const;
  constexpr reference operator[](size_type pos) noexcept;
  constexpr const_reference operator[](size_type pos) const noexcept;
  constexpr reference front() noexcept;
  constexpr const_reference front() const noexcept;
  constexpr reference back() noexcept;
  constexpr const_reference back() const noexcept;
  constexpr value_type *data() noexcept;
  constexpr const value_type *data() const noexcept;

  [[nodiscard]] constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type max_size() const noexcept;
  constexpr void reserve(size_type size);
  constexpr size_type capacity() const noexcept;
  constexpr void shrink_to_fit();

  constexpr void clear() noexcept;
  constexpr void push_back(const_reference value);
  constexpr void push_back(double_reference value);
  constexpr void pop_back();
  constexpr void swap(Vector &other) noexcept;

  constexpr iterator insert(iterator pos, const_reference value);
  constexpr iterator insert(iterator pos, double_reference value);
  constexpr void erase(iterator pos);

  constexpr iterator begin() noexcept;
  constexpr iterator end() noexcept;
  constexpr const_iterator begin() const noexcept;
  constexpr const_iterator end() const noexcept;

  template <typename... Args>
  constexpr iterator emplace(const_iterator pos, Args &&...args);

  template <typename... Args> constexpr void emplace_back(Args &&...args);

private:
  allocator_type data_;
  size_type size_;

  constexpr static void construct(void *ptr);
  constexpr static void construct(void *ptr, const_reference value);
  constexpr static void construct(void *ptr, double_reference value);
  constexpr static void destroy(value_type *ptr);

  constexpr void shrink(size_type size);
  constexpr void reorganize_for_push_back();

  template <typename... Args>
  constexpr iterator emplace_helper(const_iterator pos, reference first,
                                    Args &&...args);

  constexpr iterator emplace_helper(const_iterator pos, reference value);

  constexpr static const char *kOutOfRangeMsg =
      "Position is greater or equal than size of a vector";
  constexpr static const char *kMaxCapacityMsg =
      "Requested size is greater than maximum possible capacity";
  constexpr static const char *kMaxCapacityReachedMsg =
      "There is no more capacity for new elements";
};

#include "custom_vector.tpp"

} // namespace custom

#endif // _SEQUENCE_CONTAINERS_VECTOR_CUSTOM_VECTOR_H_