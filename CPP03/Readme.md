---

# C++ Module 03 – Inheritance Basics

This module introduces **single inheritance** in C++, building from a base class (`ClapTrap`) and extending it with specialized robots (`ScavTrap`, `FragTrap`).
Focus is on:

* Constructor/destructor chaining
* Attribute initialization in derived classes
* Method overriding
* Adding new behaviors in child classes

---

## Exercises Overview

### **ex00 – Aaaaand… OPEN!**

**Goal:**
Implement a `ClapTrap` class with:

* Attributes: `Name`, `hit_points = 10`, `energy_points = 10`, `attack_damage = 0`
* Methods:

  * `attack(const std::string&)`
  * `takeDamage(unsigned int)`
  * `beRepaired(unsigned int)`
* Orthodox Canonical Form (default, param, copy, assignment, destructor)
* Messages in ctors/dtor and actions for visibility

**Concepts:**

* Basic class design
* Encapsulation (private/protected attributes)
* State changes gated by conditions (HP/EP > 0)
* Output messages to trace object lifecycle

---

### **ex01 – Serena, my love!**

**Goal:**
Create a `ScavTrap` class **inheriting from `ClapTrap`**:

* Stats updated:

  * `hit_points = 100`
  * `energy_points = 50`
  * `attack_damage = 20`
* Override `attack()` with a different message
* Add `guardGate()` → prints “Gate keeper mode”
* Show correct ctor/dtor chaining

**Concepts:**

* Public inheritance
* Constructor initialization lists for inherited attributes
* Method overriding (same signature, different output)
* Adding unique abilities to a derived class

---

### **ex02 – Repetitive work**

**Goal:**
Create a `FragTrap` class **inheriting from `ClapTrap`**:

* Stats updated:

  * `hit_points = 100`
  * `energy_points = 100`
  * `attack_damage = 30`
* Override messages for ctor/dtor
* Add `highFivesGuys()` → prints a friendly high-five request
* Maintain ctor/dtor chaining

**Concepts:**

* Another single-inheritance specialization
* Differentiating derived classes with custom stats & methods
* Reinforcing canonical form and proper base initialization

---
