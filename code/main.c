#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) 
{
  //Write your code here.
  int sum = 0;
  switch(gender)
  {
    case 'b':
        for(int i=0; i<number_of_students; i++)
        {
            if(i%2 == 0)
            {
                sum += marks[i];
            }
        }
        break;
    case 'g':
        for(int i=0; i<number_of_students; i++)
        {
            if(i%2 == 1)
            {
                sum += marks[i];
            }
        }
        break;
    default:
        break;
  }
  
  return sum;
}

int main() {

    char* input = "3 3 2 5 b";
    int number_of_students;
    char gender;
    int sum;
  
    sscanf(input + 0, "%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        sscanf(input + ( student * 2 + 2), "%d", (marks + student));
    }
    
    sscanf(input + (number_of_students*2 +2) ," %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}