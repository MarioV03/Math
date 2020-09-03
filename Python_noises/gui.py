from tkinter import Tk, Canvas, PhotoImage
import perlin
from math import sin

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


def clip(value, limit):
    return min(value, limit)/limit


def get_noise_value(x, y):
    v1 = noise.get_value(x/2, 1.5 + y/30)
    v2 = noise.get_value(0.5 + x/30, y)
    v = v1*v2
    if(v < 0.5):
        v = 0
    else:
        v = (v - 0.5) * 2
    v = int(v*0xff)
    return v


noise = perlin.Perlin(int(input("Seed: ")))
#print(noise.get_value(4.5, 4.5))
show(noise)
