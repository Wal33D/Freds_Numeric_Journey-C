/*
 //Interactive Numeric Journey in C
 //
 //This program embarks on an interactive exploration of the basics of variables, 
 //pointers, and memory addresses in C. It starts by introducing a variable named 
 //fred and allows the user to assign a value to it. The program displays fred's 
 //value and address in both decimal and hexadecimal formats. It incorporates user 
 //input to manipulate fred's value through a pointer, offering an engaging and 
 //educational exploration of how pointers can alter the state of a variable.
 //
 //User interaction is further enhanced by allowing decisions on the initial value 
 //of fred and how much fred's value should be altered through the pointer, making 
 //it not just a demonstration, but an interactive journey through the concepts 
 //of variables and pointers in C.
 */

#include <stdio.h>
#include <stdint.h>
#include "userInputHelpers.h" 

// Function declaration
double getUserInput(double presetValue, const char* variableName);
double getPointerInput(double currentPointerValue);

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

    // A twist in the tale: User decides how to alter Fred's value through the guide
    printf("\n🌀 A twist in the tale! You decide how the guide alters Fred's essence...\n");
    double changeAmount = getPointerInput(*fredsPointer);
    *fredsPointer += changeAmount;
    printf("Behold! Fred's new value, through the magic of pointers: %.2f\n", *fredsPointer);
    printf("And directly from Fred: %.2f\n", fred);

    // The end of this chapter in Fred's journey
    printf("\n🌠 And thus concludes a chapter of Fred's Numeric Journey. Until next time! 🌠\n");

    return 0;
}
