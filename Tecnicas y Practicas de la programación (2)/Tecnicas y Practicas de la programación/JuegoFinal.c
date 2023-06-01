#include <math.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "nodo.h"
#include "grafo.h"

#define NOMBRESIZE 10

typedef struct jugador {
    char nombre[NOMBRESIZE];     // Nombre del jugador
    int damage;                  // Daño físico del jugador
    int health1;                 // Salud 1 del jugador
    int health2;                 // Salud 2 del jugador
    int agilidad;                // Agilidad del jugador
    int Mana;                    // Puntos de mana del jugador
    int puntosHabilidad;         // Puntos de habilidad del jugador
    int damageMagico;            // Daño mágico del jugador
} Jugador;

typedef struct Jefe {
    char name[10];           // Nombre del jefe
    char data[10000];        // Datos adicionales del jefe
    int health1;             // Salud 1 del jefe
    int health2;             // Salud 2 del jefe
    int pointsGift;          // Puntos de regalo del jefe
} Jefe;

/* Operaciones */
/*
Función crearLista
Entrada: Ninguna.
Salida: Un puntero a una estructura de tipo List.
Descripción: Esta función crea y devuelve una nueva lista vacía.
*/
List *crearLista(){
  List *lista = (List *)malloc(sizeof(List));
  lista->head = NULL;
  lista->size = 0;
  return lista;
}

/*
Función anxList
Entrada: Un puntero a una estructura de tipo List y un objeto de tipo Objeto.
Salida: Ninguna.
Descripción: Esta función agrega un nuevo nodo con el objeto especificado al final de la lista.
*/

void anxList(List *lista, Objeto objeto) {
  Node *nuevoNodo = (Node *)malloc(sizeof(Node));
  nuevoNodo->objeto = objeto;
  nuevoNodo->next = NULL;

  if (lista->head == NULL) {
    lista->head = nuevoNodo;
  } else {
    Node *ultimoNodo = lista->head;
    while (ultimoNodo->next != NULL) {
      ultimoNodo = ultimoNodo->next;
    }
    ultimoNodo->next = nuevoNodo;
  }

  lista->size++;
}

/*
Función imprimirObjeto
Entrada: Un puntero a una estructura de tipo Node.
Salida: Ninguna.
Descripción: Esta función imprime en la consola el nombre y las estadísticas del objeto contenido en el nodo especificado.
*/
void imprimirObjeto(Node *nodo) {
  printf("Nombre: %s, Estadisticas: %d\n", nodo->objeto.name,
         nodo->objeto.stats);
}

/*
Función imprimirLista
Entrada: Un puntero a una estructura de tipo List.
Salida: Ninguna.
Descripción: Esta función imprime en la consola los elementos de la lista junto con su posición.
*/
void imprimirLista(List *lista) {
  Node *nodoActual = lista->head;
  int i = 1;
  while (nodoActual != NULL) {
    printf("%d. ", i);
    imprimirObjeto(nodoActual);
    nodoActual = nodoActual->next;
    i++;
  }
}

/* Prototipos */
void menuJuego();
void personajesTipos();
void infoBestiario();
void imprimirinventario();
void modoBatalla();
void explorar();
void estadisticas();
void objetos();
void estructuraJefes();
void creacionZonas();
void avanzarZonas();
void crearArBinEscribir();
int leerArchivo();
// void exportar_variables();

/* Variables */

int abilitypoints = 0;
int vivoMuerto = 0;
int movimiento = 0;
Jugador jugador;
Jefe Grago;
Jefe Karin;
Jefe Gorgoroth;
Jefe Banshee;
Jefe Licantropo;
Objeto Elixir;
Objeto pociones;
Objeto BaritaMagica;
Objeto anillo;
Objeto espadon;
Objeto daga;
Grafo zonita[5];

/*
Función main
Entrada: Ninguna.
Salida: Un número entero que indica el estado de finalización del programa.
Descripción: La función principal del programa. Presenta un menú de opciones al usuario y ejecuta diferentes acciones según la opción seleccionada.
*/

/**
 * La funcion principal del programa.
 * 
 * @return 0 si el programa se ejecuta correctamente.
 */
