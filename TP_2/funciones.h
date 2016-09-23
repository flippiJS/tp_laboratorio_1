
typedef struct {
    char Nombre[50];
    unsigned long Dni;
    unsigned int Edad;
    int Estado;
}ABMPersona;

int buscarLugarLibre(ABMPersona Persona[], int longitud);
void cargaPersona(ABMPersona Persona[]);
void bajaPersona(ABMPersona Persona[]);
void mostrarLista(ABMPersona Persona[]);
char getChar(char mensaje[]);
int onlyNum(char str[]);
int onlyChar(char str[]);
int checkNum(char numeros[],int maximo);
int checkInt(int i,int desde,int hasta);
void obtenerCadena (char Mensaje[],char Input[]);
