#include "app_init.h"
#include "bh1750.h"
#include "common_def.h"
#include "cw2015.h"
#include "osal_addr.h"
#include "osal_debug.h"
#include "osal_task.h"
#define TIMER_TASK_PRIO 23
#define TIMER_TASK_STACK_SIZE 1000
static int work3_task(const char *arg) {
  unused(arg);
  bh1750_init();

  cw2015_init();
  while (1) {

    uint16_t dt = bh1750_GetLightIntensity();
    osal_printk("light density is %d\n", dt);
    uint32_t v = cw2015_GetBatteryVoltage();
    osal_printk("voltage = %d \n", v);
    osal_msleep(2000);
  }
  return 0;
}

static void timer_entry(void) {
  osal_task *task_handle = NULL;
  osal_kthread_lock();
  osal_printk("Timer task starting");
  task_handle = osal_kthread_create((osal_kthread_handler)work3_task, 0,
                                    "work3", TIMER_TASK_STACK_SIZE);
  if (task_handle != NULL) {
    osal_kthread_set_priority(task_handle, TIMER_TASK_PRIO);
    osal_kfree(task_handle);
  }
  osal_kthread_unlock();
}

/* Run the timer_entry. */
app_run(timer_entry);
