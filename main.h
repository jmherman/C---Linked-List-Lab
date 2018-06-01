#include "node.h"
#include "list.h"
#include "SurveyEntry.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//gender:
#define FEMALE ('F')
#define MALE ('M')
//status:
#define STUDENT ('S')
#define STAFF ('F')
#define OTHER ('O')
//major:
#define ENGINEERING ('E')
#define HEALTH ('H')
#define EDUCATION ('D')
#define BUSINESS ('B')
#define MATH ('M')
#define HUMANITIES ('U')
#define SOCIAL ('S')
//ethnicity:
#define AFRICAN ('A')
#define NATIVE ('I')
#define ASIAN ('S')
#define CAUCASIAN ('C')
#define HISPANIC ('H')
#define HAWAIIAN ('P')
//raised:
#define SOUTHEAST ('S')
#define NORTHEAST ('N')
#define MIDWEST ('M')
#define SOUTHWEST ('W')
#define NORTHWEST ('O')
#define OUTSIDE ('T') //outside = raised out of US
//music tastes:
#define YES ('1')
#define NO ('0')

//music:
#define CLASSICAL 0
#define JAZZ 1
#define ELECTRONIC 2
#define FOLK 3
#define COUNTRY 4
#define POP 5
#define HIPHOP 6
#define ROCK 7
#define RB 8
#define REGGAE 9

//compares:
#define FIRST '1'
#define SECOND '2'
#define THIRD '3'
#define FOURTH '4'
#define FIFTH '5'
#define SIXTH '6'
#define SEVENTH '7'

//max count array:
#define MAX_SONGS 10

#define MAXHAR 35;

int readBinFile(list_t* listPtr, char fileName[], FILE* fp);
int checkFile(FILE* fp, char fileName[]);
void traverseGender(list_t* listPtr, char genreWords[10][15]);
int findMaxIndex(int array[], int count);
void initGenreWords(char genreWords[10][15]);
void initCountArray(int counts[MAX_SONGS]);
void printAgeMenu();
void printMainMenu();
void printEthnicityMenu();
void regionMenu();
void printMajorMenu();
int traverseAge(list_t* listPtr, int counterArray[10], char compare);
void countSongs(node_t* nPtr, int counts[MAX_SONGS]);
int traverseEthnicity(list_t* listPtr, int counterArray[MAX_SONGS], char compare);
int traverseRegion(list_t* listPtr, int counterArray[MAX_SONGS], char compare);
int traverseMajor(list_t* listPtr, int counterArray[MAX_SONGS], char compare);
