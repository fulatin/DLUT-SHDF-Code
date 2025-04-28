#include "motor_control.h"
#include "i2c.h"
#include "osal_timer.h"
void pwm_write(uint8_t reg_data) {
  uint8_t buffer[] = {reg_data};
  i2c_data_t data = {0};
  data.send_buf = buffer;
  data.send_len = sizeof(buffer);
  errcode_t ret = uapi_i2c_master_write(I2C_MASTER_BUS_ID, 0x5A, &data);
  if (ret != 0) {
    printf("pwm_write: failed, %0X!\n", ret);
    return;
  }
  printf("pwm_write: success! address:0x5A\r\n");
}

void pwm_writes(uint8_t *reg_data) {
  i2c_data_t data = {0};
  data.send_buf = reg_data;
  data.send_len = sizeof(reg_data);
  errcode_t ret = uapi_i2c_master_write(I2C_MASTER_BUS_ID, 0x5A, &data);
  if (ret != 0) {
    printf("pwm_write: failed, %0X!\n", ret);
    return;
  }
  printf("pwm_write: success! address:0x5A\r\n");
}

// 这里实验中左轮右轮是似乎是给的反的（），所以改了过来

// motor 1
void right_wheel_set(uint16_t CRR, uint16_t limit, bool dir) {
  if (CRR > limit)
    CRR = limit;
  uint8_t CRRH = (CRR & 0xff00) >> 8;
  uint8_t CRRL = CRR & 0x00ff;
  uint8_t PWM1CH1[3] = {0x70, 0x0, 0x0};
  uint8_t PWM1CH2[3] = {0x80, CRRH, CRRL};
  if (dir) {
    pwm_writes(PWM1CH1);
    pwm_writes(PWM1CH2);
  } else {
    uint8_t tmp = PWM1CH1[0];
    PWM1CH1[0] = PWM1CH2[0];
    PWM1CH2[0] = tmp;
    pwm_writes(PWM1CH2);
    pwm_writes(PWM1CH1);
  }
}

// motor 2
void left_wheel_set(uint16_t CRR, uint16_t limit, bool dir) {
  if (CRR > limit)
    CRR = limit;
  uint8_t CRRH = (CRR & 0xff00) >> 8;
  uint8_t CRRL = CRR & 0x00ff;

  // 这里“左轮”的前后控制似乎是反的
  uint8_t PWM1CH2[3] = {0xA0, 0x0, 0x0};
  uint8_t PWM1CH1[3] = {0x90, CRRH, CRRL};
  if (dir) {
    pwm_writes(PWM1CH1);
    pwm_writes(PWM1CH2);
  } else {
    uint8_t tmp = PWM1CH1[0];
    PWM1CH1[0] = PWM1CH2[0];
    PWM1CH2[0] = tmp;
    pwm_writes(PWM1CH2);
    pwm_writes(PWM1CH1);
  }
}
