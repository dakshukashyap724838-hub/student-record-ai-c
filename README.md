# AI-Assisted Student Record and Result Management System

## Introduction
This is a Semester-I Programming in C project. It is a console-based, menu-driven program for storing student details, viewing results, calculating CGPA, sorting records, deleting records, and giving simple CGPA-based academic advice.

## Objective
The objective is to practice basic C concepts through a useful student record system without databases, GUI frameworks, or external AI APIs.

## Features
- Starts with 5 fictional student records
- Add a student with duplicate SAP ID prevention
- Search a student by SAP ID
- Display all student records
- Calculate CGPA from available SGPA values only
- Display average CGPA for each year
- Delete a student and shift remaining array elements
- Bubble sort students by SAP ID
- Bubble sort students alphabetically by name using `strcmp()`
- Local AI-Assisted Academic Advisor using simple `if-else`
- Basic validation for year, semester, and SGPA

## C Concepts Used
Structures, arrays, functions, loops, if-else, switch-case, strings, `strcmp()`, bubble sort, standard input/output, and a do-while menu loop.

## Project Structure
```text
student-record-ai-c/
├── SAP_ID.c
├── README.md
├── AI_USAGE_LOG.md
└── tests/
    ├── sample_input.txt
    └── sample_output.txt
```

> **Before submission:** Rename `SAP_ID.c` to your actual SAP ID, for example `500123456.c`. Also replace the author placeholders below.

## How to Compile
With GCC:
```bash
gcc SAP_ID.c -o student_record
```
If you rename the source file, use the new filename in the command.

## How to Run
Windows:
```text
student_record.exe
```
Linux/macOS:
```bash
./student_record
```

## Menu Options
1. Add Student
2. Search Student
3. Display All Students
4. Calculate Student CGPA
5. Display Average CGPA by Year
6. Delete Student
7. Display Students Sorted by SAP ID
8. Display Students Sorted by Name
9. AI-Assisted Academic Advisor
0. Exit

## CGPA Calculation
The program stores 8 SGPA positions. An unavailable semester is stored as `-1`. The CGPA function adds only valid/available SGPA values and divides the sum by the number of available SGPAs.

Example: SGPA values 8.0, 8.2, 8.1, 8.1 give:
`CGPA = (8.0 + 8.2 + 8.1 + 8.1) / 4 = 8.10`

## AI-Assisted Academic Advisor
This feature is called AI-Assisted for the assignment, but it does **not** call a real AI service. The C program calculates the student's CGPA and selects one of four recommendations using simple `if-else` conditions:
- CGPA >= 9.0: Excellent Performance
- CGPA >= 7.5 and < 9.0: Good Performance
- CGPA >= 6.0 and < 7.5: Needs Improvement
- CGPA < 6.0: Requires Immediate Attention

This makes the feature easy to understand and explain in a viva.

## Sample Usage
Choose option `4`, enter SAP ID `500100001`, and the program displays CGPA `9.20`. Choose option `9` with the same SAP ID to receive the Excellent Performance recommendation. See the `tests` folder for a longer demonstration.

## Limitations
- Data is stored only while the program is running; it is not saved permanently.
- Maximum records are limited to 100.
- Validation is intentionally basic for a first-semester project.
- The academic advisor is rule-based and is not real artificial intelligence.

## Author
- Name: **YOUR NAME**
- SAP ID: **YOUR SAP ID**
- Roll Number: **YOUR ROLL NUMBER**

## Academic Disclaimer
This project is intended for academic learning. The student should review, understand, compile, test, and be able to explain the submitted code. Any AI-assisted material should be disclosed according to university rules.

# VIVA PREPARATION

## Core Ideas
**What is a structure?** A structure is a user-defined data type that groups different types of related data under one name. Here, `Student` keeps SAP ID, roll number, name, contact details, year, semester, and SGPA values together.

**Why an array of structures?** One `Student` structure stores one student. An array such as `students[]` stores many students in the same program.

