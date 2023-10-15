#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define enum to name Business Departements
enum Department {HR, Sales, Research, Software, Executive};

//Stuct for Employees
struct Employee{enum Department department; int annual_salary; unsigned int ssn;};

// Macros for base salaries for each department
#define BASE_SALARY_HR 35000
#define BASE_SALARY_SALES 21000
#define BASE_SALARY_RESEARCH 32000
#define BASE_SALARY_SOFTWARE 42000
#define BASE_SALARY_EXECUTIVE 62000

// Macros for salaries offset
#define SALARY_OFFSET 15000

// Macro to generate a random salary offset
#define RANDOM_SALARY_OFFSET (rand() % SALARY_OFFSET)

// Function to calculate a random salary for a given department
int generate_salary(enum Department department) 
{
    switch (department) 
    {
        case HR:        return BASE_SALARY_HR + RANDOM_SALARY_OFFSET;
        case Sales:     return BASE_SALARY_SALES + RANDOM_SALARY_OFFSET;
        case Research:  return BASE_SALARY_RESEARCH + RANDOM_SALARY_OFFSET;
        case Software:  return BASE_SALARY_SOFTWARE + RANDOM_SALARY_OFFSET;
        case Executive: return BASE_SALARY_EXECUTIVE + RANDOM_SALARY_OFFSET;
        default:        return 0; // Handle the default case
    }
}

// Function to print employee information
void print_employee(const struct Employee* employee) 
{
    const char* department_names[] = { "HR", "Sales", "Research", "Software", "Executive" };
    printf("Department:\t %s\n", department_names[employee->department]);
    printf("Annual Salary:\t %d\n", employee->annual_salary);
    printf("SSN:\t\t %u\n", employee->ssn);
    printf("---------------------------\n");
}

int main()
{
    srand(time(NULL));// Seed the random number generator
        
    // Create an array of 10 employees with empty salary each
    struct Employee employees[10] = 
    {
        {HR,            0, 123456789},
        {Sales,         0, 987654321},
        {Research,      0, 456789123},
        {Software,      0, 789123456},
        {Executive,     0, 234567890},
        {HR,            0, 345678901},
        {Sales,         0, 567890123},
        {Research,      0, 678901234},
        {Software,      0, 890123456},
        {Executive,     0, 345678912}
    };
    // Modify Employees salaries with random salaries based on department:
    for (int i = 0; i < 10; i++) employees[i].annual_salary = generate_salary(employees[i].department);
    
    // Print employee information
    for (int i = 0; i < 10; i++) 
    {
        printf("Employee %d:\n", i + 1);
        print_employee(&employees[i]);
    }

    return 0;
}

/*
After compiling the code, it output this result:
$ ./main
Employee 1:
Department:      HR        
Annual Salary:   45016     
SSN:             123456789 
---------------------------
Employee 2:
Department:      Sales     
Annual Salary:   32643     
SSN:             987654321 
---------------------------
Employee 3:
Department:      Research  
Annual Salary:   32240     
SSN:             456789123 
---------------------------
Employee 4:
Department:      Software  
Annual Salary:   54660     
SSN:             789123456 
---------------------------
Employee 5:
Department:      Executive 
Annual Salary:   64396     
SSN:             234567890 
---------------------------
Employee 6:
Department:      HR        
Annual Salary:   49247     
SSN:             345678901 
---------------------------
Employee 7:
Department:      Sales     
Annual Salary:   21040     
SSN:             567890123
---------------------------
Employee 8:
Department:      Research
Annual Salary:   45033
SSN:             678901234
---------------------------
Employee 9:
Department:      Software
Annual Salary:   43722
SSN:             890123456
---------------------------
Employee 10:
Department:      Executive
Annual Salary:   76908
SSN:             345678912
---------------------------
*/

