## Overview:

Check CLO-snapshot for console

## Installation:

```bash
git clone https://github.com/nn1k1kvn/checkclosnap.git 
cd checkclosnap
i686-w64-mingw32-g++ -std=c++11 -c checkclosnap.cpp
i686-w64-mingw32-g++ checkclosnap.o -o checkclosnap
```
## Download snapshot

```bash
curl -C - -O https://raw.githubusercontent.com/EthereumCommonwealth/Callisto-Snapshot/master/snapshot/snapshot_0001.txt
```
## Runing 
```bash
./checkclosnap 0x4E034B79Baf6905DCc8720af15f986f59E33f402
```
