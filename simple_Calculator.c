#include <stdio.h>
#include <math.h>

double division(double, double);
int modulus(int, int);

void print_menu();

int main() {
    int choice;
    double first, second, result;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        if (choice == 7) {
            break;
        }

        if (choice < 1 || choice > 7) {
            fprintf(stderr, "Invalid Menu Choice. Please try again.\n");
            continue;
        }

        printf("Please enter the first number: ");
        scanf("%lf", &first);
        printf("Now, please enter the second number: ");
        scanf("%lf", &second);

        switch (choice) {
            case 1: // ADD
                result = first + second;
                printf("\nResult of addition: %.2f\n", result);
                break;
            case 2: // SUBTRACT
                result = first - second;
                printf("\nResult of subtraction: %.2f\n", result);
                break;
            case 3: // MULTIPLY
                result = first * second;
                printf("\nResult of multiplication: %.2f\n", result);
                break;
            case 4: // DIVIDE
                result = division(first, second);
                if (!isnan(result)) {
                    printf("\nResult of division: %.2f\n", result);
                }
                break;
            case 5: // MODULUS
                if ((int)first != first || (int)second != second) {
                    fprintf(stderr, "Invalid input for modulus. Both numbers must be integers.\n");
                } else {
                    int mod_result = modulus((int)first, (int)second);
                    printf("\nResult of modulus: %d\n", mod_result);
                }
                break;
            case 6: // POWER
                result = pow(first, second);
                printf("\nResult of power: %.2f\n", result);
                break;
        }
    }

    return 0;
}

double division(double a, double b) {
    if (b == 0) {
        fprintf(stderr, "Invalid Argument for division: division by zero.\n");
        return NAN;
    } else {
        return a / b;
    }
}

int modulus(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Invalid Argument for modulus: modulus by zero.\n");
        return 0;
    } else {
        return a % b;
    }
}

void print_menu() {
    printf("\n\n---------------------------------------------");
    printf("\nWELCOME! THIS IS A SIMPLE CALCULATOR");
    printf("\nChoose one of the following options:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}
