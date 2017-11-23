#include <stdio.h>
#include <math.h>

void wyswietl_informacje();

void wczytaj_parametry_funkcji(double *a, double *b, double *c);

void nie_ma_rozwiazan();

void instnieja_dwa_rozwiazania(double a, double b, double delta);

void instnieje_jedno_rozwiazanie(double a, double b);

double oblicz_delta(double a, double b, double c);

void oblicz_pierwiastki_row_kw(double a, double b, double c, double delta);

int main() {

    double a, b, c, delta;

/* podczas kompilacji na Ubuntu dodajemy flagę  -lm która uruchomi #include <math.h>
gcc nazwa.c -o nazwa.o -lm */
    wyswietl_informacje();

    wczytaj_parametry_funkcji(&a, &b, &c);

    oblicz_pierwiastki_row_kw(a, b, c, delta);

    return 0;
}

void oblicz_pierwiastki_row_kw(double a, double b, double c, double delta) {
    if (a != 0) {
        delta = oblicz_delta(a, b, c);
        if (delta < 0) {
            nie_ma_rozwiazan();
        } else if (delta > 0) {
            instnieja_dwa_rozwiazania(a, b, delta);
        } else {
            instnieje_jedno_rozwiazanie(a, b);
        }
    } else {
        printf("\n Jesli wartosc a=0 nie jest to równanie kwadratowe, do zobaczenia \n ");
    }
}

double oblicz_delta(double a, double b, double c) {
    double delta;
    puts("\t\t Δ = b² – 4ac"); /*obliczenie delty*/
    delta = pow(b, 2) - 4 * a * c;
    printf("Po podstawieniu do wzoru Δ = %f \n ", delta);
    return delta;
}

void instnieje_jedno_rozwiazanie(double a, double b) {
    printf("Δ = 0 mamy tlko jedno rozwiazanie tego rownania \nx0 = -b/(2*a) \n");
    printf("x0 = %lf\n", (-b) / (2 * a));
}

void instnieja_dwa_rozwiazania(double a, double b, double delta) {
    puts("Δ > o rownanie ma 2 rozwiazania \nx1 = (-b – √Δ) / (2a)");
    puts("x2 = (-b + √Δ) / (2a)");
    printf("x1 = %lf \n", (-b - (sqrt(delta))) / (2 * a));
    printf("x2 = %lf\n", (-b + (sqrt(delta))) / (2 * a));
}

void nie_ma_rozwiazan() { printf("\n Δ < 0 brak rozwiazan dla takiego rownania \n"); }

void wczytaj_parametry_funkcji(double *a, double *b, double *c) {
    printf(" \n Wpisz wartość a:\n ");
    scanf("%lf", a);
    printf(" \n Wpisz wartość b:\n ");
    scanf("%lf", b);
    printf(" \n Wpisz wartość c:\n ");
    scanf("%lf", c);
}

void wyswietl_informacje() {
    puts("************************************************************************");
    puts("************************************************************************");
    puts("****Witam, zapraszam do wspólnego rozwiazywania równań kwadratowych*****");
    puts("****************y = ax² + bx +c*****************************************");
    puts("************************************************************************");
}
