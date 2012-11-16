#include <iostream>
using namespace std;

// Task control block
class TCB {

private:
  int status;
  int flag;
  int priority;

public:
  TCB() {
    status = 0;
    flag = 0;
    priority = 0;
    cout << "TCB Constructed!" << endl; 
  }

  ~TCB() {
    cout << "TCB Destructed!" << endl;
  }

};


// Que control block
class Que {

private:
  int prev_node;
  int next_node;
  TCB* tcb;

public:

  Que() {
    prev_node = 0;
    next_node = 0;
    tcb = new TCB;
    cout << "Que Constructed!" << endl;
  }

  ~Que() {
    delete tcb;
    cout << "Que Destructed!" << endl;
  }

  int prev() {
    return prev_node; 
  }

  int next() {
    return next_node;
  } 

};

int main() {

  Que que; 
  return 0;
}

