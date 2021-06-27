# pythonEmbeddingSamples

## playwright 설치 방법

### 윈도우즈

- 파이썬 버전

```powershell
# 파이썬 버전은
pip install playwright

python -m install playwright
```

## 리눅스

### 우분투 18.04 빌드

```bash
# wget, zlib1g-dev이 설치 되어 있지 않다면 설치
apt install wget -y
apt install zlib1g-dev -y

# python-3.7.10 설치
cd /tmp
wget --no-check-certificate https://www.python.org/ftp/python/3.7.10/Python-3.7.10.tgz
tar xzf Python-3.7.10.tgz
cd Python-3.7.10
./configure
make install

#확인
python3 -V
which python3
which python3.7

# playwright 설치
pip3.7 install playwright -i http://mirror.kakao.com/pypi/simple --trusted-host mirror.kakao.com
python3.7 -m playwright install

# playwright 실행시 필요한 패키지 설치
apt install -y libnss3 \
libnspr4 \
libatk1.0-0 \
libatk-bridge2.0-0 \
libcups2 \
libdrm2 \
libdbus-1-3 \
libxkbcommon0 \
libxcomposite1 \
libxdamage1 \
libxfixes3 \
libxrandr2 \
libgbm1 \
libpango-1.0-0 \
libcairo2 \
libasound2 \
libatspi2.0-0

apt install libxshmfence-dev -y
```

index-url=http://mirror.kakao.com/pypi/simple
trusted-host=mirror.kakao.com

./configure --enable-optimizations
sudo make altinstall

# 추가

which python3.6

sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.6 1
sudo update-alternatives --install /usr/bin/python3 python3 /usr/local/bin/python3.7 2

sudo update-alternatives --config python3

sudo pip3.7 install playwright

```

ls -al /usr/bin/python
ls /usr/bin | grep python

sudo update-alternatives --install /usr/bin/python python /usr/bin/python2.7 1
sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.6 2
sudo update-alternatives --install /usr/bin/python python /usr/local/bin/python3.7 3
sudo update-alternatives --config python


pip3.7 install playwright

python3.7 -m playwright install

#
PLAYWRIGHT_BROWSERS_PATH=0 python3.7 -m playwright install

# 위에거 안되면
python3.7 -m playwright install

sudo apt-get install libgbm1
```
