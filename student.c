#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int roll;
    char name[50];
    float marks;
    int deleted;
} Student;

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    Student s;

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    printf("Enter student name (no spaces): ");
    scanf("%49s", s.name);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    s.deleted = 0;
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);

    printf("Student added successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("students.dat", "rb");
    Student s;
    int found = 0;

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.deleted == 0) {
            printf("Roll: %d | Name: %s | Marks: %.2f\n",
                   s.roll, s.name, s.marks);
            found = 1;
        }
    }

    if (!found) {
        printf("No student records found.\n");
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("students.dat", "rb");
    Student s;
    int roll, found = 0;

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll == roll && s.deleted == 0) {
            printf("Student found!\n");
            printf("Roll: %d | Name: %s | Marks: %.2f\n",
                   s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(fp);
}

void updateStudent() {
    FILE *fp = fopen("students.dat", "rb+");
    Student s;
    int roll, found = 0;

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll == roll && s.deleted == 0) {
            printf("Enter new name (no spaces): ");
            scanf("%49s", s.name);

            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -(long)sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);

            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(fp);
}

void deleteStudent() {
    FILE *fp = fopen("students.dat", "rb+");
    Student s;
    int roll, found = 0;

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.roll == roll && s.deleted == 0) {
            s.deleted = 1;

            fseek(fp, -(long)sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);

            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}