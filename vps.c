#include <stdio.h>
#include <string.h>

#define MAX_PARKING_SPOTS 20
#define MAX_VEHICLE_NUMBER_LENGTH 10
#define MAX_PASSWORD_LENGTH 20
#define BIKE 1
#define CAR 2
#define BIKE_RATE 30.00
#define CAR_RATE 100.00

struct Vehicle {
    int type;
    char number[MAX_VEHICLE_NUMBER_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    double amountPayable;
};

struct Vehicle parkingSpaces[MAX_PARKING_SPOTS];

void initializeParkingSystem() {
    for (int i = 0; i < MAX_PARKING_SPOTS; i++)
        parkingSpaces[i].type = 0;
}

void displayParkingStatus() {
    printf("\nParking Status:\n");
    for (int i = 0; i < MAX_PARKING_SPOTS; i++) {
        if (parkingSpaces[i].type == BIKE || parkingSpaces[i].type == CAR) {
            printf("Spot %d: %s parked (Number: %s, Amount Payable: %.2f)\n",
                   i + 1, (parkingSpaces[i].type == BIKE) ? "Bike" : "Car",
                   parkingSpaces[i].number, parkingSpaces[i].amountPayable);
        } else {
            printf("Spot %d: Available\n", i + 1);
        }
    }
}

int parkVehicle(int vehicleType) {
    char vehicleNumber[MAX_VEHICLE_NUMBER_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter the vehicle number: ");
    scanf("%s", vehicleNumber);

    printf("Set a password for the vehicle: ");
    scanf("%s", password);

    for (int i = 0; i < MAX_PARKING_SPOTS; i++) {
        if (parkingSpaces[i].type == 0) {
            parkingSpaces[i].type = vehicleType;
            strncpy(parkingSpaces[i].number, vehicleNumber, MAX_VEHICLE_NUMBER_LENGTH - 1);
            parkingSpaces[i].number[MAX_VEHICLE_NUMBER_LENGTH - 1] = '\0';
            strncpy(parkingSpaces[i].password, password, MAX_PASSWORD_LENGTH - 1);
            parkingSpaces[i].password[MAX_PASSWORD_LENGTH - 1] = '\0';
            parkingSpaces[i].amountPayable = (vehicleType == BIKE) ? BIKE_RATE : CAR_RATE;

            printf("%s parked at spot %d (Number: %s, Password: %s, Amount Payable: %.2f).\n",
                   (vehicleType == BIKE) ? "Bike" : "Car", i + 1,
                   parkingSpaces[i].number, parkingSpaces[i].password, parkingSpaces[i].amountPayable);
            return 1; // Successful parking
        }
    }

    printf("Sorry, all parking spots are occupied.\n");
    return 0; // Failed parking
}

int retrieveVehicle() {
    int spot;
    char enteredPassword[MAX_PASSWORD_LENGTH];

    printf("Enter the spot number to retrieve the vehicle: ");
    scanf("%d", &spot);

    if (spot >= 1 && spot <= MAX_PARKING_SPOTS) {
        if (parkingSpaces[spot - 1].type == BIKE || parkingSpaces[spot - 1].type == CAR) {
            printf("Enter the password for the vehicle: ");
            scanf("%s", enteredPassword);

            if (strcmp(enteredPassword, parkingSpaces[spot - 1].password) == 0) {
                printf("%s retrieved from spot %d (Number: %s, Amount Payable: %.2f).\n",
                        (parkingSpaces[spot - 1].type == BIKE) ? "Bike" : "Car", spot,
                        parkingSpaces[spot - 1].number, parkingSpaces[spot - 1].amountPayable);

                parkingSpaces[spot - 1].type = 0;
                parkingSpaces[spot - 1].number[0] = parkingSpaces[spot - 1].password[0] = '\0';
                parkingSpaces[spot - 1].amountPayable = 0;
                return 1;
            } else {
                printf("Incorrect password. Vehicle retrieval failed.\n");
                return 0;
            }
        } else {
            printf("No vehicle found at spot %d.\n", spot);
            return 0; 
        }
    } else {
        printf("Invalid spot number. Please enter a valid spot number.\n");
        return 0; 
    }
}

int main() {
    int choice;

    initializeParkingSystem();

    do {
        printf("\nParking System Menu\n1. Display Parking Status\n2. Park Bike\n3. Park Car\n4. Retrieve Vehicle\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayParkingStatus(); break;
            case 2: parkVehicle
                 (BIKE); break;
            case 3: parkVehicle(CAR); break;
            case 4: retrieveVehicle(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
