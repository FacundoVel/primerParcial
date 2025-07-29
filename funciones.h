#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NOTA: NO MODIQUE NI AGREGE NADA EN ESTE ARCHIVO

// Estructura para representar un Paciente
typedef struct Paciente{
    int IDPaciente;             // Identificador único del paciente
    char *NombreCompleto;   // Nombre y apellido
    char *DepartamentoOrigen; // Departamento del hospital (Cardiología, Pediatría, Traumatología)
    int Edad;                   // Edad del paciente
    char *DiagnosticoPrincipal; // Diagnóstico médico
    int EstadoAlta;             // 0: Internado, 1: Posible Alta / Dado de Alta
} Paciente;

// Estructura para el nodo de la lista enlazada de Pacientes
typedef struct NodoPaciente {
    Paciente datos;           
    struct NodoPaciente *siguiente; 
} NodoPaciente;

struct Paciente * PacientesCardio();
struct Paciente * PacientesTraumato();
struct Paciente * PacientesPediatria();
void MostrarLinea();
void MostrarPacientesDeArreglo(Paciente * Paciente, int cantidad, const char * Titulo);
Paciente crearPaciente(int id, const char *nombre, const char *departamento, int edad, const char *diagnostico, int estado);
void MostrarPaciente(struct Paciente Paciente);

/// definicíon de funciones 
struct Paciente * PacientesCardio() {
    struct Paciente* Pacientes = (struct Paciente*) malloc(sizeof(struct Paciente) * 30);

    Pacientes[0] = crearPaciente(101, "Juan Perez", "Cardiologia", 65, "Insuficiencia Cardiaca", 0);
    Pacientes[1] = crearPaciente(102, "Ana Gomez", "Cardiologia", 72, "Arritmia", 0);
    Pacientes[2] = crearPaciente(103, "Carlos Lopez", "Cardiologia", 58, "Hipertension Arterial Severa", 0);
    Pacientes[3] = crearPaciente(104, "Maria Rodriguez", "Cardiologia", 61, "Angina de Pecho Estable", 0);
    Pacientes[4] = crearPaciente(105, "Jose Fernandez", "Cardiologia", 78, "Enfermedad Coronaria Cronico", 0);
    Pacientes[5] = crearPaciente(106, "Laura Martinez", "Cardiologia", 55, "Miocardiopatia Dilatada", 0);
    Pacientes[6] = crearPaciente(107, "Pedro Sanchez", "Cardiologia", 69, "Valvulopatia Aortica", 0);
    Pacientes[7] = crearPaciente(108, "Sofia Diaz", "Cardiologia", 71, "Fibrilacion Auricular", 0);
    Pacientes[8] = crearPaciente(109, "Miguel Torres", "Cardiologia", 63, "Post-infarto Agudo de Miocardio", 0);
    Pacientes[9] = crearPaciente(110, "Elena Ruiz", "Cardiologia", 80, "Insuficiencia Cardiaca Cronico", 0);
    Pacientes[10] = crearPaciente(111, "David Jimenez", "Cardiologia", 59, "Hipertension Pulmonar", 0);
    Pacientes[11] = crearPaciente(112, "Carmen Moreno", "Cardiologia", 66, "Estenosis Mitral", 0);
    Pacientes[12] = crearPaciente(113, "Francisco Alonso", "Cardiologia", 75, "Bloqueo AV Completo", 0);
    Pacientes[13] = crearPaciente(114, "Isabel Gutierrez", "Cardiologia", 60, "Pericarditis Aguda", 0);
    Pacientes[14] = crearPaciente(115, "Javier Vazquez", "Cardiologia", 73, "Sindrome Coronario Agudo", 0);
    Pacientes[15] = crearPaciente(116, "Raquel Dominguez", "Cardiologia", 68, "Endocarditis Bacteriana", 0);
    Pacientes[16] = crearPaciente(117, "Sergio Romero", "Cardiologia", 57, "Taquicardia Supraventricular", 0);
    Pacientes[17] = crearPaciente(118, "Paula Navarro", "Cardiologia", 70, "Aneurisma Aortico Abdominal", 0);
    Pacientes[18] = crearPaciente(119, "Adrian Santos", "Cardiologia", 62, "Cardiopatia Isquemica", 0);
    Pacientes[19] = crearPaciente(120, "Natalia Gil", "Cardiologia", 77, "Hipertension Cronico", 0);
    Pacientes[20] = crearPaciente(121, "Marcos Serrano", "Cardiologia", 64, "Insuficiencia Mitral", 0);
    Pacientes[21] = crearPaciente(122, "Silvia Mendez", "Cardiologia", 74, "Embolia Pulmonar", 0);
    Pacientes[22] = crearPaciente(123, "Daniel Molina", "Cardiologia", 56, "Bradicardia Sinusal", 0);
    Pacientes[23] = crearPaciente(124, "Cristina Ortega", "Cardiologia", 79, "Diseccion Aortica", 0);
    Pacientes[24] = crearPaciente(125, "Alejandro Cano", "Cardiologia", 67, "Miocarditis Viral", 0);
    Pacientes[25] = crearPaciente(126, "Beatriz Morales", "Cardiologia", 76, "Shock Cardiogenico", 0);
    Pacientes[26] = crearPaciente(127, "Ivan Pascual", "Cardiologia", 54, "Flutter Auricular", 0);
    Pacientes[27] = crearPaciente(128, "Lorena Rubio", "Cardiologia", 81, "Taponamiento Cardiaco", 0);
    Pacientes[28] = crearPaciente(129, "Ruben Marin", "Cardiologia", 61, "Arritmia Ventricular", 0);
    Pacientes[29] = crearPaciente(130, "Eva Diez", "Cardiologia", 72, "Angina Inestable", 0);

