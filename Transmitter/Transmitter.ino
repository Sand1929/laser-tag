#define LED_PIN        3
#define SPEAKER_PIN    5
#define BUTTON_PIN     7

int ammo = 20;
bool automatic = true;

void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(BUTTON_PIN, HIGH);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(BUTTON_PIN) == LOW)
  {
    // check for ammo
    if (ammo > 0)
    {
      --ammo;
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
    else
    {
      tone(SPEAKER_PIN, 50, 1000);
      // reload
      delay(5000);
      ammo = 20;
    }
    // if semi-automatic, wait for button release
    if (!automatic)
    {
      while (digitalRead(BUTTON_PIN) == LOW);
    }
  }
}
