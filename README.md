# CPPConsole

CPPConsole is a header-only library for `C++` projects that adds features to the console to make logging easier, like getting dimensions, coloring text, etc.

## Using CPPConsole

To use CPPConsole in your project, copy all the file located in the `include/` directory into your own personal `include/` folder.
After that, you can add `#include "cppconsole.hpp"` to your file to include all CPPConsole functions, or include each file individually.

## Features

* ANSI Escape Code support
* Cross-platform support for Windows and Linux for most functions
* Colorizing text using RGB values
* Moving the Console cursor
* Getting Console Dimensions
* Clearing parts of the Console
* Manipulating text graphics, like making text bold/italic
* Printing data structures, like vectors and maps

## Examples

``` cpp
std::vector<std::string> vec = {"a", "b", "c", "d", "e"};
vec[0] = console::colorize(vec[0], 255, 255, 0);
console::println(vec);
```

``` cpp
console::set({console::Graphics::BOLD, console::Graphics::ITALIC});
console::Dimensions dim = console::getDimensions();
for (int i = 0; i < 256; ++i) {
    if (i % (dim.width / 4) == 0)
        console::println();
    console::print(console::colorize(std::string(3 - std::to_string(i).length(), ' ') + std::to_string(i), i) + " ");
}
```

## Screenshots

![Example 1](./assets/example1.png)
![Example 2](./assets/example2.png)
