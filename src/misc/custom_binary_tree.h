#ifndef _MISC_CUSTOM_BINARY_TREE_H_
#define _MISC_CUSTOM_BINARY_TREE_H_

#include <initializer_list>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <utility>

#include "../interfaces/custom_iterator.h"
#include "../sequence_containers/vector/custom_vector.h"

namespace custom {

// For set and map functions return values compatibility
template <class T> struct TypeOfValue__ {
  const T &operator()(const T &t__) const { return t__; }
};

template <class Key, class T, class Select = TypeOfValue__<Key>,
          class Compare = std::less<Key>>
class SortedBinaryTree__ {
public:
  using key_type = Key;
  using key_identify = Select;
  using value_type = T;
  using key_compare = Compare;
  using pointer = value_type *;
  using const_pointer = const value_type *;
  using reference = value_type &;
  using const_reference = const value_type &;
  using double_reference = value_type &&;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;

  SortedBinaryTree__();
  ~SortedBinaryTree__();
  SortedBinaryTree__(const SortedBinaryTree__ &other);
  SortedBinaryTree__(SortedBinaryTree__ &&other) noexcept;
  explicit SortedBinaryTree__(const std::initializer_list<value_type> &items);

  SortedBinaryTree__ &operator=(const SortedBinaryTree__ &other);
  SortedBinaryTree__ &operator=(SortedBinaryTree__ &&other);
  SortedBinaryTree__ &operator=(const std::initializer_list<value_type> &items);

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  bool contains(const key_type &key) const;
  void swap(SortedBinaryTree__ &other);
  void merge(SortedBinaryTree__ &other, bool is_repeated_allowed = false);
  void clear();

private:
  struct Node {
    using pointer = struct Node *;

    ~Node() = default;

    explicit Node(pointer parent = nullptr,
                  const_reference value = value_type())
        : data_(value), key_(key_identify()(data_)), left_(nullptr),
          right_(nullptr), parent_(parent) {}

    const key_type &key() const { return key_; }
    reference value() { return data_; }
    void set_parent(pointer parent) { parent_ = parent; }
    void set_left(pointer left) { left_ = left; }
    void set_right(pointer right) { right_ = right; }

    value_type data_;
    const key_type &key_;
    pointer left_;
    pointer right_;
    pointer parent_;
  };

  using node_type = struct Node;
  using node_pointer = node_type *;

public:
  class SortedBinaryTreeIterator__ : public IIterator<node_type> {
  public:
    using base = IIterator<node_type>;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;

    SortedBinaryTreeIterator__(node_pointer ptr, node_pointer root)
        : base(ptr), tree_root_(root) {}

    SortedBinaryTreeIterator__ &operator++();
    SortedBinaryTreeIterator__ operator++(int);
    SortedBinaryTreeIterator__ &operator--();
    SortedBinaryTreeIterator__ operator--(int);

    bool operator==(const SortedBinaryTreeIterator__ &other) const {
      return this->ptr_ == other.ptr_ && tree_root_ == other.tree_root_;
    }

    bool operator!=(const SortedBinaryTreeIterator__ &other) const {
      return !(*this == other);
    }

    reference operator*() { return this->ptr_->data_; }
    node_pointer root() { return tree_root_; }

  protected:
    node_pointer tree_root_;
  };

  using iterator = SortedBinaryTreeIterator__;

  class SortedBinaryTreeConstIterator__ : public iterator {
  public:
    using iterator_category = typename iterator::iterator_category;
    using difference_type = typename iterator::difference_type;

    SortedBinaryTreeConstIterator__(node_pointer ptr, node_pointer root)
        : iterator(ptr, root) {}

    explicit SortedBinaryTreeConstIterator__(const iterator &iter)
        : iterator(iter) {}

    const_reference operator*() const { return this->ptr_->data_; }
  };

  using const_iterator = SortedBinaryTreeConstIterator__;

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  std::pair<iterator, bool> insert(const_reference value,
                                   bool is_repeated_allowed = false);
  void erase(iterator pos);
  iterator find(const key_type &key);
  const_iterator find(const key_type &key) const;

  node_pointer root() const { return root_; }

  template <class... Args>
  Vector<std::pair<const_iterator, bool>> emplace(bool is_repeated_allowed,
                                                  Args &&...args);

private:
  node_pointer root_;
  size_type size_;

  value_type &at_helper(const key_type &key);
  node_pointer find_suitable_node(const key_type &key) const;

  std::pair<iterator, bool> insert_new_node(node_pointer node,
                                            node_pointer suitable_node,
                                            bool is_repeated_allowed = false);

  void erase_case_right_only(node_pointer save_ptr);
  void erase_case_right_and_left(node_pointer save_ptr);
  void erase_case_left_only(node_pointer save_ptr);
  void erase_case_no_childs(node_pointer save_ptr);
  node_pointer repoint_for_erase(iterator pos);

  void free_tree();

  template <class... Args>
  void emplace_helper(Vector<std::pair<const_iterator, bool>> &result,
                      bool is_repeated_allowed, const_reference value,
                      Args &&...rest);
  void emplace_helper(Vector<std::pair<const_iterator, bool>> &result,
                      bool is_repeated_allowed, const_reference value);
};

#include "custom_binary_tree.tpp"

} // namespace custom

#endif // _MISC_CUSTOM_BINARY_TREE_H_