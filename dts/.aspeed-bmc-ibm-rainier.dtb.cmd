cmd_arch/arm/boot/dts/aspeed-bmc-ibm-rainier.dtb := gcc -E -Wp,-MMD,arch/arm/boot/dts/.aspeed-bmc-ibm-rainier.dtb.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm/boot/dts/.aspeed-bmc-ibm-rainier.dtb.dts.tmp arch/arm/boot/dts/aspeed-bmc-ibm-rainier.dts ; ./scripts/dtc/dtc -O dtb -o arch/arm/boot/dts/aspeed-bmc-ibm-rainier.dtb -b 0 -iarch/arm/boot/dts/ -i./scripts/dtc/include-prefixes -Wno-interrupt_provider -Wno-unit_address_vs_reg -Wno-unit_address_format -Wno-avoid_unnecessary_addr_size -Wno-alias_paths -Wno-graph_child_address -Wno-simple_bus_reg -Wno-unique_unit_address -Wno-pci_device_reg  -d arch/arm/boot/dts/.aspeed-bmc-ibm-rainier.dtb.d.dtc.tmp arch/arm/boot/dts/.aspeed-bmc-ibm-rainier.dtb.dts.tmp ; cat arch/arm/boot/dts/.aspeed-bmc-ibm-rainier.dtb.d.pre.tmp arch/arm/boot/dts/.aspeed-bmc-ibm-rainier.dtb.d.dtc.tmp > arch/arm/boot/dts/.aspeed-bmc-ibm-rainier.dtb.d

source_arch/arm/boot/dts/aspeed-bmc-ibm-rainier.dtb := arch/arm/boot/dts/aspeed-bmc-ibm-rainier.dts

deps_arch/arm/boot/dts/aspeed-bmc-ibm-rainier.dtb := \
  arch/arm/boot/dts/aspeed-g6.dtsi \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/arm-gic.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/irq.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/aspeed-scu-ic.h \
  scripts/dtc/include-prefixes/dt-bindings/clock/ast2600-clock.h \
  arch/arm/boot/dts/aspeed-g6-pinctrl.dtsi \
  scripts/dtc/include-prefixes/dt-bindings/gpio/aspeed-gpio.h \
  scripts/dtc/include-prefixes/dt-bindings/gpio/gpio.h \
  scripts/dtc/include-prefixes/dt-bindings/i2c/i2c.h \
  scripts/dtc/include-prefixes/dt-bindings/leds/leds-pca955x.h \
  arch/arm/boot/dts/openbmc-flash-layout-128.dtsi \

arch/arm/boot/dts/aspeed-bmc-ibm-rainier.dtb: $(deps_arch/arm/boot/dts/aspeed-bmc-ibm-rainier.dtb)

$(deps_arch/arm/boot/dts/aspeed-bmc-ibm-rainier.dtb):
