
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
