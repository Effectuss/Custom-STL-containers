#ifndef _INTERFACES_CUSTOM_ITERATOR_H_
#define _INTERFACES_CUSTOM_ITERATOR_H_

namespace custom {

template <class T> class IIterator {
public:
  using value_type = T;
  using pointer = value_type *;
  using const_pointer = const value_type *;
  using reference = value_type &;
  using const_reference = const value_type &;
  using double_reference = value_type &&;

  explicit IIterator(const_pointer ptr) : ptr_((pointer)ptr) {}
  virtual ~IIterator() = 0;
  bool operator==(const IIterator &other) const { return ptr_ == other.ptr_; };
  bool operator!=(const IIterator &other) const { return !(*this == other); };
  pointer data() { return ptr_; };
  const_pointer data() const { return ptr_; }

protected:
  pointer ptr_;
};

template <class T> IIterator<T>::~IIterator() {}

} // namespace custom

#endif // _INTERFACES_CUSTOM_ITERATOR_H_