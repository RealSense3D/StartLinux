#ifndef MYSYSLOG_H
#define MYSYSLOG_H

#include "base_type.h"


// 日志级别定义
#define LOG_FATAL       0     // 严重错误
#define LOG_ERROR       1     // 一般错误
#define LOG_WARN        2     // 警告
#define LOG_INFO        3     // 一般信息
#define LOG_TRACE       4     // 跟踪信息
#define LOG_DEBUG       5     // 调试信息
#define LOG_ALL         6     // 所有信息


// 全局变量
extern uint32  g_iLogLevel     ;    // 日志等级
extern uint32  g_iLogPosition  ;    // 日志位置
extern uint8   g_szLogFile[100];  // 带路径的日志文件名

#endif // MYSYSLOG_H
