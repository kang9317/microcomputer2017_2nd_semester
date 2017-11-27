from gtts import gTTS
tts = gTTS(text='Hello', lang='en', slow=True)
tts.save('hello.mp3')
