# create a project
open_project -reset "proj"
# specify the name of the function to synthetize
set_top loop_basic

# load source code for synthesis
add_files src/func.cc
# load source code for the testbench
add_files -tb src/testbench.cc

# create a solution (i.e. a hardware configuration for synthesis)
open_solution -reset "solution" -flow_target vitis

# set the FPGA
set_part {xcu55c-fsvh2892-2L-e}
create_clock -period 3.5

# just check that the C++ compiles
csim_design -ldflags="-fuse-ld=gold" -argv "10 30"

# run synthesis
csynth_design

# run cosimulations
#cosim_design -rtl verilog -ldflags="-fuse-ld=gold"
#cosim_design -rtl vhdl -ldflags="-fuse-ld=gold"

exit
