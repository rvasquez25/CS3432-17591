#include <stdio.h>
float convert(float fahrenheit) {
  float celsius = 5 * (fahrenheit-32) /9;
  return celsius;
}
int main() {
	  float fahr, celsius;
	  printf("Farenheit: ");
	  scanf("%f", &fahr);
	  printf("Celsius: ");
	  printf("%f\n", convert(fahr));
	  return(0);
}
