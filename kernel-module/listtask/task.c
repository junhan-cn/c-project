#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h> 
#include <linux/sched.h>
#include <linux/init_task.h>

static int hello_init(void)
{
		struct task_struct *p;
		p = NULL;
		printk(KERN_ALERT "名称\t进程号\t状态\t优先级\t父进程号\t");
		for_each_process(p) {
				printk(KERN_ALERT "%s\t%d\t%ld\t%d\n",p->comm,p->pid, p->state, p->normal_prio, p->parent->pid);
		}
		return 0;
}

static void hello_exit(void)
{
		printk(KERN_ALERT "goodbye!\n");
}


module_init(hello_init);
module_exit(hello_exit);



MODULE_LICENSE("GPL");
