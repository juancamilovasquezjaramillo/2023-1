/* 
 _____        _                                   _             
|_   _|      | |                                 | |            
  | |  _ __  | |_  ___   __ _  _ __  __ _  _ __  | |_  ___  ___ 
  | | | '_ \ | __|/ _ \ / _` || '__|/ _` || '_ \ | __|/ _ \/ __|
 _| |_| | | || |_|  __/| (_| || |  | (_| || | | || |_|  __/\__ \
 \___/|_| |_| \__|\___| \__, ||_|   \__,_||_| |_| \__|\___||___/
                         __/ |                                  
                        |___/                                  
      - David Nino
      - Samuel Moncayo
      - Juan Camilo Vasquez
=====================================================================================================
=====================================================================================================
 _      _  _                       _             
| |    (_)| |                     (_)            
| |     _ | |__   _ __  ___  _ __  _   __ _  ___ 
| |    | || '_ \ | '__|/ _ \| '__|| | / _` |/ __|
| |____| || |_) || |  |  __/| |   | || (_| |\__ \
\_____/|_||_.__/ |_|   \___||_|   |_| \__,_||___/
                                                 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
______             _          _    _                    
| ___ \           | |        | |  (_)                   
| |_/ /_ __  ___  | |_  ___  | |_  _  _ __    ___   ___ 
|  __/| '__|/ _ \ | __|/ _ \ | __|| || '_ \  / _ \ / __|
| |   | |  | (_) || |_| (_) || |_ | || |_) || (_) |\__ \
\_|   |_|   \___/  \__|\___/  \__||_|| .__/  \___/ |___/
                                     | |                
                                     |_|                
*/

int menu_secundario();
void infoBestiario();
int generarNumeroAleatorio();
int batallaJefe();
int enemigoAcertarGolpe();

/*
 _____    _                   _                       
|  ___|  | |                 | |                      
| |__ ___| |_ _ __ _   _  ___| |_ _   _ _ __ __ _ ___ 
|  __/ __| __| '__| | | |/ __| __| | | | '__/ _` / __|
| |__\__ \ |_| |  | |_| | (__| |_| |_| | | | (_| \__ \
\____/___/\__|_|   \__,_|\___|\__|\__,_|_|  \__,_|___/
                                                                                                                                                            
*/

struct nodo {
  char *dato;
  struct nodo *sig;
};
typedef struct nodo *Lista;

Lista crearLista() {
  Lista lst;
  lst = NULL;
  return lst;
}

typedef struct Estadisticas{
        int ataque;
        int puntosHabilidad;
        int agilidad;
}Estadisticas;

typedef struct Player{
        char nombre[30];
        Estadisticas stats;
}Player;

typedef struct Jefes{
      char nombre[30];
      int vida;
      int derrotado;
      char descripcion[100];
}Jefes;

/*
 _____                                 _                          
|  _  |                               (_)                         
| | | | _ __    ___  _ __  __ _   ___  _   ___   _ __    ___  ___ 
| | | || '_ \  / _ \| '__|/ _` | / __|| | / _ \ | '_ \  / _ \/ __|
\ \_/ /| |_) ||  __/| |  | (_| || (__ | || (_) || | | ||  __/\__ \
 \___/ | .__/  \___||_|   \__,_| \___||_| \___/ |_| |_| \___||___/
       | |                                                        
       |_|                                                        
*/

