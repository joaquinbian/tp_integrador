#include <iostream>
#include <locale>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

int FuncionNumAleatorioParaValorONumero();
int FuncionNumAleatorioParaPalo();
int reasignarEmbaucadora(int embaucadoraActual);
bool chequearCartaRepetida(int cartas[10], int valor);
bool preguntarJugadorCambiarEmbaucadora(string nombreJugador);

int main (){
    setlocale(LC_ALL, "spanish");

    int OpcionElegida, PaloEmbaucadora, puntajeJugador1, puntajeJugador2, PuntosGanador, PuntosJugador1 = 0, PuntosJugador2 = 0, PuntosEstadistica = 0;
    char confirmacion, salir;
    string jugador1, jugador2, Ganador, GanadorConMejorPuntaje;
    bool jugador1CambioCarta = false, jugador2CambioCarta = false;
    string PaloDeCarta[4] = {"Trebol", "Pica", "Corazon", "Diamante"};
    string NumeroDeCarta[5] = {"10", "J", "Q", "K", "A"};
    int ValorDeCarta[5] = {10, 11, 12, 15, 20};

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

            int PuntosPorRondaJugador1[3];
            int PuntosPorRondaJugador2[3];
            for(int ronda = 0; ronda < 3; ronda++){

              jugador1CambioCarta = false;
              jugador2CambioCarta = false;

              cout << "+-------------------+" << endl << "|     EMBAUCADO     |" << endl << "+-------------------+" << endl;
              cout << endl << "RONDA #" << ronda + 1  <<endl;
              cout << jugador1 << " Vs " << jugador2 << endl<<endl;

              int cartas[10];
              int valordecarta[10];


              int i,  IndiceCarta, PaloAsignado, totalPuntosA = 0, totalPuntosB = 0;

              srand(time(0));

              if(ronda == 0){
                PaloEmbaucadora = FuncionNumAleatorioParaPalo();
              } else {
                PaloEmbaucadora = reasignarEmbaucadora(PaloEmbaucadora);
              }

              cout << "+------------------------------+"<< endl;
              cout << "|                              |"<< endl;
              cout << "|  " << jugador1 << " (PUNTOS " << PuntosJugador1 << ")" << string(30 - 3 - jugador1.length() - 9 - to_string(PuntosJugador1).length(), ' ') << "|" << endl;

              for(int i=0;i<5;i++){
                IndiceCarta = FuncionNumAleatorioParaValorONumero();
                PaloAsignado = FuncionNumAleatorioParaPalo();
                int cartaNueva = PaloAsignado * 10 + IndiceCarta;
                bool repetida = chequearCartaRepetida(cartas, cartaNueva);

                while(repetida == true){
                  IndiceCarta = FuncionNumAleatorioParaValorONumero();
                  PaloAsignado = FuncionNumAleatorioParaPalo();
                  cartaNueva = PaloAsignado * 10 + IndiceCarta;
                  repetida = chequearCartaRepetida(cartas, cartaNueva);
                }

                cartas[i]= cartaNueva;
                valordecarta[i] = ValorDeCarta[IndiceCarta];

                int numEspacios = 20 - PaloDeCarta[PaloAsignado].length()- NumeroDeCarta[IndiceCarta].length();

                cout << "|     "<< NumeroDeCarta[IndiceCarta] << " de " << PaloDeCarta[PaloAsignado] <<string(numEspacios, ' ')<< " |"<<endl;

              }

              cout << "|                              |" << endl;
              cout << "|  " << jugador2 << " (PUNTOS " << PuntosJugador2 << ")" << string(30 - 3 - jugador2.length() - 9 - to_string(PuntosJugador2).length(), ' ') << "|"<< endl;


              for(int i=5;i<10;i++){
                IndiceCarta = FuncionNumAleatorioParaValorONumero();
                PaloAsignado = FuncionNumAleatorioParaPalo();
                int cartaNueva = PaloAsignado * 10 + IndiceCarta;
                bool repetida = chequearCartaRepetida(cartas, cartaNueva);

                while(repetida == true){
                  IndiceCarta = FuncionNumAleatorioParaValorONumero();
                  PaloAsignado = FuncionNumAleatorioParaPalo();
                  cartaNueva = PaloAsignado * 10 + IndiceCarta;
                  repetida = chequearCartaRepetida(cartas, cartaNueva);
                }

                cartas[i] = cartaNueva;
                valordecarta[i] = ValorDeCarta[IndiceCarta];

                int numEspacios = 20 - PaloDeCarta[PaloAsignado].length()- NumeroDeCarta[IndiceCarta].length();

                cout << "|     "<< NumeroDeCarta[IndiceCarta] << " de " << PaloDeCarta[PaloAsignado] <<string(numEspacios, ' ')<< " |"<<endl;


              }
              cout << "|                              |" << endl;
             cout << "|   Embaucadora: " << PaloDeCarta[PaloEmbaucadora]<< string(13 - PaloDeCarta[PaloEmbaucadora].length(), ' ') << " |" << endl;
              cout << "|                              |" << endl;
              cout << "+------------------------------+"<<endl;
              cout << endl;

              //cambiamos la carta embaucadora
               if(ronda == 1){
                if(PuntosJugador1 >= 20){
                    jugador1CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador1);
                    if(jugador1CambioCarta){
                        PaloEmbaucadora = reasignarEmbaucadora(PaloEmbaucadora);
                        cout << endl << "La nueva carta embaucadora es: " << PaloDeCarta[PaloEmbaucadora] << endl << endl ;
                    }

                } else {
                    cout << jugador1 << " no posee los puntos suficientes para cambiar la carta embaucadora" << endl;

                }
                 if(PuntosJugador2 >= 20 && jugador1CambioCarta == false){
                  jugador2CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador2);
                    if(jugador2CambioCarta){
                        PaloEmbaucadora = reasignarEmbaucadora(PaloEmbaucadora);
                        cout << endl << "La nueva carta embaucadora es: " << PaloDeCarta[PaloEmbaucadora] << endl << endl;

                    }
                } else if(PuntosJugador2 < 20){
                   cout << jugador2 << " no posee los puntos suficientes para cambiar la carta embaucadora" << endl;
                }

               }

                if (ronda == 2){
                  if(PuntosJugador2 >= 20){
                    jugador2CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador2);
                      if(jugador2CambioCarta){
                        PaloEmbaucadora = reasignarEmbaucadora(PaloEmbaucadora);
                        cout << endl << "La nueva carta embaucadora es: " << PaloDeCarta[PaloEmbaucadora] << endl << endl;

                    }
                } else {
                  cout << jugador2 << " no posee los puntos suficientes para cambiar la carta embaucadora" << endl;
                }

                 if(PuntosJugador1 >= 20 && jugador2CambioCarta == false){
                    jugador1CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador1);
                    if(jugador1CambioCarta){
                        PaloEmbaucadora = reasignarEmbaucadora(PaloEmbaucadora);
                        cout << endl << "La nueva carta embaucadora es: " << PaloDeCarta[PaloEmbaucadora] << endl << endl;

                    }
                } else if(PuntosJugador1 < 20){
                   cout << jugador1 << " no posee los puntos suficientes para cambiar la carta embaucadora" << endl;
                }
              }


              //se calcula el puntaje de jugador1 en la ronda
              for(int i=0;i<5;i++){
                if(cartas[i]/10 != PaloEmbaucadora){
                  totalPuntosA += valordecarta[i];
                }
              }

              //se calcula el puntaje de jugador2 en la ronda
              for(int i=5;i<10;i++){
                if(cartas[i]/10 != PaloEmbaucadora){
                  totalPuntosB += valordecarta[i];
                }
              }

             cout << "+------------------+" << endl << "|PUNTAJES OBTENIDOS|" << endl << "+------------------+" << endl;

              if(jugador1CambioCarta){
              totalPuntosA -= 20;
             cout << jugador1 << " cambió la carta embaucadora, suma en esta ronda: " << totalPuntosA << " Puntos";
              }
              else{
              cout << jugador1 << " suma en esta ronda: " << totalPuntosA << " Puntos";
              }
              cout << endl;

              if(jugador2CambioCarta){
              totalPuntosB -= 20;
             cout << jugador2 << " cambió la carta embaucadora, suma en esta ronda: " << totalPuntosB << " Puntos";
              }
              else{
              cout << jugador2 << " suma en esta ronda: " << totalPuntosB << " Puntos";
              }
              cout << endl;


              cout << endl;
              cout << endl;
              PuntosPorRondaJugador1[ronda] = totalPuntosA;
              PuntosPorRondaJugador2[ronda] = totalPuntosB;
              PuntosJugador1 += totalPuntosA;
              PuntosJugador2 += totalPuntosB;

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
            cout << "TOTAL     " << PuntosJugador1 << "          " << PuntosJugador2 << endl;
            cout << endl;

            if(PuntosJugador1>PuntosJugador2){
                Ganador = jugador1;
                PuntosGanador = PuntosJugador1;
            } else {
              Ganador = jugador2;
              PuntosGanador = PuntosJugador2;
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
            PuntosJugador1 = 0;
            PuntosJugador2 = 0;
            Ganador = "";
            PuntosGanador = 0;

             system ("pause");
             system ("cls") ;

            break;
        case 2:
             system ("cls") ;
             if (PuntosEstadistica <= 0)  {
                    cout << "NO SE REGISTRARON PARTIDAS JUGADAS." << endl << endl;  }
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

int FuncionNumAleatorioParaValorONumero(){
  return rand() % 5;
}
int FuncionNumAleatorioParaPalo(){
  return rand() % 4;
}

bool chequearCartaRepetida(int cartas[10], int valor){
  bool repetida = false;
  for (int i = 0; i < 10; i++){
    if(cartas[i] == valor){
      repetida = true;
      break;
    }
  }
  return repetida;
}

int reasignarEmbaucadora(int embaucadoraActual){
  int emba = embaucadoraActual;
  do {
    emba = rand() % 4;
  } while(emba == embaucadoraActual);
  return emba;
};

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
