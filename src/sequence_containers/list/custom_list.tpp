/**
 * @brief Default constructor. Constructs an empty container
 *
 */
template <class value_type> List<value_type>::List() : size_{0} {
  shadow_node_ = new Node(value_type());
  shadow_node_->prev_ = shadow_node_;
  shadow_node_->next_ = shadow_node_;
}

/**
 * @brief Constructs the container with count default-inserted instances of
 * value_type. No copies are made.
 *
 * @param count
 */
template <class value_type> List<value_type>::List(size_type count) : List() {
  while (count--)
    push_back(value_type());
}

/**
 * @brief Constructs the container with the contents of the initializer list
 * items.
 *
 * @param items initializer list to initialize the elements of the container
 * with
 */
template <class value_type>
List<value_type>::List(const std::initializer_list<value_type> &items)
    : List() {
  for (auto &el : items)
    push_back(el);
}

/**
 * @brief Copy constructor. Constructs the container with the copy of the
 * contents of l.
 *
 * @param l another container to be used as source to initialize the elements of
 * the container with
 */
template <class value_type>
List<value_type>::List(const List<value_type> &l) : List() {
  copy_list(l);
}

/**
 * @brief Move constructor. Constructs the container with the contents of other
 * using move semantics.
 *
 * @param l another container to be used as source to initialize the elements of
 * the container with
 */
template <class value_type>
List<value_type>::List(List<value_type> &&l) : List() {
  swap(l);
}

/**
 * @brief Destructs the list. The destructors of the elements are called and the
 * used storage is deallocated
 *
 */
template <class value_type> List<value_type>::~List() {
  clear();
  delete shadow_node_;
}

/**
 * @brief Move assignment operator. Replaces the contents with those of other
 * using move semantics (i.e. the data in other is moved from other into this
 * container).
 *
 * @param other another container to use as data source
 * @return *this
 */
template <class value_type>
List<value_type> &List<value_type>::operator=(List<value_type> &&other) {
  if (this != &other) {
    this->clear();
    this->swap(other);
  }
  return *this;
}

/**
 * @brief Copy assignment operator. Replaces the contents with a copy of the
 * contents of other.
 *
 * @param other another container to use as data source
 * @return *this
 */
template <class value_type>
List<value_type> &List<value_type>::operator=(const List<value_type> &other) {
  if (this != &other) {
    this->clear();
    copy_list(other);
  }
  return *this;
}

/**
 * @brief Returns a reference to the last element in the container. Calling back
 * on an empty container causes undefined behavior.
 *
 * @return reference to the last element.
 */
template <class value_type>
typename List<value_type>::reference List<value_type>::back() {
  return shadow_node_->prev_->data_;
}

/**
 * @brief Returns a const reference to the last element in the container.
 * Calling back on an empty container causes undefined behavior.
 *
 * @return const reference to the last element.
 */
template <class value_type>
typename List<value_type>::const_reference List<value_type>::back() const {
  return shadow_node_->prev_->data_;
}

/**
 * @brief Returns a reference to the first element in the container. Calling
 * front on an empty container is undefined.
 *
 * @return reference to the first element
 */
template <class value_type>
typename List<value_type>::reference List<value_type>::front() {
  return shadow_node_->next_->data_;
}

/**
 * @brief Returns a const reference to the first element in the container.
 * Calling front on an empty container is undefined.
 *
 * @return const reference to the first element
 */
template <class value_type>
typename List<value_type>::const_reference List<value_type>::front() const {
  return shadow_node_->next_->data_;
}

/**
 * @brief Returns an iterator to the first element of the list. If the list is
 empty, the returned iterator will be equal to end().
 *
 * @return iterator to the first element
 */
template <class value_type>
typename List<value_type>::iterator List<value_type>::begin() noexcept {
  return iterator(shadow_node_->next_);
}

/**
 * @brief Returns an const iterator to the first element of the list.
 *
 * @return const iterator to the first element
 */
template <class value_type>
typename List<value_type>::const_iterator
List<value_type>::begin() const noexcept {
  return const_iterator(shadow_node_->next_);
}

/**
 * @brief Returns an const iterator to the first element of the list.
 *
 * @return const iterator to the first element
 */
template <class value_type>
typename List<value_type>::const_iterator
List<value_type>::cbegin() const noexcept {
  return const_iterator(shadow_node_->next_);
}

/**
 * @brief Returns an iterator to the element following the last element of the
 * list.
 *
 * @return Iterator to the element following the last element.
 */
template <class value_type>
typename List<value_type>::iterator List<value_type>::end() noexcept {
  return iterator(shadow_node_);
}

