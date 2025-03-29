#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// define value limits and pi
#define maxValue 500000
#define minValue 1
#define maxRadius 1000000 // max integer
#define _USE_MATH_DEFINES // to use M_PI

// storing pi in a constant because pi is easier to read / work with than M_PI
const double pi = M_PI; // previously used 22/7 to get PI but it gives larger calculation error than 10^(-6)

// Function to calculate volume of box ( magical devices )
double boxVolumeCalc(double height, double length, double width){
   return (double)height * length * width;
}

// Function to calculate volume of sphere ( magical motes )
double sphereVolumeCalc(double radius){
   return (4.0/3.0) * pi * radius * radius * radius;
}

// Merge Sort function
void mergeSort(double * arr, int len) {
   // BASE CASE: No element or 1 element only
   if (len <= 1) return; 
   
   // Recursive call
   mergeSort(arr, len / 2);
   mergeSort(&arr[len/2], len - (len/2));

   // MERGE
   int fptr = 0;
   int bptr = len/2;
   int index = 0;

   // create temporary array.
   double * tmp = (double *)malloc(len * sizeof(double));
   
   // Merge into tmp
   for (int i = 0; i < len; i++) {
      if (fptr == len/2) { // left is empty
         tmp[i] = arr[bptr];
         bptr++;
      } else if (bptr == len) { // right is empty
         tmp[i] = arr[fptr];
         fptr++;
      } else if (arr[fptr] >= arr[bptr]) {
         tmp[i] = arr[fptr];
         fptr++;
      } else {
         tmp[i] = arr[bptr];
         bptr++;
      }
   }

   // Copy tmp back into array
   for (int i = 0; i < len; i++) arr[i] = tmp[i];

   // Free memory
   free(tmp);
}


int main(){
   int number_magic = 0;   // Magical mote = SPHERES
   int index_magic = 0;    // Tracking pointer #1
   int number_device = 0;  // Magical device = BOXES
   int index_device = 0;   // Tracking pointer #2
   double freemagic = 0.0; // Store unused spheres 

   scanf("%d%d", &number_magic, &number_device);   // get input

   // allocate memory for Dynamic arrays
   double* sphereVolumeArray = (double*)malloc(number_magic * sizeof(double));
   double* boxVolumeArray = (double*)malloc(number_device * sizeof(double));

   if(number_magic < minValue || number_magic > maxValue || number_device < minValue || number_device > maxValue) return 1; // check input with predefined limits

   // M integers representing the radius of a magical mote
   for(int i = 0; i < number_magic; i++){
      int rad = 0;
      scanf("%d", &rad);
      sphereVolumeArray[i] = sphereVolumeCalc(rad);
   }
   // D lines each contain 3 integers   

   for(int i = 0; i < number_device; i++){
      int l,w,h = 0;
      scanf("%d%d%d", &l,&w,&h);
      boxVolumeArray[i] = boxVolumeCalc(l,w,h);
   }

   // Call function for sorting both arrays (array, length)
   mergeSort(sphereVolumeArray, number_magic);
   mergeSort(boxVolumeArray, number_device);

   while (index_magic < number_magic) {
      if (index_device < number_device && sphereVolumeArray[index_magic] <= boxVolumeArray[index_device]) {
      // Mote fits in the current device
         index_device++;
      } else {
      // Mote cannot be contained
         freemagic += sphereVolumeArray[index_magic];
      }
      index_magic++;
}

// Print least volume of the uncontained motes
   printf("%.6f\n", freemagic);

// Clean up memory 
free(sphereVolumeArray);
free(boxVolumeArray);

// Successfully exit program like a good boy
return 0;
}
