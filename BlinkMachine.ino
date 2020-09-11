class BlinkMachine
{
private:
  int* Periods;
  int  PereodsCount;
  unsigned long totalTime;
public:
  void SetPeriods(int* p, int pc)
  {
    Periods = p;
    PereodsCount = pc;
    totalTime = 0;
    for (int i = 0; i < PereodsCount; i++)
      totalTime += Periods[i];
  }
  int Tick(unsigned long time)
  {
    auto z = time % totalTime;
    for (int i = 0; i < PereodsCount - 1; i++)
    {
      if (z < Periods[i]) return i % 2;
      z -= Periods[i];
    }
    return 1;
  }
};

#define M_SIZE 20
BlinkMachine bm;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  int m[M_SIZE] = { 1000,1000,1000,1000,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100 };
  bm.SetPeriods(m, M_SIZE);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, bm.Tick(millis()));   // turn the LED on (HIGH is the voltage level)
  delay(25);
}
