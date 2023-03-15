/**
 * @brief construct an empty Vector<T> with zero size and capacity
 *
 */
template <class T>
constexpr Vector<T>::Vector() noexcept : data_(), size_(0UL) {}

template <class T> Vector<T>::~Vector() {
  for (size_type i = 0; i < size_; ++i)
    destroy(data_ + i);
}

/**
 * @brief construct a new Vector<T> object of specified size and fills data with
 * default values
 *
 * @param size Number of values
 */
template <class T>
constexpr Vector<T>::Vector(size_type size) : data_(size), size_(size) {
  for (size_type i = 0; i < size_; ++i)
    construct(data_ + i);
}

template <class T> constexpr Vector<T>::Vector(const Vector &other) : Vector() {
  *this = other;
}

template <class T>
constexpr Vector<T>::Vector(Vector &&other) noexcept : Vector() {
  *this = std::move(other);
}

template <class T>
constexpr Vector<T>::Vector(const std::initializer_list<value_type> &items)
    : data_(items.size()), size_(items.size()) {
  size_type i = 0UL;
  for (auto &el : items)
    construct(data_ + i++, std::move(el));
  // construct(data_ + i++, el);
}

template <class T>
constexpr Vector<T> &Vector<T>::operator=(const Vector &other) {
  if (this != &other) {
    clear();
    if (capacity() < other.capacity()) {
      allocator_type tmp(other.size_);
      data_.swap(tmp);
    }
    size_ = other.size_;
    for (size_type i = 0UL; i < size_; ++i)
      construct(data_ + i, other.data_[i]);
  }
  return *this;
}

template <class T>
constexpr Vector<T> &Vector<T>::operator=(Vector &&other) noexcept {
  if (this != &other) {
    for (size_type i = 0UL; i < size_; ++i)
      destroy(data_ + i);
    data_.swap(other.data_);
    std::swap(size_, other.size_);
  }
  return *this;
}

template <class T>
constexpr Vector<T> &
Vector<T>::operator=(std::initializer_list<value_type> const &items) {
  *this = std::move(Vector(items));
  return *this;
}

/**
 * @brief Function to access to elements of vector with boundary checks
 *
 * @param pos position of needed element
 * @return Read/write reference
 */
template <class T>
constexpr typename Vector<T>::reference Vector<T>::at(size_type pos) {
  if (pos >= size_)
    throw std::out_of_range(kOutOfRangeMsg);
  return data_[pos];
}

/**
 * @brief Function to access to elements of vector with boundary checks
 *
 * @param pos position of required element
 * @return Read only reference
 */
template <class T>
constexpr typename Vector<T>::const_reference
Vector<T>::at(size_type pos) const {
  if (pos >= size_)
    throw std::out_of_range(kOutOfRangeMsg);
  return data_[pos];
}

/**
 * @brief Provides access to data in vector array without boundary checks
 *
 * @param pos position of required element
 * @return Read/write reference
 */
template <class T>
constexpr typename Vector<T>::reference
Vector<T>::operator[](size_type pos) noexcept {
  return data_[pos];
}

/**
 * @brief Provides access to data in vector array without boundary checks
 *
 * @param pos position of required element
 * @return Read only reference
 */
template <class T>
constexpr typename Vector<T>::const_reference
Vector<T>::operator[](size_type pos) const noexcept {
  return data_[pos];
}

/**
 * @brief Returns read/write reference to the first element
 *
 * @return Read/write reference
 */
template <class T>
constexpr typename Vector<T>::reference Vector<T>::front() noexcept {
  return data_[0UL];
}

/**
 * @brief Returns read only reference to the first element
 *
 * @return Read only reference
 */
template <class T>
constexpr typename Vector<T>::const_reference
Vector<T>::front() const noexcept {
  return data_[0UL];
}

/**
 * @brief Returns read/write reference to the last element
 *
 * @return Read/write reference
 */
template <class T>
constexpr typename Vector<T>::reference Vector<T>::back() noexcept {
  return data_[size_ - 1UL];
}

/**
 * @brief Returns read only reference to the last element
 *
 * @return Read only reference
 */
template <class T>
constexpr typename Vector<T>::const_reference Vector<T>::back() const noexcept {
  return data_[size_ - 1UL];
}

