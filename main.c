#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main() {
    
    // Init standard input and output
    stdio_init_all();
    if(cyw43_arch_init()) {
    	puts("Wi-Fi init failed");
	    return -1;
    }

    // Turn the onboard led on and off.
    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        puts("LED on");
        sleep_ms(1000);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        puts("LED off");
        sleep_ms(1000);
    }

    return 0;
}
