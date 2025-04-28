
#include "app_init.h"
#include "chip_core_irq.h"
#include "common_def.h"
#include "i2c.h"
#include "osal_addr.h"
#include "osal_debug.h"
#include "osal_task.h"
#include <timer.h>

#include "./motor_control.h"
#define EXP6_TASK_PRIO 23
#define EXP6_TASK_STACK_SIZE 1000

#define I2C_MASTER_BUS_ID 1
#define CONFIG_I2C_SCL_MASTER_PIN 15
#define CONFIG_I2C_SDA_MASTER_PIN 16
#define CONFIG_I2C_MASTER_PIN_MODE 2
#define I2C_MASTER_ADDR 0x1
#define I2C_SET_BANDRATE 115200

static int exp6_task(const char *arg) {
  unused(arg);

  osal_printk("experiment6 start \n");
  uapi_pin_set_mode(CONFIG_I2C_SCL_MASTER_PIN, CONFIG_I2C_MASTER_PIN_MODE);
  uapi_pin_set_mode(CONFIG_I2C_SDA_MASTER_PIN, CONFIG_I2C_MASTER_PIN_MODE);
  uint32_t baudrate = I2C_SET_BANDRATE;
  uint32_t master_addr = I2C_MASTER_ADDR;
  uapi_i2c_master_init(I2C_MASTER_BUS_ID, baudrate, master_addr);

  pwm_write(0x16);

  right_wheel_set(600, 600, true); // 右轮正转一秒
  osal_msleep(1000);
  right_wheel_set(0, 0, true); // 右轮停

  left_wheel_set(600, 600, true); // 左轮正转一秒
  osal_msleep(1000);
  left_wheel_set(0, 0, true); // 左轮停

  // 左右轮一起正转
  left_wheel_set(600, 600, true);
  right_wheel_set(600, 600, true);
  osal_msleep(1000);

  // 左右轮一起反转
  left_wheel_set(100, 100, false);
  right_wheel_set(100, 100, false);
  osal_msleep(6000);

  // 左右轮停
  left_wheel_set(0, 600, true);
  right_wheel_set(0, 600, true);
  return 0;
}

static void exp6_entry(void) {
  osal_task *task_handle = NULL;
  osal_kthread_lock();
  task_handle = osal_kthread_create((osal_kthread_handler)exp6_task, 0, "exp6",
                                    EXP6_TASK_STACK_SIZE);
  if (task_handle != NULL) {
    osal_kthread_set_priority(task_handle, EXP6_TASK_PRIO);
    osal_kfree(task_handle);
  }
  osal_kthread_unlock();
}

/* Run the timer_entry. */
app_run(exp6_entry);
