template <class K, class T, class S, class C>
SortedBinaryTree__<K, T, S, C>::SortedBinaryTree__()
    : root_(nullptr), size_(0UL) {}

template <class K, class T, class S, class C>
SortedBinaryTree__<K, T, S, C>::~SortedBinaryTree__() {
  free_tree();
}

template <class K, class T, class S, class C>
SortedBinaryTree__<K, T, S, C>::SortedBinaryTree__(
    const SortedBinaryTree__ &other)
    : SortedBinaryTree__() {
  for (auto i = other.begin(); i != other.end(); ++i)
    (*this).insert(*i);
}

template <class K, class T, class S, class C>
SortedBinaryTree__<K, T, S, C>::SortedBinaryTree__(
    SortedBinaryTree__ &&other) noexcept
    : SortedBinaryTree__() {
  std::swap(root_, other.root_);
  std::swap(size_, other.size_);
}

template <class K, class T, class S, class C>
SortedBinaryTree__<K, T, S, C>::SortedBinaryTree__(
    const std::initializer_list<value_type> &items)
    : SortedBinaryTree__() {
  for (auto i = items.begin(); i != items.end(); ++i)
    (*this).insert(*i);
}

template <class K, class T, class S, class C>
SortedBinaryTree__<K, T, S, C> &
SortedBinaryTree__<K, T, S, C>::operator=(const SortedBinaryTree__ &other) {
  if (this != &other) {
    free_tree();
    root_ = nullptr;
    for (auto i = other.begin(); i != other.end(); ++i)
      (*this).insert(*i);
  }
  return *this;
}

template <class K, class T, class S, class C>
SortedBinaryTree__<K, T, S, C> &
SortedBinaryTree__<K, T, S, C>::operator=(SortedBinaryTree__ &&other) {
  if (this != &other) {
    free_tree();
    root_ = nullptr;
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
  }
  return *this;
}

template <class K, class T, class S, class C>
SortedBinaryTree__<K, T, S, C> &SortedBinaryTree__<K, T, S, C>::operator=(
    const std::initializer_list<value_type> &items) {
  free_tree();
  for (auto i = items.begin(); i != items.end(); ++i)
    (*this).insert(*i);
  return *this;
}

