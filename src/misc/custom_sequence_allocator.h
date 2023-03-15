#ifndef _MISC_CUSTOM_SEQUENCE_ALLOCATOR_H_
#define _MISC_CUSTOM_SEQUENCE_ALLOCATOR_H_

#include <utility>

namespace custom {

template <class T> class SequenceAllocator__ {
public:
  using value_type = T;
  using size_type = std::size_t;
  using pointer = value_type *;
  using const_pointer = const value_type *;
  using reference = value_type &;
  using const_reference = const value_type &;
  using double_reference = value_type &&;

  [[nodiscard]] constexpr static pointer allocate(size_type size) {
    return static_cast<pointer>(operator new(size * sizeof(value_type)));
  }

  constexpr static void deallocate(pointer ptr) { operator delete(ptr); }

  constexpr SequenceAllocator__() : data_(nullptr), size_(size_type()) {}

  constexpr explicit SequenceAllocator__(size_type size) : size_(size) {
    if (size_)
      data_ = allocate(size);
    else
      data_ = nullptr;
  }

  ~SequenceAllocator__() {
    if (data_)
      deallocate(data_);
  }

  constexpr SequenceAllocator__(const SequenceAllocator__ &other) = delete;
  constexpr SequenceAllocator__ &
  operator=(const SequenceAllocator__ &other) = delete;
  constexpr SequenceAllocator__(SequenceAllocator__ &&other) { swap(other); }

  constexpr SequenceAllocator__ &operator=(SequenceAllocator__ &&other) {
    swap(other);
    return *this;
  }

  constexpr inline pointer operator+(size_type shift) { return data_ + shift; }
  constexpr inline const_pointer operator+(size_type shift) const {
    return data_ + shift;
  }
  constexpr inline pointer operator-(size_type shift) { return data_ - shift; }
  constexpr inline const_pointer operator-(size_type shift) const {
    return data_ - shift;
  }

  constexpr reference operator[](size_type pos) { return data_[pos]; }
  constexpr const_reference operator[](size_type pos) const {
    return data_[pos];
  }

  constexpr void swap(SequenceAllocator__ &other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
  }

  constexpr size_type size() const { return size_; }
  constexpr pointer data() { return data_; }
  constexpr const_pointer data() const { return data_; }

private:
  pointer data_;
  size_type size_;
};

} // namespace custom

#endif // _MISC_CUSTOM_SEQUENCE_ALLOCATOR_H_