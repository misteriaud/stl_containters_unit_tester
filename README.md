# Unit Tester for STL Containers

This is a unit tester written with Catch2 in C++98 to test home made implementations of stl containers vector, map, stack and set.
It was build apon the specifications found on [https://cplusplus.com/](https://cplusplus.com/) and [https://cppreference.com/](https://cppreference.com/).

## Setup

1.  Clone the repository to your local machine.
2.  Navigate to the root directory of the project.
3.  Modify the `HDRS` variable in the `Makefile` to point to the directory containing your implementations.
4.  Run `make` to compile the tester.

## Dependencies

-   C++98

## Makefile

The Makefile contains several rules:

-   `all`: Compiles the tester.
-   `clean`: Removes the object files and dependency files.
-   `fclean`: Removes the compiled executable, object files, and dependency files.
-   `re`: Runs `fclean` and then `all`.

## Usage

Executing `./unit_test` will run all the tests for the containers you implemented. It will only display the outputs of the tests that failed. You can use some flags to modify the behaviour of the tester. these flags are implemented by *Catch2*.

#### Flags

- `./unit_test -h` will print all the flags implemented natively by *Catch2*
- `./unit_test -s` will display also the tests that succeed
- `./unit_test "[benchmark]" -d yes` will execute only the benchmark test and print durations for each of the tests.

## Contributing

Bug reports and pull requests are welcome on GitHub at [https://github.com/misteriaud/stl_containters_unit_tester](https://github.com/misteriaud/stl_containters_unit_tester).

## License

The project is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT).

