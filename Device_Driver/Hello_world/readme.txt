Module initialization function
-You may do some initialization of devices
-Initialization of device private data structures
-Requesting memory dynalically for various kernel data structures and services 
-Request for allocation of major-minor numbes
-Device file creation

=> The module initialization function is module-specific and should never be called from other modules of the kernel.It should not provide any services or functionalities which may be requested by other modules. Hence it makes sense to make this function private using'static' though it is optional

Module clean_up function
- Typically, you must do exact reverse what you had done in the module init function. undoing init function.
- free memory which are requested in init function
-De-init the devices or leave the devicein the proper state
