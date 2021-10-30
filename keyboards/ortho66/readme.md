# ergospoondox

![ergospoondox](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [MasterSpoon](https://github.com/MasterSpoon)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make ergospoondox:default

Flashing example for this keyboard:

    make ergospoondox:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

edit /qmk_firmware/.gitmodules
change submodules
[submodule "lib/chibios"]
	path = lib/chibios
	url = https://github.com/ChibiOS/ChibiOS
	branch = stable_20.3.x
[submodule "lib/chibios-contrib"]
	path = lib/chibios-contrib
	url = https://github.com/ChibiOS/ChibiOS-Contrib
	branch = stable_20.3.x
MSYS change to qmk_firmware folder 
then run
git submodule
git submodule sync
git submodule update --init --recursive --remote -f
