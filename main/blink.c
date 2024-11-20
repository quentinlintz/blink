#include "led_strip.h"

#define LED 23

static uint8_t s_led_state = 0;
static led_strip_handle_t led_strip;

static void configure_led() {
  led_strip_config_t strip_config = {
      .strip_gpio_num = LED,
      .max_leds = 1,
  };
  led_strip_rmt_config_t rmt_config = {
      .resolution_hz = 10 * 1000 * 1000,
      .flags.with_dma = false,
  };
  led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip);
  led_strip_clear(led_strip);
}

void blink_led(void) {
  if (s_led_state) {
    // My favorite color
    led_strip_set_pixel(led_strip, 0, 160, 32, 240);
    led_strip_refresh(led_strip);
  } else {
    led_strip_clear(led_strip);
  }
}

void app_main(void) {
  configure_led();
  while (1) {
    blink_led();
    s_led_state = !s_led_state;
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
