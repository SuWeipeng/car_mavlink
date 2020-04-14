#pragma once
// MESSAGE PWM_RPM PACKING

#define MAVLINK_MSG_ID_PWM_RPM 12

MAVPACKED(
typedef struct __mavlink_pwm_rpm_t {
 float rpm; /*<  Revolution(s) Per Minute*/
 int16_t pwm; /*<  */
}) mavlink_pwm_rpm_t;

#define MAVLINK_MSG_ID_PWM_RPM_LEN 6
#define MAVLINK_MSG_ID_PWM_RPM_MIN_LEN 6
#define MAVLINK_MSG_ID_12_LEN 6
#define MAVLINK_MSG_ID_12_MIN_LEN 6

#define MAVLINK_MSG_ID_PWM_RPM_CRC 165
#define MAVLINK_MSG_ID_12_CRC 165



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PWM_RPM { \
    12, \
    "PWM_RPM", \
    2, \
    {  { "rpm", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pwm_rpm_t, rpm) }, \
         { "pwm", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_pwm_rpm_t, pwm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PWM_RPM { \
    "PWM_RPM", \
    2, \
    {  { "rpm", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pwm_rpm_t, rpm) }, \
         { "pwm", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_pwm_rpm_t, pwm) }, \
         } \
}
#endif

/**
 * @brief Pack a pwm_rpm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param rpm  Revolution(s) Per Minute
 * @param pwm  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pwm_rpm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float rpm, int16_t pwm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PWM_RPM_LEN];
    _mav_put_float(buf, 0, rpm);
    _mav_put_int16_t(buf, 4, pwm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PWM_RPM_LEN);
#else
    mavlink_pwm_rpm_t packet;
    packet.rpm = rpm;
    packet.pwm = pwm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PWM_RPM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PWM_RPM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PWM_RPM_MIN_LEN, MAVLINK_MSG_ID_PWM_RPM_LEN, MAVLINK_MSG_ID_PWM_RPM_CRC);
}

/**
 * @brief Pack a pwm_rpm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rpm  Revolution(s) Per Minute
 * @param pwm  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pwm_rpm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float rpm,int16_t pwm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PWM_RPM_LEN];
    _mav_put_float(buf, 0, rpm);
    _mav_put_int16_t(buf, 4, pwm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PWM_RPM_LEN);
#else
    mavlink_pwm_rpm_t packet;
    packet.rpm = rpm;
    packet.pwm = pwm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PWM_RPM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PWM_RPM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PWM_RPM_MIN_LEN, MAVLINK_MSG_ID_PWM_RPM_LEN, MAVLINK_MSG_ID_PWM_RPM_CRC);
}

/**
 * @brief Encode a pwm_rpm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pwm_rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pwm_rpm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pwm_rpm_t* pwm_rpm)
{
    return mavlink_msg_pwm_rpm_pack(system_id, component_id, msg, pwm_rpm->rpm, pwm_rpm->pwm);
}

/**
 * @brief Encode a pwm_rpm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pwm_rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pwm_rpm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pwm_rpm_t* pwm_rpm)
{
    return mavlink_msg_pwm_rpm_pack_chan(system_id, component_id, chan, msg, pwm_rpm->rpm, pwm_rpm->pwm);
}

/**
 * @brief Send a pwm_rpm message
 * @param chan MAVLink channel to send the message
 *
 * @param rpm  Revolution(s) Per Minute
 * @param pwm  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pwm_rpm_send(mavlink_channel_t chan, float rpm, int16_t pwm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PWM_RPM_LEN];
    _mav_put_float(buf, 0, rpm);
    _mav_put_int16_t(buf, 4, pwm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_RPM, buf, MAVLINK_MSG_ID_PWM_RPM_MIN_LEN, MAVLINK_MSG_ID_PWM_RPM_LEN, MAVLINK_MSG_ID_PWM_RPM_CRC);
#else
    mavlink_pwm_rpm_t packet;
    packet.rpm = rpm;
    packet.pwm = pwm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_RPM, (const char *)&packet, MAVLINK_MSG_ID_PWM_RPM_MIN_LEN, MAVLINK_MSG_ID_PWM_RPM_LEN, MAVLINK_MSG_ID_PWM_RPM_CRC);
#endif
}

/**
 * @brief Send a pwm_rpm message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pwm_rpm_send_struct(mavlink_channel_t chan, const mavlink_pwm_rpm_t* pwm_rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pwm_rpm_send(chan, pwm_rpm->rpm, pwm_rpm->pwm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_RPM, (const char *)pwm_rpm, MAVLINK_MSG_ID_PWM_RPM_MIN_LEN, MAVLINK_MSG_ID_PWM_RPM_LEN, MAVLINK_MSG_ID_PWM_RPM_CRC);
#endif
}

#if MAVLINK_MSG_ID_PWM_RPM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pwm_rpm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float rpm, int16_t pwm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, rpm);
    _mav_put_int16_t(buf, 4, pwm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_RPM, buf, MAVLINK_MSG_ID_PWM_RPM_MIN_LEN, MAVLINK_MSG_ID_PWM_RPM_LEN, MAVLINK_MSG_ID_PWM_RPM_CRC);
#else
    mavlink_pwm_rpm_t *packet = (mavlink_pwm_rpm_t *)msgbuf;
    packet->rpm = rpm;
    packet->pwm = pwm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_RPM, (const char *)packet, MAVLINK_MSG_ID_PWM_RPM_MIN_LEN, MAVLINK_MSG_ID_PWM_RPM_LEN, MAVLINK_MSG_ID_PWM_RPM_CRC);
#endif
}
#endif

#endif

// MESSAGE PWM_RPM UNPACKING


/**
 * @brief Get field rpm from pwm_rpm message
 *
 * @return  Revolution(s) Per Minute
 */
static inline float mavlink_msg_pwm_rpm_get_rpm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field pwm from pwm_rpm message
 *
 * @return  
 */
static inline int16_t mavlink_msg_pwm_rpm_get_pwm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Decode a pwm_rpm message into a struct
 *
 * @param msg The message to decode
 * @param pwm_rpm C-struct to decode the message contents into
 */
static inline void mavlink_msg_pwm_rpm_decode(const mavlink_message_t* msg, mavlink_pwm_rpm_t* pwm_rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pwm_rpm->rpm = mavlink_msg_pwm_rpm_get_rpm(msg);
    pwm_rpm->pwm = mavlink_msg_pwm_rpm_get_pwm(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PWM_RPM_LEN? msg->len : MAVLINK_MSG_ID_PWM_RPM_LEN;
        memset(pwm_rpm, 0, MAVLINK_MSG_ID_PWM_RPM_LEN);
    memcpy(pwm_rpm, _MAV_PAYLOAD(msg), len);
#endif
}
