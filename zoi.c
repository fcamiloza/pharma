#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Const values
// Max of 5 petri dishes
const int max_dishes = 5;


// Function prototypes
float ** calc_zoi (int num_dish, int num_circ, float my_dish[num_dish][num_circ]);

// Array that stores each value of petri dish
float num[1000];

int main(int argc, char* argv[])
{
    
    // Make sure value inputted is above 0
    if (argc != 3)
    {
        printf("Usage: ./zoi <# petri dishes> <# values of circumference>");
        return 1;
    }

    // Convert string to integer
    int num_dish = atoi(argv[1]);
    int num_circ = atoi(argv[2]);
    
    // 2D array holding number of dishes and values per dish
    float my_dish[num_dish][num_circ];
    
    // Take input and store in array
    for(int i = 0; i < num_dish; i++)
    {
        
        for(int j = 0; j < num_circ; j++)
        {
            // Prompt user for circumference values
            printf("Circumference values for dish %i: ", i);
            scanf("%f", &my_dish[i][j]);
            // Print out values per dish
            printf("%f\n", my_dish[i][j]);
        }
        
    }

    
    // Calling function to calculate zoi
    float ** total_zoi = calc_zoi(num_dish, num_circ, my_dish);

    for(int i = 0; i < num_dish; i++)
    {
        printf("zoi row %d: ", i);
        for(int j = 0; j < num_circ; j++)
        {
            printf("[%.03f]", total_zoi[i][j]);
        }
        printf("\n");
    }
    // Calculating average of ZOI per petri dish
    float sum_calczoi = 0;
//
    for (int i = 0; i < num_dish; i++)
    {
        for(int j = 0; j < num_circ; j++)
        {
            sum_calczoi = total_zoi[i][j] + sum_calczoi;
        }
        
        float ave_dish = sum_calczoi / num_dish;
        printf("Average ZOI per dish: %f\n", ave_dish);
        
        // Reset value of sum_calczoi for the next row
        sum_calczoi = 0;
    }
    
    for(int i = 0; i < num_dish; i++)
    {
        free(total_zoi[i]);
    }
    
    // Free memory
    free(total_zoi);
    
}


// Define function calc_zoi
float ** calc_zoi(int num_dish, int num_circ, float my_dish[num_dish][num_circ])
{
    // Array to store the calculated zoi values
    float ** total_zoi = (float **)malloc(num_dish * sizeof(float *));
    for(int i = 0; i < num_dish; i++)
    {
        total_zoi[i] = (float *)malloc(num_circ * sizeof(float));
    }
    
    // Loop through array to obtain value
    for(int i = 0; i < num_dish; i++)
    {
        for(int j = 0; j < num_circ; j++)
        {
            // Calculating radius of ZOI
            float radius = (my_dish[i][j])/2.0;

            // Define variable for ZOI and obtaining squared output
            float squared = radius * radius;
   
            // Apply πr2
            total_zoi[i][j] = 3.14 * (squared);
        }

    }
    
    return total_zoi;
}
