

/ {
	ai_led{
		compatible = "ai,ai_led";
		led1 = <&gpioe 10 0>;
		led3 = <&gpioe 8 0>;
	};
};

&i2c1 {                                                                                                 
    pinctrl-names = "default", "sleep";
    pinctrl-0 = <&i2c1_pins_b>;
    pinctrl-1 = <&i2c1_sleep_pins_b>;
    i2c-scl-rising-time-ns = <185>;
    i2c-scl-falling-time-ns = <20>;
    clock-frequency = <400000>;
    status = "okay";
    /* spare dmas for other usage */
    /delete-property/dmas;
    /delete-property/dma-names;

    my_si7006: si7006@40 {
        compatible = "hqyj,si7006";
        reg = <0x40>;
        status = "okay";
    };
};

&spi4 {
    pinctrl-names = "default", "sleep";
    pinctrl-0 = <&spi4_pins_b>;
    pinctrl-1 = <&spi4_sleep_pins_b>;
    cs-gpios = <&gpioe 11 0>;
    status = "okay";

    my_m74hc595: m74hc595@0 {
        compatible = "hqyj,m74hc595";
        reg = <0>;
        spi-max-frequency = <10000000>;
        status = "okay";
    };
};
