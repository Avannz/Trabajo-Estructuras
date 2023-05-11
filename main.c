#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[30];
    char genero;
} stAlumno;

stAlumno cargarAlumno();
int alumnoArreglo(stAlumno alumno[], int dim);
int busquedaAlumno(stAlumno alumno[], int busqueda, int validos);
int busqueda(stAlumno alumno[],int posBusqueda,int validos);
void ordenarAlumnosNombre(stAlumno alumno[], int validos);
void insertarAlumnoNombre (stAlumno alumno[], int posBusqueda, stAlumno dato);
void insertarAlumno (stAlumno alumno[], int *validos);
void ordenarAlumnos(stAlumno alumno[], int validos);
void mostrarAlumnos(stAlumno alumno[], int validos);
void mostrarAlumno(stAlumno alumno);
void mostrarGenero (stAlumno alumno[], char genero, int validos);

int main()
{
    int dim = 15;
    int validos = 0;
    int matricula;
    int pos;
    int genero;
    stAlumno nuevoAlumno[dim];
    validos = alumnoArreglo(nuevoAlumno, dim);
    mostrarAlumnos(nuevoAlumno, validos);

    printf("\n\nAlumnos:\n");
    ordenarAlumnosNombre(nuevoAlumno, validos);
    printf("\n\nAlumnos Ordenados:\n");
    mostrarAlumnos(nuevoAlumno, validos);
//    insertarAlumno(nuevoAlumno, &validos);
//    mostrarAlumnos(nuevoAlumno, validos);
//
//    printf("Ingrese el genero que quiere mostrar");
//    fflush(stdin);
//    scanf("%c", &genero);
//
//    mostrarGenero(nuevoAlumno, genero, validos);

}

stAlumno cargarAlumno()
{
    stAlumno alumno;
    int flag = 0;

    printf("\nIngrese el nombre (maximo 30 caracteres): \n");
    fflush(stdin);
    gets(alumno.nombre);
    while(flag == 0)
    {
        printf("\nIngrese su genero(m, f, o):\n");
        fflush(stdin);
        scanf("%c", &alumno.genero);
        if(alumno.genero != 'm' && alumno.genero != 'f' && alumno.genero != 'o')
        {
            printf("\nError. El genero debe ser m, f u o\n");
        }
        else
        {
            flag = 1;
        }
    }
    printf("\nIngrese matricula:\n");
    fflush(stdin);
    scanf("%d", &alumno.matricula);

    return alumno;
}

void mostrarAlumno(stAlumno alumno)
{
    printf("\n==========================");
    printf("\nNombre: %s\n", alumno.nombre);
    printf("Genero: %c\n", alumno.genero);
    printf("Matricula: %d\n", alumno.matricula);
    printf("==========================\n");
}

int alumnoArreglo(stAlumno alumno[], int dim)
{

    int i = 0;
    char eleccion = 's';

    while(i<dim && eleccion == 's')
    {

        alumno[i] = cargarAlumno();
        i++;
        printf("\nIngrese 's' para seguir cargando alumnos: ");
        fflush(stdin);
        scanf("%c", &eleccion);
    }

    return i;
}

void mostrarAlumnos(stAlumno alumno[], int validos)
{
    int i = 0;
    for(i = 0; i<validos; i++)
    {
        mostrarAlumno(alumno[i]);
    }
}

int busquedaAlumno(stAlumno alumno[], int busqueda, int validos)
{
    int i = 0;
    int flag = 0;
    for(i = 0; i<validos; i++)
    {
        if(busqueda == alumno[i].matricula)
        {
            mostrarAlumno(alumno[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nEl alumno no esta registrado!\n");
    }
    return i;
}

void ordenarAlumnos(stAlumno alumno[], int validos)
{

    int i = 0;
    stAlumno aux;
    int posmenor;
    while(i<validos-1)
    {
        posmenor = busqueda(alumno,i,validos);
        aux = alumno[posmenor];
        alumno[posmenor] = alumno[i];
        alumno[i]=aux;
        i++;
    }
}

int busqueda(stAlumno alumno[],int posBusqueda,int validos)
{

    int menor = alumno[posBusqueda].matricula;
    int posmenor = posBusqueda;
    int i = posBusqueda+1;
    while(i<validos)
    {
        if(menor > alumno[i].matricula)
        {
            menor = alumno[i].matricula;
            posmenor = i;
        }
        i++;
    }
    return posmenor;
}

void mostrarGenero (stAlumno alumno[], char genero, int validos)
{
    int i = 0;
    while(i < validos)
    {
        if(genero == alumno[i].genero)
        {
            mostrarAlumno(alumno[i]);
            i++;
        }
        else
        {
            i++;
        }
    }
}

void insertarAlumnoMatricula (stAlumno alumno[], int *validos){
    int dim = *validos+1;
    stAlumno aux = cargarAlumno();
    int i = *validos;
    while(i >= 0){
        if(aux.matricula < alumno[i].matricula){
            alumno[i+1] = alumno[i];
            alumno[i] = aux;
        }
    i--;
    }
    *validos = dim;
}

void insertarAlumnoNombre (stAlumno alumno[], int posBusqueda, stAlumno dato)
{
    int i = posBusqueda;


    while(i>=0 && strcmp(dato.nombre,alumno[i].nombre) == -1){
        alumno[i+1]=alumno[i];
        i--;
    }
    alumno[i+1]=dato;
}

void ordenarAlumnosNombre(stAlumno alumno[], int validos){
    int i = 0;
    while(i<validos-1){
        insertarAlumnoNombre(alumno,i,alumno[i+1]);
        i++;
    }
}
