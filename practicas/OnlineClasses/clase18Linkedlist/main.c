#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

LinkedList* ll_newLinkedList(void)
{
    LinkedList* newList=NULL;
    newList=(LinkedList*) malloc(sizeof(LinkedList));
    if(newList!=NULL)
    {
        newList->size=0;
        newList->firstNode=NULL;
    }
    return newList;
}

int ll_len(LinkedList* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        retorno=this->size;
    }
    return retorno;
}

static Node* getNode (LinkedList* this, int NodeIndex)
{
    int tam=ll_len(this);
    Node* pNodo=NULL;

    if(this!=NULL&&nodeIndex>=0&&nodeIndex<tam)
    {
        pNodo=this->pFirstNode;/*si uso un putero sin asterisco ya hablo de DIRECCIONES DE MEMORIA*/
        /*direccion del primero nodo indice 0*/
        while(nodeIndex>0)
        {
            pNodo=pNodo->pNextNode;
            nodeIndex--;
        }
    }

    return pNodo;
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodo=NULL;
    Node* anterior=NULL;
    if(this!=NULL&&nodeIndex>=0&&nodeIndex<=4)
    {
        /*pido espacio para ese nuevo nodo*/
        pNodo=(Node*)malloc(sizeof(Node));
        if(pNodo!=NULL)
        {
           pNodo->pElement=pElement;
           pNodo->pNextNode=NULL;

           if(nodeIndex==0)
           {
               pNodo->pNextNode=this->pFirstNode;
               this->pFirstNode=pNodo;
           }
           else
           {
            anterior=getNode(this,nodeIndex-1);
            pNodo->pNextNode=anterior->pNextNode;
            anterior->pNextNode=pNodo;
           }
           this->size++;
           returnAux=0;
        }

    }

    return returnAux;
}
