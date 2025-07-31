# modern_cadet

![modern_cadet](imgur.com image)


A 120% keyboard for nerds paying hommage to the IBM model M and Space Cadet keyboards.
Features all the bucky bits and a hex numpad.  The PCB supports split left shift, split
backspace, split numpad 0, stepped caps lock and two possible additional keys on either
side of the up arrow position (but the default plate does _not_ have openings for
those two keys as-is.

* Keyboard Maintainer: [Marc A. Pelletier](https://github.com/Cauren)
* Hardware Supported: [Build your own](https://github.com/Cauren/modern-cadet)
* Hardware Availability: DIY

Make example for this keyboard (after setting up your build environment):

    make modern_cadet:default

Flashing example for this keyboard:

    make modern_cadet:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the top left key, SAK in the default layout) and plug in the keyboard
* **Jumper**:  Close the jumper on the underside of the keyboard PCB.
