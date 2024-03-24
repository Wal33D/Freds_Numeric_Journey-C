#include "userInputHelpers.h"
#include <stdio.h>

// Function to get user input for a double value
double getUserInput(double presetValue, const char* variableName) {
    double value;
    char decision;

    printf("\nWould you like to use the preset value for %s [%.2f]? (Y/n): ", variableName, presetValue);
    decision = getchar();
    // Clear the input buffer
    while (getchar() != '\n');

    if (decision == 'n' || decision == 'N') {
        printf("Enter your value for %s: ", variableName);
        scanf("%lf", &value);
        // Clear the input buffer after reading
        while (getchar() != '\n');
        return value;
    }

    return presetValue;
}

// Function to get user input for how much to change the pointer value
double getPointerInput(double currentPointerValue) {
    double changeAmount;
    printf("Fred's guide can alter his essence. Current value is: %.2f\n", currentPointerValue);
    printf("How much would you like to add to Fred's value? ");
    scanf("%lf", &changeAmount);
    // Clear the input buffer after reading
    while (getchar() != '\n');
    return changeAmount;
}
