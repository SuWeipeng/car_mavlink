#pragma once
// MESSAGE IMU PACKING

#define MAVLINK_MSG_ID_IMU 15

MAVPACKED(
typedef struct __mavlink_imu_t {
 uint32_t tick; /*<  */
 int16_t ax; /*<  unit: mg*/
 int16_t ay; /*<  unit: mg*/
 int16_t az; /*<  unit: mg*/
 int16_t gx; /*<  unit: deg/10ms*/
 int16_t gy; /*<  unit: deg/10ms*/
 int16_t gz; /*<  unit: deg/10ms*/
}) mavlink_imu_t;

#define MAVLINK_MSG_ID_IMU_LEN 16
#define MAVLINK_MSG_ID_IMU_MIN_LEN 16
#define MAVLINK_MSG_ID_15_LEN 16
#define MAVLINK_MSG_ID_15_MIN_LEN 16

#define MAVLINK_MSG_ID_IMU_CRC 144
#define MAVLINK_MSG_ID_15_CRC 144



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_IMU { \
    15, \
    "IMU", \
    7, \
    {  { "tick", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_imu_t, tick) }, \
         { "ax", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_imu_t, ax) }, \
         { "ay", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_imu_t, ay) }, \
         { "az", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_imu_t, az) }, \
         { "gx", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_imu_t, gx) }, \
         { "gy", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_imu_t, gy) }, \
         { "gz", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_imu_t, gz) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_IMU { \
    "IMU", \
    7, \
    {  { "tick", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_imu_t, tick) }, \
         { "ax", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_imu_t, ax) }, \
         { "ay", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_imu_t, ay) }, \
         { "az", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_imu_t, az) }, \
         { "gx", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_imu_t, gx) }, \
         { "gy", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_imu_t, gy) }, \
         { "gz", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_imu_t, gz) }, \
         } \
}
#endif