**What does each function do?** `addStudent()` adds a record; `searchStudent()` finds by SAP ID; `displayAllStudents()` prints records; `calculateCGPA()` averages available SGPAs; `calculateStudentCGPA()` shows one student's CGPA; `averageCGPAByYear()` calculates year-wise averages; `deleteStudent()` removes a record; `sortBySapId()` and `sortByName()` display sorted copies; `academicAdvisor()` prints advice; `advisorForStudent()` finds a student and calls the advisor.

**How is CGPA calculated?** Add all available SGPA values and divide by how many SGPA values are available.

**Why only available SGPAs?** Future semesters have not been completed, so including them would make the average incorrect.

**How does deletion work?** After finding the record's array index, every later element is copied one position to the left and the student count is reduced by one.

**How does bubble sort work?** It repeatedly compares neighboring records and swaps them when they are in the wrong order. Larger values gradually move toward the end.

**How is `strcmp()` used?** `strcmp(name1, name2)` returns a value greater than zero when `name1` should come after `name2`, so the two records are swapped.

**How does the AI-Assisted Advisor work?** It receives CGPA and checks four ranges using `if-else`, then prints a fixed recommendation.

**Why is it not actually calling AI?** There is no API, internet request, or AI library. It is a local rule-based feature.

**What is switch-case?** It selects one block of code based on the user's menu choice.

**Why use do-while for the menu?** It runs the menu at least once and repeats it until the user selects 0.

**What is Git?** Git is a version-control system that records changes to project files.

**What is GitHub?** GitHub is an online platform for storing and sharing Git repositories.

**What is a commit?** A commit is a saved checkpoint of meaningful changes in Git.

**What is a GitHub Issue?** An Issue is a task, bug, or feature discussion tracked inside a GitHub repository.

## Likely Viva Questions and Short Answers
1. **Why did you use `typedef struct`?** To create a simple `Student` type containing all fields of one student.
2. **Why is `sgpa` an array of size 8?** A B.Tech student can have 8 semesters.
3. **What does `-1` mean in the SGPA array?** That semester's SGPA is unavailable.
4. **How do you prevent duplicate SAP IDs?** I search the existing array before adding the new student.
5. **What happens if SAP ID is not found?** The search function returns `-1` and the program prints `Student not found`.
6. **Why use `long long` for SAP ID?** It safely stores large numeric IDs.
7. **How do you avoid division by zero in CGPA?** If no SGPA is available, `calculateCGPA()` returns `0.0`.
8. **Why use functions?** They divide the program into small, reusable, easy-to-understand tasks.
9. **Why use a temporary array for sorting?** So displaying sorted data does not change the original record order.
10. **Which sorting algorithm is used?** Bubble sort.
11. **How are names compared?** With `strcmp()` from `string.h`.
12. **Why include `string.h`?** It is required for `strcmp()`.
13. **How is a student deleted?** Find the index, shift later records left, and reduce `count`.
14. **What does `count` represent?** The number of student records currently stored.
15. **What validation is included?** SGPA 0-10, year 1-4, semester 1-8, duplicate SAP IDs, empty-list checks, and not-found checks.
16. **Is the advisor real AI?** No. It is a simple local rule-based advisor using CGPA ranges.
17. **What happens for CGPA 7.5?** It falls in Good Performance.
18. **Why use `do-while` instead of only `while`?** The menu must be shown at least once.
19. **What is the maximum number of students?** 100, because `MAX_STUDENTS` is 100.
20. **Does the program save data after exit?** No. This version uses an in-memory array only.

## Five Small Changes an Examiner Might Ask
1. **Change maximum students to 50:** change `#define MAX_STUDENTS 100` to `50`.
2. **Change Excellent threshold to 8.5:** in `academicAdvisor()`, change `cgpa >= 9.0f` to `cgpa >= 8.5f` and adjust the next range if required.
3. **Sort SAP IDs in descending order:** change `>` to `<` in the comparison inside `sortBySapId()`.
4. **Search by roll number instead:** make a loop similar to `findStudentIndex()` but compare `rollNumber`.
5. **Display only name and CGPA:** make a small loop and print `students[i].name` with `calculateCGPA(students[i])`.
