import pygame
import tkinter as tk

def play_beep():
  pygame.mixer.init()
  pygame.mixer.music.load("beep.mp3")
  pygame.mixer.music.play()
  while pygame.mixer.music.get_busy() == True: 
      continue


def key(event):
    if event.keysym == 'Escape':
      root.destroy()
    if event.char == event.keysym:
      print( 'Normal Key %r' % event.char )
      play_beep()
    elif len(event.char) == 1:
      print( 'Punctuation Key %r (%r)' % (event.keysym, event.char) )
      play_beep()
    else:
      print( 'Special Key %r' % event.keysym )
      play_beep()
      
root = tk.Tk()
print( "Press a key (Escape key to exit):" )
root.bind_all('<Key>', key)
# don't show the tk window
root.withdraw()
root.mainloop()