/**
 * @brief Returns raw non-constant pointer to the data of the Vector
 *
 * @return Non-constant pointer
 */
template <class T>
constexpr typename Vector<T>::pointer Vector<T>::data() noexcept {
  return data_.data();
}

/**
 * @brief Returns raw constant pointer to the data of the Vector
 *
 * @return Constant pointer
 */
template <class T>
constexpr typename Vector<T>::const_pointer Vector<T>::data() const noexcept {
  return data_.data();
}

/**
 * @brief Checks if Vector is empty
 *
 * @return true if empty
 * @return false if not empty
 */
template <class T> constexpr bool Vector<T>::empty() const noexcept {
  return size_ == 0UL ? true : false;
}

/**
 * @brief Returns current size of the Vector
 *
 */
template <class T>
constexpr typename Vector<T>::size_type Vector<T>::size() const noexcept {
  return size_;
}

/**
 * @brief Returns theoretical maximum size of the Vector with current template
 * parameter
 *
 */
template <class T>
constexpr typename Vector<T>::size_type Vector<T>::max_size() const noexcept {
  return std::numeric_limits<difference_type>().max() / sizeof(value_type);
}

/**
 * @brief Reserves raw memory for new objects
 *
 * @param size Amount of objects that will be reserved
 */
template <class T> constexpr void Vector<T>::reserve(size_type size) {
  if (size > data_.size())
    shrink(size);
}

/**
 * @brief Returns amount of memory that is allocated for objects. It is not
 * necessary that all of these objects are initialized.
 *
 */
template <class T>
constexpr typename Vector<T>::size_type Vector<T>::capacity() const noexcept {
  return data_.size();
}

/**
 * @brief Frees memory that is used not for initialized objects
 *
 */
template <class T> constexpr void Vector<T>::shrink_to_fit() {
  if (data_.size() > size_)
    shrink(size_);
}

/**
 * @brief Frees all currently initialized objects
 *
 */
template <class T> constexpr void Vector<T>::clear() noexcept {
  for (size_type i = 0; i < size_; ++i)
    destroy(data_ + i);
  size_ = 0UL;
}

/**
 * @brief Function to add new element at the end of Vector. If there is not
 * enough raw memory for new object, doubles allocated raw memory
 *
 * @param value Constant reference to object so it can be copied
 */
template <class T> constexpr void Vector<T>::push_back(const_reference value) {
  reorganize_for_push_back();
  construct(data_ + size_++, value);
}

/**
 * @brief Function to add new element at the end of Vector. If there is not
 * enough raw memory for new object, doubles allocated raw memory
 *
 * @param value Double reference to object so it can be moved
 */
template <class T> constexpr void Vector<T>::push_back(double_reference value) {
  reorganize_for_push_back();
  construct(data_ + size_++, std::move(value));
}

/**
 * @brief Function to free last element of the Vector
 *
 */
template <class T> constexpr void Vector<T>::pop_back() {
  if (size_) {
    --size_;
    destroy(data_ + size_);
  }
}

/**
 * @brief Function to swap data and sizes of Vectors
 *
 * @param other Vector to be swapped with current Vector
 */
template <class T> constexpr void Vector<T>::swap(Vector &other) noexcept {
  data_.swap(other.data_);
  std::swap(size_, other.size_);
}

/**
 * @brief Function to add an element to the Vector at arbitrary place
 *
 * @param pos Iterator that points on the position in the Vector where element
 * will be added
 * @param value Constant reference to an element so it will be copied
 * @return Iterator that points at inserted object
 */
template <class T>
constexpr typename Vector<T>::iterator
Vector<T>::insert(iterator pos, const_reference value) {
  size_type distance = pos - data_.data();
  ++pos;
  push_back(value);
  for (pointer i = data_ + distance; i != data_ + size_; ++i) {
    value_type tmp = std::move(*i);
    *i = std::move(*(data_ + size_ - 1UL));
    *(data_ + size_ - 1UL) = std::move(tmp);
  }
  return data_ + distance;
}

/**
 * @brief Function to add an element to the Vector at arbitrary place
 *
 * @param pos Iterator that points on the position in the Vector where element
 * will be added
 * @param value Double reference to an element so it will be moved
 * @return Iterator that points at inserted object
 */
