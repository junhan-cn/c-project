/*
 *  linux/mykernel/mymain.c
 *
 *  Kernel internal my_start_kernel
 *
 *  Copyright (C) 2013  Mengning
 *
 */
#include <linux/types.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/stackprotector.h>
#include <linux/string.h>
#include <linux/ctype.h>
#include <linux/delay.h>
#include <linux/ioport.h>
#include <linux/init.h>
#include <linux/initrd.h>
#include <linux/acpi.h>
#include <linux/tty.h>
#include <linux/percpu.h>
#include <linux/kmod.h>
#include <linux/vmalloc.h>
#include <linux/kernel_stat.h>
#include <linux/start_kernel.h>
#include <linux/security.h>
#include <linux/smp.h>
#include <linux/profile.h>
#include <linux/rcupdate.h>
#include <linux/moduleparam.h>
#include <linux/kallsyms.h>
#include <linux/writeback.h>
#include <linux/cpu.h>
#include <linux/cpuset.h>
#include <linux/cgroup.h>
#include <linux/efi.h>
#include <linux/tick.h>
#include <linux/interrupt.h>
#include <linux/taskstats_kern.h>
#include <linux/delayacct.h>
#include <linux/unistd.h>
#include <linux/rmap.h>
#include <linux/mempolicy.h>
#include <linux/key.h>
#include <linux/buffer_head.h>
#include <linux/debug_locks.h>
#include <linux/debugobjects.h>
#include <linux/lockdep.h>
#include <linux/kmemleak.h>
#include <linux/pid_namespace.h>
#include <linux/device.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/signal.h>
#include <linux/idr.h>
#include <linux/kgdb.h>
#include <linux/ftrace.h>
#include <linux/async.h>
#include <linux/sfi.h>
#include <linux/shmem_fs.h>
#include <linux/slab.h>
#include <linux/perf_event.h>
#include <linux/file.h>
#include <linux/ptrace.h>
#include <linux/blkdev.h>
#include <linux/elevator.h>

#include <asm/io.h>
#include <asm/bugs.h>
#include <asm/setup.h>
#include <asm/sections.h>
#include <asm/cacheflush.h>

#include <linux/list.h>
#include <linux/kfifo.h>
#ifdef CONFIG_X86_LOCAL_APIC
#include <asm/smp.h>
#endif

void __init my_start_kernel(void)
{
	int i = 0;
	while (1) {
		i++;
		if (i % 100000000 == 0) {
			pr_notice("my_start_kernel here  %d \n", i);

			//Linux内核中的链表
			struct fox {
				unsigned long tail_length; //尾巴长度
				unsigned long weight; //重量
				struct list_head list; //fox结构形成的链表
			};

			struct fox *red_fox;
			red_fox = kmalloc(sizeof(*red_fox), GFP_KERNEL);
			red_fox->tail_length = 40;
			red_fox->weight = 10;
			INIT_LIST_HEAD(&(red_fox->list));

			struct fox *red_fox2;
			red_fox2 = kmalloc(sizeof(*red_fox2), GFP_KERNEL);
			red_fox2->tail_length = 30;
			red_fox2->weight = 8;

			struct fox *red_fox3;
			red_fox3 = kmalloc(sizeof(*red_fox3), GFP_KERNEL);
			red_fox3->tail_length = 20;
			red_fox3->weight = 6;

			list_add(&(red_fox2->list), &(red_fox->list));
			list_add(&(red_fox3->list), &(red_fox2->list));

			struct fox *p;
			list_for_each_entry (p, &(red_fox->list), list) {
				pr_notice("print %ld\n", p->tail_length);
			}

			//Linux内核中的队列
			struct kfifo fifo;

			int ret = 0;
            //unsigned char buf[1024] = {1,2,3,4,5};

			ret = kfifo_alloc(&fifo, 1024, GFP_KERNEL);
			if (ret)
					return -1;

			//kfifo_in(&fifo, buf, 20);
			//kfifo_put(&fifo,100);
			int i;
			for (i = 1 ; i != 10 ; i++) {
					kfifo_put(&fifo, i);
			}
			while(kfifo_get(&fifo, &i)) {
					pr_notice("KFIFO item = %d\n", i);
			}

		}
	}
}
