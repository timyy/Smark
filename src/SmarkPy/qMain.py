import sys
from PyQt5 import *

import Ui_SmkMainWindow
import SmkHtmlWidget
#void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
#{
#    static QMutex mutex;
#    mutex.lock();

#    QString text;

#    switch(type)
#    {
#    case QtDebugMsg:
#        text = QString("Debug:");
#        break;

#    case QtWarningMsg:
#        text = QString("Warning:");
#        break;

#    case QtCriticalMsg:
#        text = QString("Critical:");
#        break;

#    case QtFatalMsg:
#        text = QString("Fatal:");
#    }

#    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
#    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
#    QString current_date = QString("(%1)").arg(current_date_time);
#    QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

#    QFile file("~Smark_log.txt");
#    file.open(QIODevice::WriteOnly | QIODevice::Append);
#    QTextStream text_stream(&file);
#    text_stream << message << "\r\n";
#    file.flush();
#    file.close();

#    mutex.unlock();
#}
class MyForm(QtWidgets.QMainWindow):
    def __init__(self,parent =None):
        QtWidgets.QMainWindow.__init__(self,parent)
        self.ui = Ui_SmkMainWindow()
        self.ui.setupUi(self)
if __name__ == '__main__':
    app=QtWidgets.QApplication(sys.argv)
    form = MyForm()
    form.show()
    sys.exit(app.exec_())
