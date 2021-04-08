#pragma once
#include <QDebug>
#include <Logger/Logger.h>

#ifndef LOG_TAG
    #define LOG_TAG Q_FUNC_INFO
#endif

#define HInfo()     LogStream(Utility::Logger::LogType::INFO, LOG_TAG)
#define HDebug()    LogStream(Utility::Logger::LogType::DEBUG, LOG_TAG)
#define HWarning()  LogStream(Utility::Logger::LogType::WARNING, LOG_TAG)
#define HError()    LogStream(Utility::Logger::LogType::ERROR, LOG_TAG)

namespace hmiappcommon
{
class LogStream {
public:
    LogStream(const Utility::Logger::LogType& logType, const QString& logTag);
    ~LogStream();

    template<typename T>
    LogStream& operator << (T t) {
        mStream << t;
        return *this;
    }

private:
    QDebug mStream;
    QString mOutString;
    Utility::Logger::LogType mLogType;
    QString mLogTag;
};

} // namespace hmiappcommon
