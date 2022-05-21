#include <stdio.h>
#include <string.h>
#include "chain_hull.h"

//Effektiv och ful c-lösning med flera lösningar jag
//inte skulle använda om målet var läsbarhet m.m.
//men när jag löser mot kattis m.m. som ofta är tidssnåla
//plockar jag fram alla "fula" tidsoptimeringar jag kan.


//store texts in rows of 52 characters,
//52 to make space for newline and null character
//maximum 500 files
char texts[500][52];

static int hashes[500];

static int copies[500] = { 0 };

int main() {
    int len;
    
    //read number of test cases, skip trailing newline
    //if we read a 0, quit
    while (scanf("%d%*1c", &len) && len != 0) {
        int unique_files = 0;
        int collisions = 0;


        while (len--) {
            //reset hash and number of copies from earlier runs
            hashes[unique_files] = 0;
            copies[unique_files] = 0;

            //create loop counter outside for use with custom getline
            int j;

            //classic strict c doesn't have bool's, so we use an int
            int unique_file = 1;



            //read input string, assume sanitized input
            //overwrites previous texts if last file wasn't unique
            //we have to manually read characters so as not to skip
            //leading spaces
            for (j = 0; (texts[unique_files][j] = getchar()) != '\n'; ++j);
            texts[unique_files][j] = '\0';


            //create hash by xor'ing read characters until
            //we encounter end of string
            for (j=0; texts[unique_files][j] != '\0'; ++j) {
                hashes[unique_files] ^= texts[unique_files][j];
            }


            //loop through all previously found unique files
            for (j=0; j < unique_files; ++j) {

                //check for hash matches
                if (hashes[unique_files] == hashes[j]) {

                    //if hash matches, compare whole string
                    if (strcmp(texts[unique_files], texts[j]) == 0) {

                        //if string matches, we have the same file
                        unique_file = 0;
                        ++copies[j];
                    }
                    else {

                        //otherwise we have a hash collision with
                        //the unique file and all its copies
                        collisions += 1 + copies[j];
                    }
                }
            }


            //if this was a unique file, increment number of unique files
            //otherwise, overwrite all of our non-unique file's values
            //in the next lteration because we don't need them.
            if (unique_file) {
                ++unique_files;
            }
        }

        //at the end of each input, print results
        printf("%d %d\n", unique_files, collisions);
    }

    return 0;
}