int main() {
  int option = 0;

  // Bucle hasta que se seleccione la opcion 3 (Salir)
  while (option != 3) {
    system("cls"); // Limpia la pantalla

    // Impresion del encabezado del juego
    printf("     _______.  ______    __    __   __           ______   .__   __.     _______  __  .______       _______ \n");
    printf("    /       | /  __  \\  |  |  |  | |  |         /  __  \\  |  \\  |    |   ____||  | |   _  \\     |   ____|\n");
    printf("   |   (----`|  |  |  | |  |  |  | |  |        |  |  |  | |   \\|  |    |  |__   |  | |  |_)  |    |  |__   \n");
    printf("    \\   \\    |  |  |  | |  |  |  | |  |        |  |  |  | |  . `  |    |   __|  |  | |      /     |   __|  \n");
    printf(".----)   |   |  `--'  | |  `--'  | |  `----.   |  `--'  | |  |\\   |    |  |     |  | |  |\\  \\----.|  |____ \n");
    printf("|_______/     \\______/   \\______/  |_______|    \\______/  |__| \\__|    |__|     |__| | _| `._____||_______|\n\n");
    printf(" ============================================================================================================ \n\n");
    printf("                                           1.Juego Nuevo\n                                          2.continuar \n");
    printf("                                           3.Salir \n                                               Elige una opcion -->");

    scanf("%d", &option); // Captura la opcion seleccionada por el usuario

    // Realiza diferentes acciones segun la opcion seleccionada
    switch (option) {
      case 1:
        printf("\nIniciando Juego...\n\n");
        personajesTipos();
        objetos();
        estructuraJefes();
        menuJuego();
        break;
      case 2:
        printf("\nReanudando Juego...\n\n");
        leerArchivo();
        menuJuego();
      case 3:
        printf("\nSaliendo...\n\n");
        break;
      default:
        printf("\nLa opcion ingresada no existe\n\n");
        break;
    }
  }

  return 0;
}

/*
Función menuJuego
Entrada: Ninguna.
Salida: Ninguna.
Descripción: Esta función presenta un menú de opciones al jugador y ejecuta diferentes acciones según la opción seleccionada.
*/
void menuJuego() {
  creacionZonas();  // Crea las zonas del juego
  List *inventario = crearLista();  // Crea una lista para almacenar objetos en el inventario del jugador
  int opcion1 = 0;

  // Bucle hasta que se seleccione la opcion 6 (Salir) o el jugador est muerto
  while (opcion1 != 6 && vivoMuerto == 0) {
    printf("\n1. Explorar\n2. Avanzar\n3. Estadisticas\n4. Inventario\n5. Bestiario\n6. Salir\nElige una opcion > ");
    scanf("%d", &opcion1);

    // Realiza diferentes acciones segun la opcion seleccionada
    switch (opcion1) {
      case 1:
        printf("\nIniciando Exploracion...\n\n");
        explorar(inventario);  // Realiza la exploracion del area y actualiza el inventario
        break;
      case 2:
        printf("\nAvanzando...\n\n");
        avanzarZonas();  // Avanza a la siguiente zona
        printf("\n");
        modoBatalla();  // Inicia el modo de batalla si hay un enemigo en la zona
        break;
      case 3:
        printf("\nCargando Estadisticas...\n\n");
        estadisticas();  // Muestra las estadisticas del jugador
        break;
      case 4:
        printf("\nAbriendo Inventario...\n\n");
        imprimirinventario(inventario);  // Muestra el contenido del inventario
        break;
      case 5:
        printf("\nInspeccionando Bestiario...\n\n");
        infoBestiario();  // Muestra informacion sobre los enemigos del juego
        break;
      case 6:
        printf("\nSaliendo...\n\n");
        break;
      default:
        printf("\nLa opcion ingresada no existe\n\n");
        break;
    }
  }

  // Comprueba si el jugador esta muerto y muestra un mensaje correspondiente
  if (vivoMuerto == 1){
    printf("Has sido derrotado\n");
    vivoMuerto = 0;
  }
}

/*
Función objetos
Entrada: Ninguna.
Salida: Ninguna.
Descripción: Esta función inicializa los diferentes objetos del juego con sus respectivos nombres y estadísticas.
*/

