#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h> 
#include <linux/sched.h>
#include <linux/init_task.h>


static int hello_init(void)
{
	long  cr3;
	__asm__ __volatile__ (
   		"mov %%cr3, %%rax\n\t"
    	"mov %%rax, %0\n\t"
    	: "=m" (cr3)
    	:
    	: "%rax"
   );
	pr_err("cr3 = 0x%lx ", (long)cr3);
	pr_err("\tcurrent->mm->pgd = 0x%lx\n", current->mm->pgd);
    return 0;
}

static void hello_exit(void)
{
                printk(KERN_ALERT "goodbye!\n");
}


module_init(hello_init);
module_exit(hello_exit);



MODULE_LICENSE("GPL");

