//
// Explore the basics of variables, pointers, and memory addresses in C.
// Assign a value to a variable named fred, display it, and then manipulate
// it using a pointer. Display fred's address in both decimal and hexadecimal
// formats. Finally, modify fred's value using the pointer and display the changes.
//

#include <stdio.h>
#include <stdint.h>

// Function declaration
double getUserInput(double presetValue, const char* variableName);

int main() {
    double presetFred = 42.24; // Preset value for fred
    double fred; // Fred will now be set by user input or use the preset value
    double *fredsPointer; // A pointer to guide Fred through his adventures

    // Prompt user for fred's value or use the preset value
    fred = getUserInput(presetFred, "fred");

    fredsPointer = &fred; // The guide points to Fred, ready to navigate

    // Introduction to Fred's journey
    printf("\n🌟 Welcome to Fred's Numeric Journey! 🌟\n");
    printf("Today, we embark on an adventure with Fred, a curious number exploring the realms of C.\n");
    printf("🔮 Fred's current value: %.2f! But that's just the beginning...\n", fred);

    // Using the guide (pointer) to reflect on Fred's value
    printf("\n🧭 With the help of his guide, Fred's value is confirmed to be: %.2f\n", *fredsPointer);

    // Discovering Fred's location in the vast universe of memory
    printf("\n🌌 Discovering Fred's location in the universe of memory:\n");
    printf("In the realm of decimal addresses: %lu\n", (unsigned long)(&fred));
    printf("In the mystic land of hexadecimal: %p\n", &fred);

    // The guide's perspective on Fred's location
    printf("\n🗺️ From the guide's perspective:\n");
    printf("In decimals: %lu\n", (unsigned long)fredsPointer);
    printf("In hexadecimals: %p\n", fredsPointer);

    // A twist in the tale: Altering Fred's value through the guide
    printf("\n🌀 A twist in the tale! The guide alters Fred's essence...\n");
    *fredsPointer += 57.76;
    printf("Behold! Fred's new value, through the magic of pointers: %.2f\n", *fredsPointer);
    printf("And directly from Fred: %.2f\n", fred);

    // The end of this chapter in Fred's journey
    printf("\n🌠 And thus concludes a chapter of Fred's Numeric Journey. Until next time! 🌠\n");

    return 0;
}

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
