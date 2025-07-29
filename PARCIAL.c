#include "funciones.h"

NodoPaciente *CrearListaVacia();
NodoPaciente *CrearNodo(Paciente p);
void InsertarAlFinal(NodoPaciente **inicio, Paciente p);
void GenerarArchivoCentral(NodoPaciente **archivo, Paciente *cardio, Paciente *pedia, Paciente *trauma, int cant, int idInicial);
void MostrarListaPacientes(NodoPaciente *inicio, const char *titulo);
void MarcarPosiblesAltas(NodoPaciente *lista, const char *departamento, int edadUmbral);
void EliminarPorDepartamento(NodoPaciente **lista, const char *departamento);
void MoverPacientesCronicos(NodoPaciente **origen, NodoPaciente **seguimiento);



int main()
{
    Paciente *cardio = PacientesCardio();
    Paciente *pediatria = PacientesPediatria();
    Paciente *traumato = PacientesTraumato();

    NodoPaciente *ArchivoCentral = CrearListaVacia();
    GenerarArchivoCentral(&ArchivoCentral, cardio, pediatria, traumato, 30, 2201);

    MostrarListaPacientes(ArchivoCentral, "LISTA UNIFICADA DE PACIENTES: ");

    MarcarPosiblesAltas(ArchivoCentral, "Pediatria", 3);
    printf("\nPACIENTES TRAS MARCAR POSIBLES ALTAS (Pediatria menores de 3 años):\n");
    MostrarListaPacientes(ArchivoCentral, "Archivo Central (Actualizado)");

    EliminarPorDepartamento(&ArchivoCentral, "Traumatologia");
    MostrarListaPacientes(ArchivoCentral, "Archivo Central (Sin Traumatología)");

    NodoPaciente *PacientesSeguimientoCronico = CrearListaVacia();
    MoverPacientesCronicos(&ArchivoCentral, &PacientesSeguimientoCronico);

    printf("\nPACIENTES CON SEGUIMIENTO CRÓNICO:\n");
    MostrarListaPacientes(PacientesSeguimientoCronico, "Pacientes Cronicos");
    printf("\nRESTANTES EN ARCHIVO CENTRAL:\n");
    MostrarListaPacientes(ArchivoCentral, "Archivo Central Final");

    LiberarLista(&ArchivoCentral);
    LiberarLista(&PacientesSeguimientoCronico);

    free(cardio);
    free(pediatria);
    free(traumato);


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

void MarcarPosiblesAltas(NodoPaciente *lista, const char *departamento, int edadUmbral)
{
    NodoPaciente *actual = lista;
    while(actual != NULL)
    {
        if(strcmp(actual->datos.DepartamentoOrigen, departamento) == 0 && actual->datos.Edad < edadUmbral)
        {
            actual->datos.EstadoAlta = 1;
        }
        actual = actual->siguiente;
    }
}

void EliminarPorDepartamento(NodoPaciente **lista, const char *departamento)
{
    NodoPaciente *actual = *lista;
    NodoPaciente *anterior = NULL;

    while(actual != NULL)
    {
        if(strcmp(actual->datos.DepartamentoOrigen, departamento) == 0)
        {
            NodoPaciente *aEliminar = actual;

            if(anterior == NULL)
            {
                //nodo al iniciop
                *lista = actual->siguiente;
                actual = *lista;
            }else
            {
                anterior->siguiente = actual->siguiente;
                actual = actual->siguiente;
            }

            //liberar strings internos
            free(aEliminar->datos.NombreCompleto);
            free(aEliminar->datos.DepartamentoOrigen);
            free(aEliminar->datos.DiagnosticoPrincipal);
            free(aEliminar);
        }else
        {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}

int ContieneCronico(const char *texto) {
    return strstr(texto, "Cronico") != NULL;
}

void MoverPacientesCronicos(NodoPaciente **origen, NodoPaciente **seguimiento)
{
    NodoPaciente *actual = *origen;
    NodoPaciente *anterior = NULL;

    while(actual != NULL)
    {
        if(ContieneCronico(actual->datos.DiagnosticoPrincipal))
        {
            NodoPaciente *aMover = actual;

            if (anterior == NULL)
            {
                //nodo inicio
                *origen = actual->siguiente;
                actual = *origen;
            }else
            {
                anterior->siguiente = actual->siguiente;
                actual = actual->siguiente;
            }

            //insertar al principio de la nueva lista
            aMover->siguiente = *seguimiento;
            *seguimiento = aMover;
        }else
        {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}

void LiberarLista(NodoPaciente **inicio)
{
    NodoPaciente *actual = *inicio;
    while(actual != NULL)
    {
        NodoPaciente *aEliminar = actual;
        actual = actual->siguiente;

        free(aEliminar->datos.NombreCompleto);
        free(aEliminar->datos.DepartamentoOrigen);
        free(aEliminar->datos.DiagnosticoPrincipal);
        free(aEliminar);        
    }
    *inicio = NULL;
}