#include <funciones.h>

NodoPaciente *CrearListaVacia();
NodoPaciente *CrearNodo(Paciente p);

int main()
{
    Paciente *cardio = PacientesCardio();
    Paciente *pediatria = PacientesPediatria();
    Paciente *traumato = PacientesTraumato();


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
