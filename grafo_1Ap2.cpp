/* Gabriel Andriola AP2 - Estrutura de dados*/
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
struct nodo
{
    int dado;
    struct nodo *prox;
};
struct vertice
{
    int v;
    
    struct vertice *proxv;
    struct nodo *proxa;
};
void conecta(struct vertice **grafo, int vo,int vd)
{ 
     
	struct vertice *aux,*ant;
    struct nodo *vadj,*antd;
    int achou=0,achoud; 
     
    if(*grafo == NULL)
	{
        aux=(struct vertice*) malloc (sizeof(struct vertice));
        if(aux != NULL)
		{
            aux->v=vo;
            aux->proxv=NULL;
            vadj=(struct nodo*) malloc (sizeof(struct nodo));
            vadj->dado=vd;
            vadj->prox=NULL;
            aux->proxa=vadj;
            (*grafo)=aux;
        }
    }
	else
	{
        aux=*grafo;
        ant=aux;
        while(aux != NULL)
		{                      
            if(aux->v == vo)
			{
                achou=1;                                
                vadj=aux->proxa;
                antd=vadj;
                achoud=0;
                while((vadj != NULL)&&(achoud == 0))
				{
                    if(vadj->dado == vd)
					{
                    	printf("\n ja existe \n");
                        achoud=1;
                    }
					else
					{
                        antd=vadj;
                        vadj=vadj->prox;
                    }
                }                           
                    if(achoud == 0)
					{
                        vadj=(struct nodo*) malloc (sizeof(struct nodo));
                        vadj->dado=vd;
                        vadj->prox=NULL;
                        antd->prox=vadj;
                    } 
            }
                    ant=aux;
                    aux=aux->proxv;                
        }        
	    if(achou == 0)
		{
            aux=(struct vertice*) malloc (sizeof(struct vertice));
            aux->v=vo;
            aux->proxv=NULL;
            vadj=(struct nodo*) malloc (sizeof(struct nodo));
            vadj->dado=vd;
        	vadj->prox=NULL;
            aux->proxa=vadj;
            ant->proxv=aux;
        }   
    }
}

void desconecta(struct vertice **grafo, int vo, int vd)
{
    struct vertice *aux;
    struct nodo *aux_a, *ant_a;
    if(grafo!=NULL)
	{
        aux=*grafo;
        while((aux!=NULL)&&(aux->v!=vo))
            aux=aux->proxv;
        if(aux!=NULL)
		{
            aux_a=aux->proxa;
            while(aux_a && (aux_a->dado!=vd))
			{
                ant_a=aux_a;
                aux_a=aux_a->prox;
            }
            if(aux_a!=NULL)
			{ 
                if(aux->proxa==aux_a)
                    aux->proxa=aux_a->prox;
                else ant_a->prox=aux_a->prox; 
                    free(aux_a);                  		
            }
        }
	}
}

void mostra_grafo(struct vertice *grafo)
{
    struct vertice *aux;
    struct nodo *auxd;
   
    aux=grafo;
     	
	while(aux)
	{
        printf("vertice->%i",aux->v);
        auxd=aux->proxa;
      
        while(auxd)
		{
            printf("->%i",auxd->dado);
            auxd=auxd->prox;
        }
        printf("\n");
        aux=aux->proxv;
    }
    getch();
}
		
	
		
										
int main()
{
    int vdestino,vorigem,op;
    struct vertice *g=NULL;

    printf("Digite 0 para mostrar o grafo.....\n");
    
    do
	{
        printf("\nVertice Origem:");
        scanf("%i",& vorigem);
    
	    if(vorigem != 0)
		{
            printf("\nVertice Destino:");
            scanf("%i",&vdestino);
            
			if(vdestino != 0)
			{
                conecta(&g,vorigem,vdestino);
            }
        }
    }while(vorigem != 0);
    
	if (mostra_grafo == NULL)
    	printf("Vazio\n");
	else
    	mostra_grafo(g);
    
	getch();               
}