void objetos() {
  // Esta funcion inicializa los diferentes objetos del juego con sus respectivos nombres y estadisticas. 
  /* Pocion de vida */
  strcpy(Elixir.name, "Pocion de vida");
  Elixir.stats = 150;
  /* Pocion de Mana */
  strcpy(pociones.name, "Pocion de Mana");
  pociones.stats = 100;
  /* Baston Magico*/
  strcpy(BaritaMagica.name, "Baston magico");
  BaritaMagica.stats = 200;
  /* Jeringa */
  strcpy(anillo.name, "Jeringa de adrenalina");
  anillo.stats = 350;
  /* Espada */
  strcpy(espadon.name, "Espada");
  espadon.stats = 200;
  /* Daga */
  strcpy(daga.name, "Daga");
  daga.stats = 300;
}

/*
Función estructuraJefes
Entrada: Ninguna.
Salida: Ninguna.
Descripción: Esta función crea la estructura de jefes del juego, inicializando cada uno con sus atributos.
*/
void estructuraJefes() {
  //Esta funcion crea la estructura de jefes del juego, inicializando cada uno con sus atributos.
  /* Grago */
  strcpy(Grago.name, "Grago");
  strcpy(Grago.data, "Es una figura imponente con escamas oscuras y ojos carmesi. Domina las artes oscuras y controla las sombras. Su lair es un templo sombrio lleno de tesoros saqueados. Los aventureros valientes deben enfrentarse a el con habilidad y coraje para derrotarlo y liberar al mundo de su reinado de oscuridad.");
  Grago.health1 = 2500;
  Grago.health2 = 2500;
  Grago.pointsGift = 3;
  /* Karin */
  strcpy(Karin.name, "Karin");
  strcpy(Karin.data, "Vestido con una armadura oscura y emanando un aura de maldad, Karin desafia a los valientes jugadores a enfrentarse a su poderoso arsenal de habilidades y estrategias letales.");
  Karin.health1 = 3000;
  Karin.health2 = 3000;
  Karin.pointsGift = 4;
  /* Gorgoroth */
  strcpy(Gorgoroth.name, "Gorgoroth");
  strcpy(Gorgoroth.data, "Este colosal jefe acuatico es conocido por su fuerza descomunal y habilidades misticas. Posee la capacidad de controlar las aguas a su voluntad, convirtiendolas en poderosos torrentes que arrastran a los aventureros desprevenidos hacia un destino incierto. Su rugido atronador resuena a traves de las profundidades, llenando de temor a aquellos que se atreven a enfrentarlo.");
  Gorgoroth.health1 = 2000;
  Gorgoroth.health2 = 2000;
  Gorgoroth.pointsGift = 2;
  /* Banshee */
  strcpy(Banshee.name, "Banshee");
  strcpy(Banshee.data, "Su cuerpo esta compuesto de tierra y rocas, emanando una energia terrosa. Su piel esta cubierta de musgo brillante y emite un resplandor verde y dorado, sus ojos son esferas luminosas que cambian de color, deslumbrando a quienes los miran. Banshee tiene una fuerza sobrenatural y puede manipular la tierra, levantando rocas y abriendo el suelo. Tambien puede lanzar rayos luminosos y generar escudos de energia.");
  Banshee.health1 = 3500;
  Banshee.health2 = 3500;
  Banshee.pointsGift = 5;
  /* Licantropo */
  strcpy(Licantropo.name, "Licantropo");
  strcpy(Licantropo.data, "Con una apariencia imponente y poderes arcanos, este jefe es capaz de transformarse en un ser lobo-humano durante las noches de luna llena. Su sabiduria y conocimiento de la magia lo convierten en un oponente temible y estrategico. Solo los mas valientes podran enfrentarlo y superar sus desafios para obtener las recompensas que guarda.");
  Licantropo.health1 = 10000;
  Licantropo.health2 = 10000;
  Licantropo.pointsGift = 10;
}
/*
Esta funcion imprime el contenido de la lista de inventario.

Args:
    inventario (List): La lista de inventario a imprimir.

Returns:
    None
*/
void imprimirinventario(List *inventario) { imprimirLista(inventario); }

/**
 * Esta funcion muestra las estadisticas del jugador y permite asignar puntos de habilidad.
 */
