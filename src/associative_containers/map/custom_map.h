#ifndef _ASSOCIATIVE_CONTAINERS_MAP_CUSTOM_MAP_H_
#define _ASSOCIATIVE_CONTAINERS_MAP_CUSTOM_MAP_H_

#include <stdexcept>

#include "../../misc/custom_binary_tree.h"

namespace custom {

// Specialization of tree iterator for first std::pair argument
template <class Pair> struct PairFirstElement__ {
  const typename Pair::first_type &operator()(const Pair &p) const {
    return p.first;
  }
};

/**
 * @brief Container to store pairs with unique keys that is based on the sorted
 * binary tree
 *
 * @tparam Key type of keys of pairs
 * @tparam T values of pairs
 * @tparam Compare defaults to @code std::less<Key> and sorts values in
 * ascending order, but can be also @code std::greater<Key> for storing values
 * in descending order
 */
template <class Key, class T, class Compare = std::less<Key>> class Map {
public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using binary_tree =
      SortedBinaryTree__<key_type, value_type, PairFirstElement__<value_type>,
                         Compare>;
  using key_compare = typename binary_tree::key_compare;
  using key_identify = typename binary_tree::key_identify;
  using reference = value_type &;
  using const_reference = const value_type;
  using iterator = typename binary_tree::iterator;
  using const_iterator = typename binary_tree::const_iterator;
  using size_type = typename binary_tree::size_type;

  Map() = default;
  Map(const Map &other) = default;
  Map(Map &&other) = default;
  ~Map() = default;
  explicit Map(const std::initializer_list<value_type> &items) : tree_(items) {}

  Map &operator=(const Map &other) = default;
  Map &operator=(Map &&other) = default;

  Map &operator=(const std::initializer_list<value_type> &items) {
    tree_.clear();
    for (auto i = items.begin(); i != items.end(); ++i)
      tree_.insert(*i);
    return *this;
  }

  /**
   * @brief Returns reference to the value of pair with given key. If there is
   * no pair with given key in the container - creates new one with default
   * constructor and returns reference to it
   *
   * @param key key to needed value
   * @return read/write reference to the value of the pair
   */
  mapped_type &operator[](const key_type &key) {
    return (*tree_.insert({key, mapped_type()}).first).second;
  }

  /**
   * @brief Checks if there is value with given key and returns reference to it.
   * If there is no value with given key - throws @code std::exception()
   *
   * @param key key to needed value
   * @return read/write reference to the value of the pair
   */
  mapped_type &at(const key_type &key) {
    auto is_contains = tree_.find(key);
    if (is_contains == tree_.end())
      throw std::exception();
    return (*is_contains).second;
  }

  /**
   * @brief Checks if there is value with given key and returns reference to it.
   * If there is no value with given key - throws @code std::exception()
   *
   * @param key key to needed value
   * @return read only reference to the value of the pair
   */
  const mapped_type &at(const key_type &key) const {
    auto is_contains = tree_.find(key);
    if (is_contains == tree_.end())
      throw std::exception();
    return (*is_contains).second;
  }

  /**
   * @brief Returns iterator to the start of the container
   *
   * @return read/write iterator
   */
  iterator begin() { return tree_.begin(); }

  /**
   * @brief Returns iterator to the start of the container
   *
   * @return read only iterator
   */
  const_iterator begin() const { return tree_.begin(); }

  /**
   * @brief Returns iterator to the past-end of container
   *
   * @return read/write iterator
   */
  iterator end() { return tree_.end(); }

  /**
   * @brief Returns iterator to the past-end of container
   *
   * @return read only iterator
   */
  const_iterator end() const { return tree_.end(); }

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
   * @param value pair key:value
   * @return std::pair<iterator, bool> - read/write iterator to where value was
   * inserted and bool indicating if insertion took place
   */
  std::pair<iterator, bool> insert(const_reference value) {
    return tree_.insert(value);
  }

  /**
   * @brief Inserts a new value into container
   *
   * @param key key of the pair
   * @param value value that corresponds to the given key
   * @return std::pair<iterator, bool> - read/write iterator to where value was
   * inserted and bool indicating if insertion took place
   */
  std::pair<iterator, bool> insert(const key_type &key,
                                   const mapped_type &value) {
    return tree_.insert({key, value});
  }

  /**
   * @brief Inserts nev pair with given key and value if there is no value with
   * given key or changes value of the key if there already a pair with given
   * key
   *
   * @param key key of the pair
   * @param value value that corresponds to the given key
   * @return read/write iterator to the pair with given key and indicator if new
   * element was created
   */
  std::pair<iterator, bool> insert_or_assign(const key_type &key,
                                             const mapped_type &value) {
    auto insert_result = insert({key, value});
    if (!insert_result.second) {
      (*(insert_result.first)).second = value;
    }
    return insert_result;
  }

  /**
   * @brief Removes value that stores where the pos points
   *
   * @param pos iterator to the element
   */
  void erase(iterator pos) { tree_.erase(pos); }

  /**
   * @brief Removes value with given key
   *
   * @param key key that needs to be deleted
   */
  void erase(const key_type &key) { tree_.erase(tree_.find(key)); }

  /**
   * @brief Swaps contents and size of the container with other map
   *
   * @param other container to be swapped
   */
  void swap(Map &other) { tree_.swap(other.tree_); }

  /**
   * @brief Extracts nodes from other container without allocating new values
   *
   * @param other container to be merged with
   */
  void merge(Map &other) { tree_.merge(other.tree_); }

  /**
   * @brief Finds element in the container by the key and returns an iterator to
   * pair with given element. If element is not in the container returns @code
   * end()
   *
   * @return read/write iterator to the element
   */
  iterator find(const key_type &key) { return tree_.find(key); }

  /**
   * @brief Finds element in the container by the key and returns an iterator to
   * pair with given element. If element is not in the container returns @code
   * end()
   *
   * @return read only iterator to the element
   */
  const_iterator find(const key_type &key) const { return tree_.find(key); }

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
  Vector<std::pair<const_iterator, bool>> emplace(Args &&...args) {
    return tree_.emplace(false, args...);
  }

private:
  binary_tree tree_;
};

} // namespace custom

#endif // _ASSOCIATIVE_CONTAINERS_MAP_CUSTOM_MAP_H_