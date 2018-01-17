#include "Smark/SmkConfig.h"
#include "Smark/SmkApp.h"
#include "Smark/SmkMainWindow.h"
void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;

    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;

    case QtWarningMsg:
        text = QString("Warning:");
        break;

    case QtCriticalMsg:
        text = QString("Critical:");
        break;

    case QtFatalMsg:
        text = QString("Fatal:");
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

    QFile file("~Smark_log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}

int main(int argc, char** argv)
{
    //注册MessageHandler
    qInstallMessageHandler(outputMessage);

    //打印日志到文件中
    // qDebug("This is a debug message");

    SmkApp app(argc, argv);

#if (QT_VERSION < 0x050000)
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));
#endif

#ifdef SMK_WINDOWS_PLATFORM
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
#else
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
#endif // SMK_WINDOWS_PLATFORM

    SmkMainWindow window(NULL);
    if(argc > 1)
        window.openMarkdownFile(QString::fromLocal8Bit(argv[1]));
    window.showNormal();

    return app.exec();
}
