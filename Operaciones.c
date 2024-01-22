# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "operaciones.h"


int comprobarId(struct empleado empleados[100], int num_emp, int id);

void mostrarMenu(){
  printf("\n Ingrse una opción: \n");
  printf("1. Alta empleado\n");
  printf("2. Baja empleado\n");
  printf("3. Listar empleados\n");
  printf("4. Consultar datos empleado\n");
  printf("5. Modificar Sueldo\n");
  printf("6. Modificar Horas\n");
  printf("7. Salir\n");
}

void listarEmpleados(struct empleado empleados[100], int num_emp){
  printf("Listar empleados\n");
  for (int i = 0; i < num_emp; i++){
    printf("Nombre: %s\n", empleados[i].nombre);
    printf("ID: %d\n", empleados[i].id);
    printf("Sueldo: %f\n", empleados[i].sueldo);
    printf("Horas: %d\n", empleados[i].horas);
    printf("\n");
  }
}

int alta(struct empleado empleados[100], int num_emp){
  int creado = 0;
  struct empleado emp;

  fflush(stdin);
  printf("Ingrese el nombre del empleado: \n ");
  gets(emp.nombre);

  printf("Ingrese el ID del empleado: \n ");
  scanf("%d", &emp.id);

  printf("Ingrese el sueldo del empleado: \n ");
  scanf("%f", &emp.sueldo);

  printf("Ingrese las horas del empleado: \n");
  scanf("%d", &emp.horas);

  int existe = comprobarId(empleados, num_emp, emp.id);

  if (num_emp<100){
    if( existe == 0){
      empleados[num_emp] = emp;
      creado = 1;
    }
    else{
      printf("El ID ya existe\n");
    }
  }
  else {
    printf("No se pueden agregar más empleados\n");
  }
  return creado;
}

int baja(struct empleado empleados[100], int num_emp){
  int eliminado = 0;
  int id, indice;

  printf("Ingrese el ID del empleado a dar de baja: \n");
  scanf("%d", &id);

  int existe = comprobarId(empleados, num_emp, id);

  if (existe==1){
    for (int i = 0; i < num_emp; i++){
      if (empleados[i].id == id){
        indice = i;
      }
    }
    for(int j = indice; j < num_emp-1; j++){
      empleados[j] = empleados[j+1];
      struct empleado aux;
      empleados[j+1] = aux;
    }
    eliminado = 1;
  }
  else{
    printf("El ID no existe\n");
  }
  return eliminado;
}

void consultarDatosEmpleado(struct empleado empleados[100], int num_emp){
  int id;
  printf("Ingrese el ID del empleado a consultar: \n");
  scanf("%d", &id);

  int existe = comprobarId(empleados, num_emp, id);
  if (existe==1){
    for (int i = 0; i < num_emp; i++){
      if (empleados[i].id == id){
        printf("Listando datos del empleado con id: %d\n", empleados[i].id);
        printf("Nombre: %s\n", empleados[i].nombre);
        printf("Sueldo: %.2f\n", empleados[i].sueldo);
        printf("Horas: %d\n", empleados[i].horas);
      }
    }
  }
  else{
    printf("El ID no existe\n");
  }

}

void modificarSueldo(struct empleado empleados[100], int num_emp){

  int id;
  printf("Ingrese el ID del empleado a modificar: \n");
  scanf("%d", &id);
  int existe = comprobarId(empleados, num_emp, id);
  if (existe==1){
    for (int i = 0; i < num_emp; i++){
      float nuevo_sueldo;
      printf("Ingrese el nuevo sueldo del empleado: \n");
      scanf("%f", &nuevo_sueldo);
      if (empleados[i].id == id){
        empleados[i].sueldo = nuevo_sueldo;
        printf("Sueldo modificado\n");
      }
    }
  }
  else{
    printf("El ID no existe\n");
  }


}

void modificarHoras(struct empleado empleados[100], int num_emp){
  int id;
  printf("Ingrese el ID del empleado a modificar: \n");
  scanf("%d", &id);
  int existe = comprobarId(empleados, num_emp, id);
  if (existe==1){
    for (int i = 0; i < num_emp; i++){
      int nuevas_horas;
      printf("Ingrese las nuevas horas del empleado: \n");
      scanf("%d", &nuevas_horas);
      if (empleados[i].id == id){
        empleados[i].horas = nuevas_horas;
        printf("Horas modificado\n");
      }
    }
  }
  else{
    printf("El ID no existe\n");
  }


}
int comprobarId(struct empleado empleados[100], int num_emp, int id){

  int resultado = 0;
  for (int i=0; i < num_emp; i++){
    if (empleados[i].id == id){
      resultado = 1;
    }
  }

  return resultado;
}




