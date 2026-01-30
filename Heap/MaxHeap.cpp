#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

class MaxHeap {
  private:
  vector<int> _heap;
  
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
    int temp = _heap[ind1];
    _heap[ind1] = _heap[ind2];
    _heap[ind2] = temp;
  }
  
  public:
  void printHeap() {
    cout << "\n[";
    for (size_t i = 0; i < _heap.size(); i++) {
      cout << _heap[i];
      if (i < _heap.size() - 1) { 
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
  
  const vector<int>& getHeap() const {
    return _heap;
  }
  
  void insert(int value) {
    _heap.push_back(value);
    
    int i = _heap.size() - 1;
    int p_i = _parent(i);
    if (i < 0) return;
    
    while (i > 0 && _heap.at(i) > _heap.at(p_i)) {
      _swap(i, p_i);
      i = p_i;
      p_i = _parent(i);
    }
  }
  
  void sinkDown(int index) {
    if (_heap.size() == 1) {
      return;
    }

    int i = 0;
    int max_index;
    int max_value = _heap[i];
    while (true) {
      max_value = max(_heap[_leftChild(i)], _heap[_rightChild(i)]);
      max_index = (max_value == _heap[_leftChild(i)]) ? _leftChild(i) : _rightChild(i);
      if (max_index < _heap.size() && max_index != index) {
        _swap(max_index, i);
        i = max_index;
      } else {
        break;
      }
    }
  }

  int remove() {
    
    if (_heap.empty()) {
      return INT_MIN;
    }
    
    int res = _heap.front();
    
    if (_heap.size() == 1) {
      _heap.pop_back();
    } else {
      _heap[0]= _heap.back();
      _heap.pop_back();
      sinkDown(0);     
    }
    
    return res;
  }
};