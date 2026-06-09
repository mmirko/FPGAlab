.PHONY: runhls
runhls:
	vitis_hls -f run_hls.tcl

runhls25:
	vitis-run --tcl run_hls.tcl

.PHONY: xclbin
xclbin: runhls
	v++ -l -t hw --platform xilinx_u55c_gen3x16_xdma_3_202210_1 -o firmware.xclbin proj/solution/impl/export.xo

clean:
	rm -rf proj *.log .ip firmware.* .Xil .ipcache _x logs
