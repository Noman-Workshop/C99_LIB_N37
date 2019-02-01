/**
# Created By: anonyman637
# Created On: 1/14/19; 7:10 AM
*/

#include <stdio.h>
#include <Temperature/celsiusNFahrenheit.h>

int main() {
    float degCelsius = 10.25f;
    float degFahrenheit = 2.35f;
    printf("%2.2f Celsius\t => %2.2f Fahrenheit\n", degCelsius, celsius2Fahrenheit(degCelsius));
    printf("%2.2f Fahrenheit\t => %2.2f Celsius\n", degFahrenheit, fahrenheit2Celsius(degFahrenheit));
    return 0;
}
