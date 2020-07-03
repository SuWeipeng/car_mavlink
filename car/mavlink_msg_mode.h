#pragma once
// MESSAGE MODE PACKING

#define MAVLINK_MSG_ID_MODE 16

MAVPACKED(
typedef struct __mavlink_mode_t {
 uint8_t mode; /*<  Mode::Number*/
 uint8_t reason; /*<  Mode::ModeReason*/
}) mavlink_mode_t;

#define MAVLINK_MSG_ID_MODE_LEN 2
#define MAVLINK_MSG_ID_MODE_MIN_LEN 2
#define MAVLINK_MSG_ID_16_LEN 2
#define MAVLINK_MSG_ID_16_MIN_LEN 2

#define MAVLINK_MSG_ID_MODE_CRC 99
#define MAVLINK_MSG_ID_16_CRC 99



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MODE { \
    16, \
    "MODE", \
    2, \
    {  { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mode_t, mode) }, \
         { "reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mode_t, reason) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MODE { \
    "MODE", \
    2, \
    {  { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_mode_t, mode) }, \
         { "reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_mode_t, reason) }, \
         } \
}
#endif

/**
 * @brief Pack a mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode  Mode::Number
 * @param reason  Mode::ModeReason
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t mode, uint8_t reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MODE_LEN];
    _mav_put_uint8_t(buf, 0, mode);
    _mav_put_uint8_t(buf, 1, reason);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MODE_LEN);
#else
    mavlink_mode_t packet;
    packet.mode = mode;
    packet.reason = reason;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MODE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MODE_MIN_LEN, MAVLINK_MSG_ID_MODE_LEN, MAVLINK_MSG_ID_MODE_CRC);
}

/**
 * @brief Pack a mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode  Mode::Number
 * @param reason  Mode::ModeReason
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t mode,uint8_t reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MODE_LEN];
    _mav_put_uint8_t(buf, 0, mode);
    _mav_put_uint8_t(buf, 1, reason);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MODE_LEN);
#else
    mavlink_mode_t packet;
    packet.mode = mode;
    packet.reason = reason;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MODE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MODE_MIN_LEN, MAVLINK_MSG_ID_MODE_LEN, MAVLINK_MSG_ID_MODE_CRC);
}

/**
 * @brief Encode a mode struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mode_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mode_t* mode)
{
    return mavlink_msg_mode_pack(system_id, component_id, msg, mode->mode, mode->reason);
}

/**
 * @brief Encode a mode struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mode_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mode_t* mode)
{
    return mavlink_msg_mode_pack_chan(system_id, component_id, chan, msg, mode->mode, mode->reason);
}

/**
 * @brief Send a mode message
 * @param chan MAVLink channel to send the message
 *
 * @param mode  Mode::Number
 * @param reason  Mode::ModeReason
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mode_send(mavlink_channel_t chan, uint8_t mode, uint8_t reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MODE_LEN];
    _mav_put_uint8_t(buf, 0, mode);
    _mav_put_uint8_t(buf, 1, reason);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODE, buf, MAVLINK_MSG_ID_MODE_MIN_LEN, MAVLINK_MSG_ID_MODE_LEN, MAVLINK_MSG_ID_MODE_CRC);
#else
    mavlink_mode_t packet;
    packet.mode = mode;
    packet.reason = reason;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODE, (const char *)&packet, MAVLINK_MSG_ID_MODE_MIN_LEN, MAVLINK_MSG_ID_MODE_LEN, MAVLINK_MSG_ID_MODE_CRC);
#endif
}

/**
 * @brief Send a mode message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mode_send_struct(mavlink_channel_t chan, const mavlink_mode_t* mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mode_send(chan, mode->mode, mode->reason);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODE, (const char *)mode, MAVLINK_MSG_ID_MODE_MIN_LEN, MAVLINK_MSG_ID_MODE_LEN, MAVLINK_MSG_ID_MODE_CRC);
#endif
}

#if MAVLINK_MSG_ID_MODE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mode_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mode, uint8_t reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, mode);
    _mav_put_uint8_t(buf, 1, reason);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODE, buf, MAVLINK_MSG_ID_MODE_MIN_LEN, MAVLINK_MSG_ID_MODE_LEN, MAVLINK_MSG_ID_MODE_CRC);
#else
    mavlink_mode_t *packet = (mavlink_mode_t *)msgbuf;
    packet->mode = mode;
    packet->reason = reason;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MODE, (const char *)packet, MAVLINK_MSG_ID_MODE_MIN_LEN, MAVLINK_MSG_ID_MODE_LEN, MAVLINK_MSG_ID_MODE_CRC);
#endif
}
#endif

#endif

// MESSAGE MODE UNPACKING


/**
 * @brief Get field mode from mode message
 *
 * @return  Mode::Number
 */
static inline uint8_t mavlink_msg_mode_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field reason from mode message
 *
 * @return  Mode::ModeReason
 */
static inline uint8_t mavlink_msg_mode_get_reason(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a mode message into a struct
 *
 * @param msg The message to decode
 * @param mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_mode_decode(const mavlink_message_t* msg, mavlink_mode_t* mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mode->mode = mavlink_msg_mode_get_mode(msg);
    mode->reason = mavlink_msg_mode_get_reason(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MODE_LEN? msg->len : MAVLINK_MSG_ID_MODE_LEN;
        memset(mode, 0, MAVLINK_MSG_ID_MODE_LEN);
    memcpy(mode, _MAV_PAYLOAD(msg), len);
#endif
}
