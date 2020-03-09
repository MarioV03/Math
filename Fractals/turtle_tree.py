import turtle

pen = turtle.Turtle()
pen.penup()
pen.left(90)
pen.backward(250)
pen.speed(200)
pen.pendown()

def branch(length):
    if(length<1):
        return
    else:
        pen.forward(length)
        pen.left(30)
        branch(length/2)
        pen.right(60)
        branch(length/2)
        pen.left(30)
        pen.backward(length)


branch(100)