    return Pacientes;
}

struct Paciente * PacientesTraumato() {
    struct Paciente* Pacientes = (struct Paciente*) malloc(sizeof(struct Paciente) * 30);

    Pacientes[0] = crearPaciente(301, "Andres Navarro", "Traumatologia", 25, "Fractura de Tibia", 0);
    Pacientes[1] = crearPaciente(302, "Valeria Mendoza", "Traumatologia", 30, "Esguince de Tobillo Grado III", 0);
    Pacientes[2] = crearPaciente(303, "Diego Silva", "Traumatologia", 45, "Lumbalgia Aguda", 0);
    Pacientes[3] = crearPaciente(304, "Camila Soto", "Traumatologia", 19, "Fractura de Clavicula", 0);
    Pacientes[4] = crearPaciente(305, "Jorge Rivas", "Traumatologia", 55, "Artrosis de Rodilla", 0);
    Pacientes[5] = crearPaciente(306, "Florencia Otero", "Traumatologia", 22, "Luxacion de Hombro", 0);
    Pacientes[6] = crearPaciente(307, "Esteban Gallardo", "Traumatologia", 38, "Hernia Discal Lumbar", 0);
    Pacientes[7] = crearPaciente(308, "Agustina Paez", "Traumatologia", 28, "Fractura de Muñeca (Radio)", 0);
    Pacientes[8] = crearPaciente(309, "Federico Bravo", "Traumatologia", 60, "Tendinitis del Manguito Rotador", 0);
    Pacientes[9] = crearPaciente(310, "Lucia Campos", "Traumatologia", 33, "Lesion de Ligamento Cruzado Anterior", 0);
    Pacientes[10] = crearPaciente(311, "Matias Duarte", "Traumatologia", 41, "Fractura de Femur", 0);
    Pacientes[11] = crearPaciente(312, "Rocio Aguilera", "Traumatologia", 26, "Esguince Cervical", 0);
    Pacientes[12] = crearPaciente(313, "Nicolas Cabrera", "Traumatologia", 50, "Bursitis de Cadera", 0);
    Pacientes[13] = crearPaciente(314, "Julieta Guzman", "Traumatologia", 18, "Fractura de Escafoides", 0);
    Pacientes[14] = crearPaciente(315, "Sebastian Ponce", "Traumatologia", 65, "Fractura de Cadera", 0);
    Pacientes[15] = crearPaciente(316, "Daniela Juarez", "Traumatologia", 31, "Lesion Meniscal", 0);
    Pacientes[16] = crearPaciente(317, "Manuel Correa", "Traumatologia", 48, "Epicondilitis (Codo de Tenista)", 0);
    Pacientes[17] = crearPaciente(318, "Paula Arce", "Traumatologia", 23, "Fractura de Perone", 0);
    Pacientes[18] = crearPaciente(319, "Rodrigo Miranda", "Traumatologia", 58, "Sindrome del Tunel Carpiano", 0);
    Pacientes[19] = crearPaciente(320, "Mariana Pinto", "Traumatologia", 35, "Contusion Osea Multiple", 0);
    Pacientes[20] = crearPaciente(321, "Gonzalo Sosa", "Traumatologia", 42, "Fractura Vertebral por Compresion", 0);
    Pacientes[21] = crearPaciente(322, "Josefina Rios", "Traumatologia", 29, "Desgarro Muscular Gemelo", 0);
    Pacientes[22] = crearPaciente(323, "Patricio Medina", "Traumatologia", 62, "Osteoartritis Cronico Manos", 0);
    Pacientes[23] = crearPaciente(324, "Milagros Rojas", "Traumatologia", 21, "Fractura de Huesos Nasales", 0);
    Pacientes[24] = crearPaciente(325, "Ramiro Paredes", "Traumatologia", 53, "Ciatalgia", 0);
    Pacientes[25] = crearPaciente(326, "Guadalupe Suarez", "Traumatologia", 37, "Politraumatismo Leve", 0);
    Pacientes[26] = crearPaciente(327, "Hernan Flores", "Traumatologia", 46, "Fractura Costal", 0);
    Pacientes[27] = crearPaciente(328, "Antonella Rios", "Traumatologia", 27, "Tendinitis Aquilea", 0);
    Pacientes[28] = crearPaciente(329, "Maximiliano Acosta", "Traumatologia", 59, "Espondilolistesis Lumbar", 0);
    Pacientes[29] = crearPaciente(330, "Brenda Ortiz", "Traumatologia", 32, "Fractura de Rotula", 0);

