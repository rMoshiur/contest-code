#include <stdio.h>
#include <string.h>

// highest number of word dictionary can hold,  highest legth of a word, highest legth of details
const int limit = 10000, word_length = 30, details_length = 400;


struct trie
{
    int index;  // what is index of details of the word in the dictionary
    int next[26]; // next node in trie
};
trie database[limit];  // trie/prefix tree container
char word[limit][word_length], details[limit][details_length];
int num_of_element, cur; // number of current words in the dictionary, number of node used for trie


// this function initialize a node in trie ( think of it as a black box, no need to explicitly use this functoin )
void init( int cn )
{
    database[cn].index = -1;
    for( int i = 0; i < 26; i++ )
        database[cn].next[i] = -1;
}

//convert a string to only lower case letters
void to_lower( char str[] )
{
    int i = 0;
    while( str[i] )
    {
        if( str[i] >= 'A' && str[i] <= 'Z' )
            str[i] += 32;
        i++;
    }
}

// this finction add new word in the dictionary, complexity O(str_length) ... no need to explicitly use this functoin
void add_word( char str[], int position_in_array )
{
    int i = 0, node = 0;
    to_lower( str );
    while( str[i] )
    {
        int d = str[i] - 'a';
        if( database[node].next[d] == -1 )
        {
            init(cur);
            node = database[node].next[d] = cur++;
        }
        else
            node = database[node].next[d];
        i++;
    }
    database[node].index = position_in_array;
}

void initialize_trie()
{
    cur = 0;
    init(cur);
    num_of_element = 0;
    FILE *input_word = fopen( "word.txt", "r" );
    FILE *input_details = fopen( "details.txt", "r" );
    char str1[word_length], str2[details_length];
    while( fgets( str1, word_length, input_word ) != NULL && fgets( str2, details_length, input_details ) != NULL )
    {
        str1[strlen(str1)-1] = '\0'; //because there in a new line character before '\0'
        str2[strlen(str2)-1] = '\0'; //because there in a new line character before '\0'
        strcpy( word[num_of_element], str1 );
        strcpy( details[num_of_element], str2 );
        add_word( str1, num_of_element++ );
    }
    fclose(input_word);
    fclose(input_details);
}

// this finction add new word given by the user in the dictionary

void update( char str1[], char str2[] ) //new word, its details
{
    strcpy( word[num_of_element], str1 );
    strcpy( details[num_of_element], str2 );
    add_word( str1, num_of_element++ );
}

// this finction return the index of word_details in the details array, complexity O(str_length)
int query( char str[] ) //word search
{
    int i = 0, node = 0;
    to_lower( str );
    while( str[i] )
    {
        int d = str[i] - 'a';
        if( database[node].next[d] == -1 )
            return -1;
        else
            node = database[node].next[d];
        i++;
    }
    return database[node].index;
}

//closes the dictionary and save all the word in a file
void close_dictionary()
{
    FILE *output_word = fopen( "word.txt", "w" );
    FILE *output_details = fopen( "details.txt", "w" );
    for( int i = 0; i < num_of_element; i++ )
    {
        fputs( word[i], output_word );
        fputs( details[i], output_details );
    }
}

int main()
{
    initialize_trie();
    //test trie start
    printf("%d\n", query( "eqerqr" ));
    update( "boobs", "booooooobieeees" );
    printf("%d\n", query( "boobs" ));
    printf("%d\n", query( "boob" ));
    int a = query( "boobs" );
    if( a != -1 )
        printf("boobs -> %s \n", details[a] );
    else
        printf("No such word exist");
    //test end
    close_dictionary();
}
