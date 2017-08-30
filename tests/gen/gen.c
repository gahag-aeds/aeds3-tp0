#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>


char* query_ops[] = {
  "Min",
  "Max",
  "Sum",
};

char* update_ops[] = {
  "Add",
  "Sub"
};


int main(int argc, char *argv[]) {
  srand(time(NULL));
  
  if (argc != 2)
    return -1;
  
  size_t n, ops_num, width;
  
  sscanf(argv[1], "%zu", &n);
  ops_num = n / 2;
  width = n / 3;
  
  printf("%zu %zu\n", n, ops_num);
  
  for (size_t i = 0; i < n; i++)
    printf("%d ", rand() % 100);
  puts("");
  
  for (size_t i = 0; i < ops_num; i++) {
    int r = rand();
    size_t ival = r % (n - width);
    
    assert(ival + width < n);
    
    fputs(i % 2 ? query_ops[r % 3] : update_ops[r % 2], stdout);
    printf(" %zu %zu\n", ival + 1, ival + width);
  }
  
  return 0;
}
