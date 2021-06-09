#include <linux/module.h>
#include <linux/kthread.h>
 
 
static int loop_func(void *arg)
{
  int i = 0;
  while(!kthread_should_stop()) {
      i++;
  }
    return 0;
}
 
 
struct task_struct *kt;
static int __init init_loop(void)
{
  kt = kthread_run(loop_func, NULL, "loop_thread");
  if (IS_ERR(kt)) {
    return -1;
  }
 
 
  return 0;
}
 
 
static void __exit exit_test(void)
{
  kthread_stop(kt);
}
 
 
module_init(init_loop);
module_exit(exit_test);
MODULE_LICENSE("GPL");
