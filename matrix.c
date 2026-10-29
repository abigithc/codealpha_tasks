#include <stdio.h>

#define MAX 10

void inputMatrix(int a[MAX][MAX], int r, int c) {
for (int i = 0; i < r; i++) {
for (int j = 0; j < c; j++) {
scanf("%d", &a[i][j]);
}
}
}

void displayMatrix(int a[MAX][MAX], int r, int c) {
for (int i = 0; i < r; i++) {
for (int j = 0; j < c; j++) {
printf("%d ", a[i][j]);
}
printf("\n");
}
}

int main() {
int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
int r1, c1, r2, c2, choice;

printf("1. Matrix Addition\n");
printf("2. Matrix Multiplication\n");
printf("3. Matrix Transpose\n");
printf("Enter choice: ");
scanf("%d", &choice);

if (choice == 1) {
    printf("Enter rows and columns: ");
    scanf("%d %d", &r1, &c1);

    if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
        printf("Invalid matrix size!\n");
        return 0;
    }

    printf("Enter first matrix elements:\n");
    inputMatrix(a, r1, c1);

    printf("Enter second matrix elements:\n");
    inputMatrix(b, r1, c1);

    printf("Addition result:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            result[i][j] = a[i][j] + b[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
else if (choice == 2) {
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX ||
        r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX) {
        printf("Invalid matrix size!\n");
        return 0;
    }

    if (c1 != r2) {
        printf("Multiplication not possible!\n");
        return 0;
    }

    printf("Enter first matrix elements:\n");
    inputMatrix(a, r1, c1);

    printf("Enter second matrix elements:\n");
    inputMatrix(b, r2, c2);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Multiplication result:\n");
    displayMatrix(result, r1, c2);
}
else if (choice == 3) {
    printf("Enter rows and columns: ");
    scanf("%d %d", &r1, &c1);

    if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
        printf("Invalid matrix size!\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    inputMatrix(a, r1, c1);

    printf("Transpose result:\n");
    for (int j = 0; j < c1; j++) {
        for (int i = 0; i < r1; i++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
else {
    printf("Invalid choice!\n");
}

return 0;

}