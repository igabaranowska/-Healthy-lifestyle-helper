#include <iostream>
#include <stdio.h>

using namespace std;

class Aktywnosc{
private:
    int numer;
    string nazwa;
    double wspolczynnik;

public:
    Aktywnosc(int pobrany_nr, string pobrana_nazwa, double pobrany_wspolczynnik){
        this->numer = pobrany_nr;
        this->nazwa = pobrana_nazwa;
        this->wspolczynnik = pobrany_wspolczynnik;
    }

    Aktywnosc(){
    }

    int Zwracanie_numeru(){
        return this->numer;
    }

    string Zwracanie_nazwy(){
        return this->nazwa;
    }

    double Zwracanie_wspolczynnika(){
        return this->wspolczynnik;
    }
};
class Lista_aktywnosci{
    Aktywnosc tablica_sportu[200];
    int rozmiar = 0;
public:
    void Wypelnianie(string nazwa_pliku){
        int numer;
        char nazwa[500];
        double wspolczynnik;

        FILE *plik = fopen(nazwa_pliku.c_str(), "r");
        int pozycja = fscanf(plik, "%d;%[^;];%lf", &numer, nazwa, &wspolczynnik);

        while(pozycja != EOF){
            Aktywnosc sport(numer, nazwa, wspolczynnik);
            tablica_sportu[rozmiar] = sport;
            rozmiar++;
            pozycja = fscanf(plik, "%d;%[^;];%lf", &numer, nazwa, &wspolczynnik);
        }

        fclose(plik);


    }
    void Wypisywanie(){

        for(int i=0; i<rozmiar; i++){
            cout<< tablica_sportu[i].Zwracanie_numeru() << " - " << tablica_sportu[i].Zwracanie_nazwy() << endl;
        }
    }

    int Zwracanie_rozmiaru(){
        return this->rozmiar;
    }

    Aktywnosc* Zwracanie_tablicy() {
    return this -> tablica_sportu;
    }


};


class Posilek{
private:
    int numer;
    string nazwa;
    int kcal;

public:
    Posilek(int pobrany_nr, string pobrana_nazwa, int pobrane_kcal){
        this->numer = pobrany_nr;
        this->nazwa = pobrana_nazwa;
        this->kcal = pobrane_kcal;
    }

    Posilek(){
    }

    int Zwracanie_numeru(){
        return this->numer;
    }

    string Zwracanie_nazwy(){
        return this->nazwa;
    }

    int Zwracanie_kcal(){
        return this->kcal;
    }
};

class Lista_posilkow{
    Posilek tablica_posilkow[200];
    int rozmiar = 0;
public:
    void Wypelnianie(string nazwa_pliku){
        int numer;
        char nazwa[200];
        int kcal;

        FILE *plik = fopen(nazwa_pliku.c_str(), "r");
        int pozycja = fscanf(plik, "%d;%[^;];%d", &numer, nazwa, &kcal);

        while(pozycja != EOF){
            Posilek posilek(numer, nazwa, kcal);
            tablica_posilkow[rozmiar] = posilek;
            rozmiar++;
            pozycja = fscanf(plik, "%d;%[^;];%d", &numer, nazwa, &kcal);
        }

        fclose(plik);

    }
    void Wypisywanie(){

        for(int i=0; i<rozmiar; i++){
            cout<< tablica_posilkow[i].Zwracanie_numeru() << " - " << tablica_posilkow[i].Zwracanie_nazwy() << ", " << tablica_posilkow[i].Zwracanie_kcal() << " kcal" << endl;
        }
    }

    int Zwracanie_rozmiaru(){
        return this->rozmiar;
    }

    Posilek* Zwracanie_tablicy() {
    return this -> tablica_posilkow;
    }

};


    int Menu (Lista_posilkow &posilki) {
        posilki.Wypisywanie();
        int wybrany_posilek;
        cout << "\nPodaj numer wybranego posiłku: ";
        cin >> wybrany_posilek;
        while (wybrany_posilek<1 || wybrany_posilek>posilki.Zwracanie_rozmiaru()){
            cout << "Podano niepoprawne wartosci. Spróbuj ponownie! \n";
            cout << "Podaj ponownie numer posiłku: ";
            cin >> wybrany_posilek;

        }
        return wybrany_posilek;
}

