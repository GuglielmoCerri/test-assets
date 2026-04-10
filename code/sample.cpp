#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <optional>

// ── Data types ────────────────────────────────────────────────────────────────

enum class Department { Engineering, Marketing, Finance, HR };

std::string departmentName(Department d) {
    switch (d) {
        case Department::Engineering: return "Engineering";
        case Department::Marketing:  return "Marketing";
        case Department::Finance:    return "Finance";
        case Department::HR:         return "HR";
        default:                     return "Unknown";
    }
}

struct Employee {
    int id;
    std::string name;
    Department department;
    double salary;
    bool active;
};

// ── Repository ────────────────────────────────────────────────────────────────

class EmployeeRepository {
public:
    explicit EmployeeRepository(std::vector<Employee> employees)
        : employees_(std::move(employees)) {}

    std::vector<Employee> findActive() const {
        std::vector<Employee> result;
        std::copy_if(employees_.begin(), employees_.end(),
                     std::back_inserter(result),
                     [](const Employee& e) { return e.active; });
        return result;
    }

    std::optional<Employee> findById(int id) const {
        auto it = std::find_if(employees_.begin(), employees_.end(),
                               [id](const Employee& e) { return e.id == id; });
        if (it != employees_.end()) return *it;
        return std::nullopt;
    }

    double averageSalary() const {
        if (employees_.empty()) return 0.0;
        double total = std::accumulate(employees_.begin(), employees_.end(), 0.0,
            [](double sum, const Employee& e) { return sum + e.salary; });
        return total / static_cast<double>(employees_.size());
    }

private:
    std::vector<Employee> employees_;
};

// ── Main ──────────────────────────────────────────────────────────────────────

int main() {
    std::vector<Employee> data = {
        {1, "Alice Martin",  Department::Engineering, 82000, true},
        {2, "Bob Chen",      Department::Marketing,   64000, true},
        {3, "Carol White",   Department::Engineering, 91000, true},
        {4, "David Kim",     Department::HR,          57000, false},
        {5, "Eva Rossi",     Department::Engineering, 78000, true},
        {6, "Frank Lopez",   Department::Marketing,   61500, true},
        {7, "Grace Müller",  Department::Finance,     73000, false},
        {8, "Henry Tanaka",  Department::HR,          55000, true},
    };

    EmployeeRepository repo(std::move(data));

    std::cout << "Active employees: " << repo.findActive().size() << "\n";
    std::cout << "Average salary:   " << repo.averageSalary() << "\n";

    if (auto emp = repo.findById(3)) {
        std::cout << "Found: " << emp->name << " (" << departmentName(emp->department) << ")\n";
    }

    return 0;
}
