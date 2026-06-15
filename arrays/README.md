# Arrays in HLS

A function that reads two input arrays `a[i]`, `b[i]`, and computes the products (dropping the 8 least significant bits), and adds them up.

It's implemented in 4 versions:

* `mul_add_basic`: no pragmas specified.
* `mul_add_alloff`: no pipelining, no partitioning
* `mul_add_pipelined`: adding `#pragma HLS pipeline II=1`
* `mul_add_partitioned`: adding `#pragma HLS array_partition variable=X complete` for both input arrays

## Structure of this example

* `Makefile` with the different commands to run the different steps of the workflow (simulation, synthesis, etc)
* `run_hls.tcl`: TCL script to create the Vitis HLS project and add the files to it
* `src` folder with the source files for the code to be synthesized and the testbench
  * `func.h`, `func.cc`: header and source file for the code to be synthesized
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
* [ ] Try out the different versions of the function and check the reports to see how the performance and resource utilization changes.
* [ ] What happens with the pipelining version ?