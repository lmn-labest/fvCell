#!/usr/bin/python
import sys
import math as m

#**********************************************************************
def main(argv):
  progArg = (['largura altura nl nh angulo fileOut'])
#checando os agumentos  
  nArgs = len(argv)
  if nArgs < 5:
    sys.stderr.write("Usage: %s "%argv[0])
    for arg in progArg:
      print arg 
    return 1

# ... atribuindo variaveis
  l       = float(argv[1])
  h       = float(argv[2])
  nl      = int(argv[3])
  nh      = int(argv[4])
  angulo  = float(argv[5])
  fileOut = argv[6]
# ... 
  dl = l/float(nl-1)
  dh = h/float(nh-1)
  x0 = 0.0
  y0 = 0.0
  print dl,dh
  print nl,nh
  print 'nCoor: ',nl*nh,'nEl: ',(nl-1)*(nh-1)
# ... coordenadas
  fileName =fileOut +'.dat'
#  fileName = fileOut + '_coor.dat'
  f = open(fileName,'w')
  f.write("coordinates\n")
  nCoor = 1
  teta = angulo*m.pi/180.0
  y = y0
  for i in range(0,nh):
    x = x0
    for j in range(0,nl):
      f.write("%9d %16.6f %16.6f\n"%(nCoor,x,y))
      x = x + float(dl)
      nCoor = nCoor + 1
    y  = y  + float(dh)*m.sin(teta) 
    x0 = x0 + float(dh)*m.cos(teta) 
  f.write("endCoordinates\n")
#  f.close()

# ... elementos
#  fileName = fileOut + '_elem.dat'
#  f = open(fileName,'w')
  f.write("cells\n")
  nElm = 1
  for i in range(0,nh-1):
    for j in range(0,nl-1):
      no1 = 1+j+i*nl
      no2 = no1 + 1
      no4 = (i+1)*nl + j + 1 
      no3 = no4 + 1 
      f.write("%9d %2d %2d %2d %2d %6d %6d %6d %6d\n"%(nElm,1,3,4,4,no1,no2,no3,no4))
      nElm  = nElm + 1
  f.write("endCells\n")
#  f.close()
# ... condicoe de contorno
#  fileName = fileOut + '_res.dat'
#  f = open(fileName,'w')
  f.write("faceRd1\n")
#parede inferior
  f.write("%9d %2d %2d %2d %2d %2d %2d\n"%(1,5,1,0,0,0,0))
  for i in range(1,nl-2):
    f.write("%9d %2d %2d %2d %2d %2d %2d\n"%(i+1,5,1,0,0,0,0))
  f.write("%9d %2d %2d %2d %2d %2d %2d\n"%(nl-1,5,1,0,0,0,0))

#parede superior
  nElm0 = (nl-1)*(nh-1) - (nl -2)
  f.write("%9d %2d %2d %2d %2d %2d %2d\n"%(nElm0,5,0,0,1,0,0))
  for i in range(1,nl-2):
    f.write("%9d %2d %2d %2d %2d %2d %2d\n"%(nElm0+i,5,0,0,1,0,0))
  f.write("%9d %2d %2d %2d %2d %2d %2d\n"%((nl-1)*(nh-1),5,0,0,1,0,0))

#parede esquerda
# for i in range(1,(nh-2)/10):
#   f.write("%9d %2d %2d %2d %2d %2d %2d\n"%(i*(nl-1)+1,5,0,0,0,2,0))
#  for i in range(1,nh-2):
#    f.write("%9d %2d %2d %2d %2d %2d %2d\n"%(i*(nl-1)+1,5,0,0,0,1,0))

#parede direita 
# for i in range(nh-2-(nh-2)/10,nh-2):
#   f.write("%9d %2d %2d %2d %2d %2d %2d\n"%(nl+i*(nl-1)-1,5,0,3,0,0,0))
#  for i in range(1,nh-2):
#    f.write("%9d %2d %2d %2d %2d %2d %2d\n"%(nl+i*(nl-1)-1,5,0,1,0,0,0))

  f.write("endFaceRd1\n")
  f.write("faceSd1\n")

# ...
#parede superior
  nElm0 = (nl-1)*(nh-1) - (nl -2)
  x = 0
  for i in range(0,nl-1):
    x  = x + dl
    xm = x-0.5*dl
#   f.write("%9d %2d %f %f %f %f %f\n"%(nElm0+i,5,0,0,m.sin(m.pi*xm),0,0))
    f.write("%9d %2d %f %f %f %f %f\n"%(nElm0+i,5,0,0,100,0,0))
  f.write("endFaceSd1\n")
#
# f.write("elveloc\n")
# for i in range(1,(nl-1)*(nh-1)):
#   f.write("%9d %.2f %.2f\n"%(i,2.0,0))
# f.write("end elveloc\n")
  f.write("endMesh")
  f.close()
      
#**********************************************************************

if __name__ == '__main__':
  sys.exit(main(sys.argv))
