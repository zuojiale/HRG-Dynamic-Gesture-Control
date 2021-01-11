#ifndef HRG_TOF_ENUMS_H
#define HRG_TOF_ENUMS_H

typedef enum {
    Dev_Usb = 0,
    Dev_Eth,
    Dev_None,
}Hrg_Dev_Type;

typedef enum {
    Mode_DistAmp = 0,
    Mode_RawPhases,
    Mode_None,
} Hrg_Frame_Mode;

typedef enum {
    Mode_Range_None = 0,
    Mode_Range_S,
    Mode_Range_M,
    Mode_Range_L,
    Mode_Range_XL,
    Mode_Range_Custom,
    Mode_Range_WDR,
} Hrg_Range_Mode;

typedef enum {
    HRG_LOG_LEVEL_TRACE = 0,
    HRG_LOG_LEVEL_DEBUG,
    HRG_LOG_LEVEL_INFO,
    HRG_LOG_LEVEL_WARN,
    HRG_LOG_LEVEL_ERROR,
    HRG_LOG_LEVEL_ALARM,
    HRG_LOG_LEVEL_FATAL,
} Hrg_Log_Level;

/*** Mirror the image along its horizontal and/or vertical central axis ***/
typedef enum {
    Default = 0,
    Flip, // (along horizontal axis)
    Mirror, //(along vertical axis)
    Flip_Mirror,
} Hrg_Flip_Mirror;

#endif
