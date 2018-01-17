#include <QTextDocument>
#include "Smark/SmkConfig.h"
#include "Smark/SmkHtmlWidget.h"

#if (QT_VERSION < 0x050000)
#   include <QtWebKit/QWebFrame>
#endif

SmkHtmlWidget::SmkHtmlWidget(QWidget* parent)
    : QWebEngineView(parent) {
}

/* *****************************************************************************
 *
 *                       get context and clear context
 *
 * ****************************************************************************/

void SmkHtmlWidget::clearHtml(void) {
    setHtml(SMK_EMPTY_STR);
    update();
}

/* *****************************************************************************
 *
 *                          synchronized scrolling
 *
 * ****************************************************************************/
//! @todo
int SmkHtmlWidget::scrollValue(void) {
    //! @todo:qt5 的page没有mainFrame, 需要改进才能把scrolling  改好。
    //!
    //!
    // return page()->mainFrame()->scrollBarValue(Qt::Vertical);
    qDebug() << "Get scroll:" << page()->scrollPosition();
    return (int)(page()->scrollPosition().y());  // 垂直方向
}

void SmkHtmlWidget::setScrollValue(int value) {
    //! @todo:qt5 的page没有mainFrame, 需要改进才能把scrolling  改好。
    //!
    //!
    // page()->mainFrame()->setScrollBarValue(Qt::Vertical, value);
    qDebug() << "Set scroll:" << value;
//    const QString ScrollJavaScript("window.scrollTo(0, document.body.scrollHeight * %1);");
//    page()->runJavaScript(ScrollJavaScript.arg(value));
}

void SmkHtmlWidget::setScrollRatio(float ratio) {
    //! @todo:qt5 的page没有mainFrame, 需要改进才能把scrolling  改好。
    //!
    //!

    // qDebug() << "setScrollRatio:" << ratio;
    //! 第一次取完了，以后都是0，是因为临时文件的问题吧。是浏览器兼容性问题。
    //! https://www.jianshu.com/p/46087c0ace05
    //! 算form的高度。

    const QString ScrollJavaScript("var oHeight=document.body.scrollHeight==0" \
                                   "?document.documentElement.scrollHeight:document.body.scrollHeight;" \
                                   "window.scrollTo(0, oHeight * %1);");
    page()->runJavaScript(ScrollJavaScript.arg(ratio));

//    int maxv = page()->mainFrame()->scrollBarMaximum(Qt::Vertical);
//    int minv = page()->mainFrame()->scrollBarMinimum(Qt::Vertical);
//    page()->mainFrame()->setScrollBarValue(Qt::Vertical,
//                                           minv + ratio*(maxv-minv));
//const QString ScrollJavaScript("window.scrollTo(0, document.body.scrollHeight * %1 / %2);");
//double cP   = m->editor->verticalScrollBar()->value();
//double maxP = m->editor->verticalScrollBar()->maximum();
//if( maxP > 0 )
//{
//    page()->runJavaScript(ScrollJavaScript.arg(cP).arg(maxP));
//}
}
