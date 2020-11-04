#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employeeAlta(Employee* this);

int list_anEmployee(LinkedList* miLista, int id);

int employee_indexFromId(LinkedList* pArrayLinkedList, int id, int* index);

int employee_set(Employee* this);


int employee_compareById(void* Emp1, void* Emp2);
int employee_compareByName(void* Emp1, void* Emp2);
int employee_compareByHour(void* Emp1, void* Emp2);
int employee_compareBySalary(void* Emp1, void* Emp2);

#endif // employee_H_INCLUDED
