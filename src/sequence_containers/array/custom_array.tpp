template <class T, const std::size_t N>
constexpr Array<T, N>::Array(const std::initializer_list<value_type> &items) {
  *this = items;
}

template <class T, const std::size_t N>
constexpr Array<T, N> &
Array<T, N>::operator=(const std::initializer_list<value_type> &items) {
  pointer current = data_;
  for (auto &i : items) {
    *current = std::move(i);
    if (++current == data_ + N)
      break;
  }
  return *this;
}

/**
 * @brief Returns an element of array with number @code pos but checks
 * boundaries and throws std::exception if index is out of bounds
 *
 * @param pos number of element
 * @return read/write reference
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::at(size_type pos) {
  if (pos >= N)
    throw std::exception();
  return data_[pos];
}

/**
 * @brief Returns reference to an element of array with number @code pos but
 * checks boundaries and throws std::exception if index is out of bounds
 *
 * @param pos index of element
 * @return read only reference
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::const_reference
Array<T, N>::at(size_type pos) const {
  if (pos >= N)
    throw std::exception();
  return data_[pos];
}

/**
 * @brief Returns reference to an element of array with number @code pos without
 * boundary checks
 *
 * @param pos index of element
 * @return read/write reference
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::reference
Array<T, N>::operator[](size_type pos) {
  return data_[pos];
}

/**
 * @brief Returns reference to an element of array with number @code pos without
 * boundary checks
 *
 * @param pos index of element
 * @return read only reference
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::const_reference
Array<T, N>::operator[](size_type pos) const {
  return data_[pos];
}

/**
 * @brief Returns reference to the first element of array
 *
 * @return read/write reference
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::front() {
  return *data_;
}

/**
 * @brief Returns reference to the first element of array
 *
 * @return read only reference
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::const_reference Array<T, N>::front() const {
  return *data_;
}

/**
 * @brief Returns reference to the last element of array
 *
 * @return read/write reference
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::reference Array<T, N>::back() {
  return data_[N - 1];
}

/**
 * @brief Returns reference to the last element of array
 *
 * @return read only reference
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::const_reference Array<T, N>::back() const {
  return data_[N - 1];
}

/**
 * @brief Returns pointer to the underlaying data array
 *
 * @return non-constant pointer
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::iterator Array<T, N>::data() {
  return data_;
}

/**
 * @brief Returns pointer to the underlaying data array
 *
 * @return constant pointer
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::data() const {
  return data_;
}

/**
 * @brief Returns iterator to the beginning of the array
 *
 * @return non-constant pointer
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::iterator Array<T, N>::begin() {
  return data();
}

/**
 * @brief Returns iterator to the beginning of the array
 *
 * @return constant pointer
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::begin() const {
  return data();
}

/**
 * @brief Returns iterator to the past-end element of the array
 *
 * @return non-constant pointer
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::iterator Array<T, N>::end() {
  return data() + N;
}

/**
 * @brief Returns iterator to the past-end element of the array
 *
 * @return constant pointer
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::const_iterator Array<T, N>::end() const {
  return data() + N;
}
/**
 * @brief Checks if the array has no elements
 *
 * @return true if array is empty
 * @return false otherwise
 */
template <class T, const std::size_t N>
constexpr bool Array<T, N>::empty() const {
  return !N;
}

/**
 * @brief Returns actual size of the array
 *
 * @return size of the array
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::size_type Array<T, N>::size() const {
  return N;
}

/**
 * @brief Returns actual size of the array
 *
 * @return size of the array
 */
template <class T, const std::size_t N>
constexpr typename Array<T, N>::size_type Array<T, N>::max_size() const {
  return size();
}

/**
 * @brief Swaps two arrays data with each other
 *
 * @param other array to swap data with
 */
template <class T, const std::size_t N>
constexpr void Array<T, N>::swap(Array &other) {
  std::swap(data_, other.data_);
}

/**
 * @brief Fills array with given element
 *
 * @param value constant reference to an element
 */
template <class T, const std::size_t N>
constexpr void Array<T, N>::fill(const_reference value) {
  std::fill(begin(), end(), value);
}