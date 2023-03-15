#ifndef _SEQUENCE_CONTAINERS_QUEUE_CUSTOM_QUEUE_H_
#define _SEQUENCE_CONTAINERS_QUEUE_CUSTOM_QUEUE_H_

#include "../list/custom_list.h"
#include "../vector/custom_vector.h"

namespace custom {

template <class T, class Container = custom::List<T>> class Queue {
public:
  using container_type = Container;
  using value_type = typename Container::value_type;
  using size_type = typename Container::size_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;

  /**
   * @brief Default constructor. Value-initializes the container
   *
   */
  Queue() = default;

  /**
   * @brief Constructs the container with the contents of the initializer list
   * items
   *
   * @param items initializer queue to initialize the elements of the container
   * with
   */
  explicit Queue(std::initializer_list<value_type> const &items)
      : queue_(items) {}

  /**
   * @brief Copy constructor. The adaptor is copy-constructed with the contents
   * of other.c.
   *
   * @param other another container adaptor to be used as source to initialize
   the underlying container
   */
  Queue(const Queue &other) : queue_(other.queue_) {}

  /**
   * @brief Move constructor. The adaptor is constructed with
   * std::move(other.c).
   *
   * @param other another container adaptor to be used as source to initialize
   * the underlying container
   */
  Queue(Queue &&other) : queue_(std::move(other.queue_)) {}

  /**
   * @brief Destructs the queue. The destructors of the elements are called and
   * the used storage is deallocated
   *
   */
  ~Queue() = default;

  /**
   * @brief Replaces the contents of the container adaptor with those of other.
   * Copy assignment operator. Replaces the contents with a copy of the contents
   * of other. Effectively calls c = other.c;
   *
   * @param other another container adaptor to be used as source
   * @return *this
   */
  Queue &operator=(Queue &&other) {
    queue_ = std::move(other.queue_);
    return *this;
  }

  /**
   * @brief Replaces the contents of the container adaptor with those of other.
   * Move assignment operator. Replaces the contents with those of other using
   * move semantics. Effectively calls c = std::move(other.c);
   *
   * @param other another container adaptor to be used as source
   * @return *this
   */
  Queue &operator=(const Queue &other) {
    queue_ = other.queue_;
    return *this;
  }

  /**
   * @brief Returns reference to the first element in the queue. This element
   * will be the first element to be removed on a call to pop(). Effectively
   * calls c.front()
   *
   * @return const reference to the first element.
   */
  const_reference front() const { return queue_.front(); }

  /**
   * @brief Returns reference to the last element in the queue. This is the most
   * recently pushed element. Effectively calls c.back().
   *
   * @return const reference to the last element
   */
  const_reference back() const { return queue_.back(); }

  /**
   * @brief Returns reference to the first element in the queue. This element
   * will be the first element to be removed on a call to pop(). Effectively
   * calls c.front()
   *
   * @return const reference to the first element.
   */
  reference front() { return queue_.front(); }

  /**
   * @brief Returns reference to the last element in the queue. This is the most
   * recently pushed element. Effectively calls c.back().
   *
   * @return reference to the first element.
   */
  reference back() { return queue_.back(); }

  /**
   * @brief Checks if the underlying container has no elements, i.e. whether
   * c.empty().
   *
   * @return true if the underlying container is empty, false otherwise
   */
  bool empty() const { return queue_.empty(); }

  /**
   * @brief Returns the number of elements in the underlying container, that is,
   * c.size().
   *
   * @return The number of elements in the container.
   */
  size_type size() const { return queue_.size(); }

  /**
   * @brief Pushes the given element value to the end of the queue.
   *
   * @param value the value of the element to push
   */
  void push(const_reference value) { queue_.push_back(value); }

  /**
   * @brief Removes an element from the front of the queue. Effectively calls
   * c.pop_front()
   *
   */
  void pop() { queue_.pop_front(); }

  /**
   * @brief changes the contents of the container adaptor with those of other.
   *
   * @param other	container adaptor to exchange the contents with
   */
  void swap(Queue &other) { queue_.swap(other.queue_); }

  /**
   * @brief Pushes a new element to the end of the queue. The element is
   * constructed in-place, i.e. no copy or move operations are performed
   *
   * @param args arguments to forward to the constructor of the element
   */
  template <class... Args> void emplace_back(Args &&...args) {
    (queue_.emplace_back(std::forward<Args>(args)), ...);
  }

private:
  container_type queue_;
};
}; // namespace custom

#endif // _SEQUENCE_CONTAINERS_QUEUE_CUSTOM_QUEUE_H_