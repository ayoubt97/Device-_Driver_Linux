#include<linux/moodule.h>

/* This is module initialization entry point */
/* module initialization function*/
/* must return 0 for success nonzero means initialization failed.So the module will not get loaded in the kernel */
/* This entry point to module (like main). This function will get called during boot time in the case of static modules */
/* in the case of dynamic modules, this function will get called during module insertion*/
/* There should be ne module initialieation entry point in the module */
static int __init my_kernel_module_init(void)
{
    /* kernel's printf */
    pr_info("Hello World! \n");
    return 0;
}
/*Module clean_up function
-This is an entry point when the module is removed
-since you can not relove static modules, clean-up function will get called only in the case of dynamic modules when it is removed using user space command such as rmmod
- if you write a lodule and you are sure that it will alwayse be statically linked with the kernel,then there is no need to implement this function
- even if your ststic module has a clean-up function,the kernel bbuils system will remove it during the build process if there is an __exit marker */

/* This is module clean-up entry point */
static void __exit my_kernel_module_exit(void)
{
    pr_info("Good by World\n");
}

/* This is module registration of above entry point with kernl */
module_init(my_kernel_module_init);
module_exit(my_kernel_module_exit);

/*This is descriptive information about the modume*/

MODULE_LICENCE("GBL");
MODULE_AUTHOR("TEZNINE");
MODULE_DESCRIPTION("A kernel module to print Hello world ");