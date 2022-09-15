#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
  //add value to end of list
  if(tail_ == NULL){
		//make new item and set it equal to tail_
		//set prev of tail to head_
		//insert value at first point and increment last by 1
    tail_ = new Item();
		head_ = tail_;
    tail_->val[tail_->first] = val;
    tail_->last++;
  }else if(tail_->last == ARRSIZE){
    Item *newT = new Item();
    newT->val[newT->first] = val;
    newT->last++;
    tail_->next = newT;
    newT->prev = tail_;
    tail_ = newT;

  }else{
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
	size_++;
}

void ULListStr::push_front(const std::string& val){
  //adds value to front of list
	if(head_ == NULL){
		head_ = new Item();
		tail_ = head_;
		head_->last = ARRSIZE;
		head_->first = ARRSIZE;
		head_->val[head_->first-1] = val;
		head_->first--;
	}else if(head_->first == 0){
		Item* newH = new Item();
		head_->prev = newH;
		newH->next = head_;
		head_ = newH;
		head_->last = ARRSIZE;
		head_->first = ARRSIZE;
		head_->val[head_->first-1] = val;
		head_->first--;
	}else{
		head_->val[head_->first-1] = val;
		head_->first--;
	}
	size_++;
}

void ULListStr::pop_back(){
  //removes value from back
	if(tail_ == NULL){
		return;
	}else if(tail_->last <= tail_->first+1){
		Item* temp = tail_;
		if(tail_->prev != NULL){
			tail_ = tail_->prev;
			tail_->next = NULL;
			if(tail_->prev != NULL){
				tail_->prev->next = tail_;
			}
			delete temp;
		}else{
			delete temp;
			tail_ = NULL;
			head_ = NULL;
		}
	}else{
		tail_->last--;
	}
	size_--;
}

void ULListStr::pop_front(){
  //revomes value from front
	if(head_ == NULL){
		return;
	}else if(head_->first >= head_->last-1){
		Item* temp = head_;
		if(head_->next != NULL){
			head_ = head_->next;
			head_->prev = NULL;
			if(head_->next != NULL){
				head_->next->prev = head_;
			}
			delete temp;
		}else{
			delete temp;
			head_ = NULL;
			tail_ = NULL;
		}
		
	}else{
		head_->first++;
	}
	size_--;
}

std::string const & ULListStr::back() const{
  //Returns a const reference to the back element
	if(tail_ != NULL){
		return tail_->val[tail_->last-1];
	}else if(tail_ == NULL){
    throw std::invalid_argument("Node is Null");
  }
}

std::string const & ULListStr::front() const{
  //Returns a const reference to the front element
	if(head_ != NULL){
		return head_->val[head_->first];
	}else if(head_ == NULL){
    throw std::invalid_argument("Node is Null");
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  //Returns a pointer to the item at index, loc, if loc is valid and NULL otherwise
	if(loc > size_ || loc < 0 || size_ == 0){
		return NULL;
	}
	Item* temp = head_;
	size_t count = loc;

	while(temp != NULL){
		if(count < (temp->last - temp->first)){
			return &(temp->val[temp->first+count]);
		}
		count -= temp->last - temp->first;
		temp = temp->next;
	}
	return NULL;
}
//stop coding
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
