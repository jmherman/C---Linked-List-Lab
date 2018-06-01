/* filename: main.c
 * Author: Josh Herman
 * description: this lab processes surveys about the musical preferences of "Pellissippians"
 */

#include "main.h"
int main(int argc, char* argv[]){
	FILE* fp; //file pointer
	int count = 0; //number of survey entries in the file read in
	list_t surveyList;

	char firstInput;
	char firstCompare;
	char secondCompare;

	char genreWords[10][15];
	initGenreWords(genreWords);

	//counter arrats
	int counterArray1[MAX_SONGS];
	int counterArray2[MAX_SONGS];

	//array index info
	int firstMax = 0;
	int secondMax = 0;
	

	if(argc != 2){ //if arguments given from command line is not 2
		printf("Usage Error: MusicSurvey requires two arguments!\n");
		return(0);
	}

	fp = fopen(argv[1], "rb");
	
	int checkFileStatus = checkFile(fp, argv[1]);
	if(checkFileStatus == 0){ //if checkFile failed
		if(fp != NULL){
			fclose(fp);
		}
		return(0);
	}

	//welcome message
	printf("Welcome to the Pellissippi State Music Survey Analyzer!\n");

	//init dbl linked list
	createList(&surveyList);

	//readfile
	count = readBinFile(&surveyList, argv[1], fp);
	fclose(fp); //close file now, since i am not using it anymore


	//test to make sure list is correct
	/*node_t* nPtr = surveyList.headPtr;
	while(nPtr != NULL){
		printf("%d, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c\n", nPtr -> data.age, nPtr -> data.gender, nPtr -> data.status, nPtr -> data.major, nPtr -> data.ethnicity, nPtr -> data.raised, nPtr -> data.classical, nPtr -> data.jazz, nPtr -> data.electronic, nPtr -> data.folk, nPtr -> data.country, nPtr -> data.pop, nPtr -> data.hiphop, nPtr -> data.rock, nPtr -> data.rb, nPtr -> data.reggae);

		nPtr = nPtr -> nextPtr;
	}*/


	printMainMenu();
	firstInput = getc(stdin);
	while(getc(stdin) != '\n');
	
	//test: printf("%c\n", firstInput);
	
	while(firstInput != '6'){
		switch (firstInput){
			case '1':
				printAgeMenu();
				firstCompare = getc(stdin);
				while(firstCompare == ' '){
					firstCompare = getc(stdin);
				}
				secondCompare = getc(stdin);
				while(secondCompare == ' '){
					secondCompare = getc(stdin);
				}
				while(getc(stdin) != '\n');
				if(!isdigit(firstCompare) || !isdigit(secondCompare)){
					printf("Invalid options: %c %c\n", firstCompare, secondCompare); 
					break;
				}
				//test: printf("%c %c\n", firstCompare, secondCompare);
				
				if(firstCompare < '1' || firstCompare > '6' || secondCompare < '1' || secondCompare > '6'){
					printf("Invalid options: %c %c\n", firstCompare, secondCompare);
					break;
				}
				firstMax = traverseAge(&surveyList, counterArray1, firstCompare);
				secondMax = traverseAge(&surveyList, counterArray2, secondCompare);
				printf("\n--------------------------------------------------------\n");
				printf("%s %-28d  %s %d\n", genreWords[firstMax], counterArray1[firstMax], genreWords[secondMax], counterArray2[secondMax]); 
				break;	

			case '2':
				traverseGender(&surveyList, genreWords);
				break;

			case '3':
				printEthnicityMenu();
				firstCompare = getc(stdin);
                                while(firstCompare == ' '){
                                        firstCompare = getc(stdin);
                                }
                                secondCompare = getc(stdin);
                                while(secondCompare == ' '){
                                        secondCompare = getc(stdin);
                                }
                                while(getc(stdin) != '\n');
                                if(!isdigit(firstCompare) || !isdigit(secondCompare)){
                                        printf("Invalid options: %c %c\n", firstCompare, secondCompare);
                                        break;
                                }
                                //test: printf("%c %c\n", firstCompare, secondCompare);

                                if(firstCompare < '1' || firstCompare > '6' || secondCompare < '1' || secondCompare > '6'){
                                        printf("Invalid options: %c %c\n", firstCompare, secondCompare);
                                        break;
                                }
				firstMax = traverseEthnicity(&surveyList, counterArray1, firstCompare);
				secondMax = traverseEthnicity(&surveyList, counterArray2, secondCompare);
				printf("\n--------------------------------------------------------------\n");
				printf("%s %-28d %s %d\n", genreWords[firstMax], counterArray1[firstMax], genreWords[secondMax], counterArray2[secondMax]);
				break;

			case '4':
				regionMenu();
				firstCompare = getc(stdin);
                                while(firstCompare == ' '){
                                        firstCompare = getc(stdin);
                                }
                                secondCompare = getc(stdin);
                                while(secondCompare == ' '){
                                        secondCompare = getc(stdin);
                                }
                                while(getc(stdin) != '\n');
                                if(!isdigit(firstCompare) || !isdigit(secondCompare)){
                                        printf("Invalid options: %c %c\n", firstCompare, secondCompare);
                                        break;
                                }
                                //test: printf("%c %c\n", firstCompare, secondCompare);

                                if(firstCompare < '1' || firstCompare > '6' || secondCompare < '1' || secondCompare > '6'){
                                        printf("Invalid options: %c %c\n", firstCompare, secondCompare);
                                        break;
                                }

				firstMax = traverseRegion(&surveyList, counterArray1, firstCompare);
				secondMax = traverseRegion(&surveyList, counterArray2, secondCompare);
				printf("\n-----------------------------------------------------------\n");
				printf("%s %-28d  %s %d\n", genreWords[firstMax], counterArray1[firstMax], genreWords[secondMax], counterArray2[secondMax]);
				break;

			case '5':
				printMajorMenu();
				firstCompare = getc(stdin);
                                while(firstCompare == ' '){
                                        firstCompare = getc(stdin);
                                }
                                secondCompare = getc(stdin);
                                while(secondCompare == ' '){
                                        secondCompare = getc(stdin);
                                }
                                while(getc(stdin) != '\n');
                                if(!isdigit(firstCompare) || !isdigit(secondCompare)){
                                        printf("Invalid options: %c %c\n", firstCompare, secondCompare);
                                        break;
                                }
                                //test: printf("%c %c\n", firstCompare, secondCompare);

                                if(firstCompare < '1' || firstCompare > '7' || secondCompare < '1' || secondCompare > '7'){
                                        printf("Invalid options: %c %c\n", firstCompare, secondCompare);
                                        break;
                                }

                                firstMax = traverseMajor(&surveyList, counterArray1, firstCompare);
				secondMax = traverseMajor(&surveyList, counterArray2, secondCompare);
				printf("\n----------------------------------------------------------\n");
				printf("%s %-28d %s %d\n", genreWords[firstMax], counterArray1[firstMax], genreWords[secondMax], counterArray2[secondMax]);
                                break;

			default:
				printf("Invalid selection: %c\n", firstInput);
                                
				
				
		}

		 printMainMenu();
		 firstInput = getc(stdin);
		 while(getc(stdin) != '\n');

	}
	deleteList(&surveyList);
	printf("Thank you for your interest in the musical tastes of Pellissippians!\n");
	return(0);
}

