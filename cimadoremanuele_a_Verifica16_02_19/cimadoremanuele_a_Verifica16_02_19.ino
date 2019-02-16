int rosso;
int giallo;
int bianco;
int verde;
int TempoAccensione;
int CicliProgramma;
void setup() {
  // put your setup code here, to run once:
  rosso = 13;
  giallo = 11;
  bianco = 7;
  verde = 5;

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);

  Serial.begin(9600);

  RichiestaTempo("Dopo quanti cicli il programma ricomincia?");
  TempoAccensione = random(5000);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  for (int a = 0; a < CicliProgramma; a++)
  {
  AccensioneRosso();
  AccensioneGiallo();
  AccensioneBianco();
  AccensioneVerde();
  }
  setup();
}
void AccensioneRosso()
{
  digitalWrite(rosso, HIGH);
  delay(TempoAccensione);
}
void AccensioneGiallo()
{
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, HIGH);
  delay(TempoAccensione);
}
void AccensioneBianco()
{
  digitalWrite(giallo, LOW);
  digitalWrite(bianco, HIGH);
  delay(TempoAccensione);
}
void AccensioneVerde()
{
  digitalWrite(bianco, LOW);
  digitalWrite(verde, HIGH);
  delay(TempoAccensione);
  digitalWrite(verde, LOW);
}
void RichiestaTempo(String frase)
{
  Serial.println(frase);
  while (Serial.available() == 0) {}
  CicliProgramma = Serial.readString().toInt();
}
