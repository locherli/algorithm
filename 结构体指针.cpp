#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct info
{
    int num_subject;
    int ID;
    int* scores;
};

int main()
{
    struct info* pf = (struct info*)malloc(sizeof(struct info)); // Allocate memory for struct
    printf("input the num of subject:");
    scanf("%d", &pf->num_subject); // Add address of num_subject

    pf->scores = (int*)malloc(pf->num_subject * sizeof(int)); // Allocate memory for scores

    for (int i = 0; i < pf->num_subject; i++)
    {
        scanf("%d", &(pf->scores[i])); // Correct array access
    }

    int sum = 0;
    for (int i = 0; i < pf->num_subject; i++)
    {
        sum += pf->scores[i]; // Correct array access
    }

    double average = (double)sum / pf->num_subject; // Cast sum to double for accurate division
    printf("average scores:%.2lf", average);

    free(pf->scores); // Free allocated memory for scores
    free(pf); // Free allocated memory for struct
    return 0;
}