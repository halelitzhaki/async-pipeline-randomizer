
# Asynchronous Pipeline Randomizer

This project implements an asynchronous pipeline that processes numbers through a series of stages, each handled by an Active Object. The pipeline generates random numbers, modifies them, checks for primality, and outputs the results.

## Features

- **Active Object Implementation:** Each stage in the pipeline is managed by an Active Object, encapsulating a thread and a task queue.
- **Thread-Safe Queue:** Utilizes mutexes and condition variables to ensure safe access and to prevent busy-waiting.
- **Random Number Generation:** Generates random numbers with a specified seed to ensure reproducibility.
- **Primality Testing:** Checks if numbers are prime using an efficient algorithm.

## Pipeline Stages

1. **Number Generation:** Generates random numbers and passes them to the next stage.
2. **Addition Stage:** Adds 2 to the number, checks for primality, and passes it on.
3. **Subtraction Stage:** Subtracts 4 from the number, checks for primality, and passes it on.
4. **Final Addition Stage:** Adds 2 to the number and outputs the final result.

## Usage

1. **Compilation:**

   ```bash
   make all
   ```

2. **Execution:**

   ```bash
   ./st_pipeline <N> [<seed>]
   ```

   - `<N>`: Number of tasks to process.
   - `<seed>` (optional): Seed for random number generation. If not provided, a default seed is used.

3. **Clean Up:**

   ```bash
   make clean
   ```

## Example

```bash
./st_pipeline 2 123456
```

Output:

```
Generated number: 123456
123458 is not prime
123454 is not prime
Final number: 123456
```

## Notes

- Ensure that the `Makefile` is present and correctly configured.
- The program is written in C.
- The pipeline ensures that the final number matches the initially generated number after all transformations.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

## Contact

For questions or suggestions, please open an issue in the repository or contact the maintainer directly.
