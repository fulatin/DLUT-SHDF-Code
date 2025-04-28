
#include "app_init.h"
#include "chip_core_irq.h"
#include "common_def.h"
#include "osal_addr.h"
#include "osal_debug.h"
#include "osal_task.h"
#define TIMER_PRIO 3

#include <timer.h>
#define EXP5_TASK_PRIO 23
#define EXP5_TASK_STACK_SIZE 1000

#define TIMER_DURIATION 1000000

static int hour, minute, second;
static timer_handle_t tmh;

static void my_timer_callback(uintptr_t data) {
  unused(data);
  second++;
  uapi_timer_start(tmh, TIMER_DURIATION, my_timer_callback, 0);
}

static int exp5_task(const char *arg) {
  unused(arg);
  uapi_timer_init();
  uapi_timer_adapter(TIMER_INDEX_1, TIMER_1_IRQN, TIMER_PRIO);
  uapi_timer_create(TIMER_INDEX_1, &tmh);
  uapi_timer_start(tmh, TIMER_DURIATION, my_timer_callback, 0);
  while (1) {
    if (second >= 60) {
      second = 0;
      minute++;
    }
    if (minute >= 60) {
      minute = 0;
      hour++;
    }
    if (hour >= 24) {
      hour = 0;
    }

    osal_printk("Now it is %02d:%02d:%02d\n", hour, minute, second);
    osal_msleep(2000);
  }
  uapi_timer_stop(tmh);
  uapi_timer_delete(tmh);
  uapi_timer_deinit();
  return 0;
}

static void exp5_entry(void) {
  osal_task *task_handle = NULL;
  osal_kthread_lock();
  task_handle = osal_kthread_create((osal_kthread_handler)exp5_task, 0, "exp5",
                                    EXP5_TASK_STACK_SIZE);
  if (task_handle != NULL) {
    osal_kthread_set_priority(task_handle, EXP5_TASK_PRIO);
    osal_kfree(task_handle);
  }
  osal_kthread_unlock();
}

/* Run the timer_entry. */
app_run(exp5_entry);
