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
