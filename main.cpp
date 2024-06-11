#include <iostream>
#include <locale>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

int repartirCarta();
int asignarPalo();
int asignarEmbaucadora();
string Ganador;
int PuntosGanador;
int PuntosA = 0, PuntosB = 0;

int main (){
    setlocale(LC_ALL, "spanish");

    int opcion;
    char confirmacion, salir;
    string jugador1, jugador2;
    int puntajeJugador1, puntajeJugador2, ronda1Jugador1, ronda2Jugador1, ronda3Jugador1, ronda1Jugador2, ronda2Jugador2, ronda3Jugador2;

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
            for(int x = 0; x < 3; x ++){

                cout << "EMBAUCADO" << endl << "----------------------------------------" << endl;
                cout << "RONDA #" << x + 1  <<endl;
                cout << jugador1 << " Vs " << jugador2 << endl<<endl;

                char * num[5] = {"10", "J", "Q", "K", "A"};
                char * palo[4] = {"Trebol", "Pica", "Corazon", "Diamante"};
                int valores[5] = {10, 11, 12, 15, 20};
                int i, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0, C6 = 0, C7 = 0, C8 = 0, C9 = 0, C10 = 0;

                srand(time(0)); //semilla o seed
                int z = asignarEmbaucadora();
                cout << "+------------------------------+"<< endl;
                cout << "|                              |"<< endl;
                cout << "|  " << jugador1 << " (PUNTOS " << PuntosA << " )" << endl;
                for(i=0;i<5;i++){
                  int x = repartirCarta();
                  int y = asignarPalo();

                  if(C1 == 0 && y!=z){
                    C1 = valores[x];
                  }else if(C2 == 0 && y!=z){
                    C2 = valores[x];
                  }else if (C3 == 0 && y!=z){
                    C3 = valores[x];
                  }else if(C4 == 0 && y!=z){
                    C4 = valores[x];
                  }else if(C5 == 0 && y!=z){
                    C5 = valores[x];
                  }
                  cout << "|     " << num[x] << " de " << palo[y] << endl;
                }
                cout << "|                              |" << endl;
                cout << "|  " << jugador2 << " (PUNTOS " << PuntosB << " )" << endl;
                for(i=0;i<5;i++){
                  int x = repartirCarta();
                  int y = asignarPalo();
                  if(C6 == 0 && y!=z){
                    C6 = valores[x];
                  }else if(C7 == 0 && y!=z){
                    C7 = valores[x];
                  }else if (C8 == 0 && y!=z){
                    C8 = valores[x];
                  }else if(C9 == 0 && y!=z){
                    C9 = valores[x];
                  }else if(C10 == 0 && y!=z){
                    C10 = valores[x];
                  }
                  cout << "|     " << num[x] << " de " << palo[y] << endl;
                }
                    cout << "|                              |" << endl;
                    cout << "|   Embaucadora: " << palo[z] << endl;
                    cout << "|                              |" << endl;
                    cout << "+------------------------------+"<<endl;
                    cout << endl;

                    cout << "Puntajes Obtenidos:" << endl;
                    cout << "----------------------------------------" << endl;
                    int totalPuntosA = C1 + C2 + C3 + C4 + C5;
                    cout << jugador1 << " = " << totalPuntosA << " Puntos";
                    cout << endl;
                    int totalPuntosB = C6 + C7 + C8 + C9 + C10;
                    cout << jugador2 << " = " << totalPuntosB << " Puntos";
                    cout << endl;
                    cout << endl;
                    puntosronda[x] = totalPuntosA;
                    puntosrondab[x] = totalPuntosB;
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
              string Ganador = jugador1;
              int PuntosGanador = PuntosA;
            } else {
              Ganador = jugador2;
              PuntosGanador = PuntosB;
            }
            cout << "GANADOR: " << Ganador << " con " << PuntosGanador << " puntos de victoria." << endl;
            cout << endl;
            PuntosA = 0;
            PuntosB = 0;

            system ("pause");
            system ("cls") ;

            break;
        case 2:
            system ("cls") ;
            cout <<"SE ELIJIÓ ESTADISTICAS" << endl ;
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
  int mano;
  mano = rand() % 5;
  return mano;
}
int asignarPalo(){
  int pal;
  pal = rand() % 4;
  return pal;
}
int asignarEmbaucadora(){
  int emba;
  emba = rand() % 4;
  return emba;
}