#include "ins5699s.h"
#include "app_init.h"
#include "common_def.h"
#include "gpio.h"
#include "hal_gpio.h"
#include "i2c.h"
#include "pinctrl.h"
#include "soc_osal.h"

#define I2C_MASTER_BUS_ID 1
void ins5699s_SendREG(uint8_t reg, uint8_t reg_data) {
  uint8_t buffer[] = {reg, reg_data};
  i2c_data_t data = {0};
  data.send_buf = buffer;
  data.send_len = sizeof(buffer);
  errcode_t ret =
      uapi_i2c_master_write(I2C_MASTER_BUS_ID, INS5699S_ADDR >> 1, &data);
  if (ret != 0) {
    printf("INS5699S:I2cWriteREG(%02X) failed, %0X!\n", reg, ret);
    return;
  }
}
uint8_t ins5699s_ReadREG(uint8_t reg) {
  uint8_t send_buffer[] = {reg};
  uint8_t read_buffer[1] = {0};
  i2c_data_t data = {0};
  data.send_buf = send_buffer;
  data.send_len = sizeof(send_buffer);
  data.receive_buf = read_buffer;
  data.receive_len = 1;
  errcode_t ret =
      uapi_i2c_master_writeread(I2C_MASTER_BUS_ID, INS5699S_ADDR >> 1, &data);
  if (ret != 0) {
    printf("INS5699S:I2cReadREG(%02X) failed, %0X!\n", reg, ret);
    return 0;
  }
  return data.receive_buf[0];
}
void ins5699s_init(void) {
  osal_msleep(100);
  osal_printk("INS5699S Init SUCC!\r\n");
}
ins5699s_time ins5699s_GetTime(void) {
  ins5699s_time ret;
  uint8_t secraw = ins5699s_ReadREG(INS5699S_REG_SEC);
  ret.sec = (secraw >> 4) * 10 + (secraw & 0xf);
  uint8_t minraw = ins5699s_ReadREG(INS5699S_REG_MIN);
  ret.min = (minraw >> 4) * 10 + (minraw & 0xf);
  uint8_t hourraw = ins5699s_ReadREG(INS5699S_REG_HOUR);
  ret.hour = (hourraw >> 4) * 10 + (hourraw & 0xf);
  uint8_t weekraw = ins5699s_ReadREG(INS5699S_REG_WEEK);
  uint8_t week = 0;
  while (weekraw > 0) {
    weekraw /= 2;
    week++;
  }
  ret.week = week - 1;
  uint8_t dayraw = ins5699s_ReadREG(INS5699S_REG_DAY);
  ret.day = (dayraw >> 4) * 10 + (dayraw & 0xf);
  uint8_t monthraw = ins5699s_ReadREG(INS5699S_REG_MONTH);
  ret.month = (monthraw >> 4) * 10 + (monthraw & 0xf);
  uint8_t yearraw = ins5699s_ReadREG(INS5699S_REG_YEAR);
  ret.year = (yearraw >> 4) * 10 + (yearraw & 0xf);

  return ret;
}

void ins5699s_SetTime(ins5699s_time dest) {
  ins5699s_SendREG(INS5699S_REG_SEC,
                   ((dest.sec / 10) << 4) + (dest.sec - dest.sec / 10 * 10));
  ins5699s_SendREG(INS5699S_REG_MIN,
                   ((dest.min / 10) << 4) + (dest.min - dest.min / 10 * 10));
  ins5699s_SendREG(INS5699S_REG_HOUR,
                   ((dest.hour / 10) << 4) + (dest.hour - dest.hour / 10 * 10));

  ins5699s_SendREG(INS5699S_REG_YEAR,
                   ((dest.year / 10) << 4) + (dest.year - dest.year / 10 * 10));
  ins5699s_SendREG(INS5699S_REG_MONTH, ((dest.month / 10) << 4) +
                                           (dest.month - dest.month / 10 * 10));
  ins5699s_SendREG(INS5699S_REG_DAY,
                   ((dest.day / 10) << 4) + (dest.day - dest.day / 10 * 10));

  ins5699s_SendREG(INS5699S_REG_WEEK, 1 << dest.week);
}
