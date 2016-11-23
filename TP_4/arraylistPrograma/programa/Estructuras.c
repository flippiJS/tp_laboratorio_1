#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"
#include "ArrayList.h"
#include "implemetation.h"

User* newUser(char *name, char *nick, char *password,char *email, int id)
{
    User* retorno = NULL;
    User* pUser = malloc(sizeof(User));

    if(pUser != NULL)
    {
        strcpy(pUser->name,name);
        strcpy(pUser->nick,nick);
        strcpy(pUser->password,password);
        strcpy(pUser->email,email);
        pUser->id = id;

        pUser->isEmpty = 0;

        retorno = pUser;
    }

    return retorno;

}

ETweets* newComment(char *comments, int idUsuario,int id)
{
    ETweets* retorno = NULL;
    ETweets* pComment = malloc(sizeof(ETweets));

    if(pComment != NULL)
    {
        strcpy(pComment->comments,comments);

        pComment->idUsuario = idUsuario;
        pComment->likes = 0;
        pComment->isEmpty = 0;
        pComment->id = id;

        retorno = pComment;
    }

    return retorno;

}

int compareUser(void* UserA,void* UserB)
{
    int retorno=0;
    if(strcmp((((User*)UserA)->name),(((User*)UserB)->name)) >0)
    {
        retorno=1;
    }
    if(strcmp((((User*)UserA)->name),(((User*)UserB)->name)) <0)
    {
        retorno=-1;
    }

    return retorno;
}



void printUser(User* user)
{
    printf("%d= Nombre:%s Nombre de Usuario:%s Mail:%s\r\n",user->id,user->name,user->nick,user->email);
}

