/**
# Created By: Noman^Alien#0637 
# Created On: 8/14/2018; 11:30 PM
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef UTIL_CUSTOM_MATH_LIB
#define UTIL_CUSTOM_MATH_LIB "customMathLib.h"

#include UTIL_CUSTOM_MATH_LIB"customMathLib.h"
#endif

#ifndef UTIL_STR
#define UTIL_STR "strUtl.h"

#include UTIL_STR"strUtl.h""strUtl.h"

#endif

#define FRAC_INT int
#define FRAC_INT_FORMAT "%d"
#define FRAC_STR_LIMIT 12

// todo handle the mixed fractions

/*========================================Fraction Data Type===================================*/

/**
 * @brief fraction data type
 * @variables numerator
 * @variables denominator
 * @warning denominator can never be negative
 * @short fraction
 */
typedef struct fraction {
    FRAC_INT numerator;
    FRAC_INT denominator;
} fraction;


/*--------------------Radical Fraction--------------------*/

// radical + rational combined
typedef struct RootAndRadicalFraction {
    fraction *rational;
    fraction *radical;

} raditionalFrac;


/*========================================Initializer===================================*/

fraction *frac_simplify(const fraction *);
short frac_isOne(const fraction *);

fraction *frac_init(const FRAC_INT numerator, const FRAC_INT denominator) {
    fraction *frac = malloc(sizeof(fraction));
    if (denominator == 0) {
        errorExit(DivByZero);
    } else if (numerator == 0) {
        frac->numerator = 0;
        frac->denominator = denominator;
    } else if (numerator / abs(numerator) == -1 && denominator / abs(denominator) == -1) {
        // if both are negative
        // then none is negative
        frac->numerator = abs(numerator);
        frac->denominator = abs(denominator);
    } else if (numerator / abs(numerator) == -1 || denominator / abs(denominator) == -1) {
        // if one of them is negative then it must be numerator
        // because we have some others things to do with the denominator
        frac->numerator = abs(numerator) * -1;
        frac->denominator = abs(denominator);
    } else {
        frac->numerator = numerator;
        frac->denominator = denominator;
    }
    if(frac_isOne(frac)){
        return frac;
    }
    return frac_simplify(frac);
}

raditionalFrac *frac_radtionalInit(fraction *rational, fraction *radical) {
    raditionalFrac *radFrac = malloc(sizeof(*radFrac));
    radFrac->rational = rational;
    radFrac->radical = radical;
    return radFrac;
}

raditionalFrac *frac_radtionalInitEx(FRAC_INT rationalNumerator, FRAC_INT rationalDenominator,
                                     FRAC_INT radicalNumerator, FRAC_INT radicalDenominator) {

    return frac_radtionalInit(frac_init(rationalNumerator, rationalDenominator),
                              frac_init(radicalNumerator, radicalDenominator));
}


/*========================================Fraction Maths===================================*/

fraction *frac_copy(const fraction *);


/**
 * @brief converts the fraction in to its least form
 * @param fracOrg the fraction pointer
 * @return a new pointer to fraction in the simplified form
 *
 * @details <b>#pureFunction <i>#noMemoryLeak</i></b>
 * @warning free the pointer
 */
fraction *frac_simplify(const fraction *fracOrg) {
    fraction *frac = frac_copy(fracOrg);
    FRAC_INT gcd = getGCD2(frac->numerator, frac->denominator);
    if (gcd == 1) {
        return frac;
    }

    frac->numerator /= gcd;
    frac->denominator /= gcd;

    return frac;
}

/**
 * @brief add two fractions
 * @param fraction1 the first fraction
 * @param fraction2 the second fraction
 * @return the addition of two fractions
 *
 * @details <b>#pureFunction <i>#noMemoryLeak</i></b>
 * @warning free the pointer
 */
fraction *frac_add(const fraction *fraction1, const fraction *fraction2) {
    FRAC_INT lcm = getLCM2(fraction1->denominator, fraction2->denominator);
    fraction *sumSimp = frac_init(fraction1->denominator / lcm * fraction1->numerator
                                  + fraction2->denominator / lcm * fraction2->numerator, lcm);
    return sumSimp;
}

/**
 * @brief add two fractions
 * @param fraction1 the first fraction
 * @param fraction2 the second fraction
 * @return the addition of two fractions
 *
 * @details <b>#pureFunction <i>#noMemoryLeak</i></b>
 * @warning free the pointer
 */
