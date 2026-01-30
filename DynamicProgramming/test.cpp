#include <iostream>
#include "RemoveElement.h"

int main() {

  vector<int> element = {32, 32, 2, 3, 4, 1};
  // removeElement(element, 32);
  element[1] = element[0];
  element.resize(32);
  // removeElement(element, 32);
  for (auto it = element.begin(); it != element.end(); it++) {
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
  return 0;
}