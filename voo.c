/*
	

	Nomes: nomes dos responsaveis

	Simulação de Tráfego de Aterrissagem e Decolagem em Aeroportos

*/

// Inclusão das bibliotecas
#include <stdio.h>
#include <stdlib.h>
//blibioteca do rand
#include<time.h>
//numero de vezes que o programa roda
#define maximo 20

// Declaração das estruturas
// Estrutura que guarda o endereço das posições da fila
struct Posicao {
	int num;
	struct Posicao *prox;
};

// Novo tipo chamado node com características da estrutura Posicao
typedef struct Posicao node;

// Declaração de variáveis e funções globais
int tam_fila_dec,tam_fila_pouso;
void inicia(node *FILA);
int vazia(node *FILA);
node *aloca(int num_aviao);
void insere(node *FILA, int num_aviao);
node *retira(node *FILA);
int enviar_pista(node *FILA);
void mostrar(node *FILA, char tipo_de_fila);
void libera(node *FILA);

// Função principal
int main(void) {
    int av_pousando, av_dec, pista1 = 0, pista2 = 0, pista3 = 0, num_av_dec = 2, num_av_pousando = 1,cont=0;
    node *FILAdec = (node *) malloc(sizeof(node));
    node *FILApouso = (node *) malloc(sizeof(node));
    node *tmp;
    int sair;
    while(sair!=2) {
        printf("              Simulacao de Trafego de Aterrissagem e Decolagem em Aeroportos\n\n");
                        printf("               i1,         \n");
                        printf("                1i         \n");
                        printf("                 iii            \n");
                        printf("                  ii;                \n");
                        printf("       tf         ii;;;                 \n");
                        printf("        fft        i;;;;                \n");
                        printf("        fffttt1if111TKTf:t111111.:        \n");
                        printf("        fft        i;;;;                \n");
                        printf("       Lf         ii;;:                 \n");
                        printf("                 iii;                   \n");
                        printf("                 iii                    \n");
                        printf("                1i;                     \n");
                        printf("               it       \n\n");

        printf("MENU\n");
                printf("    1. INICIAR SIMULACAO\n");
                printf("    2. SAIR\n\n");
                        printf("FORNECA SUA OPCAO: ");
        scanf("%d",&sair);
        switch (sair) {
        case 1:
            if (!FILAdec || !FILAdec) {
                printf("Sem memoria disponivel!\n");
                exit(1);
            }
            else {
                 inicia(FILApouso);
                 inicia(FILAdec);
                 do {
					 av_dec = 1 + ( rand() % 3);//gera valor aleatorio entre de 1-3
                     av_pousando = 1 + ( rand() % 3);//gera valor aleatorio entre de 1-3
                     system("cls");
                     printf("PARA TERMINAR A SIMULACAO PRESSIONE A LETRA S \n\n");
                     printf("\n\nSolicitacao de Pouso : %d \n\nSolicitacao de Decolagem: %d \n\n\n", av_pousando, av_dec);
                     printf("Pista 1: Aviao Numero : %d\n", pista1);
                     printf("Pista 2: Aviao Numero : %d\n", pista2);
                     printf("Pista 3: Aviao Numero : %d\n\n", pista3);
                     int i;
                     for(i = 0; i < av_dec; i++){
                         insere(FILAdec, num_av_dec);
                         num_av_dec+=2;
                     }
                     for(i = 0; i < av_pousando; i++){
                         insere(FILApouso, num_av_pousando);
                         num_av_pousando+=2;
                     }
                     mostrar(FILApouso, 'A');
                     mostrar(FILAdec, 'D');
                     // Teste de prioridades
                     if(tam_fila_dec != 0 && tam_fila_pouso != 0){
                     if(tam_fila_dec >= 2*tam_fila_pouso){
                         pista1 = enviar_pista(FILApouso);
                         pista2 = enviar_pista(FILAdec);
                         pista3 = enviar_pista(FILAdec);
                     }
                     else{
                         pista1 = enviar_pista(FILApouso);
                         pista2 = enviar_pista(FILApouso);
                         pista3 = enviar_pista(FILAdec);
                     }
                     }
                     else{
                         if(tam_fila_dec == 0){
                             pista1 = enviar_pista(FILApouso);
                             pista2 = enviar_pista(FILApouso);
                             pista3 = enviar_pista(FILApouso);
                         }
                         else{
                             pista1 = enviar_pista(FILAdec);
                             pista2 = enviar_pista(FILAdec);
                             pista3 = enviar_pista(FILAdec);
                         }
                     }
                     if (getch() == 's')//função que para a sumuulação
                            {
                                system("CLS"); //limpeza da tela
                                return main();//retorna para o menu inicial

                            }


                     cont++;//contador do maximo

                 } while(cont<maximo); //final da funçao da pista
                 free(FILApouso);
                 free(FILAdec);
                 return 0;
            } // fim else

            case 2:
            break;

            default:
                printf("Opcao invalida. Tente novamente.\n\n\n\n");
                getch();
                system("cls");

            } // fim switch
    }// fim while sair!=2 menu primeira opcao

}