class Cwiczenia{
private:
    int numer;
    string nazwa;
    int kcal;

public:
    Cwiczenia(int pobrany_nr, string pobrana_nazwa, int pobrane_kcal){
        this->numer = pobrany_nr;
        this->nazwa = pobrana_nazwa;
        this->kcal = pobrane_kcal;
    }

    Cwiczenia(){
    }

    int Zwracanie_numeru(){
        return this->numer;
    }

    string Zwracanie_nazwy(){
        return this->nazwa;
    }

    int Zwracanie_kcal(){
        return this->kcal;
    }
};

class Lista_cwiczen{
    Cwiczenia tablica_cwiczen[200];
    int rozmiar = 0;
public:
    void Wypelnianie(string nazwa_pliku){
        int numer;
        char nazwa[200];
        int kcal;

        FILE *plik = fopen(nazwa_pliku.c_str(), "r");
        int pozycja = fscanf(plik, "%d;%[^;];%d", &numer, nazwa, &kcal);

        while(pozycja != EOF){
            Cwiczenia cwiczenia(numer, nazwa, kcal);
            tablica_cwiczen[rozmiar] = cwiczenia;
            rozmiar++;
            pozycja = fscanf(plik, "%d;%[^;];%d", &numer, nazwa, &kcal);
        }

        fclose(plik);

    }
    void Wypisywanie(){

        for(int i=0; i<rozmiar; i++){
            cout<< tablica_cwiczen[i].Zwracanie_numeru() << " - " << tablica_cwiczen[i].Zwracanie_nazwy() << ", " << tablica_cwiczen[i].Zwracanie_kcal() << " kcal" << endl;
        }
    }

    int Zwracanie_rozmiaru(){
        return this->rozmiar;
    }

    Cwiczenia* Zwracanie_tablicy() {
    return this -> tablica_cwiczen;
    }

};



    int Cwiczenia_odczyt (Lista_cwiczen &Cwiczenia) {
        Cwiczenia.Wypisywanie();
        int wybrane_cwiczenie;
        cout << "\nPodaj numer wybranego ćwiczenia: ";
        cin >> wybrane_cwiczenie;
        while (wybrane_cwiczenie<1 || wybrane_cwiczenie>Cwiczenia.Zwracanie_rozmiaru()){
            cout << "Podano niepoprawne wartosci. Spróbuj ponownie! \n";
            cout << "Podaj ponownie numer posiłku: ";
            cin >> wybrane_cwiczenie;

        }
        return wybrane_cwiczenie;
}







