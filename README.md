# qmk-lge-crkbd
LGe mapping for the corne keyboard
```
sudo apt install -y pipx
pipx install qmk
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
git submodule add git@github.com:lgranie/qmk-lge-crkbd.git keyboards/crkbd/keymaps/lge
git commit -am "add crkbd/lge"
qmk setup
qmk compile -kb crkbd -km lge
```

