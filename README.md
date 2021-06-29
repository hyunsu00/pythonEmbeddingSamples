# pythonEmbeddingSamples

## playwright 설치 방법

## 윈도우즈

- [embeddable python 무설치 파이썬 사용법 포터블 파이썬](https://m.blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=wonjinho81&logNo=221680495397&proxyReferer=)
- python3.7.8 (VS2019 python 개발시 포함 버전)

```cmd
# playwright 설치
pip install playwright
python -m install playwright
```

## 리눅스

- [Linux에 Python을 설치하는 방법](https://realpython.com/installing-python/#how-to-install-python-on-linux)

### 우분투 18.04

- 패키지 관리자에서 설치

```bash
# python-3.7
apt update
# 배포
apt -y install python3.7 python3-pip tk
# 개발
#apt -y install python3.7-dev python3-pip tk

#확인
which python3.7
ls -al /usr/bin/python3.7
ls /usr//bin | grep python

# playwright 설치
python3.7 -m pip install playwright
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

- 소스코드에서 빌드

```bash
# python-3.7.10 빌드시 필요한 패키지 설치
apt update
apt upgrade -y
apt dist-upgrade

# libffi-dev : python 디버깅시 ctype에러 수정
apt -y install build-essential python-dev python-setuptools python-pip python-smbus \
    libncursesw5-dev libgdbm-dev libc6-dev \
    zlib1g-dev libsqlite3-dev tk-dev \
    libssl-dev openssl \
    libffi-dev \
    wget

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

# 확인
which python3.7
ls -al /usr/local/bin/python3.7
ls /usr/local/bin | grep python

# playwright 설치
# openssl 설치해서 -i(index-url), --trusted-host 불필요
# pip3.7 install playwright -i http://mirror.kakao.com/pypi/simple --trusted-host mirror.kakao.com
# python3.7 -m pip install playwright -i http://mirror.kakao.com/pypi/simple --trusted-host mirror.kakao.com
# pip3.7 install playwright
python3.7 -m pip install playwright
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

#### 참고 (여러버전 파이선 설정)

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

### centos 7

- 소스코드에서 빌드

```bash
# python-3.7.10 빌드시 필요한 패키지 설치
# libffi-devel : python 디버깅시 ctype에러 수정
yum -y install make \
gcc gcc-c++ \
zlib zlib-devel \
openssl-devel \
libffi-devel

yum -y install wget which

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

# 확인
which python3.7
ls -al /usr/local/bin/python3.7
ls /usr/local/bin | grep python

# playwright 설치
# openssl 설치해서 -i(index-url), --trusted-host 불필요
# pip3.7 install playwright -i http://mirror.kakao.com/pypi/simple --trusted-host mirror.kakao.com
# python3.7 -m pip install playwright -i http://mirror.kakao.com/pypi/simple --trusted-host mirror.kakao.com
# pip3.7 install playwright
python3.7 -m pip install playwright
# 브라우저 모두 설치
# python3.7 -m playwright install
# 브라우저 chromium만 설치
python3.7 -m playwright install chromium

# playwright 실행시 필요한 패키지 설치
yum install -y atk \
at-spi2-atk \
cups-libs \
libdrm \
libxcb \
libxkbcommon \
libX11 \
libXcomposite \
libXdamage \
libXext \
libXfixes \
libXrandr \
mesa-libgbm \
pango \
cairo \
alsa-lib \
at-spi2-core \
libxshmfence
```

#### 참고 (pip 저장소 kakao로 사용)

```bash
# pip kakao 로 설정
# ~/.pip/pip.conf 파일 생성후 아래의 내용 입력
[global]
index-url=http://mirror.kakao.com/pypi/simple
trusted-host=mirror.kakao.com
```

#### 참고 (playwright 바이너리 로컬 폴더에 설치)

```bash
# Linux/macOS
pip install playwright
PLAYWRIGHT_BROWSERS_PATH=0 playwright install

# Windows with cmd.exe
set PLAYWRIGHT_BROWSERS_PATH=0
pip install playwright
playwright install

# Windows with PowerShell
$env:PLAYWRIGHT_BROWSERS_PATH=0
pip install playwright
playwright install
```

#### 참고 (chromium, firefox cli)

```powershell
#크롬
# 화면캡쳐 - 전체화면 캡쳐는 확인 요망
chrome --headless --disable-gpu --hide-scrollbars --screenshot=naver.png https://www.naver.com
# PDF 저장
chrome --headless --disable-gpu --print-to-pdf=naver.pdf https://www.naver.com

[파이어폭스]
# 화면캡쳐 - 전체 화면
firefox --screenshot=naver.png https://www.naver.com
# PDF 저장 지원안함
```
