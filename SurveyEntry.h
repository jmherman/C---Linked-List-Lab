/* filename: SurveyEntry.h
 * Author: Josh Herman
 * desctription: this is the header file for the survey entry structure that will be used throughout the program
 */

#ifndef SURVEYENTRY
#define SURVEYENTRY

typedef struct {
	int age;
	char gender, status, major, ethnicity, raised;
	 char classical, jazz, electronic, folk, country, pop,
                hiphop, rock, rb, reggae;
}SurveyEntry;

#endif
