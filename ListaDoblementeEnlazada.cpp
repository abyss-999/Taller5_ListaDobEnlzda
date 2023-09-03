#include <iostream>
#include <conio.h>
using namespace std;

struct Elmto {
    int num;
    Elmto* siguiente;
    Elmto* anterior;
};

Elmto* primero = nullptr;
Elmto* ultimo = nullptr;

typedef struct Elmto* Tlista;
///////////////////////////////////////////////////////////
void insertar_dato(int dato) {
    Elmto* nuevo = new Elmto;
    nuevo->num = dato;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;

    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
    }
}
///////////////////////////////////////////////////////////
void BuscarElemento(Elmto* lista, int valor) {
    Tlista q = lista;
    int i = 0, band = 0;

    while (q != nullptr) {
        if (q->num == valor) {
            cout << endl << "Encontrado en la posicion: " << i << endl;
            band = 1;
        }
        q = q->siguiente;
        i++;
    }

    if (band == 0)
        cout << "\n\nNumero no encontrado" << endl;
}
///////////////////////////////////////////////////////////
void EliminarDato(Elmto*& lista, int valor) {
    Elmto* actual = lista;

    while (actual != nullptr) {
        if (actual->num == valor) {
            if (actual->anterior != nullptr) {
                actual->anterior->siguiente = actual->siguiente;
            } else {
                primero = actual->siguiente;
            }

            if (actual->siguiente != nullptr) {
                actual->siguiente->anterior = actual->anterior;
            } else {
                ultimo = actual->anterior;
            }

            delete actual;
            return;
        }
        actual = actual->siguiente;
    }

    cout << "\n\nNumero no encontrado" << endl;
}
///////////////////////////////////////////////////////////
int ActualizarLista(int valor, int valor_actualizar) {
    Tlista temp = primero;
    int encontrado = 0;

    while (temp != nullptr) {
        if (temp->num == valor) {
            temp->num = valor_actualizar;
            encontrado = 1;
        }
        temp = temp->siguiente;
    }

    return encontrado;
}
///////////////////////////////////////////////////////////
void mostrar_lista() {
    int i = 0;
    Elmto* temp = primero;

    while (temp != nullptr) {
        cout << "elemento " << i << ": " << temp->num << endl << endl;
        temp = temp->siguiente;
        i++;
    }
}
///////////////////////////////////////////////////////////
int main() {
    int dato, valor_actualizar;
    char respuesta;

    do {
        cout << endl << "***************";
        cout << endl << "Ingrese un dato: ";
        cin >> dato;
        insertar_dato(dato);
        cout << endl << "Seguir ingresando datos? (s/n)"<<endl;
        respuesta = getch();
    } while (respuesta == 's');

    mostrar_lista();

    do {
        cout << endl << "***************";
        cout << endl << "Deseas buscar elementos? (s/n): ";
        respuesta = getch();
        if (respuesta == 's' || respuesta == 'S') {
            cout << "\nDigite el numero que quieres buscar: ";
            cin >> dato;
            BuscarElemento(primero, dato);
        }
    } while (respuesta == 's');

    do {
        cout << endl << "***************";
        cout << endl << "Desea actualizar elementos? (s/n)";
        respuesta = getch();
        if (respuesta == 's') {
            cout << "\nDigite el numero que quieres actualizar: ";
            cin >> dato;
            cout << "\nValor a modificar: ";
            cin >> valor_actualizar;
            if (ActualizarLista(dato, valor_actualizar) == 1) {
                cout << "El valor se actualizo" << endl;
                mostrar_lista();
            } else {
                cout << "El valor no se encontro en la lista" << endl;
            }
        }
    } while (respuesta == 's');

    do {
        cout << endl << "***************";
        cout << endl << "Desea eliminar elementos? (s/n)";
        respuesta = getch();
        if (respuesta == 's') {
            cout << "\nDigite el numero que quieres eliminar: "<<endl;
            cin >> dato;
            EliminarDato(primero, dato);
            mostrar_lista();
        }
    } while (respuesta == 's');
    return 0;
}