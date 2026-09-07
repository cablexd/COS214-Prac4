<div align="center">

# 🛠️ TaskForge

**University of Pretoria | COS 214 | Practical 4**

![C++11](https://img.shields.io/badge/Language-C%2B%2B11-00599C?style=for-the-badge&logo=cplusplus)
![Build](https://img.shields.io/badge/Build-Passing-success?style=for-the-badge&logo=make)
![Valgrind](https://img.shields.io/badge/Memory-0%20Leaks-brightgreen?style=for-the-badge&logo=valgrind)
![Docker](https://img.shields.io/badge/Environment-Docker-2496ED?style=for-the-badge&logo=docker)
![Due Date](https://img.shields.io/badge/Due-08%20Sept%202026-orange?style=for-the-badge)

*An enterprise-grade, memory-safe C++ task management engine demonstrating GoF structural and behavioral design patterns.*

---

</div>

## 👥 Team

| Name | Student Number |
| :--- | :--- |
| **Caleb Jennings** | `u25173805` |
| **Corné Myburgh** | `u25505204` |
| **Reneilwe Molopyane** | `u25161874` |

---

## 📌 Overview

TaskForge is a task-tracking and project management platform designed to organize, structure, and monitor features, bugs and changes. Modern software development requires implementations on different granularity. Some are individual bug fixes and others are features that require a number of tasks to be implemented in a complex hierarchy.

TaskForge solves this problem by providing a structural framework with the **Composite** design pattern. It encapsulates this structure with a snapshot **Iterator** design that solves the issue of exposing the internal structure of the Composite. 

* **Issues & IssueBuckets**: Single atomic tasks are called **`Issues`**. These can be grouped together inside an **`IssueBucket`**, which can store multiple issues as well as nested `IssueBucket` containers.
* **State Lifecycle**: Issues feature dynamic execution states, transitioning between **`Open`**, **`InProgress`**, or **`Resolved`**.
* **Decorators**: Each `Issue` or `IssueBucket` can be decorated dynamically with metadata such as the **`Languages`** used or the **`Priority`** of the task.
* **Traversals**: The list of issues can be iterated through via two methods:
  * Depth-first traversal over all issues.
  * Filtered traversal focusing specifically on high-priority issues.

---

## 🏗️ Design Pattern Architecture

| Pattern | Role & Responsibilities | Key Constraints |
| :--- | :--- | :--- |
| 🧩 **Composite** | Models recursive hierarchy of root, group, and leaf tasks. | $\ge 3$ nesting levels deep. |
| 🔄 **Iterator** | Encapsulates hierarchy traversal without exposing STL internals. | 2 orderings, 2 concurrent iterators. |
| 🚦 **State** | Manages valid lifecycle state transitions. | Graceful invalid transition handling. |
| 🎨 **Decorator** | Adds dynamic responsibilities (logging, priority, auditing). | Stackable, transparent execution. |

---

## ⚙️ Make Commands

* `make`: Compile and run program.
* `make clean`: Clean build artifacts and submission zip file.
* `make docker`: Create docker image that contains program executable.
* `make zip`: Create `submission.zip` containing flattened program files and additional resources for submission.

---

## 📁 Repository Map

```text
TaskForge/
├── 📂 include/              # Header declarations (.h / .hpp)
├── 📂 src/                  # C++ source implementations (.cpp)
├── 📂 docs/                 # Architectural diagrams
├── 🐳 Dockerfile            # Standardized toolchain container
├── ⚙️ Makefile              # Build orchestration
└── 📄 README.md             # Project documentation
