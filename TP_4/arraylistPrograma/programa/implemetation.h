int mostrarMenu(char *menu);

void listarContenido(ArrayList *usuarios,ArrayList *tweets);
void nuevoUsuario(ArrayList *usuarios);
void modificaUsuario(ArrayList *usuarios);
void borrarUsuario(ArrayList * usuarios);
void nuevoTweet(ArrayList *usuarios,ArrayList *tweets);
void reTweet(ArrayList *usuarios,ArrayList *tweets);
int informarContenido(ArrayList *usuarios,ArrayList *usuariosOriginales,ArrayList *tweets,ArrayList *tweetsOriginales);
int cargaArchivo(ArrayList* pList,char* nombreArchivo, int opcion);
int guardarArchivo(ArrayList* pList, char* nombreArchivo, int opcion);
