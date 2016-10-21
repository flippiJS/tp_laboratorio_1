#ifndef DEFINES_H
#define DEFINES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// TAGS MENU
#define MENU_OPTIONS "***** MENU ******\n\n 1) Agregar pelicula\n 2) Borrar pelicula\n 3) Modificar pelicula\n 4) Generar pagina web\n 5) Imprimir lista de peliculas\n 6) Salir\n\nSeleccione una opcion: "
#define MENU_OPTIONS_1        1
#define MENU_OPTIONS_2        2
#define MENU_OPTIONS_3        3
#define MENU_OPTIONS_4        4
#define MENU_OPTIONS_5        5
#define MENU_OPTIONS_6		  6
#define MENU_OPTIONS_7		  7
#define MENU_ERROR           "\n** La opcion ingresada es incorrecta. **\n"

// DEFINIMOS ESTRUCTURA
typedef struct {

	int id;
	char titulo[500];
	char genero[500];
	int duracion;
	char descripcion[500];
	int puntaje;
	char urlPortada[500];

} EMovie;

//TAGS WEB INICIO Y FIN
#define WEB_HEAD "<!DOCTYPE html>\n\n<html lang='en'>\n<head>\n\t<meta charset='utf-8'>\n\t<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n\t\n\t<title>Lista peliculas</title>\n\t<!-- Bootstrap Core CSS -->\n\t<link href='css/bootstrap.min.css' rel='stylesheet'>\n\t<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n\t<link href='css/custom.css' rel='stylesheet'>\n\t<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n\t<!-- WARNING: Respond.js doesn't work if you view the page via file:\x2f\x2f -->\n\t<!--[if lt IE 9]>\n\t\t<script src='https:\x2f\x2foss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n\t\t<script src='https:\x2f\x2foss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n\t<![endif]-->\n</head>\n<body>\n\t<div class='container'>\n\t\t<div class='row'>\n"
#define WEB_BODY "\t\t</div>\n\t\t\n\t</div>\n\t\n\t\n\t<script src='js/jquery-1.11.3.min.js'></script>\n\t\n\t<script src='js/bootstrap.min.js'></script>\n\t\n\t<script src='js/ie10-viewport-bug-workaround.js'></script>\n\t\n\t<script src='js/holder.min.js'></script>\n</body>\n</html>"

// POR CADA PELICULA
#define WEB_URL_IMG "\n\n\t\t\t\n\t\t\t<article class='col-md-4 article-intro'>\n\t\t\t\t<a href='#'>\n\t\t\t\t\t<img class='img-responsive img-rounded' src='"
#define WEB_TITULO "' alt='' width='230px' height='290px'>\n\t\t\t\t</a>\n\t\t\t\t<h3>\n\t\t\t\t\t<a href='#'>"
#define WEB_GENERO "</a>\n\t\t\t\t</h3>\n\t\t\t\t<ul>\n\t\t\t\t\t<li><strong>Genero:</strong>"
#define WEB_PUNTAJE "</li>\n\t\t\t\t\t<li><strong>Puntaje: </strong>"
#define WEB_DURACION " /10</li>\n\t\t\t\t\t<li><strong>Duracion: </strong>"
#define WEB_DESCRIPCION " minutos</li>\n\t\t\t\t</ul>\n\t\t\t\t<strong>Sinopsis:</strong><p>"
#define WEB_CIERRE_ARTICLE "</p>\n\t\t\t</article>\n\t\t\t\n\n\n"


#endif // DEFINES_H
