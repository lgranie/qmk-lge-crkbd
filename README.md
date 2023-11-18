# qmk-lge-crkbd
LGe mapping for the corne keyboard
```
sudo apt install -y pipx
pipx install qmk
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
git submodule add https://github.com/lgranie/qmk-lge-crkbd keyboards/crkbd/keymaps/lge
git commit -am "add crkbd/lge"
qmk setup
qmk compile -kb crkbd -km lge
```