// Função inicia
void inicia(node *FILA)
{
    FILA->prox = NULL;
    tam_fila_pouso = 0;
    tam_fila_dec = 0;
}

// Função vazia: verifica se a próxima posição da fila é nula (inexistente)
int vazia(node *FILA)
{
    if(FILA->prox == NULL)
    return 1;
    else
    return 0;
} // Fim da função vazia


// Função aloca: se não houver espaço disponível em memória, a função deixa de ser executada, caso contrário, aloca nova posição para avião
node *aloca(int num_aviao) //
{
    node *novo=(node *) malloc(sizeof(node));
    if(!novo) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else {
        novo->num = num_aviao;
        return novo;
    }
} // Fim da função aloca

// Função insere: adiciona nova posição na fila e manipula a fila de decolagem
void insere(node *FILA, int num_aviao)
{
    node *novo = aloca(num_aviao);
    novo->prox = NULL;
    if(vazia(FILA))
        FILA->prox=novo;
    else {
        node *tmp = FILA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    // se o aviao for par aumenta a fila de decolagem
    if(num_aviao % 2 == 0)
        tam_fila_dec++;
    else
        tam_fila_pouso++;
} // Fim da função insere


// Função que retira os aviões que já decolaram da fila
node *retira(node *FILA)
{
    if(FILA->prox == NULL) {
        printf("Fila ja esta vazia\n");
        return NULL;
    }
    else {
        node *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        // se o aviao a ser retirado for par, diminui a fila de decolagem
        if(tmp->num % 2 == 0)
            tam_fila_dec--;
        else
            tam_fila_pouso--;
        return tmp;
    }
} // Fim retira

// Função mostrar: retorna fila ou se fila é vazia
void mostrar(node *FILA, char tipo_de_fila)
{
    if(vazia(FILA)) {
        printf("Fila vazia!\n\n");
    return ;
} // Fim função mostrar


// a variavel char tipo_de_fila recebe do main 'A', aterrissagem ou 'D', decolagem
if(tipo_de_fila == 'A')
    printf("Fila para aterrissagem : ");
else
    printf("Fila para decolagem : ");

node *tmp;
tmp = FILA->prox;

while(tmp != NULL) {
    printf("%d ", tmp->num);
    tmp = tmp->prox;
}
    printf("\n\n\n");

}

// a funcao pega o primeiro elemento da fila retorna p/ pista em seguida apaga da fila
int enviar_pista(node *FILA) {
    int pista;
    if(vazia(FILA)) {
        return 0;
    }
    node *tmp;
    tmp = FILA->prox;
    pista = tmp -> num;
    retira(FILA);
    return pista;
}

// Função libera, limpa a fila quando já houve decolagem
void libera(node *FILA)
{
    if(!vazia(FILA)) {
        node *proxNode, *atual;
        atual = FILA->prox;
        while(atual != NULL) {
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }
}
