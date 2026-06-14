# HLS basic floating point example

This project defines a few simple functions to be synthesized, and a testbench to run them on a few random input numbers. The goal of this example is to show how to create a Vitis HLS project, and how to run the different steps of the workflow (simulation, synthesis, etc) from the command line and from the GUI.

## Structure of this example

* `Makefile` with the different commands to run the different steps of the workflow (simulation, synthesis, etc)
* `run_hls.tcl`: TCL script to create the Vitis HLS project and add the files to it
* `src` folder with the source files for the code to be synthesized and the testbench
  * `functions.h`, `functions.cc`: header and source file for the code to be synthesized
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

* [ ] Explore the `src/functions.h` and `src/functions.cc` files to understand the code that will be synthesized into hardware.
* [ ] Explore the `src/testbench.cc` file to understand the testbench that will be used to simulate the design and check the outputs.
* [ ] Run the whole workflow using `make` paying attention to the produced output and logs.
* [ ] Change the code in `src/functions.cc` to add new functions to fill the following utilization table:

| Function | LUTs | FFs | DSPs | Latency | II |
| --- | --- | --- | --- | --- | --- |
| float sum |  |  |  |  |  |  |
| float mult |  |  |  |  |  |
| float div |  |  |  |  |  |
| double sum |  |  |  |  |  |
| double mult |  |  |  |  |  |
| double div |  |  |  |  |  |