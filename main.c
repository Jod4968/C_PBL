#include <stdio.h>
#include <string.h>

struct Leave {
    int id;
    char name[50];
    int days;
    char status[20];
};


// View Leaves
void viewLeaves() {
    FILE *fp = fopen("leave.txt", "r");
    struct Leave l;

    printf("\n--- Leave Records ---\n");

    while (fscanf(fp, "%d %s %d %s", &l.id, l.name, &l.days, l.status) != EOF) {
        printf("ID: %d | Name: %s | Days: %d | Status: %s\n",
               l.id, l.name, l.days, l.status);
    }

    fclose(fp);
}

// Main Menu
int main() {
    int choice;

    while (1) {
        printf("\n===== Leave Management System =====\n");
        printf("1. Apply Leave\n");
        printf("2. View Leaves\n");
        printf("3. Approve/Reject Leave\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: applyLeave(); break;
            case 2: viewLeaves(); break;
            case 3: updateLeave(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}