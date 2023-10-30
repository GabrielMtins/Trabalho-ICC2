#include "process.h"

struct s_lista{
	celula* celulas;
	int tamanho;
};

horario horario_criar(int hh, int mm, int ss){
}

int celula_cmp(celula *a, celula *b, bool cmp_by_priority){
}

celula celula_criar(int prior, horario h, const char *descricao){
}

lista* lista_criar(void){
}

void lista_sort(lista *l, bool sort_by_priority){
}

void lista_add(lista *l, celula nova){
}

void lista_modificaPrioridade(lista* l, int nova_prioridade){
}

void lista_modificaTempo(lista* l, horario novo_horario){
}

void lista_printListaPorPrioridade(lista* l){
}

void lista_printListaPorTempo(lista* l){
}
