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
# wget 설치 되어 있지 않다면 설치
apt install wget -y

# python-3.7.0 빌드시 필요한 패키지 설치
apt update
apt upgrade
apt dist-upgrade
apt -y install build-essential python-dev python-setuptools python-pip python-smbus
apt -y install libncursesw5-dev libgdbm-dev libc6-dev
apt -y install zlib1g-dev libsqlite3-dev tk-dev
apt -y install libssl-dev openssl
# libffi-dev : python 디버깅시 ctype에러 수정
apt -y install libffi-dev
apt -y install zlib1g-dev6

#확인
python -V
which python
ls -al /usr/bin/python
ls /usr/bin | grep python

# python-3.7.10 설치
cd /tmp
# openssl 설치해서 --no-check-certificate 불필요
# wget --no-check-certificate https://www.python.org/ftp/python/3.7.10/Python-3.7.10.tgz
wget https://www.python.org/ftp/python/3.7.10/Python-3.7.10.tgz
tar xzf Python-3.7.10.tgz
cd Python-3.7.10
# ./configure
# make install
./configure --enable-optimizations
make altinstall

#확인
which python3.7
ls -al /usr/local/bin/python3.7
ls /usr/local/bin | grep python

# playwright 설치
# openssl 설치해서 -i(index-url), --trusted-host 불필요
# pip3.7 install playwright -i http://mirror.kakao.com/pypi/simple --trusted-host mirror.kakao.com
pip3.7 install playwright
# 브라우저 모두 설치
# python3.7 -m playwright install
# 브라우저 chromium만 설치
python3.7 -m playwright install chromium

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

apt -y install libxshmfence-dev
```

## 참고 (여러버전 파이선 설정)

```bash
# python 확인
python -V
which python
ls -al /usr/bin/python
ls /usr/bin | grep python
which python3.7
ls -al /usr/local/bin/python3.7
ls /usr/local/bin | grep python

# 설정
update-alternatives --config python
update-alternatives --install /usr/bin/python python /usr/bin/python2.7 1
update-alternatives --install /usr/bin/python python /usr/local/bin/python3.7 2
update-alternatives --config python
```

### centos 7 빌드

```bash

```

```bash
#
index-url=http://mirror.kakao.com/pypi/simple
trusted-host=mirror.kakao.com

PLAYWRIGHT_BROWSERS_PATH=0 python3.7 -m playwright install
# 위에거 안되면
python3.7 -m playwright install
sudo apt-get install libgbm1
```
