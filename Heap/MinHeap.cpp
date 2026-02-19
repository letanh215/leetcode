#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

class MinHeap {
  private:
  vector<int> heap_;
  
  int _leftChild(int index) {
    return index * 2 + 1;
  }
  
  int _rightChild(int index) {
    return index * 2 + 2;
  }
  
  int _parent(int index) {
    return (index - 1) / 2;
  }
  
  void _swap(int ind1, int ind2) {
    int temp = heap_[ind1];
    heap_[ind1] = heap_[ind2];
    heap_[ind2] = temp;
  }
  
  public:
  void printHeap() {
    cout << "\n[";
    for (size_t i = 0; i < heap_.size(); i++) {
      cout << heap_[i];
      if (i < heap_.size() - 1) { 
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
  
  const vector<int>& getHeap() const {
    return heap_;
  }
  
  void insert(int value) {
    heap_.push_back(value);
    
    int i = heap_.size() - 1;
    int p_i = _parent(i);
    if (i < 0) return;
    
    while (i > 0 && heap_.at(i) < heap_.at(p_i)) {
      _swap(i, p_i);
      i = p_i;
      p_i = _parent(i);
    }
  }
  
  void sinkDown(int index) {
    if (heap_.size() == 1) {
      return;
    }

    int i = 0;
    int min_index;
    int min_value = heap_[i];
    while (true) {
      min_value = min(heap_[_leftChild(i)], heap_[_rightChild(i)]);
      min_index = (min_value == heap_[_leftChild(i)]) ? _leftChild(i) : _rightChild(i);
      if (min_index < heap_.size() && min_index != index) {
        _swap(min_index, i);
        i = min_index;
      } else {
        break;
      }
    }
  }

  int remove() {
    
    if (heap_.empty()) {
      return INT_MIN;
    }
    
    int res = heap_.front();
    
    if (heap_.size() == 1) {
      heap_.pop_back();
    } else {
      heap_[0]= heap_.back();
      heap_.pop_back();
      sinkDown(0);     
    }
    
    return res;
  }
};