Lista anxLista(Lista lst, char *elem) {
  Lista nuevo, tmp;
  nuevo = (Lista)malloc(sizeof(struct nodo));
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if (lst == NULL)
    lst = nuevo;
  else {
    tmp = lst;
    while (tmp->sig != NULL)
      tmp = tmp->sig;
    tmp->sig = nuevo;
  }

  return lst;
}
int main() {
  int option = 0;
  while (option != 2) {
    system("cls");
    printf("     _______.  ______    __    __   __           ______   .__   __.     _______  __  .______       _______ \n");
    printf("    /       | /  __  \\  |  |  |  | |  |         /  __  \\  |  \\ |  |    |   ____||  | |   _  \\     |   ____|\n");
    printf("   |   (----`|  |  |  | |  |  |  | |  |        |  |  |  | |   \\|  |    |  |__   |  | |  |_)  |    |  |__   \n");
    printf("    \\   \\    |  |  |  | |  |  |  | |  |        |  |  |  | |  . `  |    |   __|  |  | |      /     |   __|  \n");
    printf(".----)   |   |  `--'  | |  `--'  | |  `----.   |  `--'  | |  |\\   |    |  |     |  | |  |\\  \\----.|  |____ \n");
    printf("|_______/     \\______/   \\______/  |_______|    \\______/  |__| \\__|    |__|     |__| | _| `._____||_______|\n\n");
    printf(" =============================================================================================================== \n\n");
    printf("                                           1.Juego Nuevo\n                                           2.Salir \n");
    printf("                                             Elige una opcion -->");
    scanf("%d", &option);
    switch (option) {
    case 1:
      printf("\n\nIniciando juego...\n");
      menu_secundario();
      break;
    case 2:
      printf("Saliendo...\n");
      break;
    default:
      printf("La opcion ingresada no existe.\n");
      break;
    }
  }
  return 1;
}

int menu_secundario() {
  int optionSecond = 0;
  int flag1 = 0;
  int position = 0;
  char nick[30];
  Estadisticas basicStats = {1,0,1};
  Player principal;
  printf("Ingrese su nickname de jugador\n");
  scanf("%s", principal.nombre);
  principal.stats = basicStats;
  Lista inventario;
  while (optionSecond != 6) {
    printf("\n1.Explorar \n2.Avanzar \n3.Estadisticas \n4.Inventario "
           "\n5.Bestiario \n6.Salir \n");
    printf("Elige una opcion -->");
    scanf("%d", &optionSecond);

    switch (optionSecond) {
      /////////////////////////////////////////////////////////////////////////////////
    case 1:
      printf("Explorando...\n");
      int option;
      int option_antorcha;
      int rand_item;
      srand(time(NULL)); // Inicializar la semilla con el tiempo actual
      option = rand() % 5 + 1;
      rand_item = rand() % 6;
      ///////////////////////////////////// Seccion Objetos

      char objetos[5][20] = {"Espada", "Escudo", "Lingote", "Anillo", "Gema"};

      ////////////////////// PUNTOS DE
      /// HABILIDAD////////////////////////////////////
      ///////////////////////SISTEMA COMBATE//////////////////////////////////
      int turnos = 1;
      //////////////////////////////////////////////////
      printf("El numero aleatorio generado es: %d\n", option);
      switch (option) {
      case 1: // Antorcha - Guardar Partida
        printf("\n¿Deseas guardar la partida?\n1. Si\n2. No\n");
        scanf("%d", &option_antorcha);
        if (option_antorcha == 1) {
          printf("Has guardado la partida\n\n");
        } else if (option_antorcha == 2) {
          printf("\nRegresando al menu...\n\n");
        } else {
          printf("\n==== Opcion Invalida =====\n");
        }
        break;
      case 2: // Objetos
          anxLista(inventario, objetos[rand_item]);
        break;
      case 3: // Puntos de Habilidad
        printf("\nFelicidades, ¡has encontrado un punto de habilidad!\n");
        int *puntos;
        puntos = &principal.stats.puntosHabilidad;
        (*puntos)++;  // Incremento del valor al que apunta el puntero
        printf("Puntos de Habilidad actuales: %d\n", principal.stats.puntosHabilidad);
        break;

      case 4:
        
        printf("===== ¡Has encontrado un Jefe!... ========\n");
        batallaJefe();

        break;
      case 5:
        printf("\n ===== NO has encontrado nada en esta busqueda, ¡Buena "
               "suerte en la proxima!... =====\n");

        break;
      default:
        printf("La opcion ingresada no existe.\n");
        break;
      }
      break;

      /////////////////////////////////////////////////////////////////////////////
    case 2:
      printf("Avanzando...\n");
      break;
    case 3:
      printf("Estadisticas...\n");
      break;
    case 4:
      printf("Inventario...\n");
      break;
    case 5:
      printf("Bestiario...\n");
      infoBestiario();
      break;
    case 6:
      printf("Saliendo...\n");
      break;
    default:
      printf("La opcion ingresada no existe.\n");
      break;
    }
  }
  return 0;
}

