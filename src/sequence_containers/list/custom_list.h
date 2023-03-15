#ifndef _SEQUENCE_CONTAINERS_LIST_CUSTOM_LIST_H_
#define _SEQUENCE_CONTAINERS_LIST_CUSTOM_LIST_H_

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <limits>
#include <stdexcept>

namespace custom {

template <class T> class List {
public:
  using size_type = std::size_t;
  using value_type = T;
  using pointer = value_type *;
  using const_pointer = const value_type *;
  using reference = value_type &;
  using const_reference = const value_type &;

private:
  class Node {
  public:
    Node() = delete;
    Node(const value_type &data = value_type(), Node *next = nullptr,
         Node *prev = nullptr)
        : data_{data}, next_{next}, prev_{prev} {}
    value_type data_;
    Node *next_;
    Node *prev_;
  };

public:
  class ListIterator {
  public:
    template <class> friend class List;

    explicit ListIterator(Node *ptr) : ptr_{ptr} {}
    Node *data() { return ptr_; };
    const Node *data() const { return ptr_; }
    bool operator==(const ListIterator &other) const {
      return ptr_ == other.ptr_;
    }
    bool operator!=(const ListIterator &other) const {
      return ptr_ != other.ptr_;
    }
    ListIterator &operator++() noexcept {
      ptr_ = ptr_->next_;
      return *this;
    }
    ListIterator operator++(int) noexcept {
      ListIterator tmp(*this);
      ptr_ = ptr_->next_;
      return tmp;
    }
    ListIterator &operator--() noexcept {
      ptr_ = ptr_->prev_;
      return *this;
    }
    ListIterator operator--(int) noexcept {
      ListIterator tmp(*this);
      ptr_ = ptr_->prev_;
      return tmp;
    }
    reference operator*() noexcept { return this->data()->data_; }

  private:
    Node *ptr_;
  };

  using iterator = ListIterator;

  class ListConstIterator : public iterator {
  public:
    explicit ListConstIterator(Node *ptr) : iterator(ptr) {}
    explicit ListConstIterator(iterator it) : iterator(it) {}
    const_reference operator*() noexcept { return this->data()->data_; }
  };

  using const_iterator = ListConstIterator;

  List();
  explicit List(size_type count);
  explicit List(std::initializer_list<value_type> const &items);
  List(const List &l);
  List(List &&l);
  ~List();

  List &operator=(List &&other);
  List &operator=(const List &other);

  reference back();
  const_reference back() const;
  reference front();
  const_reference front() const;

  size_type size() const noexcept;
  bool empty() const noexcept;
  size_type max_size() const noexcept;

  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  const_iterator cbegin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;
  const_iterator cend() const noexcept;

  void clear();
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(List &other);

  iterator insert(iterator pos, const_reference value);
  iterator erase(iterator pos);
  void reverse() noexcept;
  void sort();
  void unique();
  void splice(const_iterator pos, List &other);
  void merge(List &other);

  void emplace() {}
  template <class... Args> iterator emplace(const_iterator pos, Args &&...args);
  template <class... Args> void emplace_back(Args &&...args);
  template <class... Args> void emplace_front(Args &&...args);

private:
  size_type size_;
  Node *shadow_node_;
  iterator insert_after(iterator pos, const_reference value);
  void copy_list(const List<T> &other);
};

#include "custom_list.tpp"

} // namespace custom

#endif // _SEQUENCE_CONTAINERS_LIST_CUSTOM_LIST_H_