/* traverseMajor: this function will traverse the passed list & count the music tastes of the selected major
 * Parameters:
 * 	listPtr - a pointer to the list
 * 	counterArray - array with the amounts of music
 * 	compare - the major chosen
 * Precondition: the compare variable is valid
 * Postcondition: the counterArray is filled with the counts desired
 * returns: the index of counterArray that has the largest count
 */

int traverseMajor(list_t* listPtr, int counterArray[MAX_SONGS], char compare){
	initCountArray(counterArray);
	char switchCompare;
	node_t* curPtr = listPtr -> headPtr;

	switch (compare){
		case FIRST:
			printf("%-35s", "Engineering/Computing");
			switchCompare = ENGINEERING;
			break;
		case SECOND:
			printf("%-35s", "Education");
			switchCompare = EDUCATION;
			break;
		case THIRD:
			printf("%-35s", "Math/Science");
			switchCompare = MATH;
			break;
		case FOURTH:
			printf("%-35s", "Social Science");
			switchCompare = SOCIAL;
			break;
		case FIFTH:
			printf("%-35s", "Health Science");
			switchCompare = HEALTH;
			break;
		case SIXTH:
			printf("%-35s", "Business");
			switchCompare = BUSINESS;
			break;
		case SEVENTH:
			printf("%-35s", "Humanities");
			switchCompare = HUMANITIES;
			break;
	}

	while(curPtr != NULL){ //while still in list
                if(curPtr -> data.major == switchCompare){//if key matches
                        countSongs(curPtr, counterArray);
                }
                curPtr = curPtr -> nextPtr;
        }
        int maxIndex = findMaxIndex(counterArray, MAX_SONGS);
        return(maxIndex);

}

