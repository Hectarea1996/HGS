
Carpeta donde se guardaran los elementos necesarios para crear animaciones que se dibujarán por pantalla.

HGS_Imagen es una estructura de datos que guarda una imagen.

Podemos agrupar varias HGS_Imagen en una HGS_Animacion, que se crean utilizando el fichero HGS_FactoriaAnimacion. El programador es libre de crear otro tipo de animaciones si lo desea.

Seguidamente, debemos agrupar todas las animaciones en un array e insertarlo en un ConjuntoAnimacion donde debemos implementar qué animacion, y cuándo, debe dibujarse.

Este ConjuntoAnimacion se le pasará a un sprite.
