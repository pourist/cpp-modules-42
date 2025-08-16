# C++ Module 04 – Subtype Polymorphism, Abstract Classes, and Interfaces

This module introduces advanced OOP concepts in C++, focusing on:

* **Subtype polymorphism** via virtual functions
* **Abstract classes** and pure virtual methods
* **Interfaces** (C++98 style = pure abstract classes)
* **Deep vs shallow copy** and correct memory management
* Building extensible systems while avoiding leaks

---

## Exercises Overview

### **ex00 – Polymorphism**

**Goal:**

* Base class `Animal`, derived classes `Dog` and `Cat`.
* `makeSound()` declared **virtual** to enable runtime polymorphism.
* Destructor declared **virtual** to ensure safe deletion via base pointers.
* Added `WrongAnimal` / `WrongCat` as a counter-example (no virtuals).

**Concepts:**

* Virtual methods enable correct dynamic dispatch.
* Virtual destructors prevent leaks in polymorphic hierarchies.
* Demonstrated what happens when `virtual` is missing.

---

### **ex01 – I don’t want to set the world on fire**

**Goal:**

* Introduced a `Brain` class (array of 100 `std::string ideas`).
* `Dog` and `Cat` hold a `Brain*`.
* Implemented **deep copy** in copy constructor and assignment operator.
* Deleted `Brain` in destructor to avoid leaks.

**Concepts:**

* **Shallow copy** vs **Deep copy**.
* Rule of Three: destructor, copy constructor, assignment operator.
* Verified correctness with tools like Valgrind.

---

### **ex02 – Abstract class**

**Goal:**

* Made `Animal` **abstract** by declaring `makeSound()` pure virtual.
* Prevented direct instantiation of `Animal`.
* Forced derived classes to implement `makeSound()`.

**Concepts:**

* Abstract base classes define contracts, not objects.
* Pure virtual functions enforce implementation in derived classes.

---

### **ex03 – Interface & Recap**

**Goal:**

* Created abstract base class `AMateria`:

  * Common data (`type`)
  * Pure virtual `clone()`
  * Virtual `use(ICharacter&)`
* Implemented concrete classes: `Ice`, `Cure`.
* Defined interfaces:

  * `ICharacter` (equip, unequip, use)
  * `IMateriaSource` (learnMateria, createMateria)
* Implemented:

  * `Character` with 4-slot inventory (deep copy of equipped Materias).
  * `MateriaSource` as a factory (stores templates, clones new Materias).

**Concepts:**

* Interfaces = pure abstract classes.
* Polymorphism = extensibility (easy to add new Materias/Characters).
* Factory pattern for object creation.
* Memory management: `clone()` allocates new instances, `unequip()` doesn’t delete, deep copy avoids shared ownership.

---

## Key Takeaways

* **Polymorphism:** late binding → correct function calls at runtime.
* **Virtual destructors:** prevent leaks when deleting via base class pointers.
* **Deep copies:** required when managing resources with raw pointers.
* **Abstract classes & Interfaces:** define contracts, enforce design.
* **Factory pattern:** separates object creation from usage.

---