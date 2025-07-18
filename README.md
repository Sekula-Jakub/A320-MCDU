# KOMPUTER POKŁADOWY SAMOLOTU AIRBUS A320 - MCDU
### Projekt używający C++ i biblioteki SFML do stworzenia programu okienkowego symulującego działanie MCDU - Multipurpose Control and Disply Unit
### Przykładowy wygląd programu
![obrazek1](Readme_images/Obraz7.png)
### Cel projektu
Celem projektu jest stworzenie symulowanego komputera pokładowego MCDU 
(Multipurpose Control and Disply Unit) obsługującego jedynie podstawowe zadania 
oraz prostą bazę danych stworzoną na podstawie danych udostępnianych przez PANSA 
(Polską Agencję Żeglugi Powietrznej).

### Wzornictwo
Projekt inspirowany interfejsem MCDU samolotu Airbus A320-200.  
Układ graficzny został samodzielnie odwzorowany na podstawie ogólnodostępnych źródeł.

### Działanie 
Projekt działa w oparciu o bibliotekę SFML oraz bazę danych stworzoną przy 
pomocy SQLite. Z bazy pobierane są informacje na temat lotnisk wybieranych
podczas wypełniania odpowiednich stron.

### Instrukcja
Sczegółowa instrukcja użytkowania znajduje się w pliku [instrukcja.pdf](instrukcja.pdf)

### Podgląd 
![obrazek2](Readme_images/Obraz6.png)

### Uruchamianie
#### Instalacja wymaganych pakietów
```
sudo apt update
sudo apt install build-essential cmake git \
    libx11-dev libxrandr-dev libfreetype6-dev \
    libgl1-mesa-dev libudev-dev libopenal-dev \
    libvorbis-dev libflac-dev
```

#### Pobranie projektu z GitHub
```
git clone https://github.com/Sekula-Jakub/A320-MCDU.git
```

#### Utworzenie katalogu build i skonfigurowanie projektu
```
cd A320-MCDU
mkdir build
cd build
cmake ..
```

#### Zbudowanie projektu
```
make
```

#### Uruchomienie programu z głównego katalogu
```
cd ..
./build/MCDU
```

### Źródła danych do bazy danych
Dane (kody lotnisk, współrzędne geograficzne) pochodzą z AIP IFR PANSA
(https://www.ais.pansa.pl/publikacje/aip-polska/) 