
Debian
====================
This directory contains files used to package StakeCenterCashd/StakeCenterCash-qt
for Debian-based Linux systems. If you compile StakeCenterCashd/StakeCenterCash-qt yourself, there are some useful files here.

## StakeCenterCash: URI support ##


StakeCenterCash-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install StakeCenterCash-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your StakeCenterCashqt binary to `/usr/bin`
and the `../../share/pixmaps/StakeCenterCash128.png` to `/usr/share/pixmaps`

StakeCenterCash-qt.protocol (KDE)

