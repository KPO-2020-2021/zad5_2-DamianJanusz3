## Informacje na temat testów
W klasach Scene i Drone znajdują się metody które uogólniając ruszają dronem, albo odpowiadają za
kontakt z użytkownikiem. Nie mam pomysłu na ich testy a nawet zastanawiam się czy są one wykonalne.
W pliku testowym cuboid.cpp testuję tak naprawdę odziedziczone metody klasy solid. Klasy Cuboid i
Prism nie mają strikte swoich testów bo zawierają w sobie tylko konstruktor destruktor i wszystko od klasy Solid.

Stwierdzenia z fazy 1 pozostają w mocy. W fazie 2 dodany został tylko jeden test dla metody gettype().
## informacje ogólne
Nie za dobrze z asercjami, ale w ramach poprawnego wykożystywania wszystko działa.
Nie do końca wiem czy dobrze zrobiłem doxygena, ale stronę html odpalałem wchodząc do dox->html i klikałem losowy plik 
z końcówką .html. strona się odpala wszystko tam jest. 
## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: cmake, gnuplot, doxygen + dot (in graphviz library)

Example:

``` bash
> mkdir build && cd build
> cmake .. #### options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make     #### compilation
> ./main   #### main() from app
> make test      #### Compile the tests
> ./unit_tests -s   #### Start the tests, -s flag - full description of each case
> make fulltest #### alternative for above, compile & run tests with full decription
> make coverage  #### Generate a coverage report
> make doc       #### Generate html documentation
```

Things to remember:
* changes to CMakeLists.txt in the main folder with new files added, i.e.:
```cpp
# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------
set(SOURCES          # All .cpp files in src/
    src/lacze_do_gnuplota
    src/Matrix2x2.cpp
    src/Rectangle .cpp
    src/Vector2D.cpp # etc.
)
set(TESTFILES        # All .cpp files in tests/
    Vector2D.cpp
    Matrix2x2.cpp
    Rectangle.cpp # etc.
)
set(LIBRARY_NAME zadX)  # Default name for the library built from src/*.cpp (change if you wish)
```
* changes to tests/CMakeLists.txt (in tests subfolder) with new files added, i.e.:
```cpp
# List all files containing tests. (Change as needed)
set(TESTFILES        # All .cpp files in tests/
    main.cpp
    test_Wektor2D.cpp
    test_Macierz2x2.cpp
    test_Prostokat.cpp # etc.
)
```
The `main.cpp` in the folder `tests` is needed. Only there we define `#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN`.

The main loop of the program is in the `app` folder.

