#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  float SOH=100*(*presentCapacities)/120;
  struct CountsBySoH counts = {0, 0, 0};
 
  for(int i=0;i< nBatteries;i++)
    {
     if(SOH >80 && SOH<=100)
       counts.healthy++;
      else if (SOH > 62 && SOH <80)
        counts.exchange++;
      else 
        counts.failed++;
    }
  
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
