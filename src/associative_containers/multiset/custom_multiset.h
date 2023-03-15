#ifndef _ASSOCIATIVE_CONTAINERS_MULTISET_CUSTOM_MULTISET_H_
#define _ASSOCIATIVE_CONTAINERS_MULTISET_CUSTOM_MULTISET_H_

#include <stdexcept>

#include "../../misc/custom_binary_tree.h"

namespace custom {

/**
 * @brief Container that stores values in sorted order using sorted binary tree.
 * Can store identical values
 *
 * @tparam Key type of value to be stored
 * @tparam Compare defaults to @code std::less<Key> and sorts values in
 * ascending order, but can be also @code std::greater<Key> for storing values
 * in descending order
 */
template <class Key, class Compare = std::less<Key>> class Multiset {
public:
  using binary_tree = SortedBinaryTree__<Key, Key, TypeOfValue__<Key>, Compare>;
  using key_type = typename binary_tree::key_type;
  using value_type = typename binary_tree::value_type;
  using key_compare = typename binary_tree::key_compare;
  using reference = typename binary_tree::reference;
  using const_reference = typename binary_tree::const_reference;
  using double_reference = typename binary_tree::double_reference;
  using size_type = typename binary_tree::size_type;
  using iterator = typename binary_tree::const_iterator;
  using const_iterator = iterator;

  Multiset() = default;
  ~Multiset() = default;

  Multiset(const Multiset &other) : Multiset() { *this = other; };

  Multiset(Multiset &&) noexcept = default;

  explicit Multiset(const std::initializer_list<value_type> &items) : tree_() {
    *this = items;
  }

  Multiset &operator=(const Multiset &other) {
    if (this != &other) {
      tree_.clear();
      for (auto &i : other)
        tree_.insert(i, true);
    }
    return *this;
  }
  Multiset &operator=(Multiset &&) noexcept = default;

  Multiset &operator=(const std::initializer_list<value_type> &items) {
    tree_.clear();
    for (auto &i : items)
      tree_.insert(i, true);
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
   * @return read only iterator to where value was
   * inserted
   */
  iterator insert(const_reference value) {
    return (iterator)tree_.insert(value, true).first;
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
  void swap(Multiset &other) { tree_.swap(other.tree_); }

  /**
   * @brief Extracts nodes from other container without allocating new values
   *
   * @param other container to be merged with
   */
  void merge(Multiset &other) { tree_.merge(other.tree_, true); }

  /**
   * @brief Returns count of the elements with given key that stored in the
   * container
   *
   * @param key value to count
   */
  size_type count(const key_type &key) const {
    return count_and_find_last(key).second;
  }

  /**
   * @brief Finds element in the container by the key and returns an iterator to
   * it. If element is not in the container returns @code end()
   *
   * @return read only iterator to the element
   */
  iterator find(const key_type &key) const { return (iterator)tree_.find(key); }

  /**
   * @brief Checks if the map contains element with given key
   *
   * @return true if contains
   * @return false otherwise
   */
  bool contains(const key_type &key) const { return tree_.contains(key); }

  /**
   * @brief Returns pair of iterators: first iterator points at the first value
   * that is not less than given key, second iterator points at the first value
   * that is greater than given key
   *
   * @param key value to search range for
   * @return pair of read only iterators
   */
  std::pair<iterator, iterator> equal_range(const key_type &key) const {
    return count_and_find_last(key).first;
  }

  /**
   * @brief Returns iterator to the first value that is not less than given key
   *
   * @param key to search for
   * @return read only iterator
   */
  iterator lower_bound(const key_type &key) const {
    return count_and_find_last(key).first.second;
  }

  /**
   * @brief Returns iterator to the first value that is greater than given key
   *
   * @param key to search for
   * @return read only iterator
   */
  iterator upper_bound(const key_type &key) const {
    return (iterator)(++(count_and_find_last(key).first.first));
  }

  /**
   * @brief Inserts many elements at once
   *
   * @param args sequence of already constructed elements
   * @return Vector<std::pair<iterator, bool>> - iterators to the inserted
   * elements and indicators if the insertion took place
   */
  template <typename... Args>
  Vector<std::pair<iterator, bool>> emplace(Args &&...args) {
    return tree_.emplace(true, args...);
  }

private:
  binary_tree tree_;

  std::pair<std::pair<iterator, iterator>, size_type>
  count_and_find_last(const key_type &key) const {
    size_type result = 0;
    iterator first = tree_.find(key);
    if (!first.data())
      return std::pair<std::pair<iterator, iterator>, size_type>{
          std::pair<iterator, iterator>{iterator(nullptr, tree_.root()),
                                        iterator(nullptr, tree_.root())},
          result};
    ++result;
    iterator el(first);
    --el;
    while (el.data() && *first == *el) {
      ++result;
      --el;
    }
    if (el.data())
      ++el;
    else
      el = begin();
    return std::pair<std::pair<iterator, iterator>, size_type>{
        std::pair<iterator, iterator>{first, el}, result};
  };
};

} // namespace custom

#endif // _ASSOCIATIVE_CONTAINERS_MULTISET_CUSTOM_MULTISET_H_