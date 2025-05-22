#include <pitches.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.init();
  lcd.backlight();
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
}

char Time[] = "Time:         ";
char ti[] = "Time: HH:MM:SS";
char Calendar[] = "Date:         ";
char ca[] = "Date: DD/MM/YY";
byte i, pre, second, minute, hour, day, date, month, year;
char bs = "";
int x = 0, y = 0, k = 0, l = 0, al = 0;
byte h[2], m[2], d[2];

void DS3231_display() {
  // Convert BCD to decimal
  second = (second >> 4) * 10 + (second & 0x0F);
  minute = (minute >> 4) * 10 + (minute & 0x0F);
  hour = (hour >> 4) * 10 + (hour & 0x0F);
  date = (date >> 4) * 10 + (date & 0x0F);
  month = (month >> 4) * 10 + (month & 0x0F);
  year = (year >> 4) * 10 + (year & 0x0F);

  Time[12 + i] = second % 10 + 48; //Converting to ASCII
  Time[11 + i] = second / 10 + 48;
  Time[10 + i] = ':';
  Time[9 + i] = minute % 10 + 48;
  Time[8 + i] = minute / 10 + 48;
  Time[7 + i] = ':';
  Time[6 + i] = hour % 10 + 48;
  Time[5 + i] = hour / 10 + 48;
  Calendar[12 + i] = year % 10 + 48;
  Calendar[11 + i] = year / 10 + 48;
  Calendar[10 + i] = '/';
  Calendar[9 + i] = month % 10 + 48;
  Calendar[8 + i] = month / 10 + 48;
  Calendar[7 + i] = '/';
  Calendar[6 + i] = date % 10 + 48;
  Calendar[5 + i] = date / 10 + 48;

  lcd.setCursor(0, 0);
  lcd.print(Time);
  lcd.setCursor(0, 1);
  lcd.print(Calendar);
}

int editbutton() {
  int alarm, hp, mp, dp, tp, yp;
  alarm = 0;
  hp = hour;
  mp = minute;
  dp = date;
  tp = month;
  yp = year;
  int j, k = 1;

  char ins1[] = "Leave button";
  char ins2[] = "Press button";

  for (j = 0; j < k; j++) {
    lcd.clear();

    if (digitalRead(8) == 0) {
      hour = 0;
      while (true) {
        hour = hour + 1;
        if (digitalRead(8) == 1)
          break;
        if (hour > 23) {
          hour = 0;
          lcd.clear();
        }
        lcd.setCursor(0, 0);
        lcd.print(ins1);
        lcd.setCursor(0, 1);
        lcd.print("hour ");
        lcd.print(hour);
        delay(500);
      }
    }

    lcd.clear();
    if (digitalRead(8) == 1) {
      minute = 0;
      while (true) {
        minute = minute + 1;
        if (digitalRead(8) == 0)
          break;
        if (minute > 59) {
          minute = 0;
          lcd.clear();
        }
        lcd.setCursor(0, 0);
        lcd.print(ins2);
        lcd.setCursor(0, 1);
        lcd.print("minute ");
        lcd.print(minute);
        delay(500);
      }
    }

    lcd.clear();
    if (digitalRead(8) == 0) {
      date = 0;
      while (true) {
        date = date + 1;
        if (digitalRead(8) == 1)
          break;
        if (date > 30) {
          date = 0;
          lcd.clear();
        }
        lcd.setCursor(0, 0);
        lcd.print(ins1);
        lcd.setCursor(0, 1);
        lcd.print("date ");
        lcd.print(date);
        delay(500);
      }
    }

    lcd.clear();
    if (digitalRead(8) == 1) {
      month = 0;
      while (true) {
        month = month + 1;
        if (digitalRead(8) == 0)
          break;
        if (month > 12) {
          month = 0;
          lcd.clear();
        }
        lcd.setCursor(0, 0);
        lcd.print(ins2);
        lcd.setCursor(0, 1);
        lcd.print("month ");
        lcd.print(month);

        delay(500);
      }
    }

    lcd.clear();
    if (digitalRead(8) == 0) {
      year = 0;
      while (true) {
        year = year + 1;
        if (digitalRead(8) == 1)
          break;
        if (year > 50) {
          year = 0;
          lcd.clear();
        }

        lcd.setCursor(0, 0);
        lcd.print(ins1);
        lcd.setCursor(0, 1);
        lcd.print("year ");
        lcd.print(year);
        delay(500);
      }
    }

    lcd.clear();

    for (int tc = 0; tc < 5; tc++) {

      if (alarm == 0) {
        lcd.setCursor(0, 0);
        lcd.print("To Set Alarm 1");
        lcd.setCursor(0, 1);
        lcd.print("Press Button ");
        lcd.print(tc);
        delay(2000);
      }
      if ((digitalRead(8) == 0 && alarm < 2) || k == 2) {
        lcd.clear();
        h[alarm] = hour - 1;
        m[alarm] = minute - 1;
        d[alarm] = date - 1;
        alarm = alarm + 1;
        tc = 0;
        lcd.setCursor(0, 0);
        lcd.print("Alarm ");
        lcd.print(alarm);
        lcd.print(" Set");
        delay(5000);
      }

      lcd.clear();
      if (alarm == 1) {
        lcd.setCursor(0, 0);
        lcd.print("To Set Alarm 2");
        lcd.setCursor(0, 1);
        lcd.print("Hold Button Now");
        delay(2000);
        lcd.clear();
      }

      if (digitalRead(8) == 0 && k <= 1) {
        lcd.setCursor(0, 0);
        lcd.print("Hold Button");
        lcd.setCursor(0, 1);
        lcd.print("Set Alarm Time");
        delay(1000);
        k = k + 1;
      }

      if (k == 2) {
        break;
      }

      delay(2000);
      //lcd.clear();
    }
  }

  if (alarm != 0) {
    hour = hp;
    minute = mp;
    date = dp;
    month = tp;
    year = yp;
  }

  return alarm;
}

