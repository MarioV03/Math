import math



class Vector:

  def __init__(self, _x, _y):
    self.x = _x
    self.y = _y

  def __add__(self, other):
    return Vector(self.x+other.x, self.y+other.y)

  def __sub__(self, other):
    return Vector(self.x-other.x, self.y-other.y)

  def __mul__(self, other):
    return self.x*other.x + self.y*other.y


class Perlin:

  def __init__(self, seed):
    self.grad = []
    self.permutation = [151,160,137,91,90,15,                
    131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
    190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
    88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
    77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
    102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
    135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
    5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
    223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
    129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
    251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
    49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
    138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180]
    for x in range(16):
      for y in range(16):
        theta = self.permutation[(x+16*y + seed)%256]/256*2*math.pi
        self.grad.append(Vector(math.cos(theta), math.sin(theta)))
    
  def ease(self, t):
    return t * t * t * (t * (t * 6 - 15) + 10)
    #return -t

  def interpolate(self, v1, v2, w):
    return (1 - w)*v1 + w*v2

  #def gradient(self, x, y, cell_x, cell_y):

  def get_value(self, x, y):

    point = Vector(x, y)
    cell = Vector(int(x//1), int(y//1))
    
    # coords of the top-left corner of containing cell
    cell_x = x//1
    cell_y = y//1

    # interpolation weights
    wx = self.ease(x - cell_x)
    wy = self.ease(y - cell_y)

    nw = self.grad[cell.x%16 + cell.y%16*16]*(point - cell)
    ne = self.grad[(cell.x + 1)%16 + cell.y%16*16]*(point - cell - Vector(1, 0))
    sw = self.grad[cell.x%16 + (cell.y+1)%16*16]*(point - cell - Vector(0, 1))
    se = self.grad[(cell.x + 1)%16 + (cell.y + 1)%16*16]*(point - cell - Vector(1, 1))
    
    north = self.interpolate(nw, ne, wx)
    south = self.interpolate(sw, se, wx)
    value = self.interpolate(north, south, wy)

    return (value+1)/2

