#include <iostream>
#include <locale>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

bool preguntarJugadorCambiarEmbaucadora(string nombreJugador);

//funciones nuevas
string obtenerPalo(int indice);
int obtenerIndiceCarta();
string reasignarPaloEmbaucadora(string embaucadoraActual);
bool cartaPuedeSumarPuntos(int indiceCarta, string embaucadora);
void resetearCheckList(bool checkList[20]);
int repartirCarta(bool checkList[20]);


int main (){
    setlocale(LC_ALL, "spanish");

    int max_jugador1, max_jugador2, bandera_max_jugador1 = 0, bandera_max_jugador2 = 0;
    int OpcionElegida, PaloEmbaucadora, PuntosGanador, TotalPuntosJugador1 = 0, TotalPuntosJugador2 = 0, PuntosEstadistica = 0;
    char confirmacion, salir;
    string jugador1, jugador2, Ganador, paloEmbaucadora, GanadorConMejorPuntaje;
    bool jugador1CambioCarta = false, jugador2CambioCarta = false;

    //en base a este vector sabemos que carta seleciconamos
    bool checkList[20] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

    //cartas     
    string cards[20] = {"10 de Trebol", "J de Trebol", "Q de Trebol", "K de Trebol", "A de Trebol", "10 de Pica", "J de Pica", "Q de Pica", "K de Pica", "A de Pica", "10 de Corazon", "J de Corazon", "Q de Corazon", "K de Corazon", "A de Corazon", "10 de Diamante", "J de Diamante", "Q de Diamante", "K de Diamante", "A de Diamante"};

    //valores
    int cardPoints[20] = {10, 11, 12, 15, 20, 10, 11, 12, 15, 20, 10, 11, 12, 15, 20, 10, 11, 12, 15, 20};

    while(true){
        do{
            cout << "+-------------------+" << endl << "|     EMBAUCADO     |" << endl << "+-------------------+" << endl;
            cout << " 1 - JUGAR" << endl;
            cout << " 2 - ESTADISTICAS" << endl;
            cout << " 3 - CREDITOS" << endl << "---------------------" << endl;
            cout << " 0 - SALIR" << endl << "---------------------" << endl;

            cout << endl << "ELIJA UNA OPCIÓN: ";
            cin >> OpcionElegida;
             system ("cls");

        }
        while(OpcionElegida != 1 && OpcionElegida != 2 && OpcionElegida != 3 && OpcionElegida != 0 && OpcionElegida != 1992);

        switch(OpcionElegida)
        {

        case 1:
             system ("cls") ;
            cout << "+-------------------+" << endl << "|     EMBAUCADO     |" << endl << "+-------------------+" << endl;
            cout << "Antes de comenzar, deben registrar sus nombres:" << endl;
            cout <<endl;
            cout << "Nombre del jugador 1? ";
            cin >> jugador1;
            cout << "Nombre del jugador 2? ";
            cin >> jugador2;

            cout << endl << "Confirmar nombres? (S/N) ";
            cin >>   confirmacion;


            while(confirmacion == 'N' || confirmacion == 'n')
            {

                 system ("cls") ;
                cout << "+-------------------+" << endl << "|     EMBAUCADO     |" << endl << "+-------------------+" << endl;
                cout << "Antes de comenzar, deben registrar sus nombres:" << endl;
                cout <<endl;
                cout << "Nombre del jugador 1? ";
                cin >> jugador1;
                cout << "Nombre del jugador 2? ";
                cin >> jugador2;
                cout << endl << "Confirmar nombres? (S/N) ";
                cin >> confirmacion;
            }
             system ("cls") ;

            int PuntosPorRondaJugador1[3], PuntosPorRondaJugador2[3];

            for(int ronda = 0; ronda < 3; ronda++){

              jugador1CambioCarta = false;
              jugador2CambioCarta = false;
              resetearCheckList(checkList);

              cout << "+-------------------+" << endl << "|     EMBAUCADO     |" << endl << "+-------------------+" << endl;
              cout << endl << "RONDA #" << ronda + 1  <<endl;
              cout << jugador1 << " Vs " << jugador2 << endl<<endl;

              int cartas[10], valordecarta[10], PuntosJugador1 = 0, PuntosJugador2 = 0;

              srand(time(0));

              if(ronda == 0){
                paloEmbaucadora = obtenerPalo(obtenerIndiceCarta());
              } else {
                paloEmbaucadora = reasignarPaloEmbaucadora(paloEmbaucadora);
              }

              cout << "+------------------------------+"<< endl;
              cout << "|                              |"<< endl;
              cout << "|  " << jugador1 << " (PUNTOS " << TotalPuntosJugador1 << ")" << string(30 - 3 - jugador1.length() - 9 - to_string(TotalPuntosJugador1).length(), ' ') << "|" << endl;

              for(int i=0;i<5;i++){
                int indiceCarta = repartirCarta(checkList);

                checkList[indiceCarta] = true;
                cartas[i] = indiceCarta;
                valordecarta[i] = cardPoints[indiceCarta];

                int numEspacios = 20 - cards[indiceCarta].length();

                
                cout << "|     "<< cards[indiceCarta] <<string(numEspacios, ' ')<< " |"<<endl;
              }

              cout << "|                              |" << endl;
              cout << "|  " << jugador2 << " (PUNTOS " << TotalPuntosJugador2 << ")" << string(30 - 3 - jugador2.length() - 9 - to_string(TotalPuntosJugador2).length(), ' ') << "|"<< endl;

              for(int i=5;i<10;i++){
                int indiceCarta = repartirCarta(checkList);

                checkList[indiceCarta] = true;
                cartas[i] = indiceCarta;
                valordecarta[i] = cardPoints[indiceCarta];

                


                int numEspacios = 20 - cards[indiceCarta].length();
                
                cout << "|     "<< cards[indiceCarta] <<string(numEspacios, ' ')<< " |"<<endl;


              }
              cout << "|                              |" << endl;
              cout << "|   Embaucadora: " << paloEmbaucadora << string(13 - paloEmbaucadora.length(), ' ') << " |" << endl;
              cout << "|                              |" << endl;
              cout << "+------------------------------+"<<endl;
              cout << endl;


               if(ronda == 1){
                if(TotalPuntosJugador1 >= 20){
                    jugador1CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador1);
                    if(jugador1CambioCarta){
                        paloEmbaucadora = reasignarPaloEmbaucadora(paloEmbaucadora);
                        cout << endl << "La nueva carta embaucadora es: " << paloEmbaucadora << endl << endl ;
                    }

                } else {
                    cout << jugador1 << " no posee los puntos suficientes para cambiar la carta embaucadora" << endl;

                }
                 if(TotalPuntosJugador2 >= 20 && jugador1CambioCarta == false){
                  jugador2CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador2);
                    if(jugador2CambioCarta){
                        paloEmbaucadora = reasignarPaloEmbaucadora(paloEmbaucadora);
                        cout << endl << "La nueva carta embaucadora es: " << paloEmbaucadora << endl << endl;

                    }
                } else if(TotalPuntosJugador2 < 20){
                   cout << jugador2 << " no posee los puntos suficientes para cambiar la carta embaucadora" << endl;
                }

               }

                if (ronda == 2){
                  if(TotalPuntosJugador2 >= 20){
                    jugador2CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador2);
                      if(jugador2CambioCarta){
                        paloEmbaucadora = reasignarPaloEmbaucadora(paloEmbaucadora);
                        cout << endl << "La nueva carta embaucadora es: " << paloEmbaucadora << endl << endl;

                    }
                } else {
                  cout << jugador2 << " no posee los puntos suficientes para cambiar la carta embaucadora" << endl;
                }

                 if(TotalPuntosJugador1 >= 20 && jugador2CambioCarta == false){
                    jugador1CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador1);
                    if(jugador1CambioCarta){
                        paloEmbaucadora = reasignarPaloEmbaucadora(paloEmbaucadora);
                        cout << endl << "La nueva carta embaucadora es: " << paloEmbaucadora << endl << endl;

                    }
                } else if(TotalPuntosJugador1 < 20){
                   cout << jugador1 << " no posee los puntos suficientes para cambiar la carta embaucadora" << endl;
                }
              }

              for(int i=0;i<5;i++){
                if(cartaPuedeSumarPuntos(cartas[i], paloEmbaucadora)){
                  PuntosJugador1 += valordecarta[i];
                }
              }

              for(int i=5;i<10;i++){
                if(cartaPuedeSumarPuntos(cartas[i], paloEmbaucadora)){
                  PuntosJugador2 += valordecarta[i];
                }
              }

             cout << "+------------------+" << endl << "|PUNTAJES OBTENIDOS|" << endl << "+------------------+" << endl;

              if(jugador1CambioCarta){
              PuntosJugador1 -= 20;
             cout << endl << jugador1 << " cambió la carta embaucadora, suma en esta ronda: " << PuntosJugador1 << " Puntos";
              }
              else{
              cout << endl << jugador1 << " suma en esta ronda: " << PuntosJugador1 << " Puntos";
              }
              cout << endl;

              if(jugador2CambioCarta){
              PuntosJugador2 -= 20;
             cout << jugador2 << " cambió la carta embaucadora, suma en esta ronda: " << PuntosJugador2 << " Puntos";
              }
              else{
              cout << jugador2 << " suma en esta ronda: " << PuntosJugador2 << " Puntos";
              }
              cout << endl;


              cout << endl;
              cout << endl;
              PuntosPorRondaJugador1[ronda] = PuntosJugador1;
              PuntosPorRondaJugador2[ronda] = PuntosJugador2;
              TotalPuntosJugador1 += PuntosJugador1;
              TotalPuntosJugador2 += PuntosJugador2;

              system ("pause");
              system ("cls") ;
            }

            cout << "+-------------------+" << endl << "|     EMBAUCADO     |" << endl << "+-------------------+" << endl;
            cout << endl;
            cout << "RONDA     " << jugador1 << "     " << jugador2;
            cout << endl << "+-------------------------+" << endl;
            cout << "| 1        " << PuntosPorRondaJugador1[0] << "          " << PuntosPorRondaJugador2[0] << " |" << endl;
            cout << "| 2        " << PuntosPorRondaJugador1[1] << "          " << PuntosPorRondaJugador2[1] << " |" << endl;
            cout << "| 3        " << PuntosPorRondaJugador1[2] << "          " << PuntosPorRondaJugador2[2] << " |" ;
            cout << endl << "+-------------------------+" << endl;
            cout << "TOTAL     " << TotalPuntosJugador1 << "          " << TotalPuntosJugador2 << endl;
            cout << endl;

            for(int x = 0; x < 3; x++){
                if(bandera_max_jugador1 == 0){
                    max_jugador1 = PuntosPorRondaJugador1[x];
                    bandera_max_jugador1 = 1;
                }else if(PuntosPorRondaJugador1[x] > max_jugador1){
                    max_jugador1 = PuntosPorRondaJugador1[x];
                }
            }
            for(int x = 0; x < 3; x++){
              if(bandera_max_jugador2 == 0){
                    max_jugador2 = PuntosPorRondaJugador2[x];
                    bandera_max_jugador2 = 1;
                }else if(PuntosPorRondaJugador2[x] > max_jugador2){
                    max_jugador2 = PuntosPorRondaJugador2[x];
                }
            }

            if(TotalPuntosJugador1 > TotalPuntosJugador2){
                Ganador = jugador1;
                PuntosGanador = TotalPuntosJugador1;
            } else if(TotalPuntosJugador2 > TotalPuntosJugador1){
              Ganador = jugador2;
              PuntosGanador = TotalPuntosJugador2;
            } else{
               if(max_jugador1 > max_jugador2){
                    Ganador = jugador1;
               }else if(max_jugador2 > max_jugador1){
                    Ganador = jugador2;
               }else{
                    cout << "El juego termina en empate, no hubo ganadores " << endl;
               }
            }

            cout << "GANADOR: " << Ganador << " con " << PuntosGanador << " puntos" << endl;

            if(PuntosEstadistica == 0) {
                PuntosEstadistica = PuntosGanador;
                GanadorConMejorPuntaje = Ganador;
            } else {
                if(PuntosGanador > PuntosEstadistica){
                    PuntosEstadistica = PuntosGanador;
                    GanadorConMejorPuntaje = Ganador;
                }
            }

            cout << endl;
            TotalPuntosJugador1 = 0;
            TotalPuntosJugador2 = 0;
            Ganador = "";
            PuntosGanador = 0;

             system ("pause");
             system ("cls") ;

            break;
        case 2:
             system ("cls") ;
             if (PuntosEstadistica <= 0)  {
                    cout << "+-------------------------------------+" <<endl;
                    cout << "| NO SE REGISTRARON PARTIDAS JUGADAS  |" << endl;
                    cout << "+-------------------------------------+" << endl;
             }
             else  {
             cout << "EL MAYOR GANADOR HASTA EL MOMENTO ES " << GanadorConMejorPuntaje << " CON " << PuntosEstadistica << " PUNTOS" << endl; }

            system ("pause");
            system ("cls") ;
            break;
        case 3:
             system ("cls") ;
            cout << "+--------+" << endl <<"|CREDITOS|" << endl << "+--------+" << endl << endl << "NUÑEZ LUCAS ALEJANDRO" << endl << "Número de legajo: 30498." << endl << endl;
            cout << "FOGLIATTO FEDERICO MARTIN" << endl << "Número de legajo: 30969" << endl << endl;
            cout << "BIANCHI JOAQUIN" << endl << "Número de legajo: 30239 " << endl << endl;
            cout << "MARQUEZ LEONEL" << endl << "Número de legajo: 31037" ;
            cout << endl << endl;
            cout << "Correspondientes al grupo Número 3.";

            cout << endl << endl;
            system ("pause");
             system ("cls") ;
            break;
        case 0:
            system ("cls") ;
            cout << "Desea salir del juego?? (S/N) ";
            cin >> salir;
            if(salir == 's' || salir == 'S')
                return 0;
            else
            {
                 system ("cls") ;
            }
            break;
        case 1992:
             system ("cls") ;
            cout << "Pequeño espacio dedicado para mi hermana, donde sea que estés. " << endl << "Ahora te recordaré por mas tiempo del que te conocí" << endl;
            cout << endl << "Y a mis compañeros, que me bancaron en una situacion muy dificil, gracias a todos." << endl << endl;
             system ("pause");
             system ("cls") ;
            break;
        }
    }
}



