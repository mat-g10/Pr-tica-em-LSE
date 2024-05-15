typedef struct lse t_lse;
typedef void(*t_imprimir_lse)(void*);
typedef int(*t_comparar_lse)(void*, void*); //receber 2 ponteiros voids: carga util e buscador

void imprimir_lse(t_lse* lse);
void inserir_lse(t_lse* lse, void* carga_util);
void inserir_final_lse(t_lse* lse, void* carga_util);
void* acessar_lse(t_lse* lse, int pos);
void destruir_lse(t_lse* lse);
void* buscar_lse(t_lse* lse, void* buscado);
void* remover_inicio_lse(t_lse* lse);
void* remover_final_lse(t_lse* lse);
void inserir_ordenado_lse(t_lse* lse, void* carga);

t_lse* criar_lse(t_imprimir_lse impressora, t_comparar_lse comparador);