#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <stdlib.h>
using namespace std;

// Task control block
class TCB {

private:
  int tcb_status;
  int tcb_flag;
  int tcb_priority;
  string task_name;

public:
//  TCB() {
//    tcb_status = 0;
//    tcb_flag = 0;
//    tcb_priority = 0;
//    cout << "TCB() Constructed!" << endl; 
//  }

  TCB(int status = 0, int flag =0, int priority =0, string name ="") {
    tcb_status = status;
    tcb_flag = flag;
    tcb_priority = priority;
    task_name = name;
    cout << "TCB(x) Constructed!" << endl; 
  }

  ~TCB() {
    cout << "TCB Destructed!" << endl;
  }

  int priority() const {
    return tcb_priority;
  }

  string name() const {
    return task_name;
  }
};

bool operator < (const TCB& a, const TCB& b) {
  return a.priority() < b.priority();
}

ostream& operator << ( ostream& os, const TCB& tcb){
  return os << "Pri:" << tcb.priority() << " Name:" << tcb.name() << endl;
}


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
    tcb = new TCB(0, 0, rand()%10, "Who");
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
//  Que que; 

  priority_queue <TCB, vector<TCB>, less<TCB> > pq;

  ostringstream ss;
  for(int i=0; i< 10; i++){
    ss << "No.:" << i;
    pq.push(TCB(i, i, rand()%10, ss.str()));
    ss.str("");
    ss.clear(stringstream::goodbit);
  }
  while(!pq.empty()){
    cout << pq.top();
    pq.pop();
  }
  cout << endl;
  return 0;
}

