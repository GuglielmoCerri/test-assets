import java.util.*;
import java.util.stream.*;

/**
 * Sample Java class for parser and syntax testing.
 * Demonstrates common Java patterns: generics, streams, records, enums.
 */
public class sample {

    // ── Enum ──────────────────────────────────────────────────────────────────

    public enum Department {
        ENGINEERING, MARKETING, FINANCE, HR;
    }

    // ── Record (Java 16+) ─────────────────────────────────────────────────────

    public record Employee(int id, String name, Department department, double salary, boolean active) {}

    // ── Repository ────────────────────────────────────────────────────────────

    public static class EmployeeRepository {

        private final List<Employee> employees;

        public EmployeeRepository(List<Employee> employees) {
            this.employees = Collections.unmodifiableList(employees);
        }

        public List<Employee> findActive() {
            return employees.stream()
                    .filter(Employee::active)
                    .collect(Collectors.toList());
        }

        public Map<Department, List<Employee>> groupByDepartment() {
            return employees.stream()
                    .collect(Collectors.groupingBy(Employee::department));
        }

        public OptionalDouble averageSalary() {
            return employees.stream()
                    .mapToDouble(Employee::salary)
                    .average();
        }

        public Optional<Employee> findById(int id) {
            return employees.stream()
                    .filter(e -> e.id() == id)
                    .findFirst();
        }
    }

    // ── Main ──────────────────────────────────────────────────────────────────

    public static void main(String[] args) {
        List<Employee> data = List.of(
            new Employee(1, "Alice Martin",  Department.ENGINEERING, 82000, true),
            new Employee(2, "Bob Chen",      Department.MARKETING,   64000, true),
            new Employee(3, "Carol White",   Department.ENGINEERING, 91000, true),
            new Employee(4, "David Kim",     Department.HR,          57000, false),
            new Employee(5, "Eva Rossi",     Department.ENGINEERING, 78000, true),
            new Employee(6, "Frank Lopez",   Department.MARKETING,   61500, true),
            new Employee(7, "Grace Müller",  Department.FINANCE,     73000, false),
            new Employee(8, "Henry Tanaka",  Department.HR,          55000, true)
        );

        EmployeeRepository repo = new EmployeeRepository(data);

        System.out.println("Active employees: " + repo.findActive().size());
        repo.averageSalary().ifPresent(avg ->
            System.out.printf("Average salary: %.2f%n", avg));
        repo.findById(3).ifPresent(e ->
            System.out.println("Found: " + e.name() + " (" + e.department() + ")"));
    }
}
