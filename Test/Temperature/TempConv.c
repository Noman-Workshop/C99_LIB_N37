/**
# Created By: anonyman637
# Created On: 1/14/19; 7:10 AM
*/

#include <stdio.h>
#include <Temperature/celsiusNFahrenheit.h>

int main() {
    float degCelsius = 10.25f;
    float degFahrenheit = 2.35f;
    printf("%f Celsius\t => %f Fahrenheit\n", degCelsius, celsius2Fahrenheit(degCelsius));
    printf("%f Fahrenheit\t => %f Celsius\n", degFahrenheit, fahrenheit2Celsius(degFahrenheit));
    return 0;
}
