
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_NO(struct NO* no);
void libera_ArvBin(ArvBin* raiz);
int estaVazia_ArvBin(ArvBin *raiz);
int insNoAleatorioArvBin(ArvBin *raiz, int valor);
void pos_ordem_ArvBin(ArvBin *raiz);
void em_ordem_ArvBin(ArvBin *raiz);
void pre_ordem_ArvBin(ArvBin *raiz);
int ABouABB(ArvBin *raiz);
int insere_ArvBin(ArvBin *raiz, int valor);

