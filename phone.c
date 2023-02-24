#include <stdio.h>
#include <string.h>

// Define a struct to hold contact information
struct Contact {
    char name[50];
    char phone[20];
};

int main() {
    // Initialize an array to hold up to 10 contacts
    struct Contact contacts[10];
    int numContacts = 0;

    // Show menu options until user chooses to exit
    while (1) {
        printf("\n");
        printf("Phone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Add a new contact
                if (numContacts >= 10) {
                    printf("Error: phone book is full.\n");
                } else {
                    struct Contact contact;
                    printf("Enter name: ");
                    scanf("%s", contact.name);
                    printf("Enter phone number: ");
                    scanf("%s", contact.phone);
                    contacts[numContacts++] = contact;
                }
                break;
            }
            case 2: {
                // Display all contacts
                printf("All Contacts:\n");
                for (int i = 0; i < numContacts; i++) {
                    printf("%s - %s\n", contacts[i].name, contacts[i].phone);
                }
                break;
            }
            case 3: {
                // Search for a contact
                printf("Enter name to search: ");
                char searchName[50];
                scanf("%s", searchName);
                int found = 0;
                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(searchName, contacts[i].name) == 0) {
                        printf("%s - %s\n", contacts[i].name, contacts[i].phone);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 4: {
                // Exit the program
                printf("Exiting phone book.\n");
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }
}
