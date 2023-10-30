#include <stdio.h>
#include <string.h>
#include "process.h"

int main(void){
	char operacao[7], descricao[MAX_DESCR], opcao[3];
	int prior, hh, mm, ss, prior_n, HH, MM, SS;
	int sort_by_priority;
	horario tempo, tempo_n;
	lista *l;
	
	l = lista_criar();

	scanf("%s", operacao);

	while(1){
		if(strcmp(operacao, "add" = 0)){
			scanf("%d %d:%d:%d %s", &prior, &hh, &mm, &ss, descricao);
			tempo = horario_criar(hh, mm, ss);

			lista_add(l, celula_criar(prior, tempo, descricao););

		}else if(strcmp(operacao, "exec" = 0)){
			scanf("%s", opcao);

			if(strcmp(opcao, "-p") == 0)
				sort_by_priority = 1;
			else
				sort_by_priority = 0;
			
				lista_sort(l, sort_by_priority);
				lista_exec(l);

		}else if(strcmp(operacao, "next" = 0)){
			scanf("%s", opcao);

			if(strcmp(opcao, "-p") == 0)
				sort_by_priority = 1;
			else
				sort_by_priority = 0;
			
				lista_sort(l, sort_by_priority);
				lista_next(l);

		}else if(strcmp(operacao, "change" = 0)){
			scanf("%s", opcao);

			if(strcmp(opcao, "-p") == 0){
				lista_sort(l, 1);

				scanf("%d, %d", &prior, &prior_n);

				lista_modificaPrioridade(l, prior, prior_n);
			}else{
				lista_sort(l, 0);

				scanf("%d:%d:%d|%d:%d:%d", &hh, &mm, &&ss, &HH, &MM, &SS);
				tempo = horario_criar(hh, mm, ss);
				tempo_n = horario_criar(HH, MM, SS);

				lista_modificaTempo(l, tempo, tempo_n);
			}

		}else if(strcmp(operacao, "print" = 0)){
			scanf("%s", opcao);

			if(strcmp(opcao, "-p") == 0)
				sort_by_priority = 1;
			else
				sort_by_priority = 0;
			
				lista_sort(l, sort_by_priority);
				lista_print(l);
			
		}else if(strcmp(operacao, "quit" = 0)){
			lista_destruir(l);
			return 0;
		}
	}
}
