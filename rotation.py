from graphics import *
from random import randint
from math import sin, cos, radians
import time
 
def rotateTriangle(triangle, degrees):
   angle = radians(degrees)
   cosang, sinang = cos(angle), sin(angle)
 
   points = triangle.getPoints()
   n = len(points)
   cx = sum(p.getX() for p in points) / n
   cy = sum(p.getY() for p in points) / n
 
   new_points = []
   for p in points:
       x, y = p.getX(), p.getY() 
       tx, ty = x-cx, y-cy
       new_x = ( tx*cosang + ty*sinang) + cx
       new_y = (-tx*sinang + ty*cosang) + cy
       new_points.append(Point(new_x, new_y))
 
   rotated_ploygon = triangle.clone()
   rotated_ploygon.points = new_points
   return rotated_ploygon
 
 
 
print("Point 1")
x1=int(input("Enter x : "))
y1=int(input("Enter y : "))
 
print("Point 2")
x2=int(input("Enter x : "))
y2=int(input("Enter y : "))
print("Point 3")
x3=int(input("Enter x : "))
y3=int(input("Enter y : "))

win = GraphWin('Rotate Triangle', 600, 600)
p1 = Point(x1,y1)
p2 = Point(x2,y2)
p3 = Point(x3, y3)
triangle = Polygon(p1,p2,p3)
triangle.setFill('cyan')
triangle.draw(win)
angle=int(input("Enter the angle of rotation : "))
triangle = rotateTriangle(triangle,angle)
triangle.setFill('blue')
triangle.draw(win)

win.getMouse()
win.close()
