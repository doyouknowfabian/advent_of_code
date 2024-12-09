# Fabian's Advent of Code

This is my little repository for Advent of Code I am starting in 2024

## How I am currently adding solutions every day
1. add `void dayXX();` to `2024/include/2024/days.h` (where XX is the numerical day)
2. create `2024/src/dayXX.cpp` with `void dayXX()` function implementation (the solution for each 
part printed out)
3. add new file to `Sources.cmake`
4. download input file and put in both `2024/inputs/` and copy over to local `inputs/` folder
on the same level as `build/` (which is ignored by git)
5. run `cmake ..` from the `build/` directory (which is on the same level as `2024`
6. run `make` within `build/`
7. run `build/2024/2024` executable

*I need to write a script for this T-T*
