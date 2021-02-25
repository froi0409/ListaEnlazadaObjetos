
#include <cstdlib>
#include "Persona.h"
#include <string>
#include <iostream>
typedef Persona* Person;
using namespace std;

Persona* insertar(Persona *lista) {
    Persona *tmp;
    string nom, apell;
    int idP;
    
    cout << "Ingrese el nombre de la persona: ";
    cin >> nom;
    cout << "Ingrese el apellido de la persona: ";
    cin >> apell;
    cout << "Ingrese el ID de la pesona: ";
    cin >> idP;

    if(lista == NULL) {
        lista = new Persona(idP,nom,apell);
        tmp = lista;
    } else {
        tmp = lista;
        while(tmp->siguiente != NULL) {
            tmp=tmp->siguiente;
        }
        tmp->siguiente = new Persona(idP,nom,apell);
        tmp = tmp->siguiente;

    }

    cout << "Persona ingresada con éxito" << endl << endl;

    return lista;

}


void mostrarListado(Persona *lista) {
    Persona *tmp;
    if (lista == NULL) {
        cout << "La lista está vacía" << endl << endl;
    } else {
        cout << endl << endl << "----------LISTADO----------"<< endl << endl;
        tmp = lista;
        while(tmp != NULL) {
            cout << "ID: " << tmp->id << endl;
            cout << "Nombre: " << tmp->nombre << endl;
            cout << "Apellido: " << tmp->apellido << endl << endl;
            tmp = tmp->siguiente;
        }
        cout << "---------------------------"<< endl << endl;
        
    }
}

int main(int argc, char** argv) {
    int op;
    Persona *listaEnlazada = NULL;

    do {

        cout << "¿Qué acción desea ejecutar?" << endl;
        cout << "1.- Insertar Persona" << endl;
        cout << "2.- Mostrar listado" << endl;
        cout << "3.- Salir" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            listaEnlazada=insertar(listaEnlazada);
            listaEnlazada->showInfo();
            break;
        case 2:
            mostrarListado(listaEnlazada);
            break;
        case 3:
            cout << endl << "GRACIAS" << endl;
            break;
        default:
            cout << "ERROR: usted ha ingresado una opción inválida" << endl << endl;
            break;
        }


    }while(op!=3);

    return 0;
}