/*
Función estadisticas
Entrada: Ninguna.
Salida: Ninguna.
Descripción: Esta función muestra las estadísticas del jugador y permite asignar puntos de habilidad para aumentar las estadísticas. El jugador puede asignar puntos de habilidad a las siguientes estadísticas: salud, daño, agilidad y mana.
*/
void estadisticas() {
  int opcion3, x, vivoMuerto = 0;
  printf("Estadisticas de %s:\n", jugador.nombre);
  printf("Health = %d\n", jugador.health1);
  printf("Damage = %d\n", jugador.damage);
  printf("Agilidad = %d\n", jugador.agilidad);
  printf("Mana = %d\n", jugador.Mana);
  while (jugador.puntosHabilidad > 0 && vivoMuerto == 0) {                                                                                                                
    printf("Tienes %d punto/s disponible/s para asignar.\n\n", jugador.puntosHabilidad);
    printf("Deseas asignar tus puntos de habilidad?\n");
    printf("1. Si  2. No\n\nElige una opcion > ");
    scanf("%d", &x);
    printf("\n");
    if (x == 1) {
      printf("1. Increase health\n2. Increase damage\n3. Increase agilidad\n4. "
             "Increase Mana\n\nElige una opcion > ");
      scanf("%d", &opcion3);
      switch (opcion3) {
      case 1:
        jugador.puntosHabilidad--;
        jugador.health1 += 100;
        printf("Tu estadistica de vida ha aumentado de %d a %d\n",
               jugador.health1 - 100, jugador.health1);
        break;
      case 2:
        jugador.puntosHabilidad--;
        jugador.damage += 100;
        printf("Tu estadistica de dano ha aumentado de %d a %d\n",
               jugador.damage - 100, jugador.damage);
        break;
      case 3:
        jugador.puntosHabilidad--;
        jugador.agilidad += 100;
        printf("Tu estadistica de agilidad ha aumentado de %d a %d\n",
               jugador.agilidad - 100, jugador.agilidad);
        break;
      case 4:
        jugador.puntosHabilidad--;
        jugador.Mana += 100;
        printf("Tu estadistica de Mana ha aumentado de %d a %d\n",
               jugador.Mana - 100, jugador.Mana);
        break;
      case 5:
        break;
      default:
        printf("La opcion ingresada no existe\n");
        break;
      }
    } else {
      vivoMuerto = 1;
    }
  }
  if (jugador.puntosHabilidad == 0)
    printf("No tienes mas puntos para asignar\n");
}

/**
 * Ejecuta el modo de batalla entre el jugador y un jefe.
 * Elige aleatoriamente un jefe y muestra su información.
 * Permite al jugador realizar acciones como atacar, esquivar, parar y usar ataques mágicos.
 * El juego continúa hasta que la salud del jefe o del jugador llegue a cero.
 * Al finalizar, muestra el resultado de la batalla y otorga puntos de mejora al jugador si el jefe es derrotado.
 */
