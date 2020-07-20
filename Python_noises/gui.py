from tkinter import Tk, Canvas, PhotoImage
import perlin

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
      img.put(value_color(get_noise_value(x/32, y/32)), (x+1, y+1))

  window.mainloop()


def get_noise_value(x, y):
  v = int(noise.get_value(x, y)*0xff)
  return v


noise = perlin.Perlin(int(input("Seed: ")))
#print(noise.get_value(4.5, 4.5))
show(noise)