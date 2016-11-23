#ifndef __USER
#define ____USER

struct
{
    int id;
    char name[100];
    char nick[100];
    char password[100];
    char email[100];
    int isEmpty;

}typedef User;

struct
{
    int id;
    char comments[250];
    int likes;
    int idUsuario;
    int isEmpty;

}typedef ETweets;

#endif  //____USER

User* newUser(char *name, char *nick, char *password,char *email, int id);
ETweets* newComment(char *comments, int idUsuario,int id);
void printUser(User* user);
int compareUser(void* pEmployeeA,void* pEmployeeB);