/**
 * @brief Returns an const iterator to the element following the last element of
 * the list.
 *
 * @return const iterator to the element following the last element.
 */
template <class value_type>
typename List<value_type>::const_iterator
List<value_type>::end() const noexcept {
  return const_iterator(shadow_node_);
}

/**
 * @brief Returns an const iterator to the element following the last element of
 * the list.
 *
 * @return const iterator to the element following the last element.
 */
template <class value_type>
typename List<value_type>::const_iterator
List<value_type>::cend() const noexcept {
  return const_iterator(shadow_node_);
}

/**
 * @brief Returns the number of elements in the container
 *
 * @return The number of elements in the container.
 */
template <class value_type>
typename List<value_type>::size_type List<value_type>::size() const noexcept {
  return this->size_;
}

/**
 * @brief Checks if the container has no elements, i.e. whether begin() ==
 * end().
 *
 * @return true if the container is empty, false otherwise
 */
template <class value_type> bool List<value_type>::empty() const noexcept {
  return ((shadow_node_->prev_ == shadow_node_) &&
          (shadow_node_->next_ == shadow_node_));
}

/**
 * @brief Returns the maximum number of elements the container is able to hold
 * due to system or library implementation limitations
 *
 * @return Maximum number of elements.
 */
template <class value_type>
typename List<value_type>::size_type
List<value_type>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
}

/**
 * @brief inserts value before pos.
 *
 * @param pos iterator before which the content will be inserted.
 * @param value element value to insert
 * @return Iterator pointing to the inserted value.
 */
template <class value_type>
typename List<value_type>::iterator
List<value_type>::insert(iterator pos, const_reference value) {
  return insert_after(iterator(pos.ptr_->prev_), value);
}

template <class value_type>
typename List<value_type>::iterator
List<value_type>::insert_after(iterator pos, const_reference value) {
  Node *current = new Node(value, pos.ptr_->next_, pos.ptr_);
  pos.ptr_->next_->prev_ = current;
  pos.ptr_->next_ = current;
  ++size_;
  return iterator(current);
}

/**
 * @brief inserts new elements into the container directly before pos
 *
 * @tparam Args
 * @param pos iterator before which the new element will be constructed
 * @param args arguments to forward to the constructor of the element
 * @return Iterator pointing to the last emplaced element.
 */
template <class value_type>
template <class... Args>
typename List<value_type>::iterator
List<value_type>::emplace(const_iterator pos, Args &&...args) {
  value_type elements[] = {args...};
  size_type tmp_size = sizeof...(args);
  auto it_res = static_cast<iterator>(pos);
  for (size_type i = 0; i < tmp_size; ++i) {
    if (i == 0)
      it_res = insert(it_res, elements[i]);
    else
      it_res = insert_after(it_res, elements[i]);
  }
  return it_res;
}

/**
 * @brief appends new elements to the end of the container
 *
 * @param args 	arguments to forward to the constructor of the element
 */
template <class value_type>
template <class... Args>
void List<value_type>::emplace_back(Args &&...args) {
  (this->push_back(args), ...);
}

/**
 * @brief appends new elements to the top of the container
 *
 * @param args 	arguments to forward to the constructor of the element
 */
template <class value_type>
template <class... Args>
void List<value_type>::emplace_front(Args &&...args) {
  value_type elements[] = {args...};
  size_type tmp_size = sizeof...(args);
  auto it_pos = begin();
  for (size_type i = 0; i < tmp_size; ++i) {
    if (i == 0) {
      push_front(elements[i]);
      --it_pos;
    } else {
      it_pos = insert_after(it_pos, elements[i]);
    }
  }
}

/**
 * @brief Erases the specified elements from the container. Removes the element
 * at pos. References and iterators to the erased elements are invalidated.
 * Other references and iterators are not affected. The iterator pos must be
 * valid and dereferenceable. Thus the end() iterator (which is valid, but is
 * not dereferenceable) cannot be used as a value for pos.
 *
 * @param pos iterator to the element to remove
 * @return List<value_type>::iterator
 */
template <class value_type>
typename List<value_type>::iterator List<value_type>::erase(iterator pos) {
  if (pos == end())
    throw std::invalid_argument("value_typehe pos can't be point on end");
  Node *pretarget = pos.ptr_->prev_;
  Node *aftertarget = pos.ptr_->next_;
  aftertarget->prev_ = pretarget;
  pretarget->next_ = aftertarget;
  --size_;
  delete pos.ptr_;
  return iterator(aftertarget);
}

