#ifndef KERNEL_H
#define KERNEL_H

struct sbiret {
    long error;
    long value;
};

struct sbiret sbi_call(long arg0, long arg1, long arg2, 
					   long arg3, long arg4, long arg5,
					   long fid, long eid);
	
__attribute__((section(".text.boot")))
__attribute__((naked))
void boot(void);
void kernel_main(void);

#endif