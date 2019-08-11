# DEFCON 27 Badge Firmware

This repo contains a slightly modified copy of the official DEFCON 27 badge firmware,
the original of which can be downloaded from the
[DEFCON Media Server](https://media.defcon.org/DEF%20CON%2027/DEF%20CON%2027%20badge/Firmware/).

For more information on the DC27 badge and the hacking efforts, see
[this blog post](https://rhye.org/post/defcon-27-badge-writeup/).

This repo has been modified in a few small ways:

- Dependency on NXP-specific toolchain libraries have been removed.
    - Primarily, the Redlib libc has been swapped out for newlib-nano
- Badges flashed with this firmware will cycle throigh broadcasting as all badge types (chameleon mode).
- The extended rickroll has been enabled
- The light pattern has been modified, so that badges with this firmware can be easily identified.

## Building and flashing

To build, ensure that you have the GCC ARM toolchain installed:

```
sudo apt install binutils-arm-none-eabi gcc-arm-none-eabi gdb-arm-none-eabi
```

You can then build the badge easily with `make`:

```
cd Debug
make dc27_badge.axf
```

On success, you should get output like this:

```
Memory region         Used Size  Region Size  %age Used
   PROGRAM_FLASH:       58248 B        64 KB     88.88%
            SRAM:        5228 B        16 KB     31.91%
         USB_RAM:          0 GB        512 B      0.00%
Finished building target: dc27_badge.axf
```

To flash the badge, you can use a
[LPC-Link 2](https://twitter.com/joegrand/status/1157036422454362112)
or
[Black Magic Probe](https://1bitsquared.com/products/black-magic-probe).
Connect the probe to the SWD pins using a TagConnect
[TC-2050-IDC-NL-050-ALL](http://www.tag-connect.com/TC2050-IDC-NL-050-ALL)
cable, and then load up GDB and flash like so:

```
arm-none-eabi-gdb dc27_badge.axf
target extended-remote /dev/ttyACM0
monitor swdp scan
attach 1
load
continue
```

You can then disconnect, and your badge should be running the new firmware.
