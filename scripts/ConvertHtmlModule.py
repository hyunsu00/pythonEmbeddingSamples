#!/usr/bin/env python3.7
from playwright.sync_api import sync_playwright

def HtmlToImage(htmlURL, resultFilePath, imageType):
    with sync_playwright() as playwright:
        try:
            chromium = playwright.chromium
            browser = chromium.launch()
            page = browser.new_page()
            page.goto(htmlURL)
            page.screenshot(path=resultFilePath, type=imageType, full_page=True)
            page.close()
        except Exception as e:
            print('htmlToImageFail : %s' % (e))
            

def HtmlToPdf(htmlURL, resultFilePath):
    with sync_playwright() as playwright:
        try:
            chromium = playwright.chromium
            browser = chromium.launch()
            page = browser.new_page()
            page.goto(htmlURL)
            page.pdf(path=resultFilePath)
            page.close()
        except Exception as e:
            print('htmlToPdfFail : %s' % (e))
    
if __name__ == "__main__":
    # 1. HtmlToImage 테스트
    HtmlToImage("https://www.naver.com/", "naver.png", "png");
    # 2. HtmlToPdf 테스트
    HtmlToPdf("https://www.naver.com/", "naver.pdf");