void loop() {
  while (digitalRead(8) == 0) {
    al = editbutton();
    Serial.println(al);

    if (al == 0) {
      hour = hour - 1;
      minute = minute - 1;
      date = date - 1;
      month = month - 1;
      year = year - 1;
    }

    // Convert decimal to BCD
    minute = ((minute / 10) << 4) + (minute % 10);
    hour = ((hour / 10) << 4) + (hour % 10);
    date = ((date / 10) << 4) + (date % 10);
    month = ((month / 10) << 4) + (month % 10);
    year = ((year / 10) << 4) + (year % 10);
    // End conversion
    // Write data to DS3231 RTC
    Wire.beginTransmission(0x68); // Start I2C protocol with DS3231 address
    Wire.write(0); // Send register address
    Wire.write(0); // Reset seconds and start oscillator
    Wire.write(minute); // Write minute
    Wire.write(hour); // Write hour
    Wire.write(day); // NOT USED
    Wire.write(date); // Write date
    Wire.write(month); // Write month
    Wire.write(year); // Write year
    Wire.endTransmission(); // Stop transmission and release the I2C bus
    delay(300); // Wait 300ms
  }

  i = 1;
  y = y + 1;

  if (al > 0) {
    for (int x = 0; x < al; x++) {
      if (d[x] == date && h[x] == hour && m[x] == minute) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Alarm SET ON");
        delay(500);
        if (x == 0) {
          tone(9, NOTE_B0, 2000); // Play a different tone for Alarm 1
        } else if (x == 1) {
          tone(9, NOTE_G4, 1000); // Play a different tone for Alarm 2
        }
        delay(500); // Wait for the tone to finish playing
        noTone(9); // Turn off the tone
      } else {
        noTone(9); // Turn off the tone if the alarm is not triggered
      }
    }
  }

if(Serial.available()>0)
{
bs = Serial.read();
if(bs == 'e')
{
Serial.println("Enter Hour");  
while(x==0)
{
x = Serial.parseInt();
}
Serial.println(x);
pre = hour;
hour = x;
x=0;
}
if(hour > 23)
{
Serial.println("Invalid Entry For Hour");
hour = pre;
}
if(bs == 'e')
{
Serial.println("Enter Minute");
while(x==0)
{
x = Serial.parseInt();
}
Serial.println(x);
pre = minute;
minute = x;
x=0;
}
if(minute > 59)
{
Serial.println("Invalid Entry For Minute");
minute = pre;
}
if(bs == 'e')
{
Serial.println("Enter date");  
while(x==0)
{
x = Serial.parseInt();
}
Serial.println(x);
pre = date;
date = x;
x=0;
}
if(date > 31)
{
Serial.println("Invalid Entry For date");
date = pre;
}
if(bs == 'e')
{
Serial.println("Enter Month");  
while(x==0)
{
x = Serial.parseInt();
}
Serial.println(x);
pre = month;
month = x;
x=0;
}
if(month > 12)
{
Serial.println("Invalid Entry For Month");
month= pre;
}
if(bs == 'e')
{
Serial.println("Enter Year");  
while(x==0)
{
x = Serial.parseInt();
}
Serial.println(x);  
pre = year;
year = x;
x=0;
}
if(year > 25)
{
Serial.println("Invalid Entry For Year");
year = pre;
}


// Convert decimal to BCD
minute = ((minute / 10) << 4) + (minute % 10);
hour = ((hour / 10) << 4) + (hour % 10);
date = ((date / 10) << 4) + (date % 10);
month = ((month / 10) << 4) + (month % 10);
year = ((year / 10) << 4) + (year % 10);
// End conversion

if(bs=='v')
{
Serial.println(al);
  
Serial.println(h[0]);
Serial.println(hour);

Serial.println(m[0]);
Serial.println(minute);

Serial.println(d[0]);
Serial.println(date);

}

// Write data to DS3231 RTC
Wire.beginTransmission(0x68); // Start I2C protocol with DS3231 address
Wire.write(0); // Send register address
Wire.write(0); // Reset sesonds and start oscillator
Wire.write(minute); // Write minute
Wire.write(hour); // Write hour
Wire.write(day); // NOT USED
Wire.write(date); // Write date
Wire.write(month); // Write month
Wire.write(year); // Write year
Wire.endTransmission(); // Stop transmission and release the I2C bus
delay(300); // Wait 300ms
}

Wire.beginTransmission(0x68); // Start I2C protocol with DS3231 address
Wire.write(0); // Send register address
Wire.endTransmission(false); // I2C restart
Wire.requestFrom(0x68, 7); // Request 7 bytes from DS3231 and release I2C bus at end of reading
second = Wire.read(); // Read seconds from register 0
minute = Wire.read(); // Read minuts from register 1
hour = Wire.read(); // Read hour from register 2
day = Wire.read(); //NOT USED
date = Wire.read(); // Read date from register 4
month = Wire.read(); // Read month from register 5
year = Wire.read(); // Read year from register 6


DS3231_display(); // Display time & calendar

if(y==5)
{
Serial.println("To edit date and time enter e");
y=0;
}

Serial.println(ti);
Serial.println(Time);
Serial.println(ca);
Serial.println(Calendar);
Serial.println("\n");

delay(1000); // Wait 50ms
}
