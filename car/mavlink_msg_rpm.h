#pragma once
// MESSAGE RPM PACKING

#define MAVLINK_MSG_ID_RPM 14

MAVPACKED(
typedef struct __mavlink_rpm_t {
 float rpm_target; /*<  TARGET-Revolution(s) Per Minute*/
 float rpm; /*<  MEASUREMENT-Revolution(s) Per Minute*/
}) mavlink_rpm_t;

#define MAVLINK_MSG_ID_RPM_LEN 8
#define MAVLINK_MSG_ID_RPM_MIN_LEN 8
#define MAVLINK_MSG_ID_14_LEN 8
#define MAVLINK_MSG_ID_14_MIN_LEN 8

#define MAVLINK_MSG_ID_RPM_CRC 240
#define MAVLINK_MSG_ID_14_CRC 240



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RPM { \
    14, \
    "RPM", \
    2, \
    {  { "rpm_target", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rpm_t, rpm_target) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rpm_t, rpm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RPM { \
    "RPM", \
    2, \
    {  { "rpm_target", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rpm_t, rpm_target) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rpm_t, rpm) }, \
         } \
}
#endif

/**
 * @brief Pack a rpm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param rpm_target  TARGET-Revolution(s) Per Minute
 * @param rpm  MEASUREMENT-Revolution(s) Per Minute
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rpm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float rpm_target, float rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RPM_LEN];
    _mav_put_float(buf, 0, rpm_target);
    _mav_put_float(buf, 4, rpm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RPM_LEN);
#else
    mavlink_rpm_t packet;
    packet.rpm_target = rpm_target;
    packet.rpm = rpm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RPM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RPM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RPM_MIN_LEN, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
}

/**
 * @brief Pack a rpm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rpm_target  TARGET-Revolution(s) Per Minute
 * @param rpm  MEASUREMENT-Revolution(s) Per Minute
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rpm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float rpm_target,float rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RPM_LEN];
    _mav_put_float(buf, 0, rpm_target);
    _mav_put_float(buf, 4, rpm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RPM_LEN);
#else
    mavlink_rpm_t packet;
    packet.rpm_target = rpm_target;
    packet.rpm = rpm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RPM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RPM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RPM_MIN_LEN, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
}

/**
 * @brief Encode a rpm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rpm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rpm_t* rpm)
{
    return mavlink_msg_rpm_pack(system_id, component_id, msg, rpm->rpm_target, rpm->rpm);
}

/**
 * @brief Encode a rpm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rpm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rpm_t* rpm)
{
    return mavlink_msg_rpm_pack_chan(system_id, component_id, chan, msg, rpm->rpm_target, rpm->rpm);
}

/**
 * @brief Send a rpm message
 * @param chan MAVLink channel to send the message
 *
 * @param rpm_target  TARGET-Revolution(s) Per Minute
 * @param rpm  MEASUREMENT-Revolution(s) Per Minute
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rpm_send(mavlink_channel_t chan, float rpm_target, float rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RPM_LEN];
    _mav_put_float(buf, 0, rpm_target);
    _mav_put_float(buf, 4, rpm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, buf, MAVLINK_MSG_ID_RPM_MIN_LEN, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#else
    mavlink_rpm_t packet;
    packet.rpm_target = rpm_target;
    packet.rpm = rpm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, (const char *)&packet, MAVLINK_MSG_ID_RPM_MIN_LEN, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#endif
}

/**
 * @brief Send a rpm message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_rpm_send_struct(mavlink_channel_t chan, const mavlink_rpm_t* rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_rpm_send(chan, rpm->rpm_target, rpm->rpm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, (const char *)rpm, MAVLINK_MSG_ID_RPM_MIN_LEN, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#endif
}

#if MAVLINK_MSG_ID_RPM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rpm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float rpm_target, float rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, rpm_target);
    _mav_put_float(buf, 4, rpm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, buf, MAVLINK_MSG_ID_RPM_MIN_LEN, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#else
    mavlink_rpm_t *packet = (mavlink_rpm_t *)msgbuf;
    packet->rpm_target = rpm_target;
    packet->rpm = rpm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM, (const char *)packet, MAVLINK_MSG_ID_RPM_MIN_LEN, MAVLINK_MSG_ID_RPM_LEN, MAVLINK_MSG_ID_RPM_CRC);
#endif
}
#endif

#endif

// MESSAGE RPM UNPACKING


/**
 * @brief Get field rpm_target from rpm message
 *
 * @return  TARGET-Revolution(s) Per Minute
 */
static inline float mavlink_msg_rpm_get_rpm_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field rpm from rpm message
 *
 * @return  MEASUREMENT-Revolution(s) Per Minute
 */
static inline float mavlink_msg_rpm_get_rpm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a rpm message into a struct
 *
 * @param msg The message to decode
 * @param rpm C-struct to decode the message contents into
 */
static inline void mavlink_msg_rpm_decode(const mavlink_message_t* msg, mavlink_rpm_t* rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    rpm->rpm_target = mavlink_msg_rpm_get_rpm_target(msg);
    rpm->rpm = mavlink_msg_rpm_get_rpm(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RPM_LEN? msg->len : MAVLINK_MSG_ID_RPM_LEN;
        memset(rpm, 0, MAVLINK_MSG_ID_RPM_LEN);
    memcpy(rpm, _MAV_PAYLOAD(msg), len);
#endif
}
