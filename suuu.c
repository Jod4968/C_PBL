// Approve / Reject Leave
void updateLeave() {
    FILE *fp = fopen("leave.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    struct Leave l;
    int id, found = 0, choice;

    printf("\nEnter ID to update: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %d %s", &l.id, l.name, &l.days, l.status) != EOF) {

        if (l.id == id) {
            found = 1;

            printf("\n1. Approve\n2. Reject\nChoose: ");
            scanf("%d", &choice);

            if (choice == 1)
                strcpy(l.status, "Approved");
            else
                strcpy(l.status, "Rejected");
        }

        fprintf(temp, "%d %s %d %s\n", l.id, l.name, l.days, l.status);
    }

    fclose(fp);
    fclose(temp);

    remove("leave.txt");
    rename("temp.txt", "leave.txt");

    if (found)
        printf("✅ Status Updated Successfully!\n");
    else
        printf("❌ Record Not Found!\n");
}
