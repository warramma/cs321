/**
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/hash.h>
#include <linux/gcd.h>

long int start_jiffies;
/* This function is called when the module is loaded. */
static int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
	printk(KERN_INFO "Golden ratio prime: %llu\n", GOLDEN_RATIO_PRIME);
	start_jiffies = jiffies;
	printk(KERN_INFO "Current jiffies: %lu\n", jiffies);
       return 0;
}

/* This function is called when the module is removed. */
static void simple_exit(void) {
	printk(KERN_INFO "GCD of 3,300 and 24 %lu:\n", gcd(3300,24));	
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init ); //when you insert the module into the kernel
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