/*
Función modoBatalla
Entrada: Ninguna.
Salida: Ninguna.
Descripción: Esta función inicia el modo de batalla contra un jefe. Elige aleatoriamente un jefe entre Grago, Karin, Gorgoroth, Banshee y Licántropo. El jugador y el jefe se atacan alternativamente hasta que uno de ellos queda sin vida. El jugador puede realizar diferentes acciones durante la batalla, como ataques ligeros, ataques pesados, ataques mágicos, esquivar y parry. El resultado de cada acción se determina aleatoriamente. Si el jugador derrota al jefe, se le otorgan puntos de mejora que puede asignar a sus estadísticas.
*/
void modoBatalla() {
  int flag = 1;
  srand(time(0));
  int damage, boss = rand() % 5;
  Jefe *Variable;

  // Elige aleatoriamente un jefe según el valor de 'boss'
  if (boss == 0) {
    Variable = &Grago;
  } else if (boss == 1) {
    Variable = &Karin;
  } else if (boss == 2) {
    Variable = &Gorgoroth;
  } else if (boss == 3) {
    Variable = &Banshee;
  } else {
    Variable = &Licantropo;
  }

  // Comprueba si el jefe ya está derrotado
  if (Variable->health2 <= 0){
    flag = 0;
    printf("Encuentras el cuerpo sin vida de %s te llenas de valor recordando tu hazaña", Variable->name);
  }

  if (flag == 1){
    printf("Cuidado, ha aparecido: %s", Variable->name);
    printf("\n");
    printf("%s", Variable->data);

    while (Variable->health2 > 0 && jugador.health2 > 0) {
      int opcion2 = 0, probabilidadparry = rand() % 2,
          probabilidadgolpe = rand() % 3, probabilidadesquivar = rand() % 2,
          bossdamage = rand() % (100 - 150 + 1) + 100;

      if (jugador.Mana > 0) {
        printf("\n1. Ataque ligero\n2. Ataque pesado\n3. Ataque magico\n4. Esquivar\n5. Parry\nElige una opcion > ");
        scanf("%d", &opcion2);

        switch (opcion2) {
          case 1:
            // Ataque ligero
            Variable->health2 = Variable->health2 - jugador.damage;
            jugador.Mana -= 375;
            break;
          case 2:
            // Ataque pesado
            if (probabilidadgolpe != 0) {
              printf("\nAtaque exitoso\n");
              damage = jugador.damage * 2;
              Variable->health2 = Variable->health2 - damage;
            } else {
              printf("\nAtaque fallido\n");
            }
            jugador.health2 = jugador.health2 - bossdamage;
            jugador.Mana -= 390;
            break;
          case 3:
            // Ataque mágico
            printf("\n La furia de los dioses cae hasta tu enemigo\n");
            damage = jugador.damageMagico * 2;
            jugador.Mana -= 200;
            Variable->health2 = Variable->health2 - damage;
            break;
          case 4:
            // Esquivar
            if (probabilidadesquivar == 0) {
              printf("\nAtaque esquivado\n");
              bossdamage = bossdamage * 0;
            } else {
              printf("\nMuy lento\n");
            }
            jugador.Mana -= 410;
            break;
          case 5:
            // Parry
            if (probabilidadparry == 1) {
              printf("\nParry exitoso\n");
              bossdamage *= 0;
              Variable->health2 -= jugador.damage * 4;
            } else {
              printf("\nParry fallido\n");
            }
            jugador.Mana -= 500;
            break;
          default:
            printf("\nLa opcion ingresada no existe\n\n");
            break;
        }
      } else {
        printf("\nSin Mana, turno Perdido\n");
      }

      jugador.health2 = jugador.health2 - bossdamage;
      printf("\nVida jugador = %d  Vida Jefe = %d\n", jugador.health2, Variable->health2);
      printf("Mana %d\n", jugador.Mana);
    }

    if (jugador.health2 < 0) {
      vivoMuerto = 1;
    }

    if (Variable->health2 < 0){
      // El jefe ha sido derrotado
      printf("\nDerrotaste al temible %s, gracias a tu increíble hazaña recibiras:\n%d Puntos de mejora", Variable->name, Variable->pointsGift);
      jugador.puntosHabilidad += Variable->pointsGift;
    }
  }
}


/**
 * Realiza una exploración en busca de objetos o recompensas.
 * Genera un número aleatorio y dependiendo del resultado, otorga diferentes objetos o efectos al jugador.
 * Los objetos encontrados se agregan al inventario del jugador.
 * Algunos resultados especiales pueden guardar la partida.
 *
 * @param inventario Puntero a la lista de inventario del jugador.
 */
void explorar(List *inventario) {
  srand(time(0));
  char valor[3];
  int counter = 0, j, numero = rand() % 101;

  if (numero <= 5) {
    printf("Felicidades, encontraste: Antorcha\n");
    crearArBinEscribir();
  } else if (numero <= 8) {
    printf("Felicidades, encontraste: Poder de habilidad\n");
    jugador.puntosHabilidad++;
  } else if (numero <= 19) {
    printf("Felicidades, encontraste: %s\n", Elixir.name);
    anxList(inventario, Elixir);
  } else if (numero <= 30) {
    printf("Felicidades, encontraste: %s\n", pociones.name);
    anxList(inventario, pociones);
  } else if (numero <= 40) {
    printf("Felicidades, encontraste: %s\n", BaritaMagica.name);
    anxList(inventario, BaritaMagica);
  } else if (numero <= 50) {
    printf("Felicidades, encontraste: %s\n", anillo.name);
    anxList(inventario, anillo);
  } else if (numero <= 60) {
    printf("Felicidades, encontraste: %s\n", espadon.name);
    anxList(inventario, espadon);
  } else if (numero <= 70) {
    printf("Felicidades, encontraste: %s\n", daga.name);
    anxList(inventario, daga);
  } else {
    printf("Felicidades, encontraste: nada\n");
  }

  if (numero <= 5) {
    printf("\nDesea guardar la partida? ");
    scanf("%s", &valor);

    if (strcmp(valor, "si") == 0) {
      printf("\nLa partida se ha guardado\n");
    }
  }
}

