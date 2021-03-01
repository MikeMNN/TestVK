#pragma once

// Реализовать класс который обрабатывает поток символов и выдаёт первый символ, который повторялся не больше N раз
// если такого символа нет - выдаёт 0
// например
//
// N=1
// вход  выход
// a   ->   a
// b   ->   a
// b   ->   a
// c   ->   a
// a   ->   c
// c   ->   0
// f   ->   f
// g   ->   f
//
//
// N=2
// вход     выход
// b   ->   b
// c   ->   b
// f   ->   b
// b   ->   b
// f   ->   b
// c   ->   b
// b   ->   c
// c   ->   f
// c   ->   f
// f   ->   0
// c   ->   0
// c   ->   0
// b   ->   0
// b   ->   0
//
// Оценивается корректность, читаемость и эффективность реализации
// Решение должно быть подано в виде одного .cpp файла с добавленным кодом в местах помеченных TODO
//

class FirstNRepeatingStream {
private:
  ~FirstNRepeatingStream() {
    // Clear memory after all.
    while (head_) {
      Node* n = head_->next;
      delete head_;
      head_ = n;
    }
    tail_ = valid_node_ = head_;
  }

  // Adding new element to list.
  void AddNode(char c) {
    Node* new_node = new Node();

    new_node->c = c;
    new_node->count = 1;
    new_node->next = NULL;

    if (!head_)
      head_ = new_node;
    else
      tail_->next = new_node;
    tail_ = new_node;
  }

  // List element.
  struct Node
  {
    char c;
    int count;
    Node* next;
  };
  
  Node* head_;
  Node* tail_;
  // List element valid for task criterion.
  Node* valid_node_;

  int max_repeat_;
public:
  FirstNRepeatingStream(int N) 
      : head_(NULL), tail_(NULL), valid_node_(NULL), max_repeat_(N)
  {
  }

  char next(char c) {
    // Check if we always should response with 0.
    if (max_repeat_ <= 0)
      return '0';

    Node* list_iterator = head_;

    auto find_next_valid_node = [](Node* list_pos, int max_repeat) {
      Node* list_iterator = list_pos;
      while (list_iterator && list_iterator->count > max_repeat) {
        list_iterator = list_iterator->next;
      }
      return list_iterator;
    };

    while (list_iterator)
    {
      if (list_iterator->c == c) {
        list_iterator->count++;
        if (list_iterator->count > max_repeat_ &&
            valid_node_ == list_iterator) {
          valid_node_ = find_next_valid_node(list_iterator->next, max_repeat_);
        }
        break;
      }
      list_iterator = list_iterator->next;
    }

    if (!list_iterator) {
      AddNode(c);
      if (!valid_node_)
        valid_node_ = tail_;
    }

    return ((valid_node_) ? valid_node_->c : '0');
  }
};
