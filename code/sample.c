#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* ── Data types ──────────────────────────────────────────────────────────────*/

typedef enum {
    DEPT_ENGINEERING,
    DEPT_MARKETING,
    DEPT_FINANCE,
    DEPT_HR
} Department;

typedef struct {
    int        id;
    char       name[64];
    Department department;
    double     salary;
    bool       active;
} Employee;

/* ── Helpers ──────────────────────────────────────────────────────────────── */

const char* dept_name(Department d) {
    switch (d) {
        case DEPT_ENGINEERING: return "Engineering";
        case DEPT_MARKETING:   return "Marketing";
        case DEPT_FINANCE:     return "Finance";
        case DEPT_HR:          return "HR";
        default:               return "Unknown";
    }
}

/* Returns the average salary across all employees. */
double average_salary(const Employee *employees, size_t count) {
    if (count == 0) return 0.0;
    double total = 0.0;
    for (size_t i = 0; i < count; i++) {
        total += employees[i].salary;
    }
    return total / (double)count;
}

/* Prints all active employees to stdout. */
void print_active(const Employee *employees, size_t count) {
    printf("Active employees:\n");
    for (size_t i = 0; i < count; i++) {
        if (employees[i].active) {
            printf("  [%d] %-16s — %s — $%.0f\n",
                   employees[i].id,
                   employees[i].name,
                   dept_name(employees[i].department),
                   employees[i].salary);
        }
    }
}

/* ── Main ─────────────────────────────────────────────────────────────────── */

int main(void) {
    Employee employees[] = {
        {1, "Alice Martin",  DEPT_ENGINEERING, 82000, true},
        {2, "Bob Chen",      DEPT_MARKETING,   64000, true},
        {3, "Carol White",   DEPT_ENGINEERING, 91000, true},
        {4, "David Kim",     DEPT_HR,          57000, false},
        {5, "Eva Rossi",     DEPT_ENGINEERING, 78000, true},
        {6, "Frank Lopez",   DEPT_MARKETING,   61500, true},
        {7, "Grace Muller",  DEPT_FINANCE,     73000, false},
        {8, "Henry Tanaka",  DEPT_HR,          55000, true},
    };

    size_t count = sizeof(employees) / sizeof(employees[0]);

    print_active(employees, count);
    printf("Average salary: $%.2f\n", average_salary(employees, count));

    return EXIT_SUCCESS;
}
