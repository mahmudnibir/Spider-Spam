/*
 * EXAMPLE: Temperature Converter
 */

#include <stdio.h>

float celsiusToFahrenheit(float celsius);

int main() {
    float temp;
    
    printf("Enter temperature in Celsius: ");
    scanf("%f", &temp);
    
    float fahrenheit = celsiusToFahrenheit(temp);
    
    printf("%.1f°C = %.1f°F\n", temp, fahrenheit);
    
    return 0;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Try: 0°C should give 32°F