bool preguntarJugadorCambiarEmbaucadora(string jugador){
    char respuesta;
    do {
        cout << jugador + ", deseas cambiar la carta embaucadora? (Coste de 20 Pts) ";
        cin >> respuesta;
    } while((respuesta != 's' && respuesta != 'S') && (respuesta != 'n' && respuesta != 'N'));
    if(respuesta == 's' | respuesta == 'S'){
        return true;
    } else {
        return false;
    }
}

string obtenerPalo(int indice){
  string palo;
  //trebol, pica, corazon, diamante
  if(indice >= 0 && indice <= 4){
    palo = "Trebol";
  } else if(indice >= 5 && indice <= 9){
    palo = "Pica";
  } else if(indice >= 10 && indice <= 14){
    palo = "Corazon";
  } else {
    palo = "Diamante";
  } 

  return palo;
}

int obtenerIndiceCarta(){
  return rand() % 20;
}

string reasignarPaloEmbaucadora(string embaucadoraActual){
  string embaucadoraNueva;

  do{
    embaucadoraNueva = obtenerPalo(obtenerIndiceCarta());
  } while(embaucadoraNueva == embaucadoraActual);

  return embaucadoraNueva;
}


bool cartaPuedeSumarPuntos(int indiceCarta, string embaucadora){
  string paloCarta = obtenerPalo(indiceCarta);
  if(paloCarta == embaucadora){
    return false;
  } else {
    return true;
  }
}


void resetearCheckList(bool checkList[20]){
  for(int i = 0; i < 20; i++){
    if(checkList[i]){
      checkList[i] = false;
    }
  }
}


int repartirCarta(bool checkList[20]){
  int indiceCarta;
    do {
          indiceCarta = obtenerIndiceCarta();
        }while(checkList[indiceCarta]);

    return indiceCarta;
}

