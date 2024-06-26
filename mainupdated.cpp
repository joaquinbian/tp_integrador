#include <iostream>
#include <locale>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

int repartirCarta();
int asignarPalo();
int reasignarEmbaucadora(int embaucadoraActual);

bool chequearCartaRepetida(int cartas[10], int valor);
bool preguntarJugadorCambiarEmbaucadora(string nombreJugador);

int main (){
    setlocale(LC_ALL, "spanish");

    int opcion, z;
    char confirmacion, salir;
    string jugador1, jugador2, Ganador, GanadorEstadistica;
    int puntajeJugador1, puntajeJugador2, ronda1Jugador1, ronda2Jugador1, ronda3Jugador1, ronda1Jugador2, ronda2Jugador2, ronda3Jugador2, PuntosGanador, PuntosA = 0, PuntosB = 0, PuntosEstadistica = 0;

    bool jugador1CambioCarta = false, jugador2CambioCarta = false;



    //lo dejamos afuera de todo ya que son valores 'constantes', sino se recrean en cada vuelta del loop
    string palo[4] = {"Trebol", "Pica", "Corazon", "Diamante"};

    string num[5] = {"10", "J", "Q", "K", "A"};
    int valores[5] = {10, 11, 12, 15, 20};




    while(true){

        do{
            cout << "EMBAUCADO" << endl << "---------------------" << endl;
            cout << " 1 - JUGAR" << endl;
            cout << " 2 - ESTADISTICAS" << endl;
            cout << " 3 - CREDITOS" << endl << "---------------------" << endl;
            cout << " 0 - SALIR" << endl << "---------------------" << endl;

            cout << "ELIJA UNA OPCIÓN: ";
            cin >> opcion;
             system ("cls");

        }
        while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 0 && opcion != 1992);

        switch(opcion)
        {

        case 1:
             system ("cls") ;
            cout << "EMBAUCADO" << endl << "------------------------------------------------------------------------" << endl;
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
                cout << "EMBAUCADO" << endl << "------------------" << endl;
                cout << "ANTES DE COMENZAR, DEBEN REGISTRAR SUS NOMBRES:" << endl;
                cout <<endl;
                cout << "NOMBRE DEL JUGADOR 1? ";
                cin >> jugador1;
                cout << "NOMBRE DEL JUGADOR 2? ";
                cin >> jugador2;
                cout << endl << "Confirmar nombres? (S/N) ";
                cin >> confirmacion;
            }
             system ("cls") ;

            int puntosronda[3];
            int puntosrondab[3];
            for(int ronda = 0; ronda < 3; ronda++){
              
              jugador1CambioCarta = false;
              jugador2CambioCarta = false;

              cout << "EMBAUCADO" << endl << "----------------------------------------" << endl;
              cout << "RONDA #" << ronda + 1  <<endl;
              cout << jugador1 << " Vs " << jugador2 << endl<<endl;

              int cartas[10];
              int valordecarta[10];


              int i, x, y, totalPuntosA = 0, totalPuntosB = 0;

              srand(time(0)); //semilla o seed

              if(ronda == 0){
                z = asignarPalo(); //asignamos el palo embaucador
              } else {
                z = reasignarEmbaucadora(z); // lo re-asignamos
              }
              

              

              cout << "+------------------------------+"<< endl;
              cout << "|                              |"<< endl;
              cout << "|  " << jugador1 << " (PUNTOS " << PuntosA << " )" << endl;

              //5 cartas del jugador 1
              for(int i=0;i<5;i++){
                x = repartirCarta();
                y = asignarPalo();
                int cartaNueva = y * 10 + x; 
                bool repetida = chequearCartaRepetida(cartas, cartaNueva);

                while(repetida == true){
                  x = repartirCarta();
                  y = asignarPalo();
                  cartaNueva = y * 10 + x;
                  repetida = chequearCartaRepetida(cartas, cartaNueva);
                }

                cartas[i]= cartaNueva;
                valordecarta[i] = valores[x];

                cout << "|     " << num[x] << " de " << palo[y] << endl;
              }

              cout << "|                              |" << endl;
              cout << "|  " << jugador2 << " (PUNTOS " << PuntosB << " )" << endl;

              //5 cartas del jugador 2
              for(int i=5;i<10;i++){
                x = repartirCarta();
                y = asignarPalo();
                int cartaNueva = y * 10 + x;
                bool repetida = chequearCartaRepetida(cartas, cartaNueva);

                while(repetida == true){
                  x = repartirCarta();
                  y = asignarPalo();
                  cartaNueva = y * 10 + x;
                  repetida = chequearCartaRepetida(cartas, cartaNueva);
                }

                cartas[i] = cartaNueva;
                valordecarta[i] = valores[x];

                cout << "|     " << num[x] << " de " << palo[y] << endl;

              }
              cout << "|                              |" << endl;
              cout << "|   Embaucadora: " << palo[z] << endl;
              cout << "|                              |" << endl;
              cout << "+------------------------------+"<<endl;
              cout << endl;

              //cambiamos la carta embaucadora
               if(ronda == 1){
                if(PuntosA >= 20){
                    jugador1CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador1);
                    if(jugador1CambioCarta){
                        z = reasignarEmbaucadora(z);
                        cout << "la nueva carta embaucadora es: " << palo[z] << endl ;
                    }

                } else {
                    cout << jugador1 << "No posee los puntos suficientes para cambiar la carta embaucadora" << endl;
                  
                } 
                 if(PuntosB >= 20 && jugador1CambioCarta == false){
                  jugador2CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador2);
                    if(jugador2CambioCarta){
                        z = reasignarEmbaucadora(z);
                        cout << "la nueva carta embaucadora es: " << palo[z] << endl << endl;

                    }
                } else if(PuntosB < 20){
                   cout << jugador2 << "No posee los puntos suficientes para cambiar la carta embaucadora" << endl;
                }
                
               } 
               
                if (ronda == 2){
                  if(PuntosB >= 20){
                    jugador2CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador2);
                      if(jugador2CambioCarta){
                        z = reasignarEmbaucadora(z);
                        cout << "la nueva carta embaucadora es: " << palo[z] << endl << endl;

                    }
                } else {
                  cout << jugador2 << "No posee los puntos suficientes para cambiar la carta embaucadora" << endl;
                } 
                
                 if(PuntosA >= 20 && jugador2CambioCarta == false){
                    jugador1CambioCarta = preguntarJugadorCambiarEmbaucadora(jugador1);
                    if(jugador1CambioCarta){
                        z = reasignarEmbaucadora(z);
                        cout << "la nueva carta embaucadora es: " << palo[z] << endl << endl;

                    }
                } else if(PuntosA < 20){
                   cout << jugador1 << "No posee los puntos suficientes para cambiar la carta embaucadora" << endl;
                }
              }

              
              //se calcula el puntaje de jugador1 en la ronda
              for(int i=0;i<5;i++){
                if(cartas[i]/10 != z){
                  totalPuntosA += valordecarta[i];
                }
              }

              //se calcula el puntaje de jugador2 en la ronda
              for(int i=5;i<10;i++){
                if(cartas[i]/10 != z){
                  totalPuntosB += valordecarta[i];
                }
              }

              cout << "Puntajes Obtenidos:" << endl;
              cout << "----------------------------------------" << endl;

              cout << jugador1 << " = " << totalPuntosA << " Puntos";
              if(jugador1CambioCarta){
                cout << " (-20)";
                totalPuntosA -= 20;
              }
              cout << endl;

              cout << jugador2 << " = " << totalPuntosB << " Puntos";
               if(jugador2CambioCarta){
                cout << " (-20)";
                totalPuntosB -= 20;
              }
              cout << endl;
              cout << endl;
              puntosronda[ronda] = totalPuntosA;
              puntosrondab[ronda] = totalPuntosB;
              PuntosA += totalPuntosA;
              PuntosB += totalPuntosB;

              system ("pause");
              system ("cls") ;
            }

            cout << "EMBAUCADO" << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            cout << "RONDA     " << jugador1 << "     " << jugador2;
            cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "  1        " << puntosronda[0] << "      " << puntosrondab[0] << endl;
            cout << "  2        " << puntosronda[1] << "      " << puntosrondab[1] << endl;
            cout << "  3        " << puntosronda[2] << "      " << puntosrondab[2];
            cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "TOTAL     " << PuntosA << "     " << PuntosB << endl;
            cout << endl;

            if(PuntosA>PuntosB){
                Ganador = jugador1;
                PuntosGanador = PuntosA;
            } else {
              Ganador = jugador2;
              PuntosGanador = PuntosB;
            }
            cout << "GANADOR: " << Ganador << " con " << PuntosGanador << " puntos de victoria." << endl;

            if(PuntosEstadistica == 0) {
                PuntosEstadistica = PuntosGanador;
                GanadorEstadistica = Ganador;
            } else {
                if(PuntosGanador > PuntosEstadistica){
                    PuntosEstadistica = PuntosGanador;
                    GanadorEstadistica = Ganador;
                }
            }


            cout << endl;
            PuntosA = 0;
            PuntosB = 0;
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
             cout << "EL MAYOR GANADOR ES " << GanadorEstadistica << " CON " << PuntosEstadistica << " PUNTOS." << endl; }

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

int repartirCarta(){
  return rand() % 5;
}
int asignarPalo(){
  return rand() % 4;
}

//para la embaucadora podriamos usar la misma funcion que para asignar el palo
//al final ambas retornan un numero random del 0 al 3.
/* int asignarEmbaucadora(){
  return rand() % 4;
} */

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
        cout << jugador + " deseas cambiar la carta embaucadora ? ";
        cin >> respuesta;
    } while((respuesta != 's' && respuesta != 'S') && (respuesta != 'n' && respuesta != 'N'));

    if(respuesta == 's' | respuesta == 'S'){
        return true;
    } else {
        return false;
    }

};