#ifndef _SEQUENCE_CONTAINERS_STACK_CUSTOM_STACK_H_
#define _SEQUENCE_CONTAINERS_STACK_CUSTOM_STACK_H_

#include "../list/custom_list.h"
#include "../vector/custom_vector.h"

namespace custom {

template <class T, class Container = custom::List<T>> class Stack {
public:
  using container_type = Container;
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

  /**
   * @brief  Default constructor. Value-initializes the container.
   *
   */
  Stack() = default;

  /**
   * @brief Constructs the container with the contents of the initializer list
   * items.
   *
   * @param items initializer stack to initialize the elements of the container
   * with
   */
  explicit Stack(std::initializer_list<value_type> const &items)
      : stack_(items) {}

  /**
   * @brief Copy constructor. The adaptor is copy-constructed with the contents
   * of other.c.
   *
   * @param other another container adaptor to be used as source to initialize
   * the underlying container
   */
  Stack(const Stack &other) : stack_(other.stack_) {}

  /**
   * @brief Move constructor. The adaptor is constructed with
   * std::move(other.c).
   *
   * @param other another container adaptor to be used as source to initialize
   * the underlying container
   */
  Stack(Stack &&other) : stack_(std::move(other.stack_)) {}

  /**
   * @brief Destructs the stack. The destructors of the elements are called and
   * the used storage is deallocated.
   *
   */
  ~Stack() = default;

  /**
   * @brief Replaces the contents of the container adaptor with those of other.
   *
   * @param other another container adaptor to be used as source
   * @return *this
   */
  Stack &operator=(Stack &&other) {
    stack_ = std::move(other.stack_);
    return *this;
  }

  /**
   * @brief Move assignment operator. Replaces the contents with those of other
   * using move semantics. Effectively calls c = std::move(other.c);
   *
   * @param other another container adaptor to be used as source
   * @return *this
   */
  Stack &operator=(const Stack &other) {
    stack_ = other.stack_;
    return *this;
  }

  /**
   * @brief Returns reference to the top element in the stack. This is the most
   * recently pushed element. This element will be removed on a call to pop().
   * Effectively calls c.back().
   *
   * @return Reference to the last element
   */
  reference top() { return stack_.back(); }

  /**
   * @brief Returns reference to the top element in the stack. This is the most
   * recently pushed element. This element will be removed on a call to pop().
   * Effectively calls c.back().
   *
   * @return const reference to the last element
   */
  const_reference top() const { return stack_.back(); }

  /**
   * @brief Checks if the underlying container has no elements, i.e. whether
   * c.empty().
   *
   * @return true if the underlying container is empty, false otherwise
   */
  bool empty() const { return stack_.empty(); }

  /**
   * @brief Returns the number of elements in the underlying container, that is,
   * c.size().
   *
   * @return The number of elements in the container.
   */
  size_type size() const { return stack_.size(); }

  /**
   * @brief Pushes the given element value to the top of the stack. Effectively
   * calls c.push_back(value)
   *
   * @param value the value of the element to push
   */
  void push(const_reference value) { stack_.push_back(value); }

  /**
   * @brief Removes the top element from the stack. Effectively calls
   * c.pop_back()
   *
   */
  void pop() { stack_.pop_back(); }

  /**
   * @brief Exchanges the contents of the container adaptor with those of other.
   * Effectively calls using std::swap; swap(c, other.c);
   *
   * @param other container adaptor to exchange the contents with
   */
  void swap(Stack &other) { stack_.swap(other.stack_); }

  /**
   * @brief Pushes a new element on top of the stack. The element is constructed
   * in-place, i.e. no copy or move operations are performed.
   *
   * @param args 	arguments to forward to the constructor of the element
   */
  template <class... Args> void emplace_front(Args &&...args) {
    (stack_.emplace_back(std::forward<Args>(args)), ...);
  }

private:
  container_type stack_;
};
} // namespace custom

#endif // _SEQUENCE_CONTAINERS_STACK_CUSTOM_STACK_H_