/**
 * @brief Prepends the given element value to the beginning of the container.
 *
 * @param value the value of the element to prepend
 */
template <class value_type>
void List<value_type>::push_front(const_reference value) {
  insert_after(const_iterator(shadow_node_), value);
}

/**
 * @brief Appends the given element value to the end of the container.
 *
 * @param value the value of the element to append
 */
template <class value_type>
void List<value_type>::push_back(const_reference value) {
  insert_after(const_iterator(shadow_node_->prev_), value);
}

/**
 * @brief Removes the last element of the container.
 *
 */
template <class value_type> void List<value_type>::pop_back() {
  erase(const_iterator(shadow_node_->prev_));
}

/**
 * @brief Removes the first element of the container.
 *
 */
template <class value_type> void List<value_type>::pop_front() {
  erase(const_iterator(shadow_node_->next_));
}

/**
 * @brief Erases all elements from the container. After this call, size()
 returns zero.
 *
 */
template <class value_type> void List<value_type>::clear() {
  while (!empty())
    pop_back();
  size_ = 0;
}

/**
 * @brief Exchanges the contents of the container with those of other. Does not
 * invoke any move, copy, or swap operations on individual elements.
 *
 * @param other container to exchange the contents with
 */
template <class value_type>
void List<value_type>::swap(List<value_type> &other) {
  std::swap(shadow_node_, other.shadow_node_);
  std::swap(size_, other.size_);
}

template <class value_type>
void List<value_type>::copy_list(const List<value_type> &other) {
  for (auto it = other.begin(); it != other.end(); ++it)
    push_back(*it);
  this->size_ = other.size_;
}

/**
 * @brief Reverses the order of the elements in the container. No references or
 * iterators become invalidated.
 *
 */
template <class value_type> void List<value_type>::reverse() noexcept {
  auto head = begin();
  auto tail = iterator(shadow_node_->prev_);
  for (auto tmp_size = size_ / 2; tmp_size; --tmp_size, ++head, --tail)
    std::swap(*tail, *head);
}

/**
 * @brief Sorts the elements in ascending order. The order of equal elements is
 * preserved.
 *
 */
template <class value_type> void List<value_type>::sort() {
  int long tmp_size = static_cast<int long>(size_);
  for (int long i = 0; i < tmp_size - 1; ++i) {
    auto it_begin = begin();
    auto it_next_begin = begin();
    ++it_next_begin;
    for (int long j = 0; j < tmp_size - i - 1;
         ++j, ++it_begin, ++it_next_begin) {
      if (*it_begin > *it_next_begin)
        std::swap(*it_begin, *it_next_begin);
    }
  }
}

/**
 * @brief Removes all consecutive duplicate elements from the container. Only
 * the first element in each group of equal elements is left.
 *
 */
template <class value_type> void List<value_type>::unique() {
  for (auto it = begin(); it != end(); ++it) {
    while (it.ptr_->data_ == it.ptr_->next_->data_)
      erase(iterator(it.ptr_->next_));
  }
}

/**
 * @brief Transfers elements from one list to another. Transfers all elements
 * from other into *this. The elements are inserted before the element pointed
 * to by pos. The container other becomes empty after the operation. The
 * behavior is undefined if other refers to the same object as *this.
 *
 * @param pos element before which the content will be inserted
 * @param other	another container to transfer the content from
 */
template <class value_type>
void List<value_type>::splice(const_iterator pos, List<value_type> &other) {
  if (this == &other)
    throw std::logic_error(
        "*this == &other, two object indicate on one object");
  if (!other.empty()) {
    for (auto it = other.begin(); it != other.end(); ++it) {
      this->insert(pos, *it);
    }
    other.clear();
  }
}

/**
 * @brief Merges two sorted lists into one. The lists should be sorted into
 * ascending order. No elements are copied. The container other becomes empty
 * after the operation. No iterators or references become invalidated, except
 * that the iterators of moved elements now refer into *this, not into other.
 * Use operator < for compare
 *
 * @param other another container to merge
 */
template <class value_type>
void List<value_type>::merge(List<value_type> &other) {
  if (this != &other) {
    auto it_begin_this = begin();
    auto it_begin_other = other.begin();
    for (auto i = other.size_ + size_; i != 0; --i) {
      if ((*it_begin_this <= *it_begin_other) && (it_begin_this != end())) {
        ++it_begin_this;
      } else if (it_begin_other != other.end()) {
        insert(it_begin_this, *it_begin_other);
        ++it_begin_other;
      }
    }
    other.clear();
  }
}
