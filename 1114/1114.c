typedef struct {
  // User defined data may be declared here.
  int flag;
} Foo;

Foo* fooCreate() {
  Foo* obj = (Foo*) malloc(sizeof(Foo));
  
  // Initialize user defined data here.
  obj->flag = 0;
  
  return obj;
}

void first(Foo* obj) {
  printFirst();
  obj->flag = 1;
}

void second(Foo* obj) {
  while (obj->flag != 1)
    // Some solutions use sched_yield() but it's somehow slower
    // There should be an optimal sleep time for fastest execution, but it's hard to tune, 500
    // seems a decent setting
    usleep(500);

  printSecond();
  obj->flag = 2;
}

void third(Foo* obj) {
  while (obj->flag != 2)
    usleep(500);

  printThird();
}

void fooFree(Foo* obj) {
  // User defined data may be cleaned up here.
}