/*
Función personajesTipos
Entrada: Ninguna.
Salida: Ninguna.
Descripción: Esta función permite al jugador elegir un nombre y una clase para su personaje. El jugador puede elegir entre cuatro clases: Guerrero, Asesino, Tanque y Mago. Dependiendo de la clase elegida, se asignarán diferentes estadísticas al jugador, como daño, salud, agilidad y maná. Además, se inicializa el número de puntos de mejora del jugador en 0.
*/
void personajesTipos() {
  char nombre[30];
  int clase;
  printf("Ingrese su nickname de jugador\n");
  scanf("%s", jugador.nombre);
  printf("1. Guerrero\n");
  printf("2. Asesino\n");
  printf("3. Tanque\n");
  printf("4. Mago\n");
  printf("Seleccione su clase > ");
  scanf("%d", &clase);
  switch (clase) {
  case 1:
    printf("Tu valia se demuestra en el campo de batalla, te conviertes en un "
           "Guerrero\n");
    jugador.damage = 200;
    jugador.health1 = 2000;
    jugador.health2 = 2000;
    jugador.agilidad = 40;
    jugador.Mana = 1500;
    jugador.damageMagico = 2;
    break;
  case 2:
    printf("El sigilo te llama te has convertido en el mejor Asesino del "
           "mundo.\n");
    jugador.damage = 400;
    jugador.health1 = 1400;
    jugador.health2 = 1400;
    jugador.agilidad = 100;
    jugador.Mana = 1200;
    jugador.damageMagico = 1;
    break;

  case 3:
    printf("Tu fuerza y valia son inimaginables, te has convertido en un "
           "Tanque\n");
    jugador.damage = 80;
    jugador.health1 = 3000;
    jugador.health2 = 3000;
    jugador.agilidad = 20;
    jugador.Mana = 1600;
    jugador.damageMagico = 0;
    break;
  case 4:
    printf("La distancia y el estudio son lo tuyo, te has convertido en un "
           "Mago\n");
    jugador.damage = 50;
    jugador.health1 = 800;
    jugador.health2 = 800;
    jugador.agilidad = 70;
    jugador.Mana = 2000;
    jugador.damageMagico = 500;
    break;
  }
  jugador.puntosHabilidad = 0;
}

/*
Función infoBestiario
Entrada: Ninguna.
Salida: Ninguna.
Descripción: Esta función muestra la información de los jefes derrotados en el juego. Comprueba qué jefes han sido derrotados y crea un arreglo dinámico de estructuras de tipo Jefe para almacenar la información de los jefes derrotados. Luego, muestra la información de cada jefe derrotado, incluyendo su nombre, vida total y una descripción. Si no se ha derrotado ningún jefe, se mostrará un mensaje indicando que ningún jefe ha sido derrotado. Al finalizar, se libera la memoria asignada para el arreglo de jefes derrotados.
*/
void infoBestiario() {
  int i, contador = 0;
  int Gragof = 0, Karinf = 0, Gorgorothf = 0, Bansheef = 0, Licantropof = 0;
  for (i = 0; i < 5; i++) {
    if (i == 0 && Grago.health2 <= 0) {
      contador++;
    } else if (i == 1 && Karin.health2 <= 0) {
      contador++;
    } else if (i == 2 && Gorgoroth.health2 <= 0) {
      contador++;
    } else if (i == 3 && Banshee.health2 <= 0) {
      contador++;
    } else if (i == 4 && Licantropo.health2 <= 0) {
      contador++;
    }
  }
  Jefe *jefes;
  jefes = (Jefe *)malloc(contador * sizeof(Jefe));
  for (i = 0; i < contador; i++) {
    if (Grago.health2 <= 0 && Gragof == 0) {
      jefes[i] = Grago;
      Gragof = 1;
    } else if (Karin.health2 <= 0 && Karinf == 0) {
      jefes[i] = Karin;
      Karinf = 1;
    } else if (Gorgoroth.health2 <= 0 && Gorgorothf == 0) {
      jefes[i] = Gorgoroth;
      Gorgorothf = 1;
    } else if (Banshee.health2 <= 0 && Bansheef == 0) {
      jefes[i] = Banshee;
      Bansheef = 1;
    } else if (Licantropo.health2 <= 0 && Licantropof == 0) {
      jefes[i] = Licantropo;
      Licantropof = 1;
    }
  }
  if (contador == 0) {
    printf("Ningun jefe ha sido derrotado\n");
  } else {
    printf("------------- Bestiario ------------------------\n");
    for (i = 0; i < contador; i++) {
      printf("Jefe #%d\n", i + 1);
      printf("Nombre: %s\n", jefes[i].name);
      printf("Vida Total: %d\n", jefes[i].health1);
      if (i != contador - 1)
        printf("Informacion: %s\n\n", jefes[i].data);
      else {
        printf("Informacion: %s\n", jefes[i].data);
      }
    }
  }
  free(jefes);
  printf("\n");
  system("pause");
}

