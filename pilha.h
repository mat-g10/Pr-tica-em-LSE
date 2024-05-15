typedef struct pilha t_pilha;
t_pilha* criar_pilha();
void empilhar(t_pilha* p, void* novo);
void* desempilhar(t_pilha* p);
void* topo(t_pilha *p);
int altura_pilha(t_pilha* p);