/**
 * @brief Pack a imu message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param tick  
 * @param ax  unit: mg
 * @param ay  unit: mg
 * @param az  unit: mg
 * @param gx  unit: deg/10ms
 * @param gy  unit: deg/10ms
 * @param gz  unit: deg/10ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t tick, int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IMU_LEN];
    _mav_put_uint32_t(buf, 0, tick);
    _mav_put_int16_t(buf, 4, ax);
    _mav_put_int16_t(buf, 6, ay);
    _mav_put_int16_t(buf, 8, az);
    _mav_put_int16_t(buf, 10, gx);
    _mav_put_int16_t(buf, 12, gy);
    _mav_put_int16_t(buf, 14, gz);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_LEN);
#else
    mavlink_imu_t packet;
    packet.tick = tick;
    packet.ax = ax;
    packet.ay = ay;
    packet.az = az;
    packet.gx = gx;
    packet.gy = gy;
    packet.gz = gz;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IMU;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IMU_MIN_LEN, MAVLINK_MSG_ID_IMU_LEN, MAVLINK_MSG_ID_IMU_CRC);
}

/**
 * @brief Pack a imu message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tick  
 * @param ax  unit: mg
 * @param ay  unit: mg
 * @param az  unit: mg
 * @param gx  unit: deg/10ms
 * @param gy  unit: deg/10ms
 * @param gz  unit: deg/10ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_imu_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t tick,int16_t ax,int16_t ay,int16_t az,int16_t gx,int16_t gy,int16_t gz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IMU_LEN];
    _mav_put_uint32_t(buf, 0, tick);
    _mav_put_int16_t(buf, 4, ax);
    _mav_put_int16_t(buf, 6, ay);
    _mav_put_int16_t(buf, 8, az);
    _mav_put_int16_t(buf, 10, gx);
    _mav_put_int16_t(buf, 12, gy);
    _mav_put_int16_t(buf, 14, gz);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IMU_LEN);
#else
    mavlink_imu_t packet;
    packet.tick = tick;
    packet.ax = ax;
    packet.ay = ay;
    packet.az = az;
    packet.gx = gx;
    packet.gy = gy;
    packet.gz = gz;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IMU_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IMU;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IMU_MIN_LEN, MAVLINK_MSG_ID_IMU_LEN, MAVLINK_MSG_ID_IMU_CRC);
}

/**
 * @brief Encode a imu struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param imu C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_imu_t* imu)
{
    return mavlink_msg_imu_pack(system_id, component_id, msg, imu->tick, imu->ax, imu->ay, imu->az, imu->gx, imu->gy, imu->gz);
}

/**
 * @brief Encode a imu struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param imu C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_imu_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_imu_t* imu)
{
    return mavlink_msg_imu_pack_chan(system_id, component_id, chan, msg, imu->tick, imu->ax, imu->ay, imu->az, imu->gx, imu->gy, imu->gz);
}

/**
 * @brief Send a imu message
 * @param chan MAVLink channel to send the message
 *
 * @param tick  
 * @param ax  unit: mg
 * @param ay  unit: mg
 * @param az  unit: mg
 * @param gx  unit: deg/10ms
 * @param gy  unit: deg/10ms
 * @param gz  unit: deg/10ms
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_imu_send(mavlink_channel_t chan, uint32_t tick, int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IMU_LEN];
    _mav_put_uint32_t(buf, 0, tick);
    _mav_put_int16_t(buf, 4, ax);
    _mav_put_int16_t(buf, 6, ay);
    _mav_put_int16_t(buf, 8, az);
    _mav_put_int16_t(buf, 10, gx);
    _mav_put_int16_t(buf, 12, gy);
    _mav_put_int16_t(buf, 14, gz);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU, buf, MAVLINK_MSG_ID_IMU_MIN_LEN, MAVLINK_MSG_ID_IMU_LEN, MAVLINK_MSG_ID_IMU_CRC);
#else
    mavlink_imu_t packet;
    packet.tick = tick;
    packet.ax = ax;
    packet.ay = ay;
    packet.az = az;
    packet.gx = gx;
    packet.gy = gy;
    packet.gz = gz;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU, (const char *)&packet, MAVLINK_MSG_ID_IMU_MIN_LEN, MAVLINK_MSG_ID_IMU_LEN, MAVLINK_MSG_ID_IMU_CRC);
#endif
}

/**
 * @brief Send a imu message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_imu_send_struct(mavlink_channel_t chan, const mavlink_imu_t* imu)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_imu_send(chan, imu->tick, imu->ax, imu->ay, imu->az, imu->gx, imu->gy, imu->gz);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU, (const char *)imu, MAVLINK_MSG_ID_IMU_MIN_LEN, MAVLINK_MSG_ID_IMU_LEN, MAVLINK_MSG_ID_IMU_CRC);
#endif
}

#if MAVLINK_MSG_ID_IMU_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_imu_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t tick, int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, tick);
    _mav_put_int16_t(buf, 4, ax);
    _mav_put_int16_t(buf, 6, ay);
    _mav_put_int16_t(buf, 8, az);
    _mav_put_int16_t(buf, 10, gx);
    _mav_put_int16_t(buf, 12, gy);
    _mav_put_int16_t(buf, 14, gz);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU, buf, MAVLINK_MSG_ID_IMU_MIN_LEN, MAVLINK_MSG_ID_IMU_LEN, MAVLINK_MSG_ID_IMU_CRC);
#else
    mavlink_imu_t *packet = (mavlink_imu_t *)msgbuf;
    packet->tick = tick;
    packet->ax = ax;
    packet->ay = ay;
    packet->az = az;
    packet->gx = gx;
    packet->gy = gy;
    packet->gz = gz;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU, (const char *)packet, MAVLINK_MSG_ID_IMU_MIN_LEN, MAVLINK_MSG_ID_IMU_LEN, MAVLINK_MSG_ID_IMU_CRC);
#endif
}
#endif

#endif

// MESSAGE IMU UNPACKING


/**
 * @brief Get field tick from imu message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_imu_get_tick(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field ax from imu message
 *
 * @return  unit: mg
 */
static inline int16_t mavlink_msg_imu_get_ax(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field ay from imu message
 *
 * @return  unit: mg
 */
static inline int16_t mavlink_msg_imu_get_ay(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field az from imu message
 *
 * @return  unit: mg
 */
static inline int16_t mavlink_msg_imu_get_az(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field gx from imu message
 *
 * @return  unit: deg/10ms
 */
static inline int16_t mavlink_msg_imu_get_gx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field gy from imu message
 *
 * @return  unit: deg/10ms
 */
static inline int16_t mavlink_msg_imu_get_gy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field gz from imu message
 *
 * @return  unit: deg/10ms
 */
static inline int16_t mavlink_msg_imu_get_gz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Decode a imu message into a struct
 *
 * @param msg The message to decode
 * @param imu C-struct to decode the message contents into
 */
static inline void mavlink_msg_imu_decode(const mavlink_message_t* msg, mavlink_imu_t* imu)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    imu->tick = mavlink_msg_imu_get_tick(msg);
    imu->ax = mavlink_msg_imu_get_ax(msg);
    imu->ay = mavlink_msg_imu_get_ay(msg);
    imu->az = mavlink_msg_imu_get_az(msg);
    imu->gx = mavlink_msg_imu_get_gx(msg);
    imu->gy = mavlink_msg_imu_get_gy(msg);
    imu->gz = mavlink_msg_imu_get_gz(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_IMU_LEN? msg->len : MAVLINK_MSG_ID_IMU_LEN;
        memset(imu, 0, MAVLINK_MSG_ID_IMU_LEN);
    memcpy(imu, _MAV_PAYLOAD(msg), len);
#endif
}
