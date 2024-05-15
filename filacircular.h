typedef struct f_circular t_fila_circular;

t_fila_circular* criar_fila_circular(int tam);

int vazia_fila_circular(t_fila_circular* fc);
int ocupacao_fila_circular(t_fila_circular* fc);
short enfileirar_fila_circular(t_fila_circular* fc, void* novo);
void* desenfileirar_fila_circular(t_fila_circular* fc);
void* primeiro_fila_circular(t_fila_circular* fc);

void avancar_fila_circular(t_fila_circular* fc);