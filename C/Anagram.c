#include <stdio.h>
#include <string.h>

int check_anagram(char word1[], char word2[])
{
    int n1 = strlen(word1);
    int n2 = strlen(word2);

    //Strings of different length cannot be anagram
    if (n1 != n2)
        return -1;

    //Sorting both strings
    int i, j;
    char temp;
    for (i = 0; i < n1 - 1; i++)
    {
        for (j = i + 1; j < n1; j++)
        {
            if (word1[i] > word1[j])
            {
                temp = word1[i];
                word1[i] = word1[j];
                word1[j] = temp;
            }
            if (word2[i] > word2[j])
            {
                temp = word2[i];
                word2[i] = word2[j];
                word2[j] = temp;
            }
        }
    }
    //Check for anagram
    if (strcmp(word1, word2) == 0)
        return 0;
    else
        return -1;
}
int main()
{
    char s1[] = "earth";
    char s2[] = "heart";

    if (check_anagram(s1, s2) == 0)
        printf("Strings are Anagrams!\n");
    else
        printf("Strings are not Anagrams! \n");
    return 0;
}
