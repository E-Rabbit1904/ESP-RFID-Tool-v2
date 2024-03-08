/* Copyright (c) 2024  Raik Schneider @Einstein2150
   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
 */
 
 String hexToBinary(String hexString) {
  String binaryString = "";
  
  // Durchlaufe den Hex-String und konvertiere jeden Hex-Wert in Binär
  for (int i = 0; i < hexString.length(); i++) {
    char hexChar = hexString.charAt(i);
    int hexValue;
    
    // Konvertiere Hex-Zeichen in Dezimalzahl
    if (hexChar >= '0' && hexChar <= '9') {
      hexValue = hexChar - '0';
    } else if (hexChar >= 'A' && hexChar <= 'F') {
      hexValue = hexChar - 'A' + 10;
    } else if (hexChar >= 'a' && hexChar <= 'f') {
      hexValue = hexChar - 'a' + 10;
    } else {
      // Ungültiges Hex-Zeichen
      continue;
    }
    
    // Konvertiere Dezimalzahl in 4-Bit-Binärzahl
    for (int j = 3; j >= 0; j--) {
      binaryString += (hexValue & (1 << j)) ? '1' : '0';
    }
  }
  
  return binaryString;
}


String binaryToHex(String binaryString) {
  String hexString = "";
  
  // Stelle sicher, dass die Länge des Binär-Strings durch 4 teilbar ist
  int padding = binaryString.length() % 4;
  if (padding > 0) {
    binaryString = String("0000").substring(0, 4 - padding) + binaryString;
  }

  // Durchlaufe den Binär-String und konvertiere jeden 4-Bit-Binärwert in Hex
  for (int i = 0; i < binaryString.length(); i += 4) {
    String binarySubstring = binaryString.substring(i, i + 4);
    int hexValue = 0;

    // Konvertiere 4-Bit-Binärzahl in Dezimalzahl
    for (int j = 0; j < 4; j++) {
      hexValue = (hexValue << 1) | (binarySubstring.charAt(j) - '0');
    }

    // Konvertiere Dezimalzahl in Hex-Zeichen
    char hexChar = (hexValue < 10) ? ('0' + hexValue) : ('A' + hexValue - 10);

    hexString += hexChar;
  }
  
  return hexString;
}


String reverseHex(String hexString) {
  // Überprüfe, ob der Hex-String gerade ist
  if (hexString.length() % 2 != 0) {
    // Wenn der Hex-String ungerade ist, füge eine führende Null hinzu
    hexString = "0" + hexString;
  }

  String reversedHex = "";

  // Durchlaufe den Hex-String rückwärts in 2er-Schritten
  for (int i = hexString.length() - 2; i >= 0; i -= 2) {
    // Extrahiere ein 2-Zeichen-Paar und füge es zum umgekehrten Hex-Wert hinzu
    reversedHex += hexString.substring(i, i + 2);
  }

  return reversedHex;
}


String sanitizeString(char* buffer, int length) {
  String result = "";
  for (int i = 0; i < length; i++) {
    // Überprüfe, ob das Zeichen gültig ist (z.B. im ASCII-Bereich)
    if (buffer[i] >= 10 && buffer[i] <= 126) {
      result += buffer[i];
    } else {
      // Andernfalls ersetze es durch ein Platzhalterzeichen oder entferne es
      result += "";
    }
  }
  return result;
}