/*
Función creacionZonas
Entrada: Ninguna.
Salida: Ninguna.
Descripción: Esta función crea y asigna los valores a las diferentes zonas del juego. Cada zona tiene un nombre y una descripción asociada. Las zonas se definen como estructuras de tipo Zone y se almacenan en un arreglo global llamado "zonita". Cada zona también tiene una lista de números que representa las zonas a las que se puede acceder desde esa zona. Se asignan los valores correspondientes a cada zona y se especifica la cantidad de zonas a las que se puede acceder desde cada una. Las zonas se identifican por un número, que corresponde a su posición en el arreglo "zonita".
*/
void creacionZonas(){
  Zone A0 = {"Desierto de la desolacion",
  "El Desierto de la Desolacion se extiende como un vasto y arido paisaje, donde la vida parece haber sido abandonada por completo. Con una extension sin fin, sus dunas y llanuras de arena se desvanecen hasta el horizonte, ofreciendo una vista desolada y desafiante para aquellos valientes que se aventuran en su territorio inhospito."};
  Zone B1 = {"Manglares Oscuros", 
"Los Manglares Oscuros se alzan majestuosamente a lo largo de la costa, como guardianes silenciosos de un misterio oculto. Estos densos bosques de arboles retorcidos y raices serpentinas crean un ambiente enigmatico y cautivador. La oscuridad se filtra entre las ramas entrelazadas, proyectando sombras danzantes sobre las aguas tranquilas y pantanosas que rodean los manglares."};
  Zone C2 = {"Magestic Forest",
"En lo mas profundo de un reino encantado y oculto, se encuentra el Majestic Forest, un lugar de una belleza indescriptible. Este bosque magico esta impregnado de una energia vibrante que emana de cada rincon, envolviendo a todo aquel que se aventura en sus dominios."};
  Zone D3 = {"La bahia de los ahogados",
  "La Bahia de los Ahogados es un lugar enigmatico y sombrio ubicado en una remota region costera. Su nombre evoca un oscuro pasado y una historia llena de tragedias maritimas. Al acercarte a la bahia, una densa niebla se cierne sobre las aguas, ocultando los peligros que yacen bajo su superficie."};
  Zone E4 = {"The END",
"The End es un lugar misterioso y enigmatico que se encuentra en lo mas profundo de los confines del universo. Es un punto de convergencia donde todas las historias, todos los destinos y todas las posibilidades llegan a su fin. Este lugar esta envuelto en un silencio eterno y una oscuridad impenetrable."};
  // Zona A0
  zonita[0].zona = A0;
  zonita[0].numeros[0] = 1;
  zonita[0].size = 1;
  // Zona B1
  zonita[1].zona = B1;
  zonita[1].numeros[0] = 0;
  zonita[1].numeros[1] = 2;
  zonita[1].numeros[2] = 4;
  zonita[1].size = 3;
  // Zona C2
  zonita[2].zona = C2;
  zonita[2].numeros[0] = 1;
  zonita[2].numeros[1] = 3;
  zonita[2].size = 2;
  // Zona D3
  zonita[3].zona = D3;
  zonita[3].numeros[0] = 2;
  zonita[3].numeros[1] = 4;
  zonita[3].size = 2;
  // Zona E4
  zonita[4].zona = E4;
  zonita[4].numeros[0] = 3;
  zonita[4].numeros[1] = 1; 
  zonita[4].size = 2;

}