/* traverseRegion: this function will travers the passed list & count the music tastes of the selected region
 * Parameters:
 * 	listPtr - a pointer to the list
 * 	counterArray - array with the amounts of music
 * 	compare - the region chosen
 * Precondition: the compare variable is valid
 * Postcondition: counterArray is filled with the counts desired
 * returns: the index of counterArray that has the largest count
 */

int traverseRegion(list_t* listPtr, int counterArray[MAX_SONGS], char compare){
	initCountArray(counterArray);
	char switchCompare;
	node_t* curPtr = listPtr -> headPtr;

	switch (compare){
		case FIRST:
			printf("%-35s", "Southeast");
			switchCompare = SOUTHEAST;
			break;	

		case SECOND:
			printf("%-35s", "Southwest");
			switchCompare = SOUTHWEST;
			break;
		case THIRD:
			printf("%-35s", "Northeast");
			switchCompare = NORTHEAST;
			break;
		case FOURTH:
			printf("%-35s", "Northwest");
			switchCompare = NORTHWEST;
			break;
		case FIFTH:
			printf("%-35s", "Midwest");
			switchCompare = MIDWEST;
			break;
		case SIXTH:
			printf("%-35s", "Non-US");
			switchCompare = OUTSIDE;
			break;
	}

	while(curPtr != NULL){ //while still in list
		if(curPtr -> data.raised == switchCompare){//if key matches
			countSongs(curPtr, counterArray);
		}
		curPtr = curPtr -> nextPtr;
	}
	int maxIndex = findMaxIndex(counterArray, MAX_SONGS);
	return(maxIndex);

}

/* traverseEthnicity: this function will traverse the passes list & count the music tastes of the selected ethnicity
 * Parameters:
 * 	listPtr - a pointer to the list
 * 	counterArray - array with the counts of music
 * 	compare - the ethnicity chosen
 * Precondition: the compare variable is valid
 * Postcondition: counterArray is filled with the counts desired
 * returns: the index of counterArray that has the largest count
 */

