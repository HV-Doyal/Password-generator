#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

//Function to animate the printing
void delay_print(char *str)
{
    // Initialize a pointer 'p' to point to the first character of the given string 'str'
 char *p = str;
 /* Loop through the characters of the string until a null character is encountered
   The loop condition '*p' checks if the current character is non-zero (i.e., not a null character)*/
 for (char *p = str; *p; p++) 
 {
  // Print the current character to the console
  putchar(*p);
  // Ensure that each character is immediately displayed on the console causes the animation
  fflush(stdout);
  // Suspend the loop for 20 milliseconds (20000 microseconds) to introduce a delay between each character
  usleep(20000);
 }
}

/*Function to generate a random number between 1 and 500 */
int number_generator()
{
 srand(time(NULL));
 //uses time to gice a new seed everytime so values are random
 return rand() % 500 + 1;
}

/*Function to read from file named "4" */
char* read_from_4(void) //the * indicates that the function returns a pointer to a char, rather than a char itself.
{
 FILE* fp; /*fp short for file pointer*/
 char line[10];
 int current_line = 0;
 int line_to_read = number_generator();
 fp = fopen("4", "r"); /* open the file for reading */
 if (fp == NULL) 
 {
  perror("Error opening dictionary file containing 4 letter words ");
  exit(1);
 }
 /* read lines until the desired line is reached */
 while (current_line < line_to_read && fgets(line, 10, fp) != NULL)
 {
  current_line++;
 }
   /* copy the string to a dynamically allocated memory so that the program can access it */
  char* str = malloc(strlen(line) + 1);
  strcpy(str, line);
  return str;
 fclose(fp);
}
//The following functions are the same as the one above just modified to read from diffrent files
char* read_from_5(void)
{
 FILE* fp; /*fp short for file pointer*/
 char line[10];
 int current_line = 0;
 int line_to_read = number_generator();
 fp = fopen("5", "r"); /* open the file for reading */
 if (fp == NULL) 
 {
  perror("Error opening dictionary file containing 5 letter words ");
  exit(1);
 }
 /* read lines until the desired line is reached */
 while (current_line < line_to_read && fgets(line, 10, fp) != NULL)
 {
  current_line++;
 }
   /* copy the string to a dynamically allocated buffer */
  char* str = malloc(strlen(line) + 1);
  strcpy(str, line);
  return str;
 fclose(fp);
}

char* read_from_6(void)
{
 FILE* fp;
 char line[10];
 int current_line = 0;
 int line_to_read = number_generator();
 fp = fopen("6", "r");
 if (fp == NULL) 
 {
  perror("Error opening dictionary file containing 6 letter words ");
  exit(1);
 }
 while (current_line < line_to_read && fgets(line, 10, fp) != NULL)
 {
  current_line++;
 }
  char* str = malloc(strlen(line) + 1);
  strcpy(str, line);
  return str;
 fclose(fp);
}

char* read_from_7(void)
{
 FILE* fp; 
 char line[10];
 int current_line = 0;
 int line_to_read = number_generator();
 fp = fopen("7", "r"); 
 if (fp == NULL) 
 {
  perror("Error opening dictionary file containing 7 letter words ");
  exit(1);
 }
 while (current_line < line_to_read && fgets(line, 10, fp) != NULL)
 {
  current_line++;
 }
  char* str = malloc(strlen(line) + 1);
  strcpy(str, line);
  return str;
 fclose(fp);
}

/*Function to to choose a random file */
char* Random_file()
{
 int min = 4, max = 7, random_num;
 /*Initialize the random number generator*/
 /*Generate a random number between min and max (inclusive)*/
 srand(time(NULL));
 random_num = rand() % (max - min + 1) + min;
   switch (random_num) 
  {
    case 4:
      return read_from_4();
      break;
    case 5:
      return read_from_5();
      break;
    case 6:
      return read_from_6();
      break;
    case 7:
      return read_from_7();
      break;
    default:
      printf("An error has occurred\n");
      sleep(5); // closes the program incase an error has occured
      exit(0);
  }
}

// Function to cheack correct parameter of number of words
int Correct_Parameter()
{
  int number_of_words;
 do
 {
  delay_print("Number of words: "); 
  scanf("%d", &number_of_words);
  if (number_of_words < 3 || number_of_words > 4) 
    { 
      printf("Invalid Parameter\nNumber of words must be greater than 2 or less than 5\n"); 
    } 
 } while (number_of_words < 3 || number_of_words > 4);//loop untill correct parameter is obtained
 return number_of_words;
}
//Function to generate password
int Generate_Password()
{
  char* word[4]; //* means declare an array of four pointers | NO * means declaring an array of four characters
  int i;
  int numwords = Correct_Parameter();
  delay_print("Generating password\n"); 
  sleep(2);
 for (i = 0; i < numwords; i++)
 {
  word[i] = Random_file();
  printf("%d.%s", i + 1, word[i]);
  sleep(2); // This cause the program to wait before executing the code as it is using time as a seed
 }
 for(i = 0; i < numwords; i++)
 {
 word[i][strcspn(word[i], "\n")] = '\0'; 
 // remove newline character from word,if not included everytime word is printed it goes to the next line
 }
  printf("Your e-t-r password is: "); 
    for(int i=0; i<numwords; i++) 
    { 
     printf("%s", word[i]); 
     if (i < numwords - 1) 
      { 
       printf("-"); 
      } 
    }
    printf("\n");
}

int strengthen(char weakpassword[50])
{
    int length;
    length = strlen(weakpassword);
    for (int i = 0; i < length; i++) {
        if (weakpassword[i] == 'a') {
            weakpassword[i] = '@';
        } else if (weakpassword[i] == 'e') {
            weakpassword[i] = '3';
        } else if (weakpassword[i] == 'i') {
            weakpassword[i] = '1';
        } else if (weakpassword[i] == 'o') {
            weakpassword[i] = '0';
        } else if (weakpassword[i] == 's') {
            weakpassword[i] = '$';
        }
    }
}

//Function to display the small presentation at the start
int Intro()
{
delay_print(" _____   _____   _____    _____ _____ _____ _____ _ _ _ _____ _____ ____ \n");
delay_print("|   __| |_   _| | __  |  |  _  |  _  |   __|   __| | | |     | __  |    \\ \n");
delay_print("|   __|_  | |  _|    -|  |   __|     |__   |__   | | | |  |  |    -|  |  |\n");
delay_print("|_____|_| |_| |_|__|__|  |__|  |__|__|_____|_____|_____|_____|__|__|____/ \n");
sleep(1);
delay_print(" _____        _____         _   _    _| |_    _____             _         \n");
delay_print("| __  |_ _   |  |  |___ _ _|_|_| |  |   __|  |  |  |___ ___ ___| |_       \n");
delay_print("| __ -| | |  |    -| . | | | | . |  |   __|  |     | .'|  _|_ -|   |      \n");
delay_print("|_____|_  |  |__|__|___|\\_/|_|___|  |_   _|  |__|__|__,|_| |___|_|_|      \n");
delay_print("      |___|                           |_|                                 \n");
sleep(1);
}