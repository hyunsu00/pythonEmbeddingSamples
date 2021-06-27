# pythonEmbeddingSamples

## playwright 설치 방법

### 윈도우즈

- 파이썬 버전

```powershell
# 파이썬 버전은
pip install playwright

python -m install playwright
```

### 리눅스

- 우분투 18.04

```bash

cd /tmp

wget --no-check-certificate https://www.python.org/ftp/python/3.7.10/Python-3.7.10.tgz

tar xzf Python-3.7.10.tgz

cd Python-3.7.10

./configure --enable-optimizations

sudo make altinstall

# 추가
python3 -V

which python3
which python3.6
which python3.7

sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.6 1
sudo update-alternatives --install /usr/bin/python3 python3 /usr/local/bin/python3.7 2

sudo update-alternatives --config python3

sudo pip3.7 install playwright
```