int traverseEthnicity(list_t* listPtr, int counterArray[MAX_SONGS], char compare){
	initCountArray(counterArray);
	char switchCompare;
	node_t* curPtr = listPtr -> headPtr;

	switch (compare){
		case FIRST:
			printf("%-35s", "African American");
			switchCompare = AFRICAN;
			break;
		case SECOND:
			printf("%-35s", "American Indian/Native Alaskan");
			switchCompare = NATIVE;
			break;
		case THIRD:
			printf("%-35s", "Asian");
			switchCompare = ASIAN;
			break;
		case FOURTH:
			printf("%-35s", "Caucasian");
			switchCompare = CAUCASIAN;
			break;
		case FIFTH:
			printf("%-35s", "Hispanic");
			switchCompare = HISPANIC;
			break;
		case SIXTH:
			printf("%-35s", "Native Hawaiian/Pacific Islander");
			switchCompare = HAWAIIAN;
			break;
	}
	while(curPtr != NULL){ //while still in list
		if(curPtr -> data.ethnicity == switchCompare){
			countSongs(curPtr, counterArray);	
		}
		curPtr = curPtr -> nextPtr;
	}
	int maxIndex = findMaxIndex(counterArray, MAX_SONGS);
	return(maxIndex);
}


/* traverseAge: this function traverse the list and finds the favorite music of a age group
 * Parameters:
 * 	listPtr - a pointer to the list
 * 	counterArray - an array with the genres of music to be counted
 * 	compare - the input taken from the user to compare by
 * Preconidtion: list has data
 * Postcondition: the counterArray has changed the values and all of them are counted
 * returns: the index of the top music liked from counterArray
 */

int traverseAge(list_t* listPtr, int counterArray[MAX_SONGS], char compare){
	initCountArray(counterArray);
	int lowerBound = 0;
	int upperBound = 0;
	node_t* curPtr = listPtr -> headPtr;

	switch (compare){
		case FIRST:
			printf("%-35s", "Ages less than 18");
			lowerBound = 1;
			upperBound = 18;	
			break;
		case SECOND:
			printf("%-35s", "Ages 18 - 20");
			lowerBound = 18;
			upperBound = 21;
			break;
		case THIRD:
			printf("%-35s", "Ages 21 - 24");
			lowerBound = 21;
			upperBound = 25;
			break;
		case FOURTH:
			printf("%-35s", "Ages 25 - 34");
			lowerBound = 25;
			upperBound = 35;
			break;
		case FIFTH:
			printf("%-35s", "Ages 35 - 64");
			lowerBound = 35;
			upperBound = 65;
			break;
		case SIXTH:
			printf("%-35s", "Ages 64 and older");
			lowerBound = 65;
			upperBound = 100;
			break;
	}

	while(curPtr != NULL){ //while still in list
		if(curPtr -> data.age >= lowerBound && curPtr -> data.age < upperBound){ //if the age fits the bounds
			countSongs(curPtr, counterArray);
		}
		curPtr = curPtr -> nextPtr;
	}
	int maxIndex = findMaxIndex(counterArray, MAX_SONGS);
	return(maxIndex);
	
}

/* this function just prints out the majorMenu, no parameters and does not return anything
 */

void printMajorMenu(){
	 printf("Please choose two majors: \n");
         printf("\t1. Engineering/Computing\n");
         printf("\t2. Education\n");
         printf("\t3. Math/Science\n");
         printf("\t4. Social Science\n");
         printf("\t5. Health Science\n");
         printf("\t6. Business\n");
         printf("\t7. Humanities\n");
         printf("Two majors to compare: ");

}

/* this function just prints out the regionMenu, no parameters and does not return anything
 */

void regionMenu(){
	printf("Please choose two regions\n");
	printf("\t1. Southeast\n");
        printf("\t2. Southwest\n");
        printf("\t3. Northeast\n");
        printf("\t4. Northwest\n");
        printf("\t5. Midwest\n");
        printf("\t6. Non-US\n");
        printf("Two regions to compare: ");

}


/*This function prints out the Ethnicity Menu, has no parameters and returns nothing
 */

void printEthnicityMenu(){
	printf("Please choose two ethnicities: \n");                                
	printf("\t1. African American\n");                                
	printf("\t2. American Indian/Native Alaskan\n");
	printf("\t3. Asian\n");                                
	printf("\t4. Caucasian\n");                                
	printf("\t5. Hispanic\n");                                
	printf("\t6. Native Hawaiian/Pacific Islander\n");
	printf("Two ethnicities to compare:  ");

}

