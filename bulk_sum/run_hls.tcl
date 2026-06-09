open_project -reset proj
set_top bulksum
add_files src/bulksum.cc
add_files -tb src/testbench.cc

# reset the solution
open_solution -reset "solution" -flow_target vitis
set_part {xcu55c-fsvh2892-2L-e}
create_clock -period 3.5

# just check that the C++ compiles
csim_design -argv "10 30"

# synthethize the algorithm
csynth_design

export_design -format xo

quit
