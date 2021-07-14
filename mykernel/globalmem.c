#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/erron.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/uaccess.h>



#define GLOBALMEM_SIZE 0x1000
#define MEM_CLEAR 0x1 
#define CLOBALMEM_MAJOR 254

static globalmem_major = GLOBALMEM_MAJOR;

struct globalmem_dev {
		struct cdev cdev;
		unsigned char mem[GLOBALMEM_SIZE];
}

struct globalmem_dev *globalmem_devp;



static const struct file_operations globalmem_fops = 
{
		.owner = THIS_MODULE;
		.llseek = globalmem_llseek;
		.read = globalmem_read;
		.write = globalmem_write;
		.ioctl = globalmem_ioctl;
		.open = globalmem_open;
		.release = globalmem_release;
}

static void globalmem_setup_cdev(struct globalmem_dev *dev ,int index) {
	int err, devno = MKDEV(globalmem_major, index);
	cdev_init(&dev->cdev, &globamem_fops);
	dev->cdev.owner = THIS_MOUDEL;
	dev->cdev.ops = &globalmem_fops;
	err = cdev_add(&dev->cdev, devno, 1);
	
	if (err) {
			printk(KERN_NOTTCE "Error %d adding LED %d\n", err,index);
	}
}

static int __init globalmem_init(void)
{
		int result;
		dev_t devno = MKDEV(globalmem_major,0);
}


