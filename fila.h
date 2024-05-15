typedef struct fila t_fila; 

t_fila* criar_fila();
void enfileirar(t_fila *f, void* novo);
void* desenfileirar(t_fila* f);
void* primeiro_fila(t_fila *f);
int tamanho_fila(t_fila *f);
short vazia_fila(t_fila *f);
