#include "HLog.h"

using namespace hmiappcommon;
using namespace Utility::Logger;

LogStream::LogStream(const LogType& logType, const QString& logTag)
    : mStream(&mOutString)
    , mLogType(logType)
    , mLogTag(logTag)
{
    mStream.setAutoInsertSpaces(false);
    mStream.noquote();
    mStream << mLogTag << " ";
}

LogStream::~LogStream()
{
    switch (static_cast<int>(mLogType)) {
    case LogType::INFO:
        LOG_INF() << mOutString.toStdString();
        break;
    case LogType::DEBUG:
        LOG_DBG() << mOutString.toStdString();
        break;
    case LogType::WARNING:
        LOG_WAR() << mOutString.toStdString();
        break;
    case LogType::ERROR:
        LOG_ERR() << mOutString.toStdString();
        break;
    default:
        LOG_INF() << mOutString.toStdString();
        break;
    }
}
