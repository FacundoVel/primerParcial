#include "funciones.h"

NodoPaciente *CrearListaVacia();
NodoPaciente *CrearNodo(Paciente p);
void InsertarAlFinal(NodoPaciente **inicio, Paciente p);
void GenerarArchivoCentral(NodoPaciente **archivo, Paciente *cardio, Paciente *pedia, Paciente *trauma, int cant, int idInicial);
void MostrarListaPacientes(NodoPaciente *inicio, const char *titulo);


int main()
{
    Paciente *cardio = PacientesCardio();
    Paciente *pediatria = PacientesPediatria();
    Paciente *traumato = PacientesTraumato();

    NodoPaciente *ArchivoCentral = CrearListaVacia();
    GenerarArchivoCentral(&ArchivoCentral, cardio, pediatria, traumato, 30, 2201);

    MostrarListaPacientes(ArchivoCentral, "LISTA UNIFICADA DE PACIENTES: ");

    return 0;
}

NodoPaciente *CrearListaVacia()
{
    return NULL;
}

NodoPaciente *CrearNodo(Paciente p)
{
    NodoPaciente *nuevo = (NodoPaciente *)malloc(sizeof(NodoPaciente));
    if(nuevo != NULL)
    {
        nuevo->datos = p;
        nuevo->siguiente = NULL;
    }
    return nuevo;
}

void InsertarAlFinal(NodoPaciente **inicio, Paciente p)
{
    NodoPaciente *nuevo = CrearNodo(p);
    if(*inicio == NULL)
    {
        *inicio = nuevo;
    }else
    {
        NodoPaciente *aux = *inicio;
        while (aux->siguiente != NULL)
        {
          aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void GenerarArchivoCentral(NodoPaciente **archivo, Paciente *cardio, Paciente *pedia, Paciente *trauma, int cant, int idInicial)
{
    int id = idInicial;

    for(int i = 0; i < cant; i++)
    {
        Paciente p1 = cardio[i];
        p1.IDPaciente = id++;
        InsertarAlFinal(archivo, p1);

        Paciente p2 = pedia[i];
        p2.IDPaciente = id++;
        InsertarAlFinal(archivo, p2);

        Paciente p3 = trauma[i];
        p3.IDPaciente = id++;
        InsertarAlFinal(archivo, p3);
    }
}

void MostrarListaPacientes(NodoPaciente *inicio, const char *titulo)
{
    printf("\n%s\n", titulo);
    MostrarLinea();
    while(inicio != NULL)
    {
        MostrarPaciente(inicio->datos);
        inicio = inicio->siguiente;
    }
    MostrarLinea();
}