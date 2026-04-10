"""
sample.py — Synthetic Python module for parser and syntax testing.
Demonstrates common patterns: dataclasses, enums, type hints, comprehensions.
"""

from __future__ import annotations

import statistics
from dataclasses import dataclass, field
from enum import Enum, auto
from typing import Optional


# ── Enums ─────────────────────────────────────────────────────────────────────

class Department(Enum):
    ENGINEERING = auto()
    MARKETING = auto()
    FINANCE = auto()
    HR = auto()


# ── Data model ────────────────────────────────────────────────────────────────

@dataclass(frozen=True)
class Employee:
    id: int
    name: str
    department: Department
    salary: float
    active: bool = True


# ── Repository ────────────────────────────────────────────────────────────────

@dataclass
class EmployeeRepository:
    _employees: list[Employee] = field(default_factory=list)

    def add(self, employee: Employee) -> None:
        self._employees.append(employee)

    def find_by_id(self, employee_id: int) -> Optional[Employee]:
        return next((e for e in self._employees if e.id == employee_id), None)

    def find_active(self) -> list[Employee]:
        return [e for e in self._employees if e.active]

    def group_by_department(self) -> dict[Department, list[Employee]]:
        result: dict[Department, list[Employee]] = {}
        for emp in self._employees:
            result.setdefault(emp.department, []).append(emp)
        return result

    def average_salary(self) -> float:
        salaries = [e.salary for e in self._employees]
        return statistics.mean(salaries) if salaries else 0.0

    def top_earners(self, n: int = 3) -> list[Employee]:
        return sorted(self._employees, key=lambda e: e.salary, reverse=True)[:n]


# ── Entry point ───────────────────────────────────────────────────────────────

def main() -> None:
    repo = EmployeeRepository()
    sample_data = [
        Employee(1, "Alice Martin",  Department.ENGINEERING, 82000),
        Employee(2, "Bob Chen",      Department.MARKETING,   64000),
        Employee(3, "Carol White",   Department.ENGINEERING, 91000),
        Employee(4, "David Kim",     Department.HR,          57000, active=False),
        Employee(5, "Eva Rossi",     Department.ENGINEERING, 78000),
        Employee(6, "Frank Lopez",   Department.MARKETING,   61500),
        Employee(7, "Grace Müller",  Department.FINANCE,     73000, active=False),
        Employee(8, "Henry Tanaka",  Department.HR,          55000),
    ]
    for emp in sample_data:
        repo.add(emp)

    print(f"Active employees : {len(repo.find_active())}")
    print(f"Average salary   : ${repo.average_salary():,.2f}")
    print("Top 3 earners    :", [e.name for e in repo.top_earners(3)])

    by_dept = repo.group_by_department()
    for dept, members in by_dept.items():
        print(f"  {dept.name:<15} {len(members)} member(s)")


if __name__ == "__main__":
    main()