fraction *frac_subtract(const fraction *fraction1, const fraction *fraction2) {
    FRAC_INT lcm = getLCM2(fraction1->denominator, fraction2->denominator);
    fraction *subSimp = frac_init(fraction1->denominator / lcm * fraction1->numerator
                                  - fraction2->denominator / lcm * fraction2->numerator, lcm);
    return subSimp;
}

/**
 * @brief multiplies two fraction
 * @param fraction1
 * @param fraction1 the first fraction
 * @param fraction2 the second fraction
 * @return the product of two fractions
 *
 * @details <b>#pureFunction <i>#noMemoryLeak</i></b>
 * @warning free the pointer
 * @param fraction2
 */
const fraction *frac_multiply(const fraction *fraction1, const fraction *fraction2) {
    fraction *frac = frac_init(fraction1->numerator * fraction2->numerator,
                               fraction1->denominator * fraction2->denominator);
    return frac;
}


/**
 * @brief divides two fraction
 * @param fraction1
 * @param fraction1 the first fraction
 * @param fraction2 the second fraction
 * @return the quotient of two fractions
 *
 * @details <b>#pureFunction <i>#noMemoryLeak</i></b>
 * @warning free the pointer
 * @param fraction2
 */
fraction *frac_divide(const fraction *fraction1, const fraction *fraction2) {
    fraction *frac = frac_init(fraction1->numerator * fraction2->denominator,
                               fraction1->denominator * fraction2->numerator);
    return frac;
}


const fraction *frac_pow(fraction *frac, const INTEGER pow) {
    const fraction *fracResult = frac_init(1, 1);
    for (int i = 1; i <= pow; i++) {
        fracResult = frac_multiply(fracResult, frac);        // toKnow possible memory leak source
    }

    return fracResult;
}

fraction *frac_abs(const fraction *frac) {
    return frac_init(abs(frac->numerator), abs(frac->denominator));
}

raditionalFrac *frac_sqrt(const fraction *frac) {

    // simplifying roots and radicals of denominators
    FRAC_INT *numRadical = radicalSqrt(frac->numerator);
    FRAC_INT *denomRadical = radicalSqrt(frac->denominator);

    // creating the answer
    raditionalFrac *radFrac = frac_radtionalInitEx(numRadical[0], denomRadical[0],
                                                   numRadical[1], denomRadical[1]);

    return radFrac;
}
/*========================================Data Type Util===================================*/

/**
 * @brief
 * @param strFrac
 * @return
 */
fraction *frac_parse(const char *strFrac) {
    fraction *frac;
    char **numDen = charSplit(strFrac, '/', 1);
    if (!numDen) {
        frac = frac_init(strToInt(strFrac), 1);
    } else {
        frac = frac_init(strToInt(numDen[0]), strToInt(numDen[1]));
    }
    return frac;
}

fraction *frac_copy(const fraction *fracOrg) {
    fraction *fracCopy = malloc(sizeof(*fracCopy));
    fracCopy->numerator = fracOrg->numerator;
    fracCopy->denominator = fracOrg->denominator;
    return fracCopy;
}

short frac_isOne(const fraction *frac) {
    if (frac->numerator == 1 && frac->denominator == 1)
        return 1;
    else return 0;
}

short frac_radIsOne(const raditionalFrac *radFrac) {

    if (frac_isOne(radFrac->rational) && frac_isOne(radFrac->radical)) {
        return 1;
    } else {
        return 0;
    }
}

void frac_show(const fraction *frac) {
    if (frac->denominator == 1) {
        printf(FRAC_INT_FORMAT, frac->numerator);
        return;
    }
    printf(FRAC_INT_FORMAT"/"FRAC_INT_FORMAT, frac->numerator, frac->denominator);
}

void frac_Img_show(const fraction *frac) {
    if (frac->denominator == 1) {
        printf(FRAC_INT_FORMAT"i", frac->numerator);
        return;
    }
    printf(FRAC_INT_FORMAT"i/"FRAC_INT_FORMAT, frac->numerator, frac->denominator);
}

void frac_radicalShow(const raditionalFrac *radFrac, const int i) {
    if (frac_radIsOne(radFrac)) {
        printf("1");
    } else if (frac_isOne(radFrac->radical)) {
        fraction *frac = radFrac->rational;
        if (i) {
            frac_Img_show(frac);
        } else {
            frac_show(frac);
        }

    } else if (frac_isOne(radFrac->rational)) {
        fraction *frac = radFrac->radical;
        printf("√(");
        frac_show(frac);
        printf(")");
        if (i)
            printf("i");

    } else {
        printf("(");
        frac_show(radFrac->rational);
        printf(")");

        printf("√(");
        frac_show(radFrac->radical);
        printf(")");

        if (i)
            printf("i");
    }


}
