# Advent Of Code 2024

## 11/24/2024
In preparation of AoC, I will be writing some helper functions like reading a text file and setting
up the "build system for my cpp files. The goal here is to work on standing up smaller cpp 
projects and get more reps in understanding cpp nuances. I might tack on CMAKE just for extra 
practice.

## 11/25/2024
I'm on the east coast right now in Florida. I finally configured the CMake system for my AoC utils 
library. I used chatgpt to start and referenced some other cmake projects. I added the following structure for my project:

```
aoc
|-- 2024/
|-- utils/
|   |-- include/utils
|   |-- src/
|   |-- tests/
|   |   |-- unittests/
|   |   |-- CMakeLists.txt
|   |   |-- Sources.cmake
|   |-- CMakeLists.txt
|   |__ Sources.cmake
```

This may have been a bit overkill but I wanted a nice testing system in place. I went with Google 
Tests since it's something I've used in my job before. The goal here is to have `utils` be just a 
library with a bunch of utility functions that I'll use throughout AoC.

*Some notes about setting up CMake*
When asking ChatGPT, it did not suggest using `Sources.cmake`. I like this separation where we list
out all the source files. I think the `CMakeLists.txt` file would get too cluttered otherwise. It 
may not be necessary for smaller projects, but I went ahead anyways. Being able to just list your 
files and then just add `include("Sources.cmake")` just satisfies an itch in my brain.

My simple, 7-line `utils/CMakeLists.txt` file already caused an error when building since I had 
set `target_include_directories` to PRIVATE. This resulted in my test source file not being able 
to find the include it needed for testing. Changing this to PUBLIC fixed this issue.

From one of the cmake projects I was referencing, they used ctest. I tried configuring this utils 
library with ctest but didn't find much value in adding it. I left this out since the test 
executable is built and I can just run that. I am guessing if there was a large testing base this 
is where ctest might be helpful. Maybe running only certain subsets of tests and whatnot. I would 
think Google Tests has that too but I haven't looked much into this.

I learned that when linking `gtest_main`, you don't need your own `main()` function since a default
is used. It just initializes the framework and runs the tests. I'm sure there are configurations 
which can be set when you manually define the main function yourself. Also controlling setup and 
teardown of these tests but I think for this project it won't be necessary.

Things I want to do next:
- [ ] Learn to use multiple tabs with vim
- [X] Implement `ReadTextFileToLines`
- [ ] Investigate CTRL backspace in vim and Ubuntu terminal
- [ ] Small script to configure and build utils project
- [ ] add execution of tests to script

## 12/2/2024
Starting AoC a bit late because of Thanksgiving week but I am here now. Just moved all this project
from my work laptop to here since I don't have a personal laptop at the moment. Just gonna work on 
completing the 2 days of AoC and then focus on the other bells and whistles the next day.

So update on my work, I finished making the whole repo a CMake project and a 2024 project. I think 
I will only work on day 1 and continue on tomorrow. I was able to implement `ReadTextFileToLines`. 
The script to configure and build will definitely be huge. So I'll probably work on that soon.

*Notes on CMake multiple projects*
I had to make the top level `aoc/` directory a CMake project to link `2024/` with `utils/`. I will 
need to add a few things to the build script so I can build certain targets. I had to add options 
to manually set whether I want to build `utils/` or not. I also need to move the exectuables to 
have them more accessible. I can see the strength of CMake, it is just annoying to work with. 
Anyways, I just condition `add_subdirectory(<project>)` based on the options I created which are 
just macros I manually set such as `cmake .. -DBUILD_UTILS=ON`. 

*Notes on 2024 source code setup*
I went with making this a single executable where I will be adding `dayXX` functions to a single 
`main.cpp` file with a `main()` function. I also decided on storing all my input text files in 
`data/` and will need to work with the build script to move these text files appropriately too 
since I will need the path to be consistent. Maybe I will just have all my input files under 
`aoc/inputs/2024/` but idk, that seems ugly since I wanted everything separated by year.

## 12/8/2024
Didn't get around to day2 until Saturday December 7th, and even then only got through part 1. I 
finally got part 2 today. This had to do with refactoring part of the solution from part 1 into a 
helper function. This made the code a lot more succinct. I wonder if ther is a more optimal way for
doing this. I just made a bunch of permutations. I took a peek at day3 and it involves regex -_-

*Notes from implementation*
I didn't really learn much except how annoying parsing is in C++. I am using `std::istringstream` 
a lot which helps but still am not entirely sure how it works under the hood. I am assuming use of 
C parsing functions like stoi, etc.
