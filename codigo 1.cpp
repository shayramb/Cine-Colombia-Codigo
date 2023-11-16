#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

//----- estructuras

struct Usuario {
  string nombre;
  string cedula;
  string tarjeta = "";
  string reservas[8];
  int valor = 0;
};

//----- Variables publicas

string limpiar = "\033[0;0H\033[2J";

string LETRAS[11] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};
int GENERAL = 8000;
int PREFERENCIAL = 11000;

Usuario lista_usuarios[15];
int cont_usuarios = 0;
int cont_reservas = 0;

int sillas_disponibles[11][20];
string sillas[11][20];

//----- Funciones

string intToString(int x) {
  string numeroComoCadena = "";
  stringstream a;
  a << x;
  a >> numeroComoCadena;
  return numeroComoCadena;
}

void init_sillas() {
  // Inicializa
  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < 20; j++) {
      sillas_disponibles[i][j] = 0;
    }
  }

  // inicializa las sillas graficamente
  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < 20; j++) {
      sillas[i][j] = intToString(j + 1);
    }
  }
}

void print_sillas() {

  cout << "\t\t\t\t___________\n\n"
          "\t|\t\t\t\tPANTALLA\t\t\t\t|\n"
          "\t\t\t\t___________\n\n\n";

  for (int i = 0; i < 11; i++) {
    if (i == 8) {
      cout << "\n";
    }
    cout << LETRAS[i] + " | ";
    for (int j = 0; j < 20; j++) {
      if (sillas_disponibles[i][j] != 0) {
        if (sillas[i][j].length() == 1) {
          cout << "x | ";
        } else {
          cout << "x  | ";
        }
      } else {
        cout << sillas[i][j] + " | ";
      }
    }
    cout << endl;
  }
}

int pos_fila(string letra) {
  int pos = 0;
  for (int i = 0; i < 11; i++) {
    if (LETRAS[i] == letra) {
      pos = i;
    }
  }
  cout << pos;
  return pos;
}

Usuario reservar(string asiento, Usuario cliente) {
  int fila = pos_fila(asiento.substr(0, 1));
  int columna = stoi(asiento.substr(1, asiento.length()));

  sillas_disponibles[fila][columna - 1] = 1;
  cliente.reservas[cont_reservas] = asiento;
  cont_reservas++;

  if (fila < 8) {
    cliente.valor += GENERAL;
  } else {
    cliente.valor += PREFERENCIAL;
  }

  cout << "Reserva exitosa.\n";

  return cliente;
}

Usuario reservar_sillas(Usuario cliente) {
  cout << "\n";
  string asiento;
  print_sillas();

  cout << "\n\nAsiento preferencial (I - K) valor: $" +
              intToString(PREFERENCIAL);
  cout << "\nAsiento general (A - H) valor: $" + intToString(GENERAL);

  cout << "\n\nIngrese el asiento que desea reservar (formato E11): ";
  cin >> asiento;
  cliente = reservar(asiento, cliente);

  string o;
  cout << "\n\nDesea registrar otro asiento? : ";
  cin >> o;

  while (o != "n") {
    cout << "\n\nIngrese el asiento que desea reservar (formato E11): ";
    cin >> asiento;
    cliente = reservar(asiento, cliente);
    cout << "\n\nDesea registrar otro asiento? : ";
    cin >> o;
  }

  cout << "asientos reservados: ";
  for (int i = 0; i < cont_reservas; i++) {
    cout << cliente.reservas[i] << " ";
  }

  cout << "\nvalor a pagar: " << cliente.valor;
  cout << "\npagar? s/n: ";

  cont_reservas = 0;
  string x;
  cin >> x;

  return cliente;
}

int main() {
  // Inicializa las sillas
  init_sillas();
  int op; // opción
  do {
    cout << limpiar;
    cout << "\t > CINE COLOMBIA <\n\n"
            "Bienvenido a nuestro cine, selecciona una opción a continución: ";
    cout << "\n"
            "1. Crear Usuario: \n"
            "2. Iniciar sesión: \n"
            "3. Mostrar reservas: \n"
            "4. Salir: \n";

    cin >> op;

    switch (op) {
    case 1: {
      cout << limpiar;
      cout << "\t > Crear usuario <\n"
              "Ingrese su nombre de usuario : ";

      cin >> lista_usuarios[cont_usuarios].nombre;
      cout << "Ingresa su número de cédula : ";
      cin >> lista_usuarios[cont_usuarios].cedula;
      string tj;
      cout << "¿Tiene tarjeta cineco? s/n: ";
      cin >> tj;
      if (tj == "s") {
        cout << "Ingresa su número de tarjeta cineco: ";
        cin >> lista_usuarios[cont_usuarios].tarjeta;
      }

      cout << "\n Usuario " + lista_usuarios[cont_usuarios].nombre +
                  " creado exitosamente...";
      cont_usuarios++;
      cin >> tj;

    } break;

    case 2: {
      string aux;
      cout << limpiar;
      cout << "\t > Iniciar sesión <\n"
              "Ingrese su cedula : ";
      cin >> aux;

      for (int i = 0; i <= cont_usuarios; i++) {
        if (aux == lista_usuarios[i].cedula) {

          cout << limpiar;
          cout << "Bienvenido(a) " + lista_usuarios[i].nombre +
                      ", a continuación se muestran las sillas disponibles";

          // Pasa el cliente que inicio secion a la función de reservar sillas
          lista_usuarios[i] = reservar_sillas(lista_usuarios[i]);

          aux = "";
          break;
        }
        if ((i == cont_usuarios) && (aux != "")) {
          cout << "Usuario no encontrado...";
          cin >> aux;
        }
      }

    } break;
    case 3:

      break;
    case 4: {

    } break;
    default: {
      cout << "Intenta nuevamente,";
    }
    };

  } while (op != 5);
  cout << " Gracias por usar mi app";
}