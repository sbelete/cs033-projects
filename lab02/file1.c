#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Hint: This program is an example of why style and syntax both matter.
 */

/*
 * Searches for an occurance of c within s. replaces the first occurance with a
 * space. returns 1 if found, 0 otherwise.
 */
int function1(char c, char *s) {
    int i;

    for (i = 0; s[i] != '\0'; i++){ // Make sure these are null
        if (c == s[i]) { // Brackets were missing here and ==  not =
            s[i] = ' ';  
            return 1;
        } // Brackets were missing here also
    } // Not an error but just good practice
    return 0;
}

/*
 * Checks if name is an anagram of name2.
 */
int check(char *name, char *name2) {
    char *c;

    for (c = name; *c != '\0'; ++c){ // Make sure these are null
        if (function1(*c, name2) == 0){ 
            return 0;
        }
    }

    for (c = name2; *c != '\0'; ++c){  // Make sure these are null
        if (*c != ' ') {
            return 0;
        }
    }

    return 1;
}


/*
 * Returns an anagram of val.
 *
 * Hint: Why does this only seem to segfault every so often, when you follow
 * its execution in gdb?
 */
char *perm(char *str, int len) {
    int idx;
    char c = str[0];

    if (len == 0) {
        return str;
    } else {
        idx = rand() % len; // Rand is finding numbers outsided its range

        str[0] = str[idx]; // Swap the order between this
        str[idx] = c;      // And this

        return perm(str+ 1, len - 1)- 1;
    }
}

/* 
 * Switches between a few possible commands:
 * 0: checks if the next two arguments are anagrams of each other.
 * 1: print an anagram of the next argument.
 *
 * Hint: Why is it always a good idea to check the value of argc when parsing
 * command line arguments?
 */
int main(int argc, char **argv) {
 
    if (argc < 3) { // Check to see how many arguments meets minimum
        printf("anagram: a utility for generating and checking anagrams\n");
        printf("Usage:\n");
        printf("    ./anagram 0 cs033 03cs3 (Check if two strings are anagrams \
            of each other.\n");
        printf("    ./anagram 1 cs033 (Print the anagram of the following \
            argument.\n");

        return 1; // File didn't work
    }

                                // This should be after knowledge that there is enough arguments
    char *name = argv[3];
    char *type = argv[2];
    int cmd = atoi(argv[1]);

    if (cmd == 0)
        printf("%d\n", check(name, type));
    if (cmd == 1)
        printf("%s\n", perm(type, strlen(type)));

    return 0;
}
