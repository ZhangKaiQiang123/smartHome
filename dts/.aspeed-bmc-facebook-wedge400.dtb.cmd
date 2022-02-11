cmd_arch/arm/boot/dts/aspeed-bmc-facebook-wedge400.dtb := gcc -E -Wp,-MMD,arch/arm/boot/dts/.aspeed-bmc-facebook-wedge400.dtb.d.pre.tmp -nostdinc -I./scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm/boot/dts/.aspeed-bmc-facebook-wedge400.dtb.dts.tmp arch/arm/boot/dts/aspeed-bmc-facebook-wedge400.dts ; ./scripts/dtc/dtc -O dtb -o arch/arm/boot/dts/aspeed-bmc-facebook-wedge400.dtb -b 0 -iarch/arm/boot/dts/ -i./scripts/dtc/include-prefixes -Wno-interrupt_provider -Wno-unit_address_vs_reg -Wno-unit_address_format -Wno-avoid_unnecessary_addr_size -Wno-alias_paths -Wno-graph_child_address -Wno-simple_bus_reg -Wno-unique_unit_address -Wno-pci_device_reg  -d arch/arm/boot/dts/.aspeed-bmc-facebook-wedge400.dtb.d.dtc.tmp arch/arm/boot/dts/.aspeed-bmc-facebook-wedge400.dtb.dts.tmp ; cat arch/arm/boot/dts/.aspeed-bmc-facebook-wedge400.dtb.d.pre.tmp arch/arm/boot/dts/.aspeed-bmc-facebook-wedge400.dtb.d.dtc.tmp > arch/arm/boot/dts/.aspeed-bmc-facebook-wedge400.dtb.d

source_arch/arm/boot/dts/aspeed-bmc-facebook-wedge400.dtb := arch/arm/boot/dts/aspeed-bmc-facebook-wedge400.dts

deps_arch/arm/boot/dts/aspeed-bmc-facebook-wedge400.dtb := \
  scripts/dtc/include-prefixes/dt-bindings/gpio/aspeed-gpio.h \
  scripts/dtc/include-prefixes/dt-bindings/gpio/gpio.h \
  arch/arm/boot/dts/ast2500-facebook-netbmc-common.dtsi \
  arch/arm/boot/dts/aspeed-g5.dtsi \
  scripts/dtc/include-prefixes/dt-bindings/clock/aspeed-clock.h \
  scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/aspeed-scu-ic.h \

arch/arm/boot/dts/aspeed-bmc-facebook-wedge400.dtb: $(deps_arch/arm/boot/dts/aspeed-bmc-facebook-wedge400.dtb)

$(deps_arch/arm/boot/dts/aspeed-bmc-facebook-wedge400.dtb):
