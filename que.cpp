#include <stdlib.h>

// Task control block
class TCB {

  int status;
  int flag;
  int priority;

  constructor new() {

  }

  destructor delete() {

  }

}


// Que control block
class Que {

  int prev;
  int next;
  TCB* tcb;

  constructor new() {
    prev = 0;
    next = 0;
    tcb = TCB.new();
  }

  destructor delete() {
    prev = 0;
    next = 0;
    tcb.delete();
  }

  int prev {
    return prev; 
  }

  int next {
    return next;
  } 

}





