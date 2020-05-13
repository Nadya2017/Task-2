typedef struct node {
    int value;
    struct node* next;
} node;
typedef node* list;

void push(list* L, int element);
void print(list* L);
void push_before(list* L, int num, int element);
void push_after(list* L, int num, int element);
void push_end(list* L, int element);
int pop(list* L);
int pop_end(list* L);
int pop_num(list* L, int num);
void individual(list* L, int input, int value);
void menu();
