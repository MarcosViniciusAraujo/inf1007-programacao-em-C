typedef struct pilha Pilha;

Pilha *cria();

void push(Pilha *p, int digito);

int pop(Pilha *p);

int vazio(Pilha *p);

void libera(Pilha *P);

void exibePilha(Pilha *p);
