import PyQt5.QtWebEngineWidgets 
class SmkHtmlWidget(QWebEngineView):
    def __init__(self,**kwargs):
        
        return super().__init__(**kwargs)
    def clearHtml():
        setHtml(SMK_EMPTY_STR)
        update()
    def when_page_scrollPositionChanged():
        pass

    def scrollValue():
        return page().scrollPosition().y()
    def setScrollValue():
        pass
    def setScrollRatio(ratio):
        if(qSmkApp().option("SynScroll") == "MD2Html"):
            ScrollJavaScript = "var oHeight=document.body.scrollHeight==0" \
                                       "?document.documentElement.scrollHeight:document.body.scrollHeight;" \
                                       "window.scrollTo(0, oHeight * %1);"
            page().runJavaScript(ScrollJavaScript.arg(ratio))