void infoBestiario() {
  // Nuevo BESTIARIO
  Jefes one = {"Sans",1000,0,"Enemigo silencioso pero demasiado letal"};
  Jefes two = {"Sharkboy", 1200, 1, "Mitad Hombre y mitad tiburon posee ataques lentos"};
  Jefes three = {"Vegetta", 950, 0, "Su fuerte es la velocidad"};
  int n = 3; 
  Jefes *bosses = ( Jefes*)malloc(n * sizeof(Jefes));
  bosses[0] = one;
  bosses[1] = two;
  bosses[2] = three;

  
  char jefes[3][4][50] = {
      {"Sans", "1000", "0", "Enemigo silencioso pero demasiado letal"},
      {"Sharkboy", "1200", "1",
       "Mitad Hombre y mitad tiburon posee ataques lentos"},
      {"Vegetta", "950", "0", "Su fuerte es la velocidad"}};
  printf("------------- BESTIARIO ------------------------\n");
  for (int i = 0; i < 3; i++) {

    if (jefes[i][2][0] != '0') {
      printf("=== Nombre: %s\n", jefes[i][0]);
      printf("=== Puntos de vida: %s\n", jefes[i][1]);
      printf("=== Derrotado: %s\n\n", jefes[i][2]);
      printf("--------------------------------------------\n");
      printf("=== Descripcion del Jefe: %s\n\n", jefes[i][3]);
    }
  }
}

// Aqui podemos generar un numero aleatorio del 1 al 100
int generarNumeroAleatorio() { 
    return rand() % 100 + 1;
 }

// aqui podemos devolver 1 si el enemigo acierta el golpe, 0 en caso contrario
int enemigoAcertarGolpe() {
  int probabilidad = generarNumeroAleatorio();
  if (probabilidad <= 90) {
    return 1;
  } else {
    return 0;
  }
}

// Aqui Encontramos el sistema de batalla completo
int batallaJefe() {
  srand(time(NULL));

  int vidaJugador = 100;
  int vidaEnemigo = 100;
  int turnoJugador = 1;
  int turnoEnemigo = 0;

  while (vidaJugador > 0 && vidaEnemigo > 0) {
    
    if (turnoJugador) {
      printf("Turno del jugador:\n");
      printf("1. Ataque ligero\n");
      printf("2. Ataque pesado\n");
      printf("3. Parry\n");
      printf("Seleccione una opcion: ");

      int opcion;
      scanf("%d", &opcion);

      // Ataque ligero
      if (opcion == 1) {
        int dano = generarNumeroAleatorio() * 0.1;
        vidaEnemigo -= dano;
        printf("El jugador inflige %d puntos de daño al enemigo.\n", dano);

        // Ataque pesado
      } else if (opcion == 2) {
        int dano = generarNumeroAleatorio() * 0.2;
        vidaEnemigo -= dano;
        printf("El jugador inflige %d puntos de daño al enemigo.\n", dano);

        // Parry
      } else if (opcion == 3) {
        printf("El jugador se prepara para parar el próximo ataque del "
               "enemigo.\n");
        int dano = generarNumeroAleatorio() * 0.4;
      }

      turnoJugador = 0;
      turnoEnemigo = 1;

    } else if (turnoEnemigo) {
      printf("Turno del enemigo:\n");

      // El enemigo ataca
      if (enemigoAcertarGolpe()) {
        int dano = generarNumeroAleatorio() * 0.15;
        vidaJugador -= dano;
        printf("El enemigo inflige %d puntos de daño al jugador.\n", dano);

        // El enemigo falla el ataque
      } else {
        printf("El enemigo falla su ataque.\n");
      }

      turnoJugador = 1;
      turnoEnemigo = 0;
    }

    printf("Vida del jugador: %d\n", vidaJugador);
    printf("Vida del enemigo: %d\n", vidaEnemigo);
    printf("\n");
  }
  if (vidaJugador <= 0) {
    printf("\n===== ¡Has perdido el combate! ======\n");
  } else {
    printf("\n====== ¡Has ganado el combate! ======\n");
  }
  return 0;
}
