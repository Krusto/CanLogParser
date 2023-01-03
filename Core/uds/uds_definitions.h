#pragma once

#include <stdint.h>
#include <string_view>

#define UDS_DIAG_SESSION_CONTROL_REQUEST_SID 0x10
#define UDS_DIAG_SESSION_CONTROL_RESPONSE_SID 0x50
#define UDS_DIAG_RESET_REQUEST_SID 0x11
#define UDS_DIAG_RESET_RESPONSE_SID 0x51
#define UDS_DIAG_SEC_ACCESS_REQUEST_SID 0x27
#define UDS_DIAG_SEC_ACCESS_RESPONSE_SID 0x67
#define UDS_DIAG_COMMUNICATION_CONTROL_REQUEST_SID 0x28
#define UDS_DIAG_COMMUNICATION_CONTROL_RESPONSE_SID 0x68
#define UDS_DIAG_AUTHENTICATION_REQUEST_SID 0x29
#define UDS_DIAG_AUTHENTICATION_RESPONSE_SID 0x69
#define UDS_DIAG_TESTER_PRESENT_REQUEST_SID 0x3E
#define UDS_DIAG_TESTER_PRESENT_RESPONSE_SID 0x7E
#define UDS_DIAG_ACCESS_TIMING_PARAM_REQUEST_SID 0x83
#define UDS_DIAG_ACCESS_TIMING_PARAM_RESPONSE_SID 0xC3
#define UDS_DIAG_SECURED_DATA_TRANSMISSION_REQUEST_SID 0x84
#define UDS_DIAG_SECURED_DATA_TRANSMISSION_RESPONSE_SID 0xC4
#define UDS_DIAG_CONTROL_DTC_SETTINGS_REQUEST_SID 0x85
#define UDS_DIAG_CONTROL_DTC_SETTINGS_RESPONSE_SID 0xC5
#define UDS_DIAG_RESPONSES_ON_EVENT_REQUEST_SID 0x86
#define UDS_DIAG_RESPONSES_ON_EVENT_RESPONSE_SID 0xC6
#define UDS_DIAG_LINK_CONTROL_REQUEST_SID 0x87
#define UDS_DIAG_LINK_CONTROL_RESPONSE_SID 0xC7
#define UDS_READ_DATA_BY_ID_REQUEST_SID 0x22
#define UDS_READ_DATA_BY_ID_RESPONSE_SID 0x62
#define UDS_READ_MEMORY_BY_ADDRESS_REQUEST_SID 0x23
#define UDS_READ_MEMORY_BY_ADDRESS_RESPONSE_SID 0x63
#define UDS_READ_SCALING_DATA_BY_ID_REQUEST_SID 0x24
#define UDS_READ_SCALING_DATA_BY_ID_RESPONSE_SID 0x64
#define UDS_READ_DATA_BY_ID_PERIODIC_REQUEST_SID 0x2A
#define UDS_READ_DATA_BY_ID_PERIODIC_RESPONSE_SID 0x6A
#define UDS_DINAMICALLY_DEFINE_DATA_ID_REQUEST_SID 0x2C
#define UDS_DINAMICALLY_DEFINE_DATA_ID_RESPONSE_SID 0x6C
#define UDS_WRITE_DATA_BY_ID_REQUEST_SID 0x2E
#define UDS_WRITE_DATA_BY_ID_RESPONSE_SID 0x6E
#define UDS_WRITE_MEMORY_BY_ADDRESS_REQUEST_SID 0x3D
#define UDS_WRITE_MEMORY_BY_ADDRESS_RESPONSE_SID 0x7D
#define UDS_CLEAR_DTC_REQUEST_SID 0x14
#define UDS_CLEAR_DTC_RESPONSE_SID 0x54
#define UDS_READ_DTC_REQUEST_SID 0x19
#define UDS_READ_DTC_RESPONSE_SID 0x59
#define UDS_IO_CTRL_BY_ID_REQUEST_SID 0x2F
#define UDS_IO_CTRL_BY_ID_RESPONSE_SID 0x6F
#define UDS_ROUTINE_CTRL_REQUEST_SID 0x31
#define UDS_ROUTINE_CTRL_RESPONSE_SID 0x71
#define UDS_REQ_DOWNLOAD_REQUEST_SID 0x34
#define UDS_REQ_DOWNLOAD_RESPONSE_SID 0x74
#define UDS_REQ_UPLOAD_REQUEST_SID 0x35
#define UDS_REQ_UPLOAD_RESPONSE_SID 0x36
#define UDS_TRANSFER_DATA_REQUEST_SID 0x36
#define UDS_TRANSFER_DATA_RESPONSE_SID 0x76
#define UDS_TRANSFER_EXIT_REQUEST_SID 0x37
#define UDS_TRANSFER_EXIT_RESPONSE_SID 0x77
#define UDS_REQUEST_TRANSFER_FILE_REQUEST_SID 0x38
#define UDS_REQUEST_TRANSFER_FILE_RESPONSE_SID 0x78
#define UDS_NEGATIVE_RESPONSE_SID 0x7F


/**
 * @brief Defines type of the service
 */
enum SI_TYPE{
    NONE,
    OBD_SERVICE_REQUESTS,
    OBD_SERVICE_RESPONSE,
    ISO_14229_1_SERVICE_REQUEST,
    ISO_14229_1_POSITIVE_SERVICE_RESPONSES,
    NOT_APPLICABLE,
    NEGATIVE_RESPONSE_SERVICE_ID,
    POSITIVE_SERVICE_RESPONSES,
    SERVICE_REQUESTS,
};

/**
 * @brief Used to share where the service is defined
 */
enum SI_DEFINITION{
    ISO_14229_1,
    ISO_15031_5,
    RESERVED_BY_ISO_14229_1,
    RESERVED_BY_ISO_14230,
    RESERVED_FOR_FUTURE_EXPANSION_AS_NEEDED,
    DEFINED_BY_VEHICLE_MANUFACTURER,
    DEFINED_BY_SYSTEM_SUPPLIER,
    RESERVED_BY_DOCUMENT,
};


/**
 * @brief Used to define service info
 */
struct SERVICE_ID_INFO{
    uint8_t start;
    uint8_t end;
    SI_TYPE type;
    SI_DEFINITION definition;

};

/**
 * @brief List of all services infos
 */
SERVICE_ID_INFO SERVICE_RANGE_INFO_TABLE[10];

#define DIAG_SESSION_ACCESS_ALLOWED 0
#define DIAG_SESSION_ACCESS_NA      1
#define DIAG_SESSION_ACCESS_DENIED  2

/**
 * @brief Structure used to define diag service info
 */
struct UDS_DIAG_SERVICE_INFO{
    uint8_t RequestID;
    uint8_t ResponseID;
    uint8_t allowedInDefaultSession;
};

#define UDS_MANAGER_SUPPORTED_SERVICE_COUNT 25u

/**
 * @brief List of all USD Diag services infos
 */
UDS_DIAG_SERVICE_INFO UDS_DIAG_SERVICE_INFO_TABLE[UDS_MANAGER_SUPPORTED_SERVICE_COUNT];

/**
 * @brief Translates Service ID to human readable format
 * @param SID Service ID - uint8_t
 * @return Translated SID - string_view
 */
std::string_view TranslateServiceID(uint8_t SID);