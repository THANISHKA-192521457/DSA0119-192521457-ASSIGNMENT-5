# Assignment 5 – CO5: Reliable Software with Runtime Polymorphism and Exceptions

This package is organized around the supplied 16-page assignment PDF.

## Folder map
- Task01_Design: A1 common interface, UML and algorithmic pseudocode.
- Task02_Runtime_Binding: A2 virtual dispatch program, vtable diagram and prediction.
- Task03_Abstract_Payers: A3 payer interface, derived payers and corporate extension.
- Task04_Exception_Strategy: A4 exception design, error matrix and executable demo.
- Task05_Recovery_RAII: A5 stack unwinding and RAII/rethrow demo.
- Task06_B1_Implementation: B1 completed TODO 1–3 program.
- Task07_B2_Error_Conditions: B2 completed TODOs and error-condition tests.
- Task08_B3_Benchmark: B3 benchmark programs and measurement instructions.
- Task09_B4_Extension: B4 new EmergencyBill and CorporatePayer.
- Sanitizer_Evidence: AddressSanitizer build/run reports where supported.

Build command:
`g++ -std=c++17 -Wall -Wextra -O2 source.cpp -o program`

Sanitizer command:
`g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer source.cpp -o program_asan`

## Mandatory personal submission steps
1. Rename your GitHub repository `DSA01-<RegisterNumber>-Assignment5`.
2. Add your name, register number, compiler version and GitHub URL.
3. Run each program on your own computer and save personal terminal screenshots showing
   the command and output in each Task folder.
4. Run B3 at 1,000, 1,000,000 and 10,000,000 bills, and test 0%, 1% and 50% invalid
   claims. Record your own machine's results.
5. Make at least one progressive Git commit per task.
6. Put the working GitHub link on the report cover page.

## Screenshot integrity
PNG terminal output captures are generated from stdout captured when programs were
compiled and run in this package environment. They are not photographs of your desktop.
Replace or supplement them with screenshots from your own computer if your instructor
requires personal execution screenshots. No personal name, register number or GitHub link
has been invented.

## Measurement note
Benchmark timings depend on CPU, compiler, operating-system load and memory. The included
benchmark log is a baseline from this environment, not a claim about your computer.
