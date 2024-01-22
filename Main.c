# include <stdio.h>
# include <stdlib.h>
# include "operaciones.h"
# include "persistencia.h"

int main()
{
  int opcion = 0;
  struct empleado empleados[100];

    int num_emp = cargarEmpleados(empleados);

  printf("======================================\n");
  printf("Binvenidos al gestor de Empleados\n");
  printf("======================================\n");
  mostrarMenu();
  scanf("%d", &opcion);

  switch (opcion){
    case 1:
      int creado = alta (empleados, num_emp);
      if (creado == 1){
        num_emp++;
      }
      break;
    case 2:
      int eliminado = baja(empleados, num_emp);
      if (eliminado == 1){
        num_emp--;
      }
      break;
    case 3:
      listarEmpleados(empleados, num_emp);
      break;
    case 4:
      consultarDatosEmpleado(empleados, num_emp);
      break;
    case 5:
      modificarSueldo(empleados, num_emp);
      break;
    case 6:
      modificarHoras(empleados, num_emp);
      break;
    case 7:
      guardarEmpleados(empleados, num_emp);
      break;
    case 8:
      printf("Salir - Gracias por usar el Gestor de Empleados\n");
      break;
    default:
      printf("Opción no válida\n");
      break;
    }

}
