#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define TOTAL_SEMESTERS 8

typedef struct {
    long long sapId;
    int rollNumber;
    char name[50];
    char phone[20];
    char email[60];
    int year;
    int currentSemester;
    float sgpa[TOTAL_SEMESTERS];
} Student;

int findStudentIndex(Student students[], int count, long long sapId);
float calculateCGPA(Student student);
void displayStudent(Student student);
void addStudent(Student students[], int *count);
void searchStudent(Student students[], int count);
void displayAllStudents(Student students[], int count);
void calculateStudentCGPA(Student students[], int count);
void averageCGPAByYear(Student students[], int count);
void deleteStudent(Student students[], int *count);
void sortBySapId(Student students[], int count);
void sortByName(Student students[], int count);
void academicAdvisor(float cgpa);
void advisorForStudent(Student students[], int count);

int main() {
    Student students[MAX_STUDENTS] = {
        {500100001, 101, "Aarav Sharma", "9876500001", "aarav@example.com", 1, 2, {9.4, 9.0, -1, -1, -1, -1, -1, -1}},
        {500100002, 102, "Diya Verma", "9876500002", "diya@example.com", 2, 4, {8.0, 8.2, 8.1, 8.1, -1, -1, -1, -1}},
        {500100003, 103, "Kabir Singh", "9876500003", "kabir@example.com", 2, 3, {6.5, 6.9, 6.7, -1, -1, -1, -1, -1}},
        {500100004, 104, "Meera Joshi", "9876500004", "meera@example.com", 3, 5, {5.4, 5.8, 5.6, 5.9, 5.3, -1, -1, -1}},
        {500100005, 105, "Rohan Gupta", "9876500005", "rohan@example.com", 4, 8, {7.8, 8.0, 8.2, 8.1, 7.9, 8.3, 8.0, 8.1}}
    };
    int count = 5;
    int choice;

    do {
        printf("\n========================================\n");
        printf(" STUDENT RECORD & RESULT MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Calculate Student CGPA\n");
        printf("5. Display Average CGPA by Year\n");
        printf("6. Delete Student\n");
        printf("7. Display Students Sorted by SAP ID\n");
        printf("8. Display Students Sorted by Name\n");
        printf("9. AI-Assisted Academic Advisor\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: searchStudent(students, count); break;
            case 3: displayAllStudents(students, count); break;
            case 4: calculateStudentCGPA(students, count); break;
            case 5: averageCGPAByYear(students, count); break;
            case 6: deleteStudent(students, &count); break;
            case 7: sortBySapId(students, count); break;
            case 8: sortByName(students, count); break;
            case 9: advisorForStudent(students, count); break;
            case 0: printf("Exiting program. Thank you!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

int findStudentIndex(Student students[], int count, long long sapId) {
    int i;
    for (i = 0; i < count; i++) {
        if (students[i].sapId == sapId) return i;
    }
    return -1;
}

float calculateCGPA(Student student) {
    float sum = 0.0f;
    int available = 0;
    int i;
    for (i = 0; i < TOTAL_SEMESTERS; i++) {
        if (student.sgpa[i] >= 0.0f && student.sgpa[i] <= 10.0f) {
            sum += student.sgpa[i];
            available++;
        }
    }
    if (available == 0) return 0.0f;
    return sum / available;
}

void displayStudent(Student student) {
    int i;
    printf("\nSAP ID          : %lld\n", student.sapId);
    printf("Roll Number     : %d\n", student.rollNumber);
    printf("Name            : %s\n", student.name);
    printf("Phone Number    : %s\n", student.phone);
    printf("Email ID        : %s\n", student.email);
    printf("Year            : %d\n", student.year);
    printf("Current Semester: %d\n", student.currentSemester);
    printf("SGPA            : ");
    for (i = 0; i < TOTAL_SEMESTERS; i++) {
        if (student.sgpa[i] >= 0.0f) printf("Sem %d = %.2f  ", i + 1, student.sgpa[i]);
        else printf("Sem %d = N/A  ", i + 1);
    }
    printf("\nCGPA            : %.2f\n", calculateCGPA(student));
}

void addStudent(Student students[], int *count) {
    Student s;
    int i;
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter SAP ID: ");
    scanf("%lld", &s.sapId);
    if (findStudentIndex(students, *count, s.sapId) != -1) {
        printf("A student with this SAP ID already exists.\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNumber);
    printf("Enter Name: ");
    scanf(" %49[^\n]", s.name);
    printf("Enter Phone Number: ");
    scanf("%19s", s.phone);
    printf("Enter Email ID: ");
    scanf("%59s", s.email);

    do {
        printf("Enter Year (1-4): ");
        scanf("%d", &s.year);
        if (s.year < 1 || s.year > 4) printf("Invalid year. Enter 1 to 4.\n");
    } while (s.year < 1 || s.year > 4);

    do {
        printf("Enter Current Semester (1-8): ");
        scanf("%d", &s.currentSemester);
        if (s.currentSemester < 1 || s.currentSemester > 8) printf("Invalid semester. Enter 1 to 8.\n");
    } while (s.currentSemester < 1 || s.currentSemester > 8);

    for (i = 0; i < TOTAL_SEMESTERS; i++) s.sgpa[i] = -1.0f;

    printf("Enter SGPA for available semesters.\n");
    for (i = 0; i < s.currentSemester; i++) {
        do {
            printf("Semester %d SGPA (0-10): ", i + 1);
            scanf("%f", &s.sgpa[i]);
            if (s.sgpa[i] < 0.0f || s.sgpa[i] > 10.0f) printf("Invalid SGPA. Enter a value from 0 to 10.\n");
        } while (s.sgpa[i] < 0.0f || s.sgpa[i] > 10.0f);
    }

    students[*count] = s;
    (*count)++;
    printf("Student added successfully.\n");
}

void searchStudent(Student students[], int count) {
    long long sapId;
    int index;
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    printf("Enter SAP ID to search: ");
    scanf("%lld", &sapId);
    index = findStudentIndex(students, count, sapId);
    if (index == -1) printf("Student not found.\n");
    else displayStudent(students[index]);
}

void displayAllStudents(Student students[], int count) {
    int i;
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    for (i = 0; i < count; i++) {
        printf("\n----------- Student %d -----------\n", i + 1);
        displayStudent(students[i]);
    }
}

void calculateStudentCGPA(Student students[], int count) {
    long long sapId;
    int index;
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    printf("Enter SAP ID: ");
    scanf("%lld", &sapId);
    index = findStudentIndex(students, count, sapId);
    if (index == -1) printf("Student not found.\n");
    else printf("CGPA of %s = %.2f\n", students[index].name, calculateCGPA(students[index]));
}

void averageCGPAByYear(Student students[], int count) {
    int year, i, studentsInYear;
    float total;
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    for (year = 1; year <= 4; year++) {
        total = 0.0f;
        studentsInYear = 0;
        for (i = 0; i < count; i++) {
            if (students[i].year == year) {
                total += calculateCGPA(students[i]);
                studentsInYear++;
            }
        }
        if (studentsInYear == 0) printf("%d Year: No students available.\n", year);
        else printf("%d Year Average CGPA = %.2f\n", year, total / studentsInYear);
    }
}

void deleteStudent(Student students[], int *count) {
    long long sapId;
    int index, i;
    if (*count == 0) {
        printf("No student records available.\n");
        return;
    }
    printf("Enter SAP ID to delete: ");
    scanf("%lld", &sapId);
    index = findStudentIndex(students, *count, sapId);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }
    for (i = index; i < *count - 1; i++) students[i] = students[i + 1];
    (*count)--;
    printf("Student deleted successfully.\n");
}

void sortBySapId(Student students[], int count) {
    Student tempStudents[MAX_STUDENTS], temp;
    int i, j;
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    for (i = 0; i < count; i++) tempStudents[i] = students[i];
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (tempStudents[j].sapId > tempStudents[j + 1].sapId) {
                temp = tempStudents[j];
                tempStudents[j] = tempStudents[j + 1];
                tempStudents[j + 1] = temp;
            }
        }
    }
    printf("\nStudents sorted by SAP ID:\n");
    displayAllStudents(tempStudents, count);
}

void sortByName(Student students[], int count) {
    Student tempStudents[MAX_STUDENTS], temp;
    int i, j;
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    for (i = 0; i < count; i++) tempStudents[i] = students[i];
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(tempStudents[j].name, tempStudents[j + 1].name) > 0) {
                temp = tempStudents[j];
                tempStudents[j] = tempStudents[j + 1];
                tempStudents[j + 1] = temp;
            }
        }
    }
    printf("\nStudents sorted by Name:\n");
    displayAllStudents(tempStudents, count);
}

void academicAdvisor(float cgpa) {
    if (cgpa >= 9.0f) {
        printf("Category: Excellent Performance\n");
        printf("Recommendation: Excellent performance - maintain your current study pattern and continue challenging yourself.\n");
    } else if (cgpa >= 7.5f) {
        printf("Category: Good Performance\n");
        printf("Recommendation: Good performance - stay consistent and work on subjects where your SGPA is comparatively lower.\n");
    } else if (cgpa >= 6.0f) {
        printf("Category: Needs Improvement\n");
        printf("Recommendation: Needs improvement - focus more on subjects with lower performance and maintain a regular study schedule.\n");
    } else {
        printf("Category: Requires Immediate Attention\n");
        printf("Recommendation: Requires immediate attention - revise fundamental concepts, practice regularly, and seek help in difficult subjects.\n");
    }
}

void advisorForStudent(Student students[], int count) {
    long long sapId;
    int index;
    float cgpa;
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    printf("Enter SAP ID: ");
    scanf("%lld", &sapId);
    index = findStudentIndex(students, count, sapId);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }
    cgpa = calculateCGPA(students[index]);
    printf("Student: %s\n", students[index].name);
    printf("CGPA: %.2f\n", cgpa);
    academicAdvisor(cgpa);
}
