#include <iostream>
#include <cstring>
using namespace std;

// String concatenation
void concatStr(char a[], char b[]) {
    int i = 0, j = 0;
    while (a[i] != '\0') i++;
    while (b[j] != '\0') {
        a[i] = b[j];
        i++; j++;
    }
    a[i] = '\0';
}

// String reversal
void reverseStr(char s[]) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }
}

// Delete vowels
void deleteVowels(char s[]) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        char c = s[i];
        if (c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!='A'&&c!='E'&&c!='I'&&c!='O'&&c!='U')
            s[j++] = c;
        i++;
    }
    s[j] = '\0';
}

// Sort strings
void sortStrings(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char temp[100];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

// Convert to lowercase
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

int main() {
    // Test concatenation
    char s1[200] = "Hello";
    char s2[100] = "World";
    concatStr(s1, s2);
    cout << "Concatenation: " << s1 << endl;
    
    // Test reversal
    char s3[100] = "OpenAI";
    reverseStr(s3);
    cout << "Reversed: " << s3 << endl;
    
    // Test vowel deletion
    char s4[100] = "Beautiful";
    deleteVowels(s4);
    cout << "Without vowels: " << s4 << endl;
    
    // Test string sorting
    char strs[3][100] = {"banana", "apple", "cherry"};
    sortStrings(strs, 3);
    cout << "Sorted strings: ";
    for (int i = 0; i < 3; i++) cout << strs[i] << " ";
    cout << endl;
    
    // Test lowercase conversion
    cout << "Lowercase of G: " << toLowerCase('G') << endl;
    
    return 0;
}