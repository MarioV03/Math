from tkinter import *
from perlin import *

# color formating shit
def value_color(value):
  return "#"+"{:02X}".format(value)*3


def hex_color(rgb):
  return "#"+"".join("{:02X}".format(a) for a in rgb)

# visualization shit
def show(noise):

  W, H = 512, 512

  # The window
  window = Tk()

  # widgets
  can = Canvas(window, width=W, height=W, bg="magenta")
  can.pack()

  img = PhotoImage(width=W, height=H)
  can.create_image((W/2, H/2), image=img, state="normal")

  for x in range(W):
    for y in range(H):
      value = 2*noise.get_value(x/64, y/64)*255
      value += noise.get_value(x/16 + 3.567, y/16 + 3.567)*255
      value = int(value/3)
      img.put(value_color(value), (x+1, y+1))

  window.mainloop()


noise = Perlin(int(input("Seed: ")))
#print(noise.get_value(4.5, 4.5))
show(noise)