int main()
{
    setlocale(LC_ALL, "");

    Lista_posilkow lista_sniadan;
    lista_sniadan.Wypelnianie("Sniadania.csv");


    Lista_posilkow lista_obiadow;
    lista_obiadow.Wypelnianie("Obiady.csv");


    Lista_posilkow lista_kolacji;
    lista_kolacji.Wypelnianie("Kolacje.csv");


    Lista_posilkow lista_dodatkowych;
    lista_dodatkowych.Wypelnianie("Dodatkowy_posilek.csv");


    Lista_aktywnosci lista_aktywnosci;
    lista_aktywnosci.Wypelnianie("Aktywnosc.csv");


    Lista_cwiczen lista_cwiczen;
    lista_cwiczen.Wypelnianie("Cwiczenia.csv");


    float wzrost, waga, BMI, PPM, CPM;
    int wiek, wybor_uzytkownika;
    int wybrane_kcal=0;
    char plec;

    cout << "Podaj swoją płeć (m/k): " << endl;
    cin >> plec;

    cout << "Podaj swoj wiek: " << endl;
    cin >> wiek;

    cout << "Podaj swoj wzrost w centymetrach: " << endl;
    cin >> wzrost;

    cout << "Podaj swoja wagę w kilogramach: " << endl;
    cin >> waga;

    BMI = 10000.0 * waga /( wzrost * wzrost );
    cout << "\nTwoje BMI wynosi: " << BMI << endl;

    if(plec=='m'){

        PPM = 66.47 + (13.7*waga) + (5.0*wzrost) - (6.76*wiek);
    }
    else{

        PPM = 665.09 + (9.56*waga) + (1.85*wzrost) -(4.67*wiek);

    }

    cout << "\nKtóry punkt najbardziej odpowiada twojej aktywności fizycznej?\n\n" ;
    lista_aktywnosci.Wypisywanie();
    int wybrana_aktywnosc;
    cout << "\nPodaj numer, z którym najbardziej się identyfikujesz: ";
    cin >> wybrana_aktywnosc;
   while (wybrana_aktywnosc<1 || wybrana_aktywnosc>lista_aktywnosci.Zwracanie_rozmiaru()){
        cout << "Podano niepoprawne wartosci. Spróbuj ponownie! \n";
        cout << "Podaj ponownie numer, z którym najbardziej się identyfikujesz: ";
        cin >> wybrana_aktywnosc;
    }

    CPM = PPM*wybrana_aktywnosc;
    cout << "\nNajmniejsza ilość kalorii, którą możesz dostarczyć do swojego organizmu, by żyć i zapewnić sobie funkcjonowanie podstawowych funkcji życiowych wynosi: " << PPM << " kcal" << endl;
    cout << "\nZ kolei " << CPM << " kcal jest Ci potrzebne przy twoim trybie życia do prawidłowego funkcjonowania oraz osiągnięcia zamierzonego przez ciebie celu schudnięcia/przytycia/utrzymania stałej wagi.\n" << endl;



    if (BMI < 16){
        cout << "\nTwoj zakres wartosci BMI wskazuje na wyglodzenie." << endl;

        cout << "\nUstal swój dzisiejszy jadłospis. Wybierz to na co masz ochotę." << endl << "\nMenu śniadań: \n" ;
        wybor_uzytkownika = Menu(lista_sniadan);
        wybrane_kcal+=(lista_sniadan.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu obiadów: \n" ;
        wybor_uzytkownika = Menu(lista_obiadow);
        wybrane_kcal+=(lista_obiadow.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu kolacji: \n" ;
        wybor_uzytkownika = Menu(lista_kolacji);
        wybrane_kcal+=(lista_kolacji.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;



        while (wybrane_kcal < CPM || wybrane_kcal > PPM)
        {
            while(wybrane_kcal < PPM)
            {
                cout << "\n\nWygląda na to, że do twojego prawidłowego dziennego zapotrzebowania kalorycznego trochę Ci brakuje! Wybierz dodatkowy posiłek uzupełniający: " << endl;
                wybor_uzytkownika = Menu(lista_dodatkowych);
                wybrane_kcal+=(lista_dodatkowych.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

            if (wybrane_kcal > CPM)
            {
                cout << "\n\n Ups! Ilość kalorii, które powinny zostać przez Ciebie spożyte w ciągu tego dnia została przekroczona! Aby, zbić nadwyżkę kaloryczną wybierz aktywność fizyczną jaką dzisiaj wykonasz: " << endl;
                wybor_uzytkownika = Cwiczenia_odczyt(lista_cwiczen);
                wybrane_kcal-=(lista_cwiczen.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

        }

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;
    }


    else if (16 <= BMI && BMI <= 16.99){
        cout << "Twoj zakres wartosci BMI wskazuje na wychudzenie." << endl;

        cout << "\nUstal swój dzisiejszy jadłospis. Wybierz to na co masz ochotę." << endl << "\nMenu śniadań: \n" ;
        wybor_uzytkownika = Menu(lista_sniadan);
        wybrane_kcal+=(lista_sniadan.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu obiadów: \n" ;
        wybor_uzytkownika = Menu(lista_obiadow);
        wybrane_kcal+=(lista_obiadow.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu kolacji: \n" ;
        wybor_uzytkownika = Menu(lista_kolacji);
        wybrane_kcal+=(lista_kolacji.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;



        while (wybrane_kcal < CPM || wybrane_kcal > PPM)
        {
            while(wybrane_kcal < PPM)
            {
                cout << "\n\nWygląda na to, że do twojego prawidłowego dziennego zapotrzebowania kalorycznego trochę Ci brakuje! Wybierz dodatkowy posiłek uzupełniający: " << endl;
                wybor_uzytkownika = Menu(lista_dodatkowych);
                wybrane_kcal+=(lista_dodatkowych.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

            if (wybrane_kcal > CPM)
            {
                cout << "\n\n Ups! Ilość kalorii, które powinny zostać przez Ciebie spożyte w ciągu tego dnia została przekroczona! Aby, zbić nadwyżkę kaloryczną wybierz aktywność fizyczną jaką dzisiaj wykonasz: " << endl;
                wybor_uzytkownika = Cwiczenia_odczyt(lista_cwiczen);
                wybrane_kcal-=(lista_cwiczen.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

        }

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;
    }



    else if (17 <= BMI && BMI <= 18.49){
        cout << "Twoj zakres wartosci BMI wskazuje na niedowage." << endl;

        cout << "\nUstal swój dzisiejszy jadłospis. Wybierz to na co masz ochotę." << endl << "\nMenu śniadań: \n" ;
        wybor_uzytkownika = Menu(lista_sniadan);
        wybrane_kcal+=(lista_sniadan.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu obiadów: \n" ;
        wybor_uzytkownika = Menu(lista_obiadow);
        wybrane_kcal+=(lista_obiadow.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu kolacji: \n" ;
        wybor_uzytkownika = Menu(lista_kolacji);
        wybrane_kcal+=(lista_kolacji.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;



        while (wybrane_kcal < CPM || wybrane_kcal > PPM)
        {
            while(wybrane_kcal < PPM)
            {
                cout << "\n\nWygląda na to, że do twojego prawidłowego dziennego zapotrzebowania kalorycznego trochę Ci brakuje! Wybierz dodatkowy posiłek uzupełniający: " << endl;
                wybor_uzytkownika = Menu(lista_dodatkowych);
                wybrane_kcal+=(lista_dodatkowych.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

            if (wybrane_kcal > CPM)
            {
                cout << "\n\n Ups! Ilość kalorii, które powinny zostać przez Ciebie spożyte w ciągu tego dnia została przekroczona! Aby, zbić nadwyżkę kaloryczną wybierz aktywność fizyczną jaką dzisiaj wykonasz: " << endl;
                wybor_uzytkownika = Cwiczenia_odczyt(lista_cwiczen);
                wybrane_kcal-=(lista_cwiczen.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

        }

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;
    }



    else if (18.5 <= BMI && BMI <= 24.99){
        cout << "Twoj zakres wartosci BMI wskazuje na prawidlowa wartosc masy ciala." << endl;

        cout << "\nUstal swój dzisiejszy jadłospis. Wybierz to na co masz ochotę." << endl << "\nMenu śniadań: \n" ;
        wybor_uzytkownika = Menu(lista_sniadan);
        wybrane_kcal+=(lista_sniadan.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu obiadów: \n" ;
        wybor_uzytkownika = Menu(lista_obiadow);
        wybrane_kcal+=(lista_obiadow.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu kolacji: \n" ;
        wybor_uzytkownika = Menu(lista_kolacji);
        wybrane_kcal+=(lista_kolacji.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;



        while (wybrane_kcal < CPM || wybrane_kcal > PPM)
        {
            while(wybrane_kcal < PPM)
            {
                cout << "\n\nWygląda na to, że do twojego prawidłowego dziennego zapotrzebowania kalorycznego trochę Ci brakuje! Wybierz dodatkowy posiłek uzupełniający: " << endl;
                wybor_uzytkownika = Menu(lista_dodatkowych);
                wybrane_kcal+=(lista_dodatkowych.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

            if (wybrane_kcal > CPM)
            {
                cout << "\n\n Ups! Ilość kalorii, które powinny zostać przez Ciebie spożyte w ciągu tego dnia została przekroczona! Aby, zbić nadwyżkę kaloryczną wybierz aktywność fizyczną jaką dzisiaj wykonasz: " << endl;
                wybor_uzytkownika = Cwiczenia_odczyt(lista_cwiczen);
                wybrane_kcal-=(lista_cwiczen.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

        }

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;
    }



    else if (25 <= BMI && BMI <= 29.99){
        cout << "Twoj zakres wartosci BMI wskazuje na nadwage." << endl;

        cout << "\nUstal swój dzisiejszy jadłospis. Wybierz to na co masz ochotę." << endl << "\nMenu śniadań: \n" ;
        wybor_uzytkownika = Menu(lista_sniadan);
        wybrane_kcal+=(lista_sniadan.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu obiadów: \n" ;
        wybor_uzytkownika = Menu(lista_obiadow);
        wybrane_kcal+=(lista_obiadow.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu kolacji: \n" ;
        wybor_uzytkownika = Menu(lista_kolacji);
        wybrane_kcal+=(lista_kolacji.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;



        while (wybrane_kcal < CPM || wybrane_kcal > PPM)
        {
            while(wybrane_kcal < PPM)
            {
                cout << "\n\nWygląda na to, że do twojego prawidłowego dziennego zapotrzebowania kalorycznego trochę Ci brakuje! Wybierz dodatkowy posiłek uzupełniający: " << endl;
                wybor_uzytkownika = Menu(lista_dodatkowych);
                wybrane_kcal+=(lista_dodatkowych.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

            if (wybrane_kcal > CPM)
            {
                cout << "\n\n Ups! Ilość kalorii, które powinny zostać przez Ciebie spożyte w ciągu tego dnia została przekroczona! Aby, zbić nadwyżkę kaloryczną wybierz aktywność fizyczną jaką dzisiaj wykonasz: " << endl;
                wybor_uzytkownika = Cwiczenia_odczyt(lista_cwiczen);
                wybrane_kcal-=(lista_cwiczen.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

        }

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;
    }



    else if (30 <= BMI && BMI <= 34.99){
        cout << "Twoj zakres wartosci BMI wskazuje na I stopien otylosci." << endl;

        cout << "\nUstal swój dzisiejszy jadłospis. Wybierz to na co masz ochotę." << endl << "\nMenu śniadań: \n" ;
        wybor_uzytkownika = Menu(lista_sniadan);
        wybrane_kcal+=(lista_sniadan.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu obiadów: \n" ;
        wybor_uzytkownika = Menu(lista_obiadow);
        wybrane_kcal+=(lista_obiadow.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu kolacji: \n" ;
        wybor_uzytkownika = Menu(lista_kolacji);
        wybrane_kcal+=(lista_kolacji.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;



        while (wybrane_kcal < CPM || wybrane_kcal > PPM)
        {
            while(wybrane_kcal < PPM)
            {
                cout << "\n\nWygląda na to, że do twojego prawidłowego dziennego zapotrzebowania kalorycznego trochę Ci brakuje! Wybierz dodatkowy posiłek uzupełniający: " << endl;
                wybor_uzytkownika = Menu(lista_dodatkowych);
                wybrane_kcal+=(lista_dodatkowych.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

            if (wybrane_kcal > CPM)
            {
                cout << "\n\n Ups! Ilość kalorii, które powinny zostać przez Ciebie spożyte w ciągu tego dnia została przekroczona! Aby, zbić nadwyżkę kaloryczną wybierz aktywność fizyczną jaką dzisiaj wykonasz: " << endl;
                wybor_uzytkownika = Cwiczenia_odczyt(lista_cwiczen);
                wybrane_kcal-=(lista_cwiczen.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

        }

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;
    }



    else if (35 <= BMI && BMI <= 39.99){
        cout << "Twoj zakres wartosci BMI wskazuje na II stopien otylosci." << endl;

        cout << "\nUstal swój dzisiejszy jadłospis. Wybierz to na co masz ochotę." << endl << "\nMenu śniadań: \n" ;
        wybor_uzytkownika = Menu(lista_sniadan);
        wybrane_kcal+=(lista_sniadan.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu obiadów: \n" ;
        wybor_uzytkownika = Menu(lista_obiadow);
        wybrane_kcal+=(lista_obiadow.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu kolacji: \n" ;
        wybor_uzytkownika = Menu(lista_kolacji);
        wybrane_kcal+=(lista_kolacji.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;



        while (wybrane_kcal < CPM || wybrane_kcal > PPM)
        {
            while(wybrane_kcal < PPM)
            {
                cout << "\n\nWygląda na to, że do twojego prawidłowego dziennego zapotrzebowania kalorycznego trochę Ci brakuje! Wybierz dodatkowy posiłek uzupełniający: " << endl;
                wybor_uzytkownika = Menu(lista_dodatkowych);
                wybrane_kcal+=(lista_dodatkowych.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

            if (wybrane_kcal > CPM)
            {
                cout << "\n\n Ups! Ilość kalorii, które powinny zostać przez Ciebie spożyte w ciągu tego dnia została przekroczona! Aby, zbić nadwyżkę kaloryczną wybierz aktywność fizyczną jaką dzisiaj wykonasz: " << endl;
                wybor_uzytkownika = Cwiczenia_odczyt(lista_cwiczen);
                wybrane_kcal-=(lista_cwiczen.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

        }

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;
    }



    else if (BMI >= 40){
        cout << "Twoj zakres wartosci BMI wskazuje na otylosc skrajna." << endl;

        cout << "\nUstal swój dzisiejszy jadłospis. Wybierz to na co masz ochotę." << endl << "\nMenu śniadań: \n" ;
        wybor_uzytkownika = Menu(lista_sniadan);
        wybrane_kcal+=(lista_sniadan.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu obiadów: \n" ;
        wybor_uzytkownika = Menu(lista_obiadow);
        wybrane_kcal+=(lista_obiadow.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
        cout << "\nMenu kolacji: \n" ;
        wybor_uzytkownika = Menu(lista_kolacji);
        wybrane_kcal+=(lista_kolacji.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;



        while (wybrane_kcal < CPM || wybrane_kcal > PPM)
        {
            while(wybrane_kcal < PPM)
            {
                cout << "\n\nWygląda na to, że do twojego prawidłowego dziennego zapotrzebowania kalorycznego trochę Ci brakuje! Wybierz dodatkowy posiłek uzupełniający: " << endl;
                wybor_uzytkownika = Menu(lista_dodatkowych);
                wybrane_kcal+=(lista_dodatkowych.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

            if (wybrane_kcal > CPM)
            {
                cout << "\n\n Ups! Ilość kalorii, które powinny zostać przez Ciebie spożyte w ciągu tego dnia została przekroczona! Aby, zbić nadwyżkę kaloryczną wybierz aktywność fizyczną jaką dzisiaj wykonasz: " << endl;
                wybor_uzytkownika = Cwiczenia_odczyt(lista_cwiczen);
                wybrane_kcal-=(lista_cwiczen.Zwracanie_tablicy())[wybor_uzytkownika-1].Zwracanie_kcal();
            }

        }

        cout << "Ilość przyswojonych przez Ciebie kalorii w ciagu tego dnia wyniesie: " << wybrane_kcal << endl;
    }


    cout << "\nGratulacje! Twój dzienny plan żywieniowy jest już gotowy! Powodzenia w przygotowaniu posiłków. Bon Appetit!\n\nP.S. Pamiętaj o piciu wody!";

    return 0;
}
