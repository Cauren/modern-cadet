// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#if DIODE_DIRECTION != COL2ROW
#error This PCB has COL2ROW
#endif


static inline void gpio_atomic_set_pin_output_low(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        gpio_set_pin_output(pin);
        gpio_write_pin_low(pin);
    }
}

static inline void gpio_atomic_set_pin_output_high(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        gpio_set_pin_output(pin);
        gpio_write_pin_high(pin);
    }
}

static inline void gpio_atomic_set_pin_input(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        gpio_set_pin_input_low(pin);
    }
}

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS]   = MATRIX_COL_PINS;

void matrix_init_pins(void) {
    for(uint8_t r=0; r<MATRIX_ROWS; r++)
	if(row_pins[r] != NO_PIN)
	    gpio_atomic_set_pin_output_low(row_pins[r]);

    for(uint8_t c=0; c<MATRIX_COLS; c++)
	if(col_pins[c] != NO_PIN)
	    gpio_atomic_set_pin_input(col_pins[c]);
}

void matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    pin_t row_pin = row_pins[ current_row];
    if(row_pin == NO_PIN)
	return;
    gpio_atomic_set_pin_output_high(row_pin);
    matrix_output_select_delay();

    matrix_row_t row = 0;
    matrix_row_t row_shifter = MATRIX_ROW_SHIFTER;
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++, row_shifter <<= 1) {
	if(col_pins[col_index]!=NO_PIN && gpio_read_pin(col_pins[col_index]))
	    row |= row_shifter;
    }

    gpio_atomic_set_pin_output_low(row_pin);
    matrix_output_unselect_delay(current_row, row != 0);

    current_matrix[current_row] = row;
}

void bootmagic_scan(void) {
    matrix_init_pins();
    gpio_atomic_set_pin_output_high(row_pins[0]);
    matrix_output_select_delay();
    if(gpio_read_pin(col_pins[0]))
	bootloader_jump();
    gpio_atomic_set_pin_output_low(row_pins[0]);
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}


