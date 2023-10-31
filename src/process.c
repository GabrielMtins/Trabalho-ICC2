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
		return -horario_cmp(a->chegada, b->chegada);
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

// todo: mudar o algoritmo de sorting para quicksort
void lista_sort(lista *l, bool sort_by_priority){
	celula tmp;

	for(int i = 0; i < l->tamanho - 1; i++){
		for(int j = 0; j < l->tamanho - 1; j++){
			if(celula_cmp(&l->celulas[j], &l->celulas[j + 1], sort_by_priority) > 0){
				tmp = l->celulas[j];
				l->celulas[j] = l->celulas[j + 1];
				l->celulas[j + 1] = tmp;
			}
		}
	}
}

void lista_add(lista *l, celula nova){
	l->tamanho++;
	l->celulas = (celula*) realloc(l->celulas, l->tamanho * sizeof(celula));
	l->celulas[l->tamanho - 1] = nova;
}

void lista_exec(lista *l){
	if(l->tamanho == 0) return;

	l->tamanho--;

	if(l->tamanho == 0){
		free(l->celulas);
		l->celulas = NULL;
	}
	else{
		l->celulas = (celula*) realloc(l->celulas, l->tamanho * sizeof(celula));
	}
}

void lista_next(lista* l){
	printf("%02d %02d:%02d:%02d %s\r\n", l->celulas[l->tamanho - 1].prior, 
		l->celulas[l->tamanho - 1].chegada.hh, l->celulas[l->tamanho - 1].chegada.mm, 
		l->celulas[l->tamanho - 1].chegada.ss, l->celulas[l->tamanho - 1].descricao);
}


void lista_modificaPrioridade(lista* l, int ant_prioridade, int nova_prioridade){
	for(int i = 0; i < l->tamanho; i++){
		if(l->celulas[i].prior == ant_prioridade){
			l->celulas[i].prior = nova_prioridade;
			break;
		}
	}
}

void lista_modificaTempo(lista* l, horario ant_horario, horario novo_horario){
	for(int i = 0; i < l->tamanho; i++){
		if(horario_cmp(l->celulas[i].chegada, ant_horario) == 0){
			l->celulas[i].chegada = novo_horario;
			break;
		}
	}
}

void lista_print(lista* l){
	for(int i = l->tamanho - 1; i >= 0; i--){
		printf("%02d %02d:%02d:%02d %s\r\n", l->celulas[i].prior, 
		l->celulas[i].chegada.hh, l->celulas[i].chegada.mm, 
		l->celulas[i].chegada.ss, l->celulas[i].descricao);
	}
}

void lista_destruir(lista* l){
	if(l == NULL) return;
	if(l->celulas != NULL) free(l->celulas);
	free(l);
}
