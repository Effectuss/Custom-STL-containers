#ifndef _ASSOCIATIVE_CONTAINERS_SET_CUSTOM_SET_H_
#define _ASSOCIATIVE_CONTAINERS_SET_CUSTOM_SET_H_

#include "../../misc/custom_binary_tree.h"

namespace custom {

/**
 * @brief Container that stores unique values in sorted order using sorted
 * binary tree
 *
 * @tparam Key type of value to be stored
 * @tparam Compare defaults to @code std::less<Key> and sorts values in
 * ascending order, but can be also @code std::greater<Key> for storing values
 * in descending order
 */
template <class Key, class Compare = std::less<Key>> class Set {
public:
  using binary_tree = SortedBinaryTree__<Key, Key, TypeOfValue__<Key>, Compare>;
  using key_type = typename binary_tree::key_type;
  using value_type = typename binary_tree::value_type;
  using reference = typename binary_tree::reference;
  using const_reference = typename binary_tree::const_reference;
  using size_type = typename binary_tree::size_type;
  using const_iterator = typename binary_tree::const_iterator;
  using iterator = const_iterator;

  Set() = default;
  Set(const Set &other) = default;
  Set(Set &&other) noexcept = default;
  ~Set() = default;

  explicit Set(const std::initializer_list<value_type> &items) : tree_() {
    *this = items;
  }

  Set &operator=(const Set &other) = default;
  Set &operator=(Set &&other) = default;

  Set &operator=(const std::initializer_list<value_type> &items) {
    tree_.clear();
    for (const auto &i : items)
      tree_.insert(i);
    return *this;
  }

  /**
   * @brief Returns iterator to the start of set
   *
   * @return read only iterator
   */
  iterator begin() const { return tree_.begin(); }

  /**
   * @brief Returns iterator to the past-end of set
   *
   * @return read only iterator
   */
  iterator end() const { return tree_.end(); }

  /**
   * @brief Checks if container is empty
   *
   * @return true is empty
   * @return false otherwise
   */
  bool empty() const { return tree_.empty(); }

  /**
   * @brief Returns current size of the container
   *
   */
  size_type size() const { return tree_.size(); }

  /**
   * @brief Returns theoretical maximum container size due to OS arcitecture
   *
   */
  size_type max_size() const { return tree_.max_size(); }

  /**
   * @brief Removes all stored values from the container
   *
   */
  void clear() { tree_.clear(); }

  /**
   * @brief Inserts a new value into container
   *
   * @param value what to insert
   * @return std::pair<iterator, bool> - read only iterator to where value was
   * inserted and bool indicating if insertion took place
   */
  std::pair<iterator, bool> insert(const_reference value) {
    auto mid_res = tree_.insert(value);
    return std::pair<iterator, bool>{mid_res.first, mid_res.second};
  }

  /**
   * @brief Removes value that stores where the pos points
   *
   * @param pos iterator to the element
   */
  void erase(iterator pos) { tree_.erase(pos); }

  /**
   * @brief Swaps contents and size of the container with other map
   *
   * @param other container to be swapped
   */
  void swap(Set &other) { tree_.swap(other.tree_); }

  /**
   * @brief Extracts nodes from other container without allocating new values
   *
   * @param other container to be merged with
   */
  void merge(Set &other) { tree_.merge(other.tree_); }

  /**
   * @brief Finds element in the container by the key and returns an iterator to
   * it. If element is not in the container returns @code end()
   *
   * @return read only iterator to the element
   */
  iterator find(const key_type &key) const { return tree_.find(key); }

  /**
   * @brief Checks if the map contains element with given key
   *
   * @return true if contains
   * @return false otherwise
   */
  bool contains(const key_type &key) const { return tree_.contains(key); }

  /**
   * @brief Inserts many elements at once
   *
   * @param args sequence of already constructed elements
   * @return Vector<std::pair<iterator, bool>> - iterators to the inserted
   * elements and indicators if the insertion took place
   */
  template <class... Args>
  Vector<std::pair<iterator, bool>> emplace(Args &&...args) {
    return tree_.emplace(false, args...);
  }

private:
  binary_tree tree_;
};

} // namespace custom

#endif // _ASSOCIATIVE_CONTAINERS_SET_CUSTOM_SET_H_