
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int testPalindrome(char data[], int ters, size_t duz);

int main(void) {
    char data[] = "ana aka ana";
    size_t duz = 0;
    int ters = sizeof(data) - 2;
    int kelimePalindromu = testPalindrome(data, ters, duz);
    printf("Kelime palindrome%s.\n", kelimePalindromu ? "dir":" degildir");


    return 0;
}

int testPalindrome(char data[], int ters, size_t duz) {

    if(duz == strlen(data) / 2 ){
        return 1;
    }


    if(data[duz] == data[ters]){

        return (testPalindrome(data, ters - 1, duz + 1));

    }


    return 0;
}
