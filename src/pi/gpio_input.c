/* Implements the functions that fetch operation from PI's GPIO ports */

#include <stdio.h>
#include "gpio_input.h"
#include "gpio_button.h"

#define MODE_NUM 1

/* Function pointers arrrays used to simplify the code */
typedef operator_t (*gpio_inputs) (void);
typedef void (*gpio_inits) (void);
gpio_inputs input_selector[] = {get_button};
gpio_inits init_selector[] = {init_gpio_but};


operator_t get_input(pi_mode_t mode) {
  if (mode >= MODE_NUM) {
    fprintf(stderr, "Unknown input mode!");
    return NONE;
  }
  return input_selector[mode]();
}

void init_gpio(pi_mode_t mode) {
  if (mode >= MODE_NUM) {
    fprintf(stderr, "Unknown input mode!");
    return;
  }
  init_selector[mode]();
}
