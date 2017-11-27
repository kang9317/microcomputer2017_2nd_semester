import os
import sys
import urllib.request
client_id = "tqibfPsc5zq1oSaulrMf"
client_secret = "7GqPmDyxHc"
encText = urllib.parse.quote("자동 전환 합니다~~~~~")
data = "speaker=mijin&speed=0&text=" + encText;
url = "https://openapi.naver.com/v1/voice/tts.bin"
request = urllib.request.Request(url)
request.add_header("X-Naver-Client-Id",client_id)
request.add_header("X-Naver-Client-Secret",client_secret)
response = urllib.request.urlopen(request, data=data.encode('utf-8'))
rescode = response.getcode()
if(rescode==200):
    print("TTS mp3 저장")
    response_body = response.read()
    with open('./test/음성2.mp3', 'wb') as f:
        f.write(response_body)
else:
    print("Error Code:" + rescode)

#mijin
