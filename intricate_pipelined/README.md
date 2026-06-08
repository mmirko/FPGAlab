# HLS an example with a more intricate function calls and pipelining

This project defines a few simple functions to be synthesized, and a testbench to run them on a few random input numbers. The goal of this example is to show how latency and II are affected by the different function calls, and how to analyze the generated RTL code to understand how the original C++ code was translated into hardware.

## Structure of this example

* `Makefile` with the different commands to run the different steps of the workflow (simulation, synthesis, etc)
* `run_hls.tcl`: TCL script to create the Vitis HLS project and add the files to it
* `src` folder with the source files for the code to be synthesized and the testbench
  * `intricate.h`, `intricate.cc`: header and source file for the code to be synthesized
  * `testbench.cc`: source file for the testbench with random input generation and output checking

## Running the example (Makefile)

`make` will run the whole workflow (simulation, synthesis, etc) and generate the reports in the `proj/solution/syn/report` folder.

## Running the example (command line without Makefile)

### Create the Vitis HLS project

`vitis_hls -f run_hls.tcl`

## Open the project in the GUI

After creating the project using the tcl script (default name from script is `proj`)

`vitis_hls -p proj`

## Hands-on checklist

* [ ] Explore the `src/intricate.h` and `src/intricate.cc` files to understand the code that will be synthesized into hardware.
* [ ] Explore the `src/testbench.cc` file to understand the testbench that will be used to simulate the design and check the outputs.
* [ ] Run the whole workflow using `make` paying attention to the produced output and logs.
* [ ] Explore the generated reports in the `proj/solution/syn/report` folder to understand the latency and II of the different functions, and how they are affected by the different function calls.
  * [ ] Latency
  * [ ] II
* [ ] Explore the generated RTL code in the `proj/solution/syn` folder to understand how the original C++ code was translated into hardware, and how the different function calls were implemented in the generated RTL code.
* [ ] Check the differences in the generated RTL code between this example and the one without pipelining, to understand how the pipelining directive affected the generated RTL code.