# Bulk sum example running on Alveo U55c

This project demonstrates running a simple HLS IP (kernel) on the Alveo U55c.
The kernel will take two vectors of 16-bit integers, and write the element-wise sum in a vector of 16-bit integers.
The kernel will be reading the inputs and writing the outputs from the device memory.

## Structure of this example

* `Makefile` with the different commands to run the different steps of the workflow (simulation, synthesis, etc)
* `run_hls.tcl`: TCL script to create the Vitis HLS project and add the files to it
* `src` folder with the source files for the code to be synthesized and the testbench
  * `bulksum.h`, `bulksum.cc`: header and source file for the code to be synthesized
  * `testbench.cc`: source file for the testbench with random input generation and output checking

## Running the example (Makefile)

`make xclbin` will run the whole workflow (simulation, synthesis), and produce the bitfile `firmware.xclbin` that can be loaded on the Alveo U55c.

## Running the example (command line without Makefile)

### Create the Vitis HLS project

`vitis_hls -f run_hls.tcl`

## Open the project in the GUI

After creating the project using the tcl script (default name from script is `proj`)

`vitis_hls -p proj`

## Hands-on checklist

* [ ] Explore the `Makefile` to understand the additional xclbin target
* [ ] Explore the `run_hls.tcl` script to understand the differencies with the basic_sum example.
  * [ ] Flag to specify the Vitis flow.
  * [ ] Presence of the export_design step.
* [ ] Explore the `src/bulksum.h` and `src/bulksum.cc` files to understand the code that will be synthesized into hardware.
* [ ] Explore the `src/testbench.cc` file to understand the testbench that will be used to simulate the design and check the outputs.
* [ ] Search and analyze the generated RTL code to understand how the original C++ code was translated into hardware. Check out the differences between the Vivado and Vitis generated RTL code.
  * [ ] VHDL module.
  * [ ] Verilog module.
* [ ] Run the python scripts to interact with the Alveo U55c and run the test on the hardware.
  * [ ] `checks.py` checks several properties of the generated bitfile, such as the presence of the kernel and the correct signature.
  * [ ] `run.py` runs the kernel on the Alveo U55c and checks the outputs against a reference evaluation done on the CPU.