/*This function prints the main menu, no parameters or return values
 */

void printMainMenu(){
	printf("Let's make some comparisons. Please enter: \n");        
	printf("\t1. Compare by age range\n");        
	printf("\t2. Compare by gender\n");        
	printf("\t3. Compare by ethnicity\n");        
	printf("\t4. Compare by region raised\n");        
	printf("\t5. Compare by Major\n");        
	printf("\t6. Quit\n");
        printf(">> ");

}


/* readBinFile: this function reads the binary file into the music survey struct
 * Parameters:
 *     fp: pointer to the bin file
 *     listPtr: a pointer to the list in question
 *     fileName: the name of the file taken from command line
 * Precondition: the file is opened and closed OUTSIDE OF THIS FUNCTION
 * Postcondition: the list that listPtr points to is filled up with data from the file
 * returns: the amount of survey entries in the file
 */

int readBinFile(list_t* listPtr, char fileName[], FILE* fp){
	fseek(fp, 0, SEEK_SET); //just to make sure pointer is at the beginning
	
	int i, count = 0;
	SurveyEntry temp;
	fread(&temp, sizeof(SurveyEntry), 1, fp);
	while(!feof(fp)){ //while not end of file

		//start: upper casing the chars
		i = toupper(temp.gender);
		temp.gender = i;

		i = toupper(temp.status);
		temp.status = i;

		i = toupper(temp.major);
		temp.major = i;

		i = toupper(temp.ethnicity);
		temp.ethnicity = i;

		i = toupper(temp.raised);
		temp.raised = i;
		//end: upper casing all of the chars
		
		//init the node and insert it
		node_t* nodePtr = initNode(temp);
		insertNode(listPtr, nodePtr);

		//test
		//printf("%d, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c, %c\n", nodePtr -> data.age, nodePtr -> data.gender, nodePtr -> data.status, nodePtr -> data.major, nodePtr -> data.ethnicity, nodePtr -> data.raised, nodePtr -> data.classical, nodePtr -> data.jazz, nodePtr -> data.electronic, nodePtr -> data.folk, nodePtr -> data.country, nodePtr -> data.pop, nodePtr -> data.hiphop, nodePtr -> data.rock, nodePtr -> data.rb, nodePtr -> data.reggae);
		
		//update count and read in next survey entry	
		count++;
		fread(&temp, sizeof(SurveyEntry), 1, fp);
	}

	//test: printf("%d\n", count);
	return(count);
}

/* checkFile: this file checks to see if the file exists & is not empty
 * Parameters:
 *     fp: file pointer to the file in question
 *     fileName: the name of the file taken from the command line
 * Precondition: the file is opened and closed OUTSIDE OF THIS FUNCTION
 * returns: 1 if passed, 0 if failed
 */

int checkFile(FILE* fp, char fileName[]){
	int c;
	if( fp == NULL){ //if the file does not exist
		printf("File does not exist: %s\n", fileName);
		return(0);
	}

	c = fgetc(fp);

	if(feof(fp)){ //if the file is empty
		printf("File is empty: %s\n", fileName);
		return(0);
	}
	else{ //file exists and is not empty
		ungetc(c, fp);
		return(1);
	}
	
}

/* countSongs: this function counts whether or not the survey liked certain songs or not
 * Parameters:
 * 	nPtr: pointer to that node(specific node preffered)
 * 	counts: array of the counts
 * Precondition: counts is initialized
 * Postconition: counts is counted
 */