    return Pacientes;
}

struct Paciente * PacientesPediatria() {
    struct Paciente* Pacientes = (struct Paciente*) malloc(sizeof(struct Paciente) * 30);

    Pacientes[0] = crearPaciente(201, "Luis Garcia", "Pediatria", 2, "Bronquiolitis Aguda", 0);
    Pacientes[1] = crearPaciente(202, "Carla Benitez", "Pediatria", 1, "Gastroenteritis Viral", 0);
    Pacientes[2] = crearPaciente(203, "Mateo Alvarez", "Pediatria", 5, "Neumonia Bacteriana", 0);
    Pacientes[3] = crearPaciente(204, "Valentina Herrera", "Pediatria", 0, "Ictericia Neonatal", 0);
    Pacientes[4] = crearPaciente(205, "Hugo Castro", "Pediatria", 7, "Asma Bronquial", 0);
    Pacientes[5] = crearPaciente(206, "Martina Gimenez", "Pediatria", 3, "Otitis Media Aguda", 0);
    Pacientes[6] = crearPaciente(207, "Lucas Vidal", "Pediatria", 6, "Varicela", 0);
    Pacientes[7] = crearPaciente(208, "Mia Sosa", "Pediatria", 1, "Infeccion Urinaria", 0);
    Pacientes[8] = crearPaciente(209, "Leo Medina", "Pediatria", 4, "Faringoamigdalitis", 0);
    Pacientes[9] = crearPaciente(210, "Sofia Rojas", "Pediatria", 8, "Convulsion Febril", 0);
    Pacientes[10] = crearPaciente(211, "Enzo Paredes", "Pediatria", 2, "Laringitis Aguda", 0);
    Pacientes[11] = crearPaciente(212, "Abril Suarez", "Pediatria", 9, "Apendicitis Aguda", 0);
    Pacientes[12] = crearPaciente(213, "Thiago Flores", "Pediatria", 1, "Dermatitis Atopica Severa", 0);
    Pacientes[13] = crearPaciente(214, "Alma Rios", "Pediatria", 10, "Escarlatina", 0);
    Pacientes[14] = crearPaciente(215, "Bautista Acosta", "Pediatria", 5, "Sinusitis Aguda", 0);
    Pacientes[15] = crearPaciente(216, "Olivia Ortiz", "Pediatria", 0, "Reflujo Gastroesofagico", 0);
    Pacientes[16] = crearPaciente(217, "Benjamin Ramirez", "Pediatria", 7, "Celulitis Periorbitaria", 0);
    Pacientes[17] = crearPaciente(218, "Emma Luna", "Pediatria", 4, "Estreñimiento Cronico", 0);
    Pacientes[18] = crearPaciente(219, "Felipe Benavidez", "Pediatria", 6, "Mononucleosis Infecciosa", 0);
    Pacientes[19] = crearPaciente(220, "Isabella Peralta", "Pediatria", 1, "Conjuntivitis Bacteriana", 0);
    Pacientes[20] = crearPaciente(221, "Joaquin Ibarra", "Pediatria", 9, "Migraña Infantil", 0);
    Pacientes[21] = crearPaciente(222, "Catalina Ponce", "Pediatria", 3, "Anemia Ferropenica", 0);
    Pacientes[22] = crearPaciente(223, "Santino Figueroa", "Pediatria", 8, "Hepatitis A", 0);
    Pacientes[23] = crearPaciente(224, "Victoria Coronel", "Pediatria", 2, "Tos Ferina", 0);
    Pacientes[24] = crearPaciente(225, "Ignacio Vega", "Pediatria", 11, "Diabetes Mellitus Tipo 1", 0);
    Pacientes[25] = crearPaciente(226, "Juana Toledo", "Pediatria", 5, "Parasitosis Intestinal", 0);
    Pacientes[26] = crearPaciente(227, "Lautaro Villalba", "Pediatria", 7, "Alergia Alimentaria", 0);
    Pacientes[27] = crearPaciente(228, "Renata Aguirre", "Pediatria", 1, "Herpangina", 0);
    Pacientes[28] = crearPaciente(229, "Gael Quiroga", "Pediatria", 10, "Enfermedad Celiaca", 0);
    Pacientes[29] = crearPaciente(230, "Pilar Ferreyra", "Pediatria", 4, "Gingivoestomatitis Herpetica", 0);
    return Pacientes;
}