template <class K, class T, class S, class C>
bool SortedBinaryTree__<K, T, S, C>::empty() const {
  return size_ == 0UL;
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::size_type
SortedBinaryTree__<K, T, S, C>::size() const {
  return size_;
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::size_type
SortedBinaryTree__<K, T, S, C>::max_size() const {
  return std::numeric_limits<difference_type>().max() / sizeof(node_type);
}

template <class K, class T, class S, class C>
bool SortedBinaryTree__<K, T, S, C>::contains(const key_type &key) const {
  node_pointer ptr = find_suitable_node(key);
  return ptr && ptr->key() == key;
}

template <class K, class T, class S, class C>
void SortedBinaryTree__<K, T, S, C>::swap(SortedBinaryTree__ &other) {
  if (this != &other) {
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
  }
}

template <class K, class T, class S, class C>
void SortedBinaryTree__<K, T, S, C>::merge(SortedBinaryTree__ &other,
                                           bool is_repeated_allowed) {
  auto i = other.begin();
  while (i.data()) {
    if (is_repeated_allowed || find(key_identify()(*i)) == end()) {
      iterator save = ++i;
      if (!i.data())
        i = --other.end();
      else
        --i;
      other.repoint_for_erase(i);
      i.data()->set_left(nullptr);
      i.data()->set_right(nullptr);
      i.data()->set_parent(nullptr);
      insert_new_node(i.data(), find_suitable_node(i.data()->key()),
                      is_repeated_allowed);
      i = save;
      continue;
    }
    ++i;
  }
}

template <class K, class T, class S, class C>
void SortedBinaryTree__<K, T, S, C>::clear() {
  free_tree();
  root_ = nullptr;
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::SortedBinaryTreeIterator__ &
SortedBinaryTree__<K, T, S, C>::iterator::operator++() {
  /* forward traversing order
               8
         4           12
      2     6     10      14
    1  3  5  7  9   11  13  15
  */
  if (tree_root_) {
    if (!this->ptr_) {
      this->ptr_ = tree_root_;
      while (this->ptr_->right_)
        this->ptr_ = this->ptr_->right_;
    } else if ((!this->ptr_->parent_ ||
                this->ptr_ == this->ptr_->parent_->right_) &&
               !this->ptr_->right_) {
      while (this->ptr_->parent_ && this->ptr_->parent_->right_ == this->ptr_)
        this->ptr_ = this->ptr_->parent_;
      if (!this->ptr_->parent_)
        this->ptr_ = nullptr;
      else
        this->ptr_ = this->ptr_->parent_;
    } else {
      if (this->ptr_->right_) {
        this->ptr_ = this->ptr_->right_;
        while (this->ptr_->left_)
          this->ptr_ = this->ptr_->left_;
      } else {
        if (this->ptr_ == this->ptr_->parent_->left_)
          this->ptr_ = this->ptr_->parent_;
        else
          this->ptr_ = this->ptr_->parent_->parent_;
      }
    }
  } else {
    this->ptr_ = nullptr;
  }
  return *this;
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::SortedBinaryTreeIterator__
SortedBinaryTree__<K, T, S, C>::iterator::operator++(int) {
  const_iterator temp(*this);
  ++this;
  return temp;
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::SortedBinaryTreeIterator__ &
SortedBinaryTree__<K, T, S, C>::iterator::operator--() {
  /* reverse traversing order
                  8
            12         4
      14       10   6        2
  15     13  11  9 7  5    3   1
  */
  if (tree_root_) {
    if (!this->ptr_) {
      ++(*this);
    } else if (this->ptr_->left_) {
      this->ptr_ = this->ptr_->left_;
      while (this->ptr_->right_)
        this->ptr_ = this->ptr_->right_;
    } else if (this->ptr_->parent_ &&
               this->ptr_->parent_->right_ == this->ptr_) {
      this->ptr_ = this->ptr_->parent_;
    } else {
      while (this->ptr_->parent_ && this->ptr_->parent_->right_ != this->ptr_)
        this->ptr_ = this->ptr_->parent_;
      if (this->ptr_->parent_)
        this->ptr_ = this->ptr_->parent_;
      else
        this->ptr_ = nullptr;
    }
  } else {
    this->ptr_ = nullptr;
  }
  return *this;
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::SortedBinaryTreeIterator__
SortedBinaryTree__<K, T, S, C>::iterator::operator--(int) {
  const_iterator temp(*this);
  --(*this);
  return temp;
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::iterator
SortedBinaryTree__<K, T, S, C>::begin() {
  if (root_) {
    node_pointer ptr = root_;
    while (ptr->left_)
      ptr = ptr->left_;
    return iterator(ptr, root_);
  }
  return iterator(nullptr, root_);
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::const_iterator
SortedBinaryTree__<K, T, S, C>::begin() const {
  if (root_) {
    node_pointer ptr = root_;
    while (ptr->left_)
      ptr = ptr->left_;
    return const_iterator(ptr, root_);
  }
  return const_iterator(nullptr, root_);
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::iterator
SortedBinaryTree__<K, T, S, C>::end() {
  return iterator(nullptr, root_);
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::const_iterator
SortedBinaryTree__<K, T, S, C>::end() const {
  return const_iterator(nullptr, root_);
}

template <class K, class T, class S, class C>
std::pair<typename SortedBinaryTree__<K, T, S, C>::iterator, bool>
SortedBinaryTree__<K, T, S, C>::insert_new_node(node_pointer node,
                                                node_pointer suitable_node,
                                                bool is_repeated_allowed) {
  if (!root_) {
    // insertion in empty tree
    root_ = node;
    ++size_;
    return std::pair<iterator, bool>{iterator(root_, root_), true};
  }
  if (key_identify()(node->value()) == suitable_node->key() &&
      !is_repeated_allowed)
    // found node with given node's key
    return std::pair<iterator, bool>{iterator(suitable_node, root_), false};
  if (key_identify()(node->value()) == suitable_node->key() &&
      is_repeated_allowed) {
    // insert anyway for multiset
    node_pointer new_subtree = node;
    node->set_parent(suitable_node);
    ++size_;
    if (suitable_node->left_)
      suitable_node->left_->parent_ = new_subtree;
    new_subtree->right_ = nullptr;
    new_subtree->left_ = suitable_node->left_;
    suitable_node->left_ = new_subtree;
    return std::pair<iterator, bool>{iterator(new_subtree, root_), true};
  }

  // sorting new node in other cases
  if (key_compare()(key_identify()(node->value()), suitable_node->key())) {
    suitable_node->left_ = node;
    node->set_parent(suitable_node);
    suitable_node = suitable_node->left_;
  } else {
    suitable_node->right_ = node;
    node->set_parent(suitable_node);
    suitable_node = suitable_node->right_;
  }
  ++size_;
  return std::pair<iterator, bool>{iterator(suitable_node, root_), true};
}

template <class K, class T, class S, class C>
std::pair<typename SortedBinaryTree__<K, T, S, C>::iterator, bool>
SortedBinaryTree__<K, T, S, C>::insert(const_reference value,
                                       bool is_repeated_allowed) {
  node_pointer suitable_node = find_suitable_node(key_identify()(value));
  node_pointer new_node = suitable_node;
  if (!suitable_node || is_repeated_allowed ||
      suitable_node->key() != key_identify()(value))
    // if node with given key does not exist - allocate memory for it
    new_node = new node_type(nullptr, value);
  return insert_new_node(new_node, suitable_node, is_repeated_allowed);
}

template <class K, class T, class S, class C>
void SortedBinaryTree__<K, T, S, C>::erase_case_right_only(
    node_pointer save_ptr) {
  // just pop up right node on the current node place
  if (save_ptr == root_) {
    root_ = save_ptr->right_;
    root_->parent_ = nullptr;
  } else if (save_ptr->parent_) {
    if (save_ptr->parent_->right_ == save_ptr)
      save_ptr->parent_->right_ = save_ptr->right_;
    else
      save_ptr->parent_->left_ = save_ptr->right_;
    if (save_ptr->right_)
      save_ptr->right_->parent_ = save_ptr->parent_;
  } else {
    root_ = nullptr;
  }
}

template <class K, class T, class S, class C>
void SortedBinaryTree__<K, T, S, C>::erase_case_right_and_left(
    node_pointer save_ptr) {
  // repoint current node right subtree
  node_pointer right_end = save_ptr->left_;
  while (right_end->right_)
    right_end = right_end->right_;
  right_end->right_ = save_ptr->right_;
  if (save_ptr->right_)
    save_ptr->right_->parent_ = right_end;
  if (save_ptr == root_) {
    root_ = save_ptr->left_;
    root_->parent_ = nullptr;
  } else {
    if (save_ptr->parent_->right_ == save_ptr)
      save_ptr->parent_->right_ = save_ptr->left_;
    else
      save_ptr->parent_->left_ = save_ptr->left_;
    save_ptr->left_->parent_ = save_ptr->parent_;
  }
}

template <class K, class T, class S, class C>
void SortedBinaryTree__<K, T, S, C>::erase_case_left_only(
    node_pointer save_ptr) {
  // just repoint parent of current node
  save_ptr->left_->parent_ = save_ptr->parent_;
  if (save_ptr == root_) {
    root_ = save_ptr->left_;
  } else {
    if (save_ptr->parent_->left_ == save_ptr)
      save_ptr->parent_->left_ = save_ptr->left_;
    else
      save_ptr->parent_->right_ = save_ptr->left_;
  }
}

template <class K, class T, class S, class C>
void SortedBinaryTree__<K, T, S, C>::erase_case_no_childs(
    node_pointer save_ptr) {
  // lower node or root - simple deletion of the node
  if (save_ptr == root_)
    root_ = nullptr;
  else {
    if (save_ptr->parent_->right_ == save_ptr)
      save_ptr->parent_->right_ = nullptr;
    else
      save_ptr->parent_->left_ = nullptr;
  }
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::node_pointer
SortedBinaryTree__<K, T, S, C>::repoint_for_erase(iterator pos) {
  node_pointer save_ptr = pos.data();
  if (!save_ptr->left_ && save_ptr->right_)
    erase_case_right_only(save_ptr);
  else if (save_ptr->right_)
    erase_case_right_and_left(save_ptr);
  else if (save_ptr->left_)
    erase_case_left_only(save_ptr);
  else
    erase_case_no_childs(save_ptr);
  --size_;
  return save_ptr;
}

template <class K, class T, class S, class C>
void SortedBinaryTree__<K, T, S, C>::erase(iterator pos) {
  // making sure that we're deleting node in this exact tree
  if (pos.root() == root() && pos.data()) {
    node_pointer save_ptr = repoint_for_erase(pos);
    delete save_ptr;
  }
}

template <class K, class T, class S, class C>
template <class... Args>
Vector<std::pair<typename SortedBinaryTree__<K, T, S, C>::const_iterator, bool>>
SortedBinaryTree__<K, T, S, C>::emplace(bool is_repeated_allowed,
                                        Args &&...args) {
  Vector<std::pair<const_iterator, bool>> result;
  emplace_helper(result, is_repeated_allowed, args...);
  return result;
}

template <class K, class T, class S, class C>
template <class... Args>
void SortedBinaryTree__<K, T, S, C>::emplace_helper(
    Vector<std::pair<const_iterator, bool>> &result, bool is_repeated_allowed,
    const_reference value, Args &&...args) {
  auto mid_res = insert(value, is_repeated_allowed);
  result.push_back(
      std::pair<const_iterator, bool>{mid_res.first, mid_res.second});
  emplace_helper(result, is_repeated_allowed, args...);
}

template <class K, class T, class S, class C>
void SortedBinaryTree__<K, T, S, C>::emplace_helper(
    Vector<std::pair<const_iterator, bool>> &result, bool is_repeated_allowed,
    const_reference value) {
  auto mid_res = insert(value, is_repeated_allowed);
  result.push_back(
      std::pair<const_iterator, bool>{mid_res.first, mid_res.second});
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::iterator
SortedBinaryTree__<K, T, S, C>::find(const key_type &key) {
  node_pointer ptr = find_suitable_node(key);
  if (ptr && ptr->key() == key)
    return iterator(ptr, root_);
  else
    return end();
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::const_iterator
SortedBinaryTree__<K, T, S, C>::find(const key_type &key) const {
  node_pointer ptr = find_suitable_node(key);
  if (ptr && ptr->key() == key)
    return const_iterator(ptr, root_);
  else
    return end();
}

template <class K, class T, class S, class C>
void SortedBinaryTree__<K, T, S, C>::free_tree() {
  node_pointer current = root_;
  if (current) {
    if (current->left_) {
      root_ = current->left_;
      free_tree();
    }
    if (current->right_) {
      root_ = current->right_;
      free_tree();
    }
    delete current;
    --size_;
  }
}

template <class K, class T, class S, class C>
typename SortedBinaryTree__<K, T, S, C>::node_pointer
SortedBinaryTree__<K, T, S, C>::find_suitable_node(const key_type &key) const {
  if (!root_)
    return nullptr;
  node_pointer current = root_;
  while (key != current->key()) {
    if (key_compare()(key, current->key())) {
      if (current->left_)
        current = current->left_;
      else
        break;
    } else {
      if (current->right_)
        current = current->right_;
      else
        break;
    }
  }
  return current;
}