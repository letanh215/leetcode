#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Graph {
  private:
  unordered_map<string, unordered_set<string> > _adjList;
  
  public:
  void printGraph() {
    unordered_map<string, unordered_set<string>>::iterator kvPair = _adjList.begin();
    while (kvPair != _adjList.end()) {
      cout << kvPair->first << ": [";
      unordered_set<string>::iterator edge = kvPair->second.begin();
      bool first = true;
      while (edge != kvPair->second.end()) {
        if (!first) {
          cout << ", ";
        }
        cout << *edge;
        edge++;
        first = false;
      }
      cout << "]" << endl;
      kvPair++;
    }
  }
  
  bool addVertex(string vert) {
    if (_adjList.find(vert) == _adjList.end()) {
      _adjList[vert] = unordered_set<string>();
      return true;
    }
    return false;
  }

  bool addEdge(string vert1, string vert2) {
    if (_adjList.find(vert1) == _adjList.end() || _adjList.find(vert2) == _adjList.end()) {
      return false;
    }

    _adjList[vert1].insert(vert2);
    _adjList[vert2].insert(vert1);
    return true;
  }

  bool removeEdge(string vert1, string vert2) {
    if (_adjList.find(vert1) == _adjList.end() || _adjList.find(vert2) == _adjList.end()) {
      return false;
    } else {
      _adjList[vert1].erase(vert2);
      _adjList[vert2].erase(vert1);
      return true;
    }
  }

  bool removeVertex(string vert1) {
    if (_adjList.count(vert1) == 0) {
      return false;
    } 

    _adjList.erase(vert1);
    
    for (auto it : _adjList) {
      it.second.erase(vert1);
    }

    return true;
  }
};


