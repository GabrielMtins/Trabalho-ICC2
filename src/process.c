#include "process.h"

struct s_lista{
	celula* celulas;
	int tamanho;
};

horario horario_criar(int hh, int mm, int ss){
	horario h;
	h.hh = hh;
	h.mm = mm;
	h.ss = ss;

	return h;
}

int horario_cmp(horario a, horario b){
	if(a.hh > b.hh) return 1;

	else if(a.hh == b.hh){
		if(a.mm > b.mm) return 1;

		else if(a.mm == b.mm){
			if(a.ss > b.ss) return 1;

			else if(a.ss == b.ss) return 0;

			return -1;
		}

		return -1;
	}

	return -1;
}

int celula_cmp(celula *a, celula *b, bool cmp_by_priority){
	if(cmp_by_priority){
		if(a->prior > b->prior) return 1;
		else if(a->prior == b->prior) return 0;
		else return -1;
	}
	else{
		return horario_cmp(a->chegada, b->chegada);
	}
}

celula celula_criar(int prior, horario h, const char *descricao){
	celula nova;

	nova.prior = prior;
	nova.chegada = h;
	strcpy(nova.descricao, descricao);

	return nova;
}

lista* lista_criar(void){
	lista *l = (lista *) malloc(sizeof(lista));
	l->celulas = NULL;
	l->tamanho = 0;
	
	return l;
}

void lista_sort(lista *l, bool sort_by_priority){
}

void lista_add(lista *l, celula nova){
}

void lista_exec(lista *l){
}

void lista_next(lista* l){
	printf("%02d %02d:%02d:%02d %s", l->celulas[0].prior, 
		l->celulas[0].chegada.hh, l->celulas[0].chegada.mm, 
		l->celulas[0].chegada.ss, l->celulas[0].descricao);
}


void lista_modificaPrioridade(lista* l, int ant_prioridade, int nova_prioridade){
}

void lista_modificaTempo(lista* l, horario ant_horario, horario novo_horario){
}

void lista_print(lista* l){
	for(int i = 0; i <= l->tamanho; i++){
		printf("%02d %02d:%02d:%02d %s", l->celulas[i].prior, 
		l->celulas[i].chegada.hh, l->celulas[i].chegada.mm, 
		l->celulas[i].chegada.ss, l->celulas[i].descricao);
	}
}

void lista_destruir(lista* l){
	if(l == NULL) return;
	if(l->celulas != NULL) free(l->celulas);
	free(l);
}
