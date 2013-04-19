
// simple parallel port linux device driver

#include <linux/module.h>
#include <liuc/config.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENCE("GPL");

// open the driver
static int pp_open(struct inode *inode, struct file *filep)
{
printk("Device open\n");
return 0;
}

// close the driver
static int pp_release(struct inode *inode, struct file *filep)
{
printk("Device closed\n");
return 0;
}

// read from the driver
static ssize_t pp_read(struct file *filep, char *buf, size_t count, loff_t *f_pos)
{
printk("Reading...\n");
return 0;
}

// write to the driver
static ssize_t pp_write(struct file *filep, const char *buf, size_t count, loff_t *f_pos)
{
printk("Writing...\n");
return 0;
}


struct file_operations pp_fops =
{
owner: THIS_MODULE,
open: pp_open,
release: pp_release,
read: pp_read,
write: pp_write,
};

static int __init init_mod(void)
{
int result;
if ((result = register_chrdev(22, "ppio", &pp_fops)) < 0)
goto fail;
printk("Modulo1 started...\n");
return 0;
fail:
return -1;
}

static void __exit end_mod(void){

unregister_chrdev(22, "ppio");
printk("Modulo1 ended...\n");

}

// Macro's
module_init(init_mod);
module_exit(end_mod);
