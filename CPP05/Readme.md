

# C++ Module 05 – Bureaucracy & Forms

This module extends polymorphism and abstract classes by modeling a bureaucratic system of **Bureaucrats** and **Forms**.
It introduces **exception handling**, **abstract base classes**, and **concrete specializations**.

---

## Exercises Overview

### **ex00 – Bureaucrat**

**Goal:**

* Implement a `Bureaucrat` with:

  * `name` (constant)
  * `grade` (1 = highest, 150 = lowest)
* Methods to increment/decrement grade within bounds.
* Throw exceptions (`GradeTooHighException`, `GradeTooLowException`) if limits are violated.
* Overload `operator<<` for printing.

**Concepts:**

* Exception handling in C++ (`throw` / `catch`).
* Maintaining class invariants.
* Orthodox Canonical Form.

**Key Learning:**

* How to enforce valid state using exceptions.
* Importance of virtual destructors for polymorphic bases.

---

### **ex01 – Form**

**Goal:**

* Introduce a `Form` class with:

  * `name`, `is_signed`, `sign_grade`, `exec_grade`.
* Bureaucrats can sign forms if their grade is high enough.

**Concepts:**

* Class interaction via composition (`Bureaucrat` interacts with `Form`).
* Validation of grades with exceptions.
* Clear separation of responsibilities:

  * `Form` validates.
  * `Bureaucrat` requests signing.

**Key Learning:**

* Exception-driven collaboration between two classes.
* Encapsulation of validation logic inside the responsible class.

---

### **ex02 – Abstract Form (AForm)**

**Goal:**

* Refactor `Form` → `AForm` as an **abstract class**.
* Add pure virtual `executeConcrete()` implemented by derived classes.
* Implement non-pure `execute()` in `AForm` that checks:

  * Form is signed.
  * Executor has sufficient grade.

**Concepts:**

* **Abstract base class** with pure virtual functions (`= 0`).
* **Template Method pattern**:

  * Base handles common validation.
  * Derived handles unique behavior.

**Key Learning:**

* Enforcing a contract that all concrete forms must implement.
* Code reuse across different form types.

---

### **ex03 – Concrete Forms**

**Goal:**

* Implement three derived forms from `AForm`:

  * `ShrubberyCreationForm` → writes ASCII tree to a file.
  * `RobotomyRequestForm` → 50% chance to “robotomize” the target.
  * `PresidentialPardonForm` → announces a presidential pardon.

**Concepts:**

* Full polymorphism in practice: `AForm* f = new RobotomyRequestForm(); f->execute(bureaucrat);`
* Mixing abstract validation with concrete specialization.
* File I/O with `<fstream>`.

**Key Learning:**

* Clear split between **generic execution protocol** and **form-specific action**.
* How abstract base + derived concrete classes model real-world variation.

---

## Summary of Concepts

* **Exceptions** → enforce constraints (`GradeTooHigh`, `NotSigned`, etc.).
* **Abstract class** → `AForm`, defines interface, cannot be instantiated.
* **Concrete class** → derived forms implement required methods.
* **Polymorphism** → execute via `AForm*` runs the correct derived behavior.
* **Template Method pattern** → base class enforces common rules, derived adds uniqueness.

---

