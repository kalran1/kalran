// html->string 변환사이트
// http://davidjwatts.com/youtube/esp8266/esp-convertHTM.html#
// https://tomeko.net/online_tools/cpp_text_escape.php?lang=en
String webHead="<html> <head> <!-- <meta http-equiv='refresh' content='2'/>--> <meta name='viewport' content='width=device-width, initial-scale=1.0'/> <meta http-equiv='Content-Type' content='text/html;charset=utf-8' /> <style> body { background: #eab0dc; font-family: \\\"Lato\\\", sans-serif; } .button { border: none; color: white; padding: 20px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer; } .button-on {border-radius: 100%; background-color: #4CAF50;} .button-off {border-radius: 100%;background-color: #707070;} .button-ledon {border-radius: 100%; padding: 10px; font-size: 8px; margin: 0px 0px; background-color: #ff4500;} .button-ledoff {border-radius: 100%; padding: 10px; font-size: 8px; background-color: #707070;} </style> </head> <body> <h3 style='color:SteelBlue;'>&emsp;김동일유튜브 <a href='http://i2r.link' style='color:SteelBlue;'>http://i2r.link</a> </h3>";
String webTail="\n<p><a href='/wifi'>네트웍공유기변경-누른후 와이파설정부터 다시하세요</a></p></body>\n</html>";

void handleRoot() {
  String s=""; 

  s+="<form action='/on'>";
  if(p4[0]==1) 
    s=s+"<button type='submit' name='button' value='0' class='button button-on' >p40</button></a>"; //off
  else 
    s=s+"<button type='submit' name='button' value='0' class='button button-off' >p40</button></a>"; //on
  if(p4[1]==1) 
    s=s+"<button type='submit' name='button' value='1' class='button button-on' >p41</button></a>"; //off
  else 
    s=s+"<button type='submit' name='button' value='1' class='button button-off' >p41</button></a>"; //on
  if(p4[2]==1) 
    s=s+"<button type='submit' name='button' value='2' class='button button-on' >p42</button></a>"; //off
  else 
    s=s+"<button type='submit' name='button' value='2' class='button button-off' >p42</button></a>"; //on
  if(p4[3]==1) 
    s=s+"<button type='submit' name='button' value='3' class='button button-on' >p43</button></a>"; //off
  else 
    s=s+"<button type='submit' name='button' value='3' class='button button-off' >p43</button></a>"; //on
  if(p4[4]==1)
  s=s+"<button type='submit' name='button' value='4' class='button button-on' >all</button></a>"; //off
  else 
    s=s+"<button type='submit' name='button' value='4' class='button button-off' >all</button></a>"; //on
  s+="</form>";
    
  s=s+"<br><br>AP & IP :&emsp;"+sChipId+"&emsp;"+WiFi.localIP().toString();
  server.send(200, "text/html", webHead+s+webTail);
}

void handleWifi() {
  WiFiManager wm;
  wm.resetSettings();
  wm.resetSettings();
  ESP.reset();
}

void handleOn() {
  int no=server.arg("button").toInt();
  if(p4[no]==1)
    p4[no]=0;
  else 
    p4[no]=1;

  int out; 
  if (p4[4]==0) 
     out=p4[0]+p4[1]*2+p4[2]*4+p4[3]*8;
  else 
    out=15;
  s = "\0";
  s +=char(5);
  s += "00WSS0104%PW4000";
  s += String(out, HEX);
  s +=char(4);
  Serial.println(" ");
  Serial.println(s); 
  Serial1.print(s);
  GoHome();
}

void GoHome() {
  String s,ipS;
  //IPAddress ip;
  ipS=toStringIp(WiFi.localIP());
  s="<meta http-equiv='refresh' content=\"0;url='http://"+ipS+"/'\">";
  server.send(200, "text/html", s);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void handleScan() {
  String s;
  s="{\"chipId\":\""+sChipId+"\",\"ip\":\""+WiFi.localIP().toString()+"\"}";
  server.send(200, "text/html", s);
}
