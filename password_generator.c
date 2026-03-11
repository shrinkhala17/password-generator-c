/*
 * =============================================
 *   Password Generator in C
 *   Beginner-friendly version
 * =============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* --- Character sets --- */
#define UPPERCASE  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE  "abcdefghijklmnopqrstuvwxyz"
#define DIGITS     "0123456789"
#define SPECIALS   "!@#$%^&*()-_=+[]{}|;:,.<>?"

/* Max password length we allow */
#define MAX_LENGTH 128

/* -----------------------------------------------
   Helper: ask a yes/no question, return 1 or 0
----------------------------------------------- */
int askYesNo(const char *question) {
    char answer;
    while (1) {
        printf("%s (y/n): ", question);
        scanf(" %c", &answer);
        if (answer == 'y' || answer == 'Y') return 1;
        if (answer == 'n' || answer == 'N') return 0;
        printf("  Please enter 'y' or 'n'.\n");
    }
}

/* -----------------------------------------------
   Main program
----------------------------------------------- */
int main() {

    /* Seed the random number generator once */
    srand((unsigned int)time(NULL));

    printf("========================================\n");
    printf("        🔐 C Password Generator\n");
    printf("========================================\n\n");

    /* ── Step 1: Get desired password length ── */
    int length = 0;
    while (length < 4 || length > MAX_LENGTH) {
        printf("Enter password length (4 – %d): ", MAX_LENGTH);
        scanf("%d", &length);
        if (length < 4)
            printf("  Too short! Minimum is 4 characters.\n");
        else if (length > MAX_LENGTH)
            printf("  Too long! Maximum is %d characters.\n", MAX_LENGTH);
    }

    /* ── Step 2: Choose character types ── */
    printf("\nWhich character types should be included?\n");
    int useUpper   = askYesNo("  Uppercase letters (A-Z)  ");
    int useLower   = askYesNo("  Lowercase letters (a-z)  ");
    int useDigits  = askYesNo("  Numbers          (0-9)  ");
    int useSpecial = askYesNo("  Special chars (!@#…)    ");

    /* Make sure at least one type was selected */
    if (!useUpper && !useLower && !useDigits && !useSpecial) {
        printf("\n  You must choose at least one character type.\n");
        printf("  Defaulting to lowercase letters.\n");
        useLower = 1;
    }

    /* ── Step 3: Build the combined character pool ── */
    char pool[200] = "";   /* holds all allowed characters */

    if (useUpper)   strcat(pool, UPPERCASE);
    if (useLower)   strcat(pool, LOWERCASE);
    if (useDigits)  strcat(pool, DIGITS);
    if (useSpecial) strcat(pool, SPECIALS);

    int poolSize = (int)strlen(pool);

    /* ── Step 4: Generate the password ── */
    char password[MAX_LENGTH + 1];  /* +1 for the null terminator */
    int  i;

    for (i = 0; i < length; i++) {
        int randomIndex = rand() % poolSize;
        password[i] = pool[randomIndex];
    }
    password[length] = '\0';  /* terminate the string */

    /* ── Step 5: Display the result ── */
    printf("\n========================================\n");
    printf("  Your generated password:\n\n");
    printf("  %s\n", password);
    printf("\n========================================\n");
    printf("  Length  : %d characters\n", length);
    printf("  Options : ");
    if (useUpper)   printf("Uppercase ");
    if (useLower)   printf("Lowercase ");
    if (useDigits)  printf("Numbers ");
    if (useSpecial) printf("Specials");
    printf("\n========================================\n\n");

    printf("Tip: Store your password in a secure password manager!\n\n");

    return 0;
}
