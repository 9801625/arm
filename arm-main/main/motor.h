struct motor{
  int motor_id;
  uint32_t can_tx_id;
  uint32_t mode_switch_id;
};
void InitMotor(struct motor &data, int motor_id,bool is_gm){
  data.motor_id = motor_id;
  data.can_tx_id = is_gm ? 0x1FF : 0x200;
  data.mode_switch_id = 0x700 + motor_id;
}
