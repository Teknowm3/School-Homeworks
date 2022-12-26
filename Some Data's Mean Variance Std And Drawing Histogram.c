#include <stdio.h>
#include <math.h>

#define NPEOPLE 5
#define MIN_AGE 0
#define MAX_AGE 99

void readAges(int []);
void printAges(const int []);
float calcMean(const int []);
float calcVariance(const int [], int);
float calcStd(float);
void printStats(float, float, float);
void drawHistogram(const int []);

int main(void)
{
	int ages[NPEOPLE];
	float mean, variance, std;
	readAges(ages);
	printAges(ages);
	mean = calcMean(ages);
	variance = calcVariance(ages, mean);
	std = calcStd(variance);
	printStats(mean, variance, std);
	drawHistogram(ages);
	return 0;
}

void readAges(int ages[])
{
	for (int i = 0; i < NPEOPLE; i++) {
    int age;
    do 
	{
    	printf("Enter age for %d. Person : ", i + 1);
    	scanf("%d", &age);
    		if (age < MIN_AGE || age > MAX_AGE) 
			{
		    	printf("Age must be between %d and %d. Please try again.\n", MIN_AGE, MAX_AGE);
    		}
    } while (age < MIN_AGE || age > MAX_AGE);
    ages[i] = age;
  	}
	printf("\n");
}

void printAges(const int ages[])
{
	for (int i = 0; i < NPEOPLE; i++)
	{
		printf("%d. Person's age is : %d\n",i+1,ages[i]);
	}
	printf("\n");
}

float calcMean(const int ages[])
{
	float sum=0;
	for (int i = 0; i < NPEOPLE; i++)
	{
		sum+=ages[i];
	}
	float mean = sum/NPEOPLE;
	return mean;
}

float calcVariance(const int ages[], int mean)
{
	float variance=0;
	for (int i = 0; i < NPEOPLE; i++)
	{
		variance+=pow((ages[i]-mean),2);
	}
	variance/=NPEOPLE;
	return variance;
}

float calcStd(float variance)
{
	float std = sqrt(variance);
	return std;
}

void printStats(float mean, float variance, float std)
{
	printf("Here is some stats about your data \n");
	printf("Mean of the ages is : %.3f\n",mean);
	printf("Variance of the ages is : %.3f\n",variance);
	printf("Standard deviation of the ages is : %.3f\n",std);
	printf("\n");
}

void drawHistogram(const int ages[])
{
	printf("Histogram of your data\n");
	printf("\n");
	int histogram[100] = {0};
	for (int i = 0; i < NPEOPLE; i++) 
	{
    int index = ages[i] / 10;
    histogram[index]++;
	}
	for (int i = 0; i < 10; i++) 
	{
		if (i==0)
		{
			printf("  %d-%d | ", i * 10, (i + 1) * 10 - 1);
		}
		else
   		{
			printf("%d-%d | ", i * 10, (i + 1) * 10 - 1);
		}
	for (int j = 0; j < histogram[i]; j++) 
	{
    	printf("* ");
    }
    printf("\n");
	}
}