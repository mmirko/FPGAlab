import pynq

# load the bitfile onto device and get handle for IP
overlay = pynq.Overlay('firmware.xclbin')

bulksum = overlay.bulksum_1 # the "_1" is added by Vitis

# print the function signature to verify
print(f'IP signature: {bulksum.signature}')
