
#include "app_init.h"
#include "chip_core_irq.h"
#include "common_def.h"
#include "i2c.h"
#include "osal_addr.h"
#include "osal_debug.h"
#include "osal_task.h"
#include "timer.h"

#include "./ins5699s.h"

#define EXP5_1_TASK_PRIO 23
#define EXP5_1_TASK_STACK_SIZE 1000

#define TIMER_DURIATION 1000000
#define TIMER_PRIO 3

#define I2C_MASTER_BUS_ID 1
#define CONFIG_I2C_SCL_MASTER_PIN 15
#define CONFIG_I2C_SDA_MASTER_PIN 16
#define CONFIG_I2C_MASTER_PIN_MODE 2
#define I2C_MASTER_ADDR 0x1
#define I2C_SET_BANDRATE 115200

static timer_handle_t tmh;
static ins5699s_time tdata;

static int changed;

static char *weekmap[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                          "Thursday", "Friday", "Saturday"};

static void my_timer_callback(uintptr_t data) {
  unused(data);
  tdata = ins5699s_GetTime();
  changed = 1;
  uapi_timer_start(tmh, TIMER_DURIATION, my_timer_callback, 0);
}

static int exp5_1_task(const char *arg) {
  unused(arg);
  uapi_timer_init();
  uapi_timer_adapter(TIMER_INDEX_1, TIMER_1_IRQN, TIMER_PRIO);
  uapi_timer_create(TIMER_INDEX_1, &tmh);
  uapi_timer_start(tmh, TIMER_DURIATION, my_timer_callback, 0);

  uapi_pin_set_mode(CONFIG_I2C_SCL_MASTER_PIN, CONFIG_I2C_MASTER_PIN_MODE);
  uapi_pin_set_mode(CONFIG_I2C_SDA_MASTER_PIN, CONFIG_I2C_MASTER_PIN_MODE);
  uint32_t baudrate = I2C_SET_BANDRATE;
  uint32_t master_addr = I2C_MASTER_ADDR;
  uapi_i2c_master_init(I2C_MASTER_BUS_ID, baudrate, master_addr);

  ins5699s_time tar = {.year = (uint8_t)11,
                       .day = (uint8_t)4,
                       .month = (uint8_t)5,
                       .hour = (uint8_t)11,
                       .min = (uint8_t)4,
                       .sec = (uint8_t)51,
                       .week = (uint8_t)2};

  ins5699s_init();
  ins5699s_SetTime(tar);

  tdata = ins5699s_GetTime();
  changed = 1;

  while (1) {
    if (changed) {
      osal_printk("20%d/%d/%d %s  %02d:%02d:%02d\n", tdata.year, tdata.month,
                  tdata.day, weekmap[tdata.week], tdata.hour, tdata.min,
                  tdata.sec);
      changed = 0;
    }
    osal_msleep(2000);
  }

  uapi_timer_stop(tmh);
  uapi_timer_delete(tmh);
  uapi_timer_deinit();

  return 0;
}

static void exp5_1_entry(void) {
  osal_task *task_handle = NULL;
  osal_kthread_lock();
  task_handle = osal_kthread_create((osal_kthread_handler)exp5_1_task, 0,
                                    "exp5", EXP5_1_TASK_STACK_SIZE);
  if (task_handle != NULL) {
    osal_kthread_set_priority(task_handle, EXP5_1_TASK_PRIO);
    osal_kfree(task_handle);
  }
  osal_kthread_unlock();
}

/* Run the timer_entry. */
app_run(exp5_1_entry);
