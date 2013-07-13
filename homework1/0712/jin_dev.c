#include <linux/fs.h> 
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h> 
 
#include <asm/uaccess.h>


static struct miscdevice hello_dev = {
        /*
         * MINOR 번호를 직접 지정하지 않고
         * 커널이 선택하도록 한다.
         */
        MISC_DYNAMIC_MINOR,
        /*
         * 장치의 이름을 hello로 한다.
         */
        "jinwoo"
        /*
         * 파일 연산을 할 때 호출되게 될
         * 함수를 정의
         */
};



static int __init hello_init(void)
{
        int ret;

        /*
         * sys/class/misc 디렉토리에 /dev/hello 장치를 만든다.
         * udev가 자동적으로 정해진 규칙에 따라서 /dev/hello 장치를 
         * 만들게 된다.
         */
        ret = misc_register(&hello_dev);
        if (ret)
                //printk(KERN_ERR"Unable to register "Hello, world!" misc devicen");

        return ret;
}

module_init(hello_init);


static void __exit hello_exit(void)
{
        misc_deregister(&hello_dev);
}

module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Valerie Henson <val@nmt.edu>");
//MODULE_DESCRIPTION(""Hello, world!" minimal module");
MODULE_VERSION("dev");