/*
Función avanzarZonas
Entrada: Ninguna.
Salida: Ninguna.
Descripción: Esta función permite al jugador avanzar entre las diferentes zonas del juego. Se muestra una lista de las zonas a las que se puede acceder desde la zona actual, numeradas del 0 al n-1. El jugador elige el número correspondiente a la zona a la que quiere moverse. Se actualiza la variable "movimiento" con el número de la nueva zona a la que se ha movido el jugador. Se muestra el nombre y la descripción de la nueva zona.
*/
void avanzarZonas(){
  int num;
  int i;
  for(i = 0; i < zonita[movimiento].size; i++){
    printf("%d. %s\n",i,zonita[zonita[movimiento].numeros[i]].zona.name);
  }
  printf("Digite el numero de la zona a la que quiere moverse: ");
  scanf("%d", &num);
  movimiento = zonita[movimiento].numeros[num];
  char* nombre = zonita[movimiento].zona.name;
  char* descripcion = zonita[movimiento].zona.description;
  printf("%s\n\n", nombre);
  printf("%s\n\n", descripcion);
}

/*
Función crearArBinEscribir
Entrada: Ninguna.
Salida: Ninguna.
Descripción: Esta función crea un archivo binario llamado "partidaG" y escribe los datos del jugador en él. Los datos se escriben en el siguiente orden: nombre, damage, health1, health2, agilidad, damageMagico, Mana y puntosHabilidad. Finalmente, se cierra el archivo.
*/
void crearArBinEscribir(){
    FILE *archivo;
    archivo = fopen("partidaG","wb");
    if(archivo == NULL){
        printf("NO SE PUDO ACCEDER AL ARCHIVO\n");
    }
    else{
        fwrite(jugador.nombre,sizeof(char) * NOMBRESIZE, 1 , archivo);
        fwrite(&jugador.damage, sizeof(int), 1, archivo);
        fwrite(&jugador.health1, sizeof(int), 1, archivo);
        fwrite(&jugador.health2, sizeof(int), 1, archivo);
        fwrite(&jugador.agilidad, sizeof(int), 1, archivo);
        fwrite(&jugador.damageMagico, sizeof(int), 1, archivo);
        fwrite(&jugador.Mana, sizeof(int), 1, archivo);
        fwrite(&jugador.puntosHabilidad, sizeof(int), 1, archivo);
        fwrite(&jugador.puntosHabilidad, sizeof(int), 1, archivo);
        fwrite(&jugador.puntosHabilidad, sizeof(int), 1, archivo);
        fclose(archivo);
    }
    printf("\nGuardado exitoso\n");
}

/**
 * Esta funcion lee los datos de una partida guardada desde un archivo binario llamado "partidaG".
 * Los datos leídos incluyen el nombre del jugador y diferentes atributos del jugador.
 * Si el archivo no se puede abrir o no existe, se muestra un mensaje de error y se retorna 0.
 * Si se puede leer el archivo correctamente, se almacenan los datos en las variables correspondientes y se retorna 1.
 */
int leerArchivo() {
  FILE *archivo;
  archivo = fopen("partidaG", "rb");

  if (archivo == NULL) {
    printf("NO SE PUDO ACCEDER AL ARCHIVO - No hay una Partida Guardada.\n");
    return 0;
  } else {
    fread(jugador.nombre, sizeof(char) * NOMBRESIZE, 1, archivo);

    for (int i = 0; i < NOMBRESIZE; i++) {
      fread(&jugador.nombre[i], sizeof(int), 1, archivo);
    }

    fread(&jugador.damage, sizeof(int), 1, archivo);
    fread(&jugador.health1, sizeof(int), 1, archivo);
    fread(&jugador.health2, sizeof(int), 1, archivo);
    fread(&jugador.agilidad, sizeof(int), 1, archivo);
    fread(&jugador.damageMagico, sizeof(int), 1, archivo);
    fread(&jugador.Mana, sizeof(int), 1, archivo);
    fread(&jugador.puntosHabilidad, sizeof(int), 1, archivo);
    fread(&jugador.puntosHabilidad, sizeof(int), 1, archivo);
    fread(&jugador.puntosHabilidad, sizeof(int), 1, archivo);
  }

  fclose(archivo);
  return 1;
}
