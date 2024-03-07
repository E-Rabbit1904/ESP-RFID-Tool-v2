String css(String title) {
  String css = String()+F("<head>"
   "<meta charset=\"UTF-8\">"
   "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
   "<style>"
   "body {"
   "font-family: 'Arial', sans-serif;"
   "font-size: 16px;"
   "background-color: #f0f0f0;"
   "color: #333;"
   "}"
   "button {"
   "width: 80%;"
   "height: 40px;"
   "display: block;"
   "margin: 10 px auto;"
   "font-size: 16px;"
   "}"
   "</style>"
   "<title>")+ title +F("</title>"
   "</head>");

  return css;
  }
