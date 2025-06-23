#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  float mpg;
  float gallons;
} GasEngine;

typedef struct {
  float mpkwh;
  float kwh;
} ElectricEngine;

typedef enum {
  GAS_ENGINE,
  ELECTRIC_ENGINE,
} Engine;

typedef struct {
  char name[32];
  unsigned short int model;
  Engine engine;
  union {
    GasEngine gasEngine;
    ElectricEngine electricEngine;
  };
} Car;

bool can_make_it(Car car, unsigned int miles) {
  bool make_it = milesLeft(car) >= miles;
  if (make_it)
    compatible_cars++;
  return make_it;
}

void car_display(Car car);
unsigned short int milesLeft(Car car);
bool can_make_it(Car car, unsigned int miles);

unsigned short compatible_cars = 0;

int main() {
  Car cars[3] = {
      (Car){"Honda Civic", 11, ELECTRIC_ENGINE, .electricEngine = {12.8, 42.5}},
      (Car){"Tata Nano", 4, GAS_ENGINE, .gasEngine = {16.4, 38.2}},
      (Car){"Suzuki Alto", 7, GAS_ENGINE, .gasEngine = {12.9, 43.7}}};
  int size = sizeof(cars) / sizeof(cars[0]);

  unsigned int travel_miles;
  printf("Enter miles to travel : ");
  scanf("%u", &travel_miles);
  printf("\n");

  for (int i = 0; i < size; i++)
    if (can_make_it(cars[i], travel_miles))
      car_display(cars[i]);

  if (compatible_cars == 0)
    printf("Oops | No cars available\n");

  return 0;
}

unsigned short int milesLeft(Car car) {
  switch (car.engine) {
  case GAS_ENGINE:
    return car.gasEngine.mpg * car.gasEngine.gallons;
    break;
  case ELECTRIC_ENGINE:
    return car.electricEngine.mpkwh * car.electricEngine.kwh;
    break;
  default:
    return 1;
  }
}

bool can_make_it(Car car, unsigned int miles) {
  bool make_it = milesLeft(car) >= miles;
  if (make_it)
    compatible_cars++;
  return make_it;
}

void car_display(Car car) {
  printf("%s | %u\n", car.name, car.model);
  printf("%u | %s Engine -> %.2f\n\n", milesLeft(car),
         car.engine == GAS_ENGINE ? "Gas" : "Electric",
         car.engine == GAS_ENGINE ? car.gasEngine.mpg
                                  : car.electricEngine.mpkwh);
}