template <class T>
constexpr typename Vector<T>::iterator
Vector<T>::insert(iterator pos, double_reference value) {
  size_type distance = pos - data_.data();
  ++pos;
  push_back(std::move(value));
  for (pointer i = data_ + distance; i != data_ + size_; ++i) {
    value_type tmp = std::move(*i);
    *i = std::move(*(data_ + size_ - 1UL));
    *(data_ + size_ - 1UL) = std::move(tmp);
  }
  return data_ + distance;
}

/**
 * @brief Function to delete an element from the Vector at arbitrary place
 *
 * @param pos Iterator that points at the needed element
 */
template <class T> constexpr void Vector<T>::erase(iterator pos) {
  if (size_) {
    for (auto i = pos; i != end() - 1UL; ++i)
      std::swap(*i, *(i + 1UL));
    destroy((pointer)((end() - 1UL)));
    --size_;
  }
}

/**
 * @brief Returns read/write iterator on the first element in the Vector
 *
 */
template <class T>
constexpr typename Vector<T>::iterator Vector<T>::begin() noexcept {
  return data_.data();
}

/**
 * @brief Returns read/write iterator on the next from the last element in the
 * Vector
 *
 */
template <class T>
constexpr typename Vector<T>::iterator Vector<T>::end() noexcept {
  return data_ + size_;
}

/**
 * @brief Returns read only iterator on the first element in the Vector
 *
 */
template <class T>
constexpr typename Vector<T>::const_iterator Vector<T>::begin() const noexcept {
  return data_.data();
  ;
}

/**
 * @brief Returns read only iterator on the next from the last element in the
 * Vector
 *
 */
template <class T>
constexpr typename Vector<T>::const_iterator Vector<T>::end() const noexcept {
  return data_ + size_;
}

/**
 * @brief Inserts many elements at once in position of given iterator
 *
 * @param pos where to insert
 * @param args sequence of values that need to be inserted
 * @return read/write iterator to the first inserted value
 */
template <class T>
template <typename... Args>
constexpr typename Vector<T>::iterator Vector<T>::emplace(const_iterator pos,
                                                          Args &&...args) {
  return emplace_helper(pos, args...);
}

/**
 * @brief Inserts many elements at the end of the vector
 *
 * @param args sequence of values that need to be inserted
 * @return read/write iterator to the first inserted value
 */
template <class T>
template <typename... Args>
constexpr void Vector<T>::emplace_back(Args &&...args) {
  emplace_helper(end(), args...);
}

template <class T>
template <typename... Args>
constexpr typename Vector<T>::iterator
Vector<T>::emplace_helper(const_iterator pos, reference first, Args &&...args) {
  pos = insert((pointer)pos, first);
  ++pos;
  return emplace_helper(pos, args...);
}

template <class T>
constexpr typename Vector<T>::iterator
Vector<T>::emplace_helper(const_iterator pos, reference value) {
  iterator result = (iterator)insert((iterator)pos, value);
  ++result;
  return result;
}

template <class T> constexpr void Vector<T>::shrink(size_type size) {
  if (size > max_size())
    throw std::length_error(kMaxCapacityMsg);
  allocator_type new_data(size);
  for (size_type i = 0UL; i < size_; ++i) {
    construct(new_data + i, std::move(data_[i]));
    destroy(data_ + i);
  }
  data_.swap(new_data);
}

template <class T> constexpr void Vector<T>::reorganize_for_push_back() {
  if (capacity()) {
    if (size_ == capacity()) {
      if (capacity() == max_size())
        throw std::length_error(kMaxCapacityReachedMsg);
      else if (capacity() * 2UL > max_size())
        shrink(max_size());
      else
        shrink(capacity() * 2UL);
    }
  } else {
    allocator_type tmp(1UL);
    data_.swap(tmp);
  }
}

template <class T> constexpr void Vector<T>::construct(void *ptr) {
  new (ptr) value_type();
}

template <class T>
constexpr void Vector<T>::construct(void *ptr, const_reference el) {
  new (ptr) value_type(el);
}

template <class T>
constexpr void Vector<T>::construct(void *ptr, double_reference el) {
  new (ptr) value_type(std::move(el));
}

template <class T> constexpr void Vector<T>::destroy(value_type *ptr) {
  ptr->~value_type();
}