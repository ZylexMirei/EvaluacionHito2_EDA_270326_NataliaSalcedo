#include <iostream>
#include <cstring>
using namespace std;

// Nodo de la lista (cada estudiante)
struct Nodo {
    char nombre[50];
    char codigo[20];
    Nodo* sig;
    Nodo* ant;
};

// Cola (tipo FIFO)
struct Cola {
    Nodo* inicio;
    Nodo* fin;
    int cantidad;

    Cola() {
        inicio = nullptr;
        fin = nullptr;
        cantidad = 0;
    }
};

// Crear nodo nuevo
Nodo* nuevoNodo(const char* nombre, const char* codigo) {
    Nodo* n = new Nodo();

    strcpy(n->nombre, nombre);
    strcpy(n->codigo, codigo);

    n->sig = nullptr;
    n->ant = nullptr;

    return n;
}

// Registrar estudiante (entra al final)
void registrar(Cola& c, const char* nombre, const char* codigo) {
    Nodo* n = nuevoNodo(nombre, codigo);

    if (c.inicio == nullptr) {
        c.inicio = n;
        c.fin = n;
    } else {
        c.fin->sig = n;
        n->ant = c.fin;
        c.fin = n;
    }

    c.cantidad++;

    cout << "\nSe registro a " << nombre 
         << " (turno #" << c.cantidad << ")\n";
}

// Atender estudiante (sale el primero)
void atender(Cola& c) {
    if (c.inicio == nullptr) {
        cout << "\nNo hay nadie en la cola\n";
        return;
    }

    Nodo* temp = c.inicio;

    cout << "\nAtendiendo...\n";
    cout << "Nombre: " << temp->nombre << endl;
    cout << "Codigo: " << temp->codigo << endl;

    c.inicio = temp->sig;

    if (c.inicio != nullptr) {
        c.inicio->ant = nullptr;
    } else {
        c.fin = nullptr;
    }

    delete temp;
    c.cantidad--;
}

// Mostrar lista normal
void mostrar(Cola c) {
    if (c.inicio == nullptr) {
        cout << "\nLa cola esta vacia\n";
        return;
    }

    Nodo* aux = c.inicio;
    int i = 1;

    cout << "\nLista de estudiantes:\n";

    while (aux != nullptr) {
        cout << i << ") " << aux->nombre 
             << " - " << aux->codigo << endl;
        aux = aux->sig;
        i++;
    }
}

// Buscar estudiante
void buscar(Cola c, const char* nombre) {
    Nodo* aux = c.inicio;
    int pos = 1;

    while (aux != nullptr) {
        if (strcmp(aux->nombre, nombre) == 0) {
            cout << "\nEncontrado!\n";
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Codigo: " << aux->codigo << endl;
            cout << "Turno: " << pos << endl;
            return;
        }
        aux = aux->sig;
        pos++;
    }

    cout << "\nNo se encontro ese estudiante\n";
}

// Mostrar al reves (extra)
void mostrarReves(Cola c) {
    if (c.fin == nullptr) {
        cout << "\nNo hay datos\n";
        return;
    }

    Nodo* aux = c.fin;
    int i = c.cantidad;

    cout << "\nLista en reversa:\n";

    while (aux != nullptr) {
        cout << i << ") " << aux->nombre 
             << " - " << aux->codigo << endl;
        aux = aux->ant;
        i--;
    }
}

// Liberar memoria
void limpiar(Cola& c) {
    Nodo* aux = c.inicio;

    while (aux != nullptr) {
        Nodo* siguiente = aux->sig;
        delete aux;
        aux = siguiente;
    }

    c.inicio = nullptr;
    c.fin = nullptr;
    c.cantidad = 0;
}

// MAIN
int main() {
    Cola cola;
    int op;

    cout << "Sistema de turnos (simple)\n";

    do {
        cout << "\n    EVALUACION PROCESUAL";
        cout << "\n||======================||";
        cout << "\n||       MENU           ||"; 
        cout << "\n||1. Registrar          ||\n";
        cout << "||2. Atender            ||\n";
        cout << "||3. Mostrar            ||\n";
        cout << "||4. Buscar             ||\n";
        cout << "||5. Mostrar reverso    ||\n";
        cout << "||6. Salir              ||\n";
        cout << "||======================||\n";
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        switch (op) {
            case 1: {
                char nom[50], cod[20];
                cout << "Nombre: ";
                cin.getline(nom, 50);
                cout << "Codigo: ";
                cin.getline(cod, 20);

                registrar(cola, nom, cod);
                break;
            }
            case 2:
                atender(cola);
                break;
            case 3:
                mostrar(cola);
                break;
            case 4: {
                char nom[50];
                cout << "Nombre a buscar: ";
                cin.getline(nom, 50);
                buscar(cola, nom);
                break;
            }
            case 5:
                mostrarReves(cola);
                break;
            case 6:
                cout << "\nFin del programa\n";
                break;
            default:
                cout << "Opcion incorrecta\n";
        }

    } while (op != 6);

    limpiar(cola);
    return 0;
}