Paciente crearPaciente(int id, const char *nombre, const char *departamento, int edad, const char *diagnostico, int estado) {
    Paciente nuevoPaciente;
    nuevoPaciente.IDPaciente = id;
    nuevoPaciente.Edad = edad;
    nuevoPaciente.EstadoAlta = estado;
    nuevoPaciente.NombreCompleto = (char *)malloc(strlen(nombre) + 1); 
    nuevoPaciente.DepartamentoOrigen = (char *)malloc(strlen(departamento) + 1);
    nuevoPaciente.DiagnosticoPrincipal = (char *)malloc(strlen(diagnostico) + 1);

    if (nuevoPaciente.NombreCompleto != NULL) strcpy(nuevoPaciente.NombreCompleto, nombre);
    if (nuevoPaciente.DepartamentoOrigen != NULL) strcpy(nuevoPaciente.DepartamentoOrigen, departamento);
    if (nuevoPaciente.DiagnosticoPrincipal != NULL) strcpy(nuevoPaciente.DiagnosticoPrincipal, diagnostico);

    return nuevoPaciente;
}

void MostrarLinea()
{   
    printf("---------------------------\n");
}


void MostrarPacientesDeArreglo(Paciente * Paciente, int cantidad, const char * Titulo)
{
    printf("%s \n\r" ,Titulo);
    MostrarLinea();
    for (int i = 0; i < cantidad; i++)
    {
        MostrarPaciente(Paciente[i]);
    }
    MostrarLinea();
}

void MostrarPaciente(struct Paciente Paciente)
{
    printf("ID: %d | Nombre: %-25s | Edad: %2d | Dpto:  %-20s | Diagnostico: %-50s\n",
        Paciente.IDPaciente,
        Paciente.NombreCompleto,
        Paciente.Edad,
        Paciente.DepartamentoOrigen,
        Paciente.DiagnosticoPrincipal
        );
}