void countSongs(node_t* nPtr, int counts[MAX_SONGS]){
	if(nPtr -> data.classical == YES)
		counts[CLASSICAL]++;
        if(nPtr -> data.jazz == YES)
		counts[JAZZ]++;
        if(nPtr -> data.electronic == YES)
		counts[ELECTRONIC]++;
        if(nPtr -> data.folk == YES)
		counts[FOLK]++;
        if(nPtr -> data.country == YES)
		counts[COUNTRY]++;
        if(nPtr -> data.pop == YES)
		counts[POP]++;
        if(nPtr -> data.hiphop == YES)
		counts[HIPHOP]++;
        if(nPtr -> data.rock == YES)
		counts[ROCK]++;
        if(nPtr -> data.rb == YES)
		counts[RB]++;
        if(nPtr -> data.reggae == YES)
		counts[REGGAE]++;

}

/* traverseGender: this functions traverses the list, and counts the type of music liked by either gender, and prints out the top one
 * Parameters: 
 * 	listPtr = the pointer to the list
 * 	genreWords[][]: 2d array of all the names of the genres
 * Precondition: the list has valid data in it
 * returns: nothing via return statement, however it does print something out
 */

void traverseGender(list_t* listPtr, char genreWords[10][15]){
	int mCounts[MAX_SONGS];
	int fCounts[MAX_SONGS];

	int i;
	int mMaxIndex = 0;
	int fMaxIndex = 0;

	initCountArray(mCounts);
	initCountArray(fCounts);

	node_t* nPtr = listPtr -> headPtr;
	while(nPtr != NULL){ // while still in list
		if(nPtr -> data.gender == MALE){ //if this node is male
			countSongs(nPtr, mCounts);
		}

		else if(nPtr -> data.gender == FEMALE){ //if this node is female
			countSongs(nPtr, fCounts);
		}
		nPtr = nPtr -> nextPtr;
	}
	mMaxIndex = findMaxIndex(mCounts, MAX_SONGS);
	fMaxIndex = findMaxIndex(fCounts, MAX_SONGS);

	printf("\n");
	printf("Male\t Female\n");
	printf("------------------------\n");
	printf("%s %d\t %s %d\n", genreWords[mMaxIndex], mCounts[mMaxIndex], genreWords[fMaxIndex], fCounts[fMaxIndex]);
	printf("\n");

}

/* findMaxIndex: this functions finds the index with the most amount of genres liked
 * Parameters:
 * 	array[]: this is the array of counts for the genres liked
 * 	count: number of genres in the array
 * Precondition: array is filled with data
 * returns: the index of the genre with highest amount of likes
 */

int findMaxIndex(int array[], int count){
	int i = 0;
	int maxIndex = i;

	for(i = 0; i < count; i++){
		if(array[i] > array[maxIndex]){
			maxIndex = i;
		}
	}

	return(maxIndex);
}

/* initGenreWords: this functions fills up the genreWords array
 * Parameters: genreWords[][] the array to the filled
 * returns nothing
 */

void initGenreWords(char genreWords[10][15]){
	strcpy(genreWords[0], "Classical");
	strcpy(genreWords[1], "Jazz");
	strcpy(genreWords[2], "Electronic");
	strcpy(genreWords[3], "Folk");
	strcpy(genreWords[4], "Country");
	strcpy(genreWords[5], "Pop");
	strcpy(genreWords[6], "Hip-Hop");
	strcpy(genreWords[7], "Rock");
	strcpy(genreWords[8], "RB");
	strcpy(genreWords[9], "Reggae");
} 

/* initCountArray: this functions sets every index of passed array to 0
 * parameters: counts[]: the array in question
 * returns nothing
 */

void initCountArray(int counts[MAX_SONGS]){
	int i;
	for(i = 0; i < MAX_SONGS; i++){
		counts[i] = 0;
	}
}


/*this function prints the age menu, has no parameters or return value
 */

void printAgeMenu(){
	printf("Please choose two age ranges\n");
        printf("\t1. Less then 18\n");
        printf("\t2. 18 - 20\n");
        printf("\t3. 21 - 24\n");
        printf("\t4. 25 - 34\n");
        printf("\t5. 35 - 64\n");
        printf("\t6. 65 and older\n");
        printf("Two ranges to